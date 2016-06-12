#include "cg.h"
#define DATA_OUTPUT(str) fprintf(dataFile,"%s",str)
#define CODE_OUTPUT(str) fprintf(codeFile,"%s",str)
#define MAXFIELD 100
#define MAXLIST 1000
#define MAXSTRING 2048

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

typedef struct strStruct{
	char string[MAXSTRING];
	char rname[100];
	int size;
}datalink;
datalink dataList[MAXLIST];
int dataCnt = 0;


void emit_main_begin();
void emit_main_end();
void CGStmtAssign(pTree,int);
void CGStmtIf(pTree);
void CGexpr();
void CGFactorConst(pTree);
void CGFactorId(pTree);
void CGFor(pTree);
void CGCompare(pTree);
void CGRepeat(pTree);
void CGWhile(pTree);
void CGCaseStmt(pTree);
void CGCaseExpr(pTree);

void CGOutput(pTree);
void CGInput(pTree);
void CGloadAddress(pSymNode);
char* CGGetLabel();

void insertBss(pSymNode);
int insertDataSection(char*);
void writeBss();
void writeData();

void generateCode(pTree,int);

void init_stack();
void enter_field(pTabNode);
void leave_field();


void emit_main_begin(){
	CODE_OUTPUT("# main routine\n");
	CODE_OUTPUT(".text\n");
	CODE_OUTPUT(".global _main\n");
	CODE_OUTPUT("\t\t.type _main,@function\n");
	CODE_OUTPUT("_main:\n");
	CODE_OUTPUT("\t\tpushl\t%ebp\n");
	CODE_OUTPUT("\t\tmovl\t%esp,%ebp\n");

	bssList.size = 0;
	memset(dataList,0,sizeof(datalink)*MAXLIST);
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
int insertDataSection(char* str){
	if(strcmp(str,"")==0)
		return -1;
	int i = 0;
	for(;i < dataCnt; i++){
		if(strcmp(dataList[i].string,str)==0)
			return i;
	}
	strcpy(dataList[dataCnt].string,str);
	sprintf(dataList[dataCnt].rname,"str_%d",dataCnt);
	dataList[dataCnt++].size = 0;
	return dataCnt - 1;
}

void writeData(){
	int i = 0;
	for(;i < dataCnt; i++){
		fprintf(dataFile, ".globl %s\n", dataList[i].rname);
		DATA_OUTPUT("\t\t.section .rodata\n");
		DATA_OUTPUT("\t\t.align 4\n");
		fprintf(dataFile, ".LC%s:\n", dataList[i].rname);
		fprintf(dataFile, "\t\t.string \"%s\"\n", dataList[i].string);
		DATA_OUTPUT("\t\t.data\n");
		DATA_OUTPUT("\t\t.align 4\n");
		fprintf(dataFile, "\t\t.type %s @object\n", dataList[i].rname);
		fprintf(dataFile, "%s:\n", dataList[i].rname);
		fprintf(dataFile, "\t\t.long .LC%s\n", dataList[i].rname);
	}
	DATA_OUTPUT("\n");
}

char* CGGetLabel(){
	static int label_cnt = 0;
	char tmp[1024];
	static char label[1024];
	strcpy(label,"LABEL");
	sprintf(tmp,"%d",label_cnt);
	strcat(label,tmp);
	label_cnt++;
	return label;
}


void emit_main_end(){
	CODE_OUTPUT("\t\tleave\n");
	CODE_OUTPUT("\t\tret\n");
}

void CGStmtIf(pTree node){
	char else_label[100],exit_label[100];
	
	sprintf(else_label,"if_else_%s",CGGetLabel());
	sprintf(exit_label,"if_exit_%s",CGGetLabel());

	generateCode(node->child[1],5);

	CODE_OUTPUT("\t\tcmpl\t$1,%eax\n");
	fprintf(codeFile, "\t\tjl\t%s\n",else_label);
	
	generateCode(node->child[2],5);
	fprintf(codeFile, "\t\tjmp\t%s\n",exit_label);
	fprintf(codeFile, "%s:\n",else_label);
	generateCode(node->child[3],5);

	fprintf(codeFile, "%s:\n",exit_label);
}

void CGRepeat(pTree node){
	char repeat_start[100];
	sprintf(repeat_start,"repeat_%s",CGGetLabel());
	fprintf(codeFile, "%s:\n", repeat_start);
	generateCode(node->child[1],2);
	generateCode(node->child[2],2);

	CODE_OUTPUT("\t\tcmpl\t$0,%eax\n");
	fprintf(codeFile,"\t\tje\t%s\n",repeat_start);
}

void CGWhile(pTree node){
	char while_start[100],while_end[100];
	sprintf(while_start,"while_start_%s",CGGetLabel());
	sprintf(while_end,"while_end_%s",CGGetLabel());

	fprintf(codeFile, "%s:\n",while_start);
	generateCode(node->child[1],2);
	CODE_OUTPUT("\t\tcmpl\t$1,%eax\n");
	fprintf(codeFile, "\t\tjl\t%s\n",while_end);

	generateCode(node->child[2],2);
	fprintf(codeFile, "\t\tjmp\t%s\n",while_start);
	fprintf(codeFile, "%s:\n", while_end);
}


void CGFor(pTree node){
	char for_start[100],for_end[100],jump[100];
	int i;
	sprintf(for_start,"for_start_%s",CGGetLabel());
	sprintf(jump,"j_%s",CGGetLabel());
	sprintf(for_end,"for_end_%s",CGGetLabel());

	
	generateCode(node->child[2],2);

	int level;
	pSymNode symnode = searchIDWithinScope(node->child[1]->data.stringVal
		, currentStack.stack[currentStack.top - 1], &level);
	insertBss(symnode);
	fprintf(codeFile, "\t\tmovl\t%%eax,%s\n", symnode->rname);	//initial assign

	fprintf(codeFile, "%s:\n",for_start);
	fprintf(codeFile, "\t\tmovl\t%s,%%eax\n",symnode->rname );
	CODE_OUTPUT("\t\tpushl\t%eax\n");
	generateCode(node->child[3],2);
	CODE_OUTPUT("\t\tpopl\t%edx\n");


	if(node->type == FOR_STMT_DOWNTO){
		CODE_OUTPUT("\t\tcmpl\t%eax,%edx\n");
		CODE_OUTPUT("\t\tmovl\t$1,%eax\n");
		fprintf(codeFile, "\t\tjge\t%s\n", jump);
		CODE_OUTPUT("\t\txorl\t%eax,%eax\n");
	} else {
		CODE_OUTPUT("\t\tcmpl\t%eax,%edx\n");
		CODE_OUTPUT("\t\tmovl\t$1,%eax\n");
		fprintf(codeFile, "\t\tjle\t%s\n", jump);
		CODE_OUTPUT("\t\txorl\t%eax,%eax\n");
	}
	fprintf(codeFile, "%s:\n", jump);
	CODE_OUTPUT("\t\tcmpl\t$1,%eax\n");
	fprintf(codeFile, "\t\tjl\t%s\n", for_end);
	
	generateCode(node->child[4],2);
	fprintf(codeFile, "\t\tincl\t%s\n", symnode->rname);
	fprintf(codeFile, "\t\tjmp\t%s\n",for_start);
	fprintf(codeFile, "%s:\n", for_end);
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
			CODE_OUTPUT("\t\tsubl\t%eax,%edx\n");
			CODE_OUTPUT("\t\tmovl\t%edx,%eax\n");
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
 		case eRDIV: {
 			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\tfdivs\t%edx,%eax\n");
 			break;
 		}		
	}

}

