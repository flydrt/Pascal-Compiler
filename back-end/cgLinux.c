#include "cgLinux.h"
#include <stdio.h>
#include <time.h>

static void main_begin();			//the main function begins
static void main_end();				//the main function ends
static void program_begin();
static void program_end();
static void gen_code(Node);			//Node is DAG node

static int gen_level = 0;







static void main_begin(){
	fprintf(codfp,"\n\n# --- main routine ----\n");
	fprintf(codfp, "\t\t.text\n");
	fprintf(codfp, ".globl _main\n");					//global声明外部程序可访问的标签
	fprintf(codfp, "\t\t.type _main, @function\n");   	//.type声明函数名称
	fprintf(codfp, "_main:\n");
	fprintf(codfp, "\t\tpushl\t%%ebp\n");				//save current ebp 
	fprintf(codfp, "\t\tmovl\t%%esp, %%ebp\n");			//ebp设为当前栈指针
}

static void main_end(){
	fprintf(codfp,"\t\tleave\n");						//leave = {movl %ebp, %esp;	popl %ebp}
    fprintf(codfp,"\t\tret\n");							//ret = {popl %eip}，EIP寄存器，用来存储CPU要读取指令的地址
}

static void program_begin(){

}

static void program_end(){

}

static int gen_code(Node rootnode)
{
    int ret = 0;
    Node pnode;

    gen_level++;

    switch (generic(rootnode->op))			//#define generic(op)  ((op)&0x3F0)
    {
    case ARG:
        if (!rootnode->kids[0])
        {
            return ERROR_SUCCESS;
        }

        gen_code(rootnode->kids[0]);
        do_linux_first_arg(rootnode->kids[0]->type->type_id);

        pnode = rootnode->kids[1];
        while(pnode)
        {
            if (!pnode->kids[0])
                break;

            gen_code(pnode->kids[0]);
            do_linux_args(pnode->kids[0]->type->type_id);

            pnode = pnode->kids[1];
        }

        gen_level --;
        return ERROR_SUCCESS;
    case AND:
    case OR:
    case EQ:
    case NE:
    case GT:
    case GE:
    case LE:
    case LT:
        if (rootnode->kids[0])
        {
            ret = gen_code(rootnode->kids[0]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        emit_linux_dos_push_op(rootnode->kids[0]->type);
        if (rootnode->kids[1])
        {
            ret = gen_code(rootnode->kids[1]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        break;
    case BOR:
    case BAND:
    case BXOR:
    case ADD:
    case SUB:
        if (rootnode->kids[0])
        {
            ret = gen_code(rootnode->kids[0]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        emit_linux_dos_push_op(rootnode->kids[0]->type);
        if (rootnode->kids[1])
        {
            ret = gen_code(rootnode->kids[1]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        break;
    case RSH:
    case LSH:
    case DIV:
    case MUL:
    case MOD:
        if (rootnode->kids[0])
        {
            ret = gen_code(rootnode->kids[0]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        emit_linux_dos_push_op(rootnode->kids[0]->type);
        if (rootnode->kids[1])
        {
            ret = gen_code(rootnode->kids[1]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        break;
    case ARRAY:
        emit_linux_load_address(rootnode->syms[0]);
        emit_linux_dos_push_op(find_type_by_id(TYPE_INTEGER));
        if (rootnode->kids[0])
        {
            ret = gen_code(rootnode->kids[0]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        break;
        /*
        case ADDRG:
        if (rootnode->kids[0] != NULL)
        {
        	if (generic(rootnode->kids[0]->op) == ARRAY)
        	{
        		emit_linux_load_address(rootnode->kids[0]->syms[0]);
        		emit_linux_dos_push_op(TYPE_INTEGER);
        	}
        	else if (generic(rootnode->kids[0]->op) == FIELD)
        	{
        		emit_linux_load_address(rootnode->syms[0]);
        		emit_linux_dos_push_op(TYPE_INTEGER);
        		do_linux_record_factor(rootnode->syms[0], rootnode->syms[1]);
        	}
        }
        break;
        */
    case SYS:
        /* for sys call, all childnodes will be processed in next switch. */
        break;
    case CALL:
        push_call_stack(rootnode->symtab);

    default:
        if (rootnode->kids[0])
        {
            ret = gen_code(rootnode->kids[0]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }

        if (rootnode->kids[1])
        {
            ret = gen_code(rootnode->kids[1]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }

        if (rootnode->kids[2])
        {
            ret = gen_code(rootnode->kids[2]);
            if (ret < 0)
            {
                gen_level --;
                return ret;
            }
        }
        break;
    }

    switch (generic(rootnode->op))
    {
    case ARRAY:
        do_linux_array_factor(rootnode->syms[0]);
        break;
    case CNST:
        do_linux_factor(rootnode->syms[0]);
        break;
    case FIELD:
        emit_linux_load_address(rootnode->syms[0]);
        emit_linux_dos_push_op(find_type_by_id(TYPE_INTEGER));
        do_linux_record_factor(rootnode->syms[0], rootnode->syms[1]);
        /* emit_linux_load_field(rootnode->syms[1]); */
        break;
    case HEADER:
        emit_linux_routine_prologue(rootnode->symtab);
        break;
    case TAIL:
        emit_linux_routine_epilogue(rootnode->symtab);
        break;
    case NOT:
        do_linux_not_factor(rootnode->kids[0]->syms[0]);
        break;
    case NEG:
        do_linux_negate(rootnode->kids[0]->syms[0]);
        break;
    case ASGN:
        {
            p = rootnode->kids[0]->syms[0];
            if (!p)
                assert(0);

            if (p->defn == DEF_FUNCT)
            {
                ptab = find_routine(p->name);

                if(ptab)
                    do_linux_function_assign(ptab, rootnode->kids[0]->type->type_id);
                else
                {
                    parse_error("Undeclared identifier.", p->name);
                    gen_level --;
                    return ERROR_UNDECLARE;
                }
            }
            else
            {
                do_linux_assign(p, rootnode->kids[0]->type->type_id);
            }
        }
        break;
    case CALL:
        do_linux_procedure_call(rootnode->symtab);
        pop_call_stack();
        break;
    case SYS:

        emit_linux_address = 1;		/* signal the ADDRG to generate address. */
        if ((rootnode->kids[0] == NULL) ||
                (rootnode->kids[0]->kids[0] == NULL) ||
                (rootnode->kids[0]->kids[1] == NULL))
        {
            /* do system call without args, or with only one arg. */
            if (rootnode->kids[0])
			{
                if (rootnode->kids[0]->kids[0])
                    gen_code(rootnode->kids[0]->kids[0]);
                else
                    gen_code(rootnode->kids[0]);
			}
            do_linux_sys_routine(rootnode->u.sys_id, rootnode->kids[0]->type->type_id);
        }
        else
        {
#if DEBUG & SYSTEM_CALL_DEBUG
            {
                Symtab systab = find_sys_routine(rootnode->u.sys_id);
                printf("do system call %s with more than one arg.\n", systab->name);
            }
#endif
            switch (rootnode->u.sys_id)
            {
            case pREAD:
            case pREADLN:
            case pWRITE:
            case pWRITELN:
            default:
                gen_code(rootnode->kids[0]->kids[0]);
                do_linux_sys_routine(rootnode->u.sys_id, rootnode->kids[0]->kids[0]->type->type_id);

                pnode = rootnode->kids[0]->kids[1];
                while(pnode)
                {
                    if (!pnode->kids[0])
                        break;

                    gen_code(pnode->kids[0]);
                    do_linux_sys_routine(rootnode->u.sys_id, pnode->kids[0]->type->type_id);
                    pnode = pnode->kids[1];
                }

                break;
            }
        }
        emit_linux_address = 0;		/* clear signal */
        break;
    case COND:
        do_linux_cond_jump(rootnode->u.cond.true_or_false, rootnode->u.cond.label);
        break;
    case JUMP:
        do_linux_jump(rootnode->syms[0]);
        break;
    case LABEL:
        do_linux_label(rootnode->syms[0]);
        break;
    case INCR:
        /*
         * variable is in first child of INCR node.
         * generally an ADDRG node.
         */
        assert(rootnode->kids[0]->syms[0]);
        do_linux_incr(rootnode->kids[0]->syms[0]);
        break;
    case DECR:
        /*
         * variable is in first child of DECR node.
         * generally an ADDRG node.
         */
        assert(rootnode->kids[0]->syms[0]);
        do_linux_decr(rootnode->kids[0]->syms[0]);
        break;
    case LOAD:
        if (rootnode->kids[0] == NULL)
        {
            /* simple const or id. */
            do_linux_factor(rootnode->syms[0]);
        }
        else if (generic(rootnode->kids[0]->op) == ARRAY)
        {
            emit_linux_load_value(rootnode->kids[0]->syms[0]);
        }
        else
        {
            emit_linux_load_field(rootnode->kids[0]->syms[1]);
        }
        break;
    case EQ:
    case NE:
    case GT:
    case GE:
    case LE:
    case LT:
        do_linux_expression(rootnode->kids[1]->type, rootnode->op);
        break;
    case ADD:
    case SUB:
    case OR:
        do_linux_expr(rootnode->kids[1]->type, rootnode->op);
        break;
    case AND:
    case RSH:
    case LSH:
    case BOR:
    case BAND:
    case BXOR:
    case DIV:
    case MUL:
    case MOD:
        /*
        if (rootnode->kids[0])
        {
        	ret = gen_code(rootnode->kids[0]);
        	if (ret < 0) {
        		gen_level --;
        		return ret;
        	}
        }
        */
        do_linux_term(rootnode->kids[1]->type, rootnode->op);
        break;
    case BLOCKBEG:
    case BLOCKEND:
        break;
    case ADDRG:
        if (emit_linux_address)
            emit_linux_load_address(rootnode->syms[0]);
        break;
    default:
        assert(0);
        break;

    }

    gen_level --;
    return ret;
}