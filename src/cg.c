#include "cg.h"
#define DATA_OUTPUT(str) fprintf(dataFile,"%s",str)
#define CODE_OUTPUT(str) fprintf(codeFile,"%s",str)
#define MAXFIELD 100
#define MAXLIST 1000

FILE* codeFile = NULL;			//code file
FILE* dataFile = NULL;			//data file
FILE* targetFile = NULL;
typedef struct{
	pTabNode stack[MAXFIELD];
	int top;
}fieldStack;
fieldStack currentStack;

typedef struct{
	pSymNode symList[MAXLIST];
	int size;
}SymList;
SymList bssList;


void emit_main_begin();
void emit_main_end();
void CGStmtAssign();
void CGexpr();
void CGFactorConst(pTree);
void CGFactorId(pTree);
void CGOutput(pTree);
void insertBss(pSymNode);
void writeBss();

void generateCode(pTree,int);

void init_stack();
void enter_field(pTabNode);
void leave_field();


void emit_main_begin(){
	CODE_OUTPUT(".text\n");
	CODE_OUTPUT(".global _main\n");
	CODE_OUTPUT("\t\t.type _main,@function\n");
	CODE_OUTPUT("_main:\n");
	CODE_OUTPUT("\t\tpushl\t%ebp\n");
	CODE_OUTPUT("\t\tmovl\t%esp,%ebp\n");

	bssList.size = 0;
	int i = 0;
	for(;i < MAXLIST; i++){
		bssList.symList[i] = NULL;
	}
}

void insertBss(pSymNode node){
	if(node == NULL)
		return;
	int i = 0,flag = 0;
	for(;i < MAXLIST; i++){
		if(bssList.symList[i] == node){
			flag = 1;
			break;
		}
	}
	if(!flag)
		bssList.symList[bssList.size++] = node;
	if(bssList.size >= MAXLIST)
		printf("WARNING: TOO FEWER MAXLIST\n");
}

void writeBss(){
	int i = 0;
	CODE_OUTPUT("#bss section\n");
	for(; i < bssList.size; i++){
		switch(bssList.symList[i]->attr){
			case ATTR_INTEGER:{
				fprintf(codeFile,"\t\t.comm\t%s,4,4\n",bssList.symList[i]->rname);
				break;
			}
			case ATTR_REAL:
			case ATTR_CHAR:
			case ATTR_STRING:
			case ATTR_BOOL:break;
			default:break;
		}
	}
}

void emit_main_end(){
	CODE_OUTPUT("\t\tleave\n");
	CODE_OUTPUT("\t\tret\n");
}
void CGStmtAssign(pTree node,int space){
	int level;
	
	//get the symbol table
	pSymNode symnode = searchIDWithinScope(node->child[1]->data.stringVal
		, currentStack.stack[currentStack.top - 1], &level);
	insertBss(symnode);
	//store the value in %edx
	generateCode(node->child[2],space+1);		 
	
	if(symnode->attr == ATTR_INTEGER)
		fprintf(codeFile,"\t\tmovl\t%%eax,%s\n",symnode->rname);

}

void CGexpr(pTree node){
	if(node->child[1]!=NULL && node->child[2]!=NULL){
		generateCode(node->child[1],1);
		CODE_OUTPUT("\t\tpushl\t%eax\n");
		generateCode(node->child[2],1);
		//CODE_OUTPUT("\t\tpushl\t%eax\n");
	} else {

	}
	
	switch(node->type){
		case eOR: 	{
			//CODE_OUTPUT("\t\tpopl\t%eax\n");
			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\torl\t%edx,%eax\n");
			break;
		}				
 		case eMINUS:{
 			//CODE_OUTPUT("\t\tpopl\t%eax\n");
			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\tsubl\t%edx,%eax\n");
 			break;
 		}		
		case ePLUS: {
			//CODE_OUTPUT("\t\tpopl\t%eax\n");
			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\taddl\t%edx,%eax\n");
			break;
		}
		case eMUL: 	{
			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\timul\t%edx,%eax\n");
			break;
		}			
 		case eDIV:	{
 			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\tidiv\t%edx,%eax\n");
 			break;
 		} 				
	}

}

void CGFactorConst(pTree node){
	switch(node->child[1]->type){
		case tINTEGER:{
			fprintf(codeFile,"\t\tmovl\t$%d,%%eax\n",node->child[1]->data.intVal);
			break;
		}
		case tREAL:
		case tCHAR:
		case tSTRING:break;
		default: printf("WARNING: FACTOR CONST DEFAULT\n");break;
	}
}

void CGFactorId(pTree node){
	int level;
	pSymNode symnode = searchIDWithinScope(node->data.stringVal
		, currentStack.stack[currentStack.top - 1], &level);
	insertBss(symnode);
	switch(symnode->attr){
		case ATTR_INTEGER:{
			fprintf(codeFile,"\t\tmovl\t%s,%%eax\n",symnode->rname);
			break;
		}
		case ATTR_REAL:
		case ATTR_CHAR:
		case ATTR_STRING:
		case ATTR_BOOL:break;
		default:break;
	}
	
}


void CGOutput(pTree node){
	switch(node->child[3]->attr){
		case ATTR_INTEGER: {
			printf("INTEGER!\n");
			break;
		}
		case ATTR_REAL:{
			printf("REAL!\n");
			break;
		}
		case ATTR_NONE:{
			printf("NONE!\n");
			break;
		}
		case ATTR_CHAR:{
			printf("CHAR!\n");
			break;
		}
		default:{
			printf("DEFAULT!\n");
		}
	}
	generateCode(node->child[3],10);
}

void generateCode(pTree node,int space){
	for(int i = 0;i < space; i++)
		printf("-");
	switch(node->type){
		case tPROGRAM:			{
			emit_main_begin();
			printf("tPROGRAM\n");
			enter_field(node->symtab);

			generateCode(node->child[2],space+1);		//routine
			
			emit_main_end();
			leave_field();
			break;
		}
		case tROUTINE:			{

			printf("tROUTINE\n");
			//generateCode(node->child[1],space+1);
			generateCode(node->child[2],space+1);
			break;
		}
		case tROUTINE_HEAD: 	{
			printf("tROUTINE_HEAD\n");
			break;
		}
		
		case tSUB_ROUTINE : 	printf("tSUB_ROUTINE:\n");break;
		
		case CONST_DECL: 		printf("CONST_DECL\n");break;
		case TYPE_DECL : 		printf("TYPE_DECL\n");break;
		case ARRAY_DECL: 		printf("ARRAY_DECL\n");break;
		case FIELD_DECL: 		printf("FIELD_DECL\n");break;
		case VAR_DECL : 		printf("VAR_DECL\n"); break;
		case FUNCTION_DECL: 	{
			printf("FUNCTION_DECL\n"); 
			enter_field(node->symtab);

			leave_field();
			break;
		}
		case FUNCTION_HEAD: 	printf("FUNCTION_HEAD\n");break;
 		case PROCEDURE_DECL:	{
 			printf("PROCEDURE_DECL\n");
 			enter_field(node->symtab);

			leave_field();
 			break;
 		}
 		case PROCEDURE_HEAD: 	printf("PROCEDURE_HEAD\n");break;
		case VAR_PARA: 			printf("VAR_PARA\n");break;
 		case VAL_PARA: 			printf("VAL_PARA\n");break;
		case LABEL_STMT: 		printf("LABEL_STMT\n");break;
		case ASSIGN_STMT_1: 	{
			printf("ASSIGN_STMT_1\n");
			
			CGStmtAssign(node,space);

			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
			break;
		}
 		case ASSIGN_STMT_2: 	printf("ASSIGN_STMT_2\n");break;
 		case ASSIGN_STMT_3: 	printf("ASSIGN_STMT_3\n");break;
		case IF_STMT: 			printf("IF_STMT\n");break;
 		case REPEAT_STMT: 		printf("REPEAT_STMT\n");break;
 		case WHILE_STMT: 		printf("WHILE_STMT\n");break;
 		case FOR_STMT_TO: 		printf("FOR_STMT_TO\n");break;
 		case FOR_STMT_DOWNTO: 	printf("FOR_STMT_DOWNTO\n");break;
		case CASE_STMT: 		printf("CASE_STMT\n");break;
 		case CASE_EXPR_CONST:	printf("CASE_EXPR_CONST\n");break;
 		case CASE_EXPR_ID: 		printf("CASE_EXPR_ID\n");break;
 		case GOTO_STMT: 		printf("GOTO_STMT\n");break;

		case eGE:				printf("eGE\n");break;
 		case eGT: 				printf("eGT\n");break;
 		case eLE: 				printf("eLE\n");break;
 		case eLT: 				printf("eLT\n");break;
 		case eEQUAL: 			printf("eEQUAL\n");break;
 		case eUNEQUAL: 			printf("eUNEQUAL\n");break;

 		case eOR: 				
 		case eMINUS:			
 		case eMUL: 				
 		case eDIV: 				
		case ePLUS: 			{
			printf("EXOP\n");
			CGexpr(node);

			break;
		}
 		
 		
 		case eRDIV:				printf("eRDIV\n");break;
 		case eMOD: 				printf("eMOD\n");break;
 		case eAND: 				printf("eAND\n");break;

		case FACTOR_ID: 		{
			printf("FACTOR_ID %s\n",node->data.stringVal);
			CGFactorId(node);
			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
			break;
		}
 		case FACTOR_FUNC: 		printf("FACTOR_FUNC\n");break;
 		case FACTOR_SYS_FUNC_ARGS: printf("FACTOR_SYS_FUNC_ARGS\n");break;
 		case FACTOR_CONST: 		{
 			printf("FACTOR_CONST\n");
 			CGFactorConst(node);
 			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
 			break;
 		}
 		case FACTOR_NOT: 		printf("FACTOR_NOT\n");break;
 		case FACTOR_MINUS: 		printf("FACTOR_MINUS\n");break;
 		case FACTOR_ARRAY: 		printf("FACTOR_ARRAY\n");break;
 		case FACTOR_RECORD: 	printf("FACTOR_RECORD\n");break;

		case PROC_STMT_ID: 		printf("PROC_STMT_ID\n");break;
 		case PROC_STMT_ID_ARGS: printf("PROC_STMT_ID_ARGS\n");break;
 		case PROC_STMT_SYS_EXPR:{				//writeln, write
 			printf("PROC_STMT_SYS_EXPR\n");
 			CGOutput(node);
 			break;
 		}
 		case PROC_STMT_READ:	printf("PROC_STMT_READ\n");break;

		case tSYS_TYPE: 		printf("tSYS_TYPE\n");break;
 		case tSYS_FUNCT: 		printf("tSYS_FUNCT\n");break;
 		case tSYS_CON:			printf("tSYS_CON\n");break;
 		case tSYS_PROC:			printf("tSYS_PROC\n");break;
		case tSIMPLE_ID: 		printf("tSIMPLE_ID\n");break;
 		case tSIMPLE_ENUM: 		printf("tSIMPLE_ENUM\n");break;
 		case tSIMPLE_SUBRANGE:  printf("tSIMPLE_SUBRANGE\n");break;
 		case tSIMPLE_SUBRANGE_ID:printf("tSIMPLE_SUBRANGE_ID\n");break;
		
		case tINTEGER: 			{
			printf("tINTEGER %d\n",node->data.intVal);
			break;
		}
 		case tREAL: 			printf("tREAL\n");break;
 		case tCHAR: 			printf("tCHAR\n");break;
 		case tSTRING:		 	printf("tSTRING\n");break;
 		case tID:				printf("tID: %s\n",node->data.stringVal);break;
		default:printf("others\n");break;
	}
	// for(int i = 0 ; i < 5 ; i ++)
	// 			if(node->child[i]!=NULL)
	// 				generateCode(node->child[i],space+1);
}