void CGCaseStmt(pTree node){

	
	generateCode(node->child[1],0);
	CODE_OUTPUT("\t\tpushl\t%eax\n");
	generateCode(node->child[2],0);
}

void CGCaseExpr(pTree node){
	char case_end[100];
	sprintf(case_end,"case_%s",CGGetLabel());
	
	generateCode(node->child[1],10);
	CODE_OUTPUT("\t\tpopl\t%edx\n");
	CODE_OUTPUT("\t\tcmpl\t%edx,%eax\n");
	CODE_OUTPUT("\t\tpushl\t%edx\n");
	fprintf(codeFile, "\t\tjne\t%s\n", case_end);
	generateCode(node->child[2],10);
	fprintf(codeFile,"%s:\n",case_end);
}


void CGCompare(pTree node){
	generateCode(node->child[1],15);
	CODE_OUTPUT("\t\tpushl\t%eax\n");
	generateCode(node->child[2],15);
	
	switch(node->child[1]->attr){
		case ATTR_INTEGER:{
			CODE_OUTPUT("\t\tpopl\t%edx\n");
			CODE_OUTPUT("\t\tcmpl\t%eax,%edx\n");
			break;
		}
		case ATTR_CHAR:{
			printf("node char\n");
			break;
		}
		case ATTR_STRING:{
			printf("node string\n");
			break;
		}
		default:{
			printf("node default\n");
		}
	}
	CODE_OUTPUT("\t\tmovl\t$1,%eax\n");
	char jumpLabel[100];
	sprintf(jumpLabel,"j_%s",CGGetLabel());
	switch(node->type){
		case eGE:	{
			fprintf(codeFile, "\t\tjge\t%s\n",jumpLabel);
			break;
		}		
 		case eGT:	{
 			fprintf(codeFile, "\t\tjg\t%s\n",jumpLabel);
 			break;
 		} 				
 		case eLE: 	{
 			fprintf(codeFile, "\t\tjle\t%s\n",jumpLabel);
 			break;
 		} 						
 		case eLT: 	{
 			fprintf(codeFile, "\t\tjl\t%s\n",jumpLabel);
 			break;
 		} 						
 		case eEQUAL: {
 			fprintf(codeFile, "\t\tje\t%s\n",jumpLabel);
 			break;
 		} 						
 		case eUNEQUAL: {
 			fprintf(codeFile, "\t\tjne\t%s\n",jumpLabel);
 			break;
 		}	
	}
	CODE_OUTPUT("\t\txorl\t%eax,%eax\n");
	fprintf(codeFile, "%s:\n", jumpLabel);
}

