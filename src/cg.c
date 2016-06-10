#include "cg.h"
#define DATA_OUTPUT(str) fprintf(dataFile,"%s",str)
#define CODE_OUTPUT(str) fprintf(codeFile,"%s",str)

FILE* codeFile = NULL;			//code file
FILE* dataFile = NULL;			//data file
FILE* targetFile = NULL;


void emit_main_begin();
void emit_main_end();
void CGStmtAssign();
void generateCode(pTree,int);


void emit_main_begin(){
	CODE_OUTPUT(".text\n");
	CODE_OUTPUT(".global _main\n");
	CODE_OUTPUT("\t\t.type _main,@function\n");
	CODE_OUTPUT("_main:\n");
	CODE_OUTPUT("\t\tpushl\t%ebp\n");
	CODE_OUTPUT("\t\tmovl\t%esp,%ebp\n");
}

void emit_main_end(){
	CODE_OUTPUT("\t\tleave\n");
	CODE_OUTPUT("\t\tret\n");
}
void CGStmtAssign(pTree node,int space){
	int level;
	
	pSymNode symnode = searchIDWithinScope(node->child[1]->data.stringVal
		, node->child[1]->symtab, &level);
	if(node->symtab == NULL)
		printf("NULL too\n");
	if(symnode == NULL)
		printf("We get NULL!\n");
	generateCode(node->child[2],space+1);		//get value
	
	// if(symnode->attr == ATTR_INTEGER)
		fprintf(codeFile,"\t\tmovl\t%edx,hello\n");

}

void generateCode(pTree node,int space){
	for(int i = 0;i < space; i++)
		printf("-");
	switch(node->type){
		case tPROGRAM:			{
			emit_main_begin();
			printf("tPROGRAM\n");
			generateCode(node->child[2],space+1);		//routine
			emit_main_end();
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
		case FUNCTION_DECL: 	printf("FUNCTION_DECL\n"); break;
		case FUNCTION_HEAD: 	printf("FUNCTION_HEAD\n");break;
 		case PROCEDURE_DECL:	printf("PROCEDURE_DECL\n");break;
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

		case ePLUS: 			{
			printf("ePLUS\n");
			generateCode(node->child[1],space+1);
			generateCode(node->child[2],space+1);
			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
			break;
		}
 		case eMINUS:			printf("eMINUS\n");break;
 		case eOR: 				printf("eOR\n");break;

 		case eMUL: 				printf("eMUL\n");break;
 		case eDIV: 				printf("eDIV\n");break;
 		case eRDIV:				printf("eRDIV\n");break;
 		case eMOD: 				printf("eMOD\n");break;
 		case eAND: 				printf("eAND\n");break;

		case FACTOR_ID: 		printf("FACTOR_ID\n");break;
 		case FACTOR_FUNC: 		printf("FACTOR_FUNC\n");break;
 		case FACTOR_SYS_FUNC_ARGS: printf("FACTOR_SYS_FUNC_ARGS\n");break;
 		case FACTOR_CONST: 		{
 			printf("FACTOR_CONST\n");
 			generateCode(node->child[1],space+1);
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
 		case PROC_STMT_SYS_EXPR:printf("PROC_STMT_SYS_EXPR\n");break;
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
			printf("tINTEGER %d\n",node->data);
			break;
		}
 		case tREAL: 			printf("tREAL\n");break;
 		case tCHAR: 			printf("tCHAR\n");break;
 		case tSTRING:		 	printf("tSTRING\n");break;
 		case tID:				printf("tID: %s\n",node->data);break;
		default:printf("others\n");break;
	}
	// for(int i = 0 ; i < 5 ; i ++)
	// 			if(node->child[i]!=NULL)
	// 				generateCode(node->child[i],space+1);
}


int CG_main(pTree root,char * target){

	printf("--------- starting generating code ---------\n");
	codeFile = fopen("code_part","w");
	dataFile = fopen("data_part","w");
	char buf[20000];

	//write the program head
	DATA_OUTPUT("sys_call_id = 0x80\n");
	DATA_OUTPUT("exit_syscall = 0x1\n\n");

	generateCode(root,0);

	//write the program tail
	CODE_OUTPUT("\n.global _start\n");
	CODE_OUTPUT("_start:\n");
	CODE_OUTPUT("\t\tcall _main\n");		//call the program
	CODE_OUTPUT("\t\tmovl $0,%ebx\n");
	CODE_OUTPUT("\t\tmovl $exit_syscall,%eax\n");
	CODE_OUTPUT("\t\tint $sys_call_id\n");
	CODE_OUTPUT("");						
	//<!-- to be continued -->
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