void init_stack(){
	currentStack.top = 0;
	int i = 0;
	for(;i < MAXFIELD; i++)
		currentStack.stack[i] = NULL;
}

void enter_field(pTabNode x){
	if(x==NULL){
		printf("WARNING: THE TAB IS NULL\n");
		return;
	}
	if(currentStack.top > 0 && currentStack.stack[currentStack.top - 1] == x)
		return;
	if(currentStack.top > MAXFIELD){
		printf("WARNING: TOO MANY FIELD!\n");
		return;
	}
	currentStack.stack[currentStack.top++] = x;
}

void leave_field(){
	if(currentStack.top == 0){
		printf("WARNING: LEAVE FIELD FAILED\n");
		return;
	}
	currentStack.stack[currentStack.top--] = NULL;
}

int CG_main(pTree root,char * target){
	init_stack();
	printf("--------- starting generating code ---------\n");
	codeFile = fopen("code_part","w");
	dataFile = fopen("data_part","w");
	char buf[20000];

	//write the program head
	DATA_OUTPUT("sys_call_id = 0x80\n");
	DATA_OUTPUT("exit_syscall = 0x1\n\n");
	DATA_OUTPUT(".data\n");

	generateCode(root,0);

	//write the program tail
	CODE_OUTPUT("\n.global _start\n");
	CODE_OUTPUT("_start:\n");
	CODE_OUTPUT("\t\tcall _main\n");		//call the program
	CODE_OUTPUT("\t\tmovl $0,%ebx\n");
	CODE_OUTPUT("\t\tmovl $exit_syscall,%eax\n");
	CODE_OUTPUT("\t\tint $sys_call_id\n\n");
	CODE_OUTPUT("");						
	//<!-- to be continued -->
	writeBss();

	fclose(codeFile);
	fclose(dataFile);

	targetFile = fopen(target,"w");
	codeFile = fopen("code_part","r");
	dataFile = fopen("data_part","r");
	while(fgets(buf,BUFSIZ,dataFile)!=NULL){
		fputs(buf,targetFile);
	}

	while(fgets(buf,BUFSIZ,codeFile)!=NULL){
		fputs(buf,targetFile);
	}
	fclose(codeFile);
	fclose(dataFile);
	fclose(targetFile);

	return 0;
}