void CGFactorConst(pTree node){
	switch(node->child[1]->type){
		case tINTEGER:{
			fprintf(codeFile,"\t\tmovl\t$%d,%%eax\n",node->child[1]->data.intVal);
			break;
		}
		case tREAL:
		case tCHAR:break;
		case tSTRING:{
			int index = insertDataSection(node->child[1]->data.stringVal);
			if(index >= 0)
				fprintf(codeFile, "\t\tmovl\t%s,%%eax\n", dataList[index].rname);
			printf("string data: %s\n",node->child[1]->data.stringVal);
			break;
		}
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
	generateCode(node->child[3],10);
	switch(node->child[3]->attr){
		case ATTR_INTEGER: {
			printf("INTEGER!\n");

			if(strcmp("write",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_write_int\n");
			} else if (strcmp("writeln",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_writeln_int\n");
			}
			break;
		}
		case ATTR_REAL:{
			printf("WARNING: we can't output real\n");
			// if(strcmp("write",node->child[1]->data.stringVal)==0){
			// 	CODE_OUTPUT("\t\tpushl\t%eax\n");
			// 	CODE_OUTPUT("\t\tpushl\t%ebp\n");
			// 	CODE_OUTPUT("\t\tcall\t_write_int\n");
			// } else if (strcmp("writeln",node->child[1]->data.stringVal)==0){
			// 	CODE_OUTPUT("\t\tpushl\t%eax\n");
			// 	CODE_OUTPUT("\t\tpushl\t%ebp\n");
			// 	CODE_OUTPUT("\t\tcall\t_writeln_int\n");
			// } else {
				
			// }
			break;
		}
		case ATTR_STRING:{
			if(strcmp("write",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_write_string\n");
			} else if (strcmp("writeln",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_writeln_string\n");
			}
			break;
		}
		case ATTR_CHAR:{
			printf("CHAR!\n");
			if(strcmp("write",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_write_char\n");
			} else if (strcmp("writeln",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_writeln_char\n");
			} else {
				
			}
			break;
		}
		case ATTR_NONE:{
			printf("WRITE NONE!\n");
			if(strcmp("write",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_write_int\n");
			} else if(strcmp("writeln",node->child[1]->data.stringVal)==0){
				CODE_OUTPUT("\t\tpushl\t%eax\n");
				CODE_OUTPUT("\t\tpushl\t%ebp\n");
				CODE_OUTPUT("\t\tcall\t_writeln_int\n");
			}
			break;
		}
		default:{
			printf("WRITE DEFAULT!\n");
		}
	}
	CODE_OUTPUT("\t\taddl\t$8,%esp\n");
}


void CGloadAddress(pSymNode symnode){
	fprintf(codeFile, "\t\tleal\t%s,%%eax\n",symnode->rname);
}

void CGInput(pTree node){
	int level;
	pSymNode symnode = searchIDWithinScope(node->child[1]->data.stringVal
		, currentStack.stack[currentStack.top - 1], &level);

	CGloadAddress(symnode);

	CODE_OUTPUT("\t\tpushl\t%eax\n");
	CODE_OUTPUT("\t\tpushl\t%ebp\n");
	switch(node->child[1]->attr){
		case ATTR_INTEGER: {
			//printf("READ INTEGER!\n");
			CODE_OUTPUT("\t\tcall\t_read_int\n");
			break;
		}
		case ATTR_REAL:{
			printf("WARNING: we can't input real\n");
			break;
		}
		case ATTR_STRING:{
			CODE_OUTPUT("\t\tcall\t_read_string\n");
			break;
		}
		case ATTR_CHAR:{
			printf(" READ CHAR!\n");
			CODE_OUTPUT("\t\tcall\t_read_char\n");
			break;
		}
		default:{
			printf("READ default\n");
		}
	}
	CODE_OUTPUT("\t\taddl\t$8,%esp\n");
}


void generateCode(pTree node,int space){
	for(int i = 0;i < space; i++)
		printf("-");
	switch(node->type){
		case tPROGRAM:			{
			emit_main_begin();

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
		case IF_STMT: 			{
			//printf("IF_STMT\n");
			CGStmtIf(node);
			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
			break;
		}
 		case REPEAT_STMT: 		{
 			//printf("REPEAT_STMT\n");
 			CGRepeat(node);
 			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
 			break;
 		}
 		case WHILE_STMT: 		{
 			//printf("WHILE_STMT\n");
 			CGWhile(node);
 			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
 			break;
 		}
 		case FOR_STMT_TO: 		{
 			printf("FOR_STMT_TO\n");
 			CGFor(node);
 			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
 			break;
 		}
 		case FOR_STMT_DOWNTO: 	{
 			printf("FOR_STMT_DOWNTO\n");
 			CGFor(node);
 			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
 			break;
 		}
		case CASE_STMT: 		{
			printf("CASE_STMT\n");
			CGCaseStmt(node);
			break;
		}
 		case CASE_EXPR_CONST:	{
 			printf("CASE_EXPR_CONST\n");
 			CGCaseExpr(node);
 			if(node->child[0]!=NULL)
				generateCode(node->child[0],space+1);
 			break;
 		}
 		case CASE_EXPR_ID: 		printf("CASE_EXPR_ID\n");break;
 		case GOTO_STMT: 		printf("GOTO_STMT\n");break;

 		//compare
		case eGE:				
 		case eGT: 				
 		case eLE: 				
 		case eLT: 				
 		case eEQUAL: 			
 		case eUNEQUAL: {
 			printf("COMPARE\n");
 			CGCompare(node);
 			break;
 		}			

 		//expr
 		case eRDIV:				
 		case eOR: 				
 		case eMINUS:			
 		case eMUL: 				
 		case eDIV: 				
		case ePLUS: 			{
			printf("EXOP\n");
			CGexpr(node);

			break;
		}
 		
 		
 		
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
 			if(node->child[0] != NULL)
 				generateCode(node->child[0],space+1);
 			break;
 		}
 		case PROC_STMT_READ:	{
 			printf("PROC_STMT_READ\n");
 			CGInput(node);
 			if(node->child[0] != NULL)
 				generateCode(node->child[0],space+1);
 			break;
 		}

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
	DATA_OUTPUT(".data\n\n");

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
	writeData();
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