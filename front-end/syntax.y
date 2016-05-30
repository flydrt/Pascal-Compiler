%code requires{
#include "tree.h"
#define YYSTYPE pTree
}

%{
#include <stdio.h>
extern FILE * yyin;
%}

%token DOT PROGRAM ID SEMI CONST EQUAL
%token INTEGER REAL CHAR STRING SYS_CON
%token TYPE ARRAY LB RB OF RECORD END
%token COLON COMMA SYS_TYPE LP RP DOTDOT
%token MINUS VAR FUNCTION PROCEDURE ASSIGN
%token SYS_PROC READ PBEGIN IF THEN ELSE
%token REPEAT UNTIL WHILE DO FOR TO DOWNTO
%token CASE GOTO GE GT LE LT UNEQUAL PLUS
%token OR MUL DIV MOD AND SYS_FUNCT NOT

%%
program : program_head routine DOT {
			$$ = newTreeNode(tPROGRAM);
			$$->child[1] = $1;
			$$->child[2] = $2;
		}
		;

program_head : PROGRAM ID SEMI {
				$$ = $2;
				$$->type = tPROGRAM_HEAD;
			 }
			 ;

routine : routine_head routine_body {
			$$ = newTreeNode(tROUTINE);
			$$->child[1] = $1;
			$$->child[2] = $2;
		}
		;

sub_routine : routine_head routine_body {
				$$ = newTreeNode(tSUB_ROUTINE);
				$$->child[1] = $1;
				$$->child[2] = $2;
			}
			;

routine_head : label_part const_part type_part var_part routine_part {
			 	$$ = newTreeNode(tROUTINE_HEAD);
				$$->child[0] = $1;
				$$->child[1] = $2;
				$$->child[2] = $3;
				$$->child[3] = $4;
				$$->child[4] = $5;
			 }
			 ;

label_part : { $$ = NULL; }
		   ;

const_part : CONST const_expr_list {
		       $$ = $2;
		   }
		   | { $$ = NULL; }
		   ;

const_expr_list : const_expr_list ID EQUAL const_value SEMI {
					pTree temp = newTreeNode(DECL_CONST);
					temp->child[1] = $2;
					temp->child[2] = $4;
					
					pTree p = $1;
					while(p->child[0])
						p = p->child[0];
					p->child[0] = temp;

					$$ = $1;
				}
				| ID EQUAL const_value SEMI {
					$$ = newTreeNode(DECL_CONST);
					$$->child[1] = $1;
					$$->child[2] = $3;
				}
				;

const_value : INTEGER { $$ = $1; }
			| REAL { $$ = $1; }
			| CHAR { $$ = $1; }
			| STRING { $$ = $1; }
			| SYS_CON { $$ = $1; }
			;

type_part : TYPE type_decl_list {
		      $$ = $2;
		  }
		  | { $$ = NULL; }
		  ;

type_decl_list : type_decl_list type_definition {
			       pTree p = $1;
				   while(p->child[0])
				       p = p->child[0];
				   p->child[0] = $2;
				   $$ = $1;
			   }
			   | type_definition {
			       $$ = $1;
			   }
			   ;

type_definition : ID EQUAL type_decl SEMI {
					$$ = newTreeNode(DECL_TYPE);
					$$->child[1] = $1;
					$$->child[2] = $3;
				}
				;

type_decl : simple_type_decl { $$ = $1; }
		  | array_type_decl { $$ = $1; }
		  | record_type_decl { $$ = $1; }
		  ;

array_type_decl : ARRAY LB simple_type_decl RB OF type_decl
				;

record_type_decl : RECORD field_decl_list END
				 ;

field_decl_list : field_decl_list field_decl
				| field_decl
				;

field_decl : name_list COLON type_decl SEMI
		   ;

name_list : name_list COMMA ID
		  | ID
		  ;

simple_type_decl : SYS_TYPE
				 | ID
				 | LP name_list RP
				 | const_value DOTDOT const_value
				 | MINUS const_value DOTDOT const_value
				 | MINUS const_value DOTDOT MINUS const_value
				 | ID DOTDOT ID
				 ;

var_part : VAR var_decl_list
		 |
		 ;

var_decl_list : var_decl_list var_decl
			  | var_decl
			  ;

var_decl : name_list COLON type_decl SEMI
		 ;

routine_part : routine_part function_decl {
                pTree p = $1;
                if(p) {
                    while(p->child[0])
                        p = p->child[0];
                    p->child[0] = $2;
                    $$ = $1;
                }
                else
                    $$ = $2;
			 }
			 | routine_part procedure_decl {
                pTree p = $1;
                if(p) {
                    while(p->child[0])
                        p = p->child[0];
                    p->child[0] = $2;
                    $$ = $1;
                }
                else
                    $$ = $2;
             }
			 | function_decl {
                $$ = $1;
             }
			 | procedure_decl {
                $$ = $1;
             }
			 | { $$ = NULL; }
			 ;

function_decl : function_head SEMI sub_routine SEMI {
                  $$ = newTreeNode(FUNCTION_DECL);
                  $$->child[1] = $1;
                  $$->child[2] = $3;
              }
			  ;

function_head : FUNCTION ID parameters COLON simple_type_decl {
                  $$ = newTreeNode(FUNCTION_HEAD);
                  $$->child[1] = $2;
                  $$->child[2] = $3;
                  $$->child[3] = $5;
              }
			  ;

procedure_decl : procedure_head SEMI sub_routine SEMI {
                   $$ = newTreeNode(PROCEDURE_DECL);
                   $$->child[1] = $1;
                   $$->child[2] = $3;
               }
			   ;

procedure_head : PROCEDURE ID parameters {
                   $$ = newTreeNode(PROCEDURE_HEAD);
                   $$->child[1] = $2;
                   $$->child[2] = $3;
               }
			   ;

parameters : LP para_decl_list RP {
               $$ = $2;
           }
		   | { $$ = NULL; }
		   ;

para_decl_list : para_decl_list SEMI para_type_list {
                   pTree p = $1;
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = $3;
                   $$ = $1;
               }
			   | para_type_list {
                   $$ = $1;
               }
			   ;

para_type_list : var_para_list COLON simple_type_decl {
                   $$ = newTreeNode(VAR_PARA);
                   $$->child[1] = $1;
                   $$->child[2] = $3;
               }
			   | val_para_list COLON simple_type_decl {
                   $$ = newTreeNode(VAL_PARA);
                   $$->child[1] = $1;
                   $$->child[2] = $3;
               }
			   ;

var_para_list : VAR name_list { $$ = $2; }
			  ;

val_para_list : name_list { $$ = $1; }
			  ;

routine_body : compound_stmt { $$ = $1; }
			 ;

stmt_list : stmt_list stmt SEMI {
              pTree p = $1;
              if(p) {
                  while(p->child[0])
                      p = p->child[0];
                  p->child[0] = $2;
                  $$ = $1;
              }
              else
                  $$ = $2;
          }
		  | { $$ = NULL; }
		  ;

stmt : INTEGER COLON non_label_stmt
	 | non_label_stmt
	 ;

non_label_stmt : assign_stmt
			   | proc_stmt
			   | compound_stmt
			   | if_stmt
			   | repeat_stmt
			   | while_stmt
			   | for_stmt
			   | case_stmt
			   | goto_stmt
			   ;

assign_stmt : ID ASSIGN expression
			| ID LB expression RB ASSIGN expression
			| ID DOT ID ASSIGN expression
			;

proc_stmt : ID
          | ID LP args_list RP
          | SYS_PROC
          | SYS_PROC LP expression_list RP
          | READ LP factor RP
		  ;

compound_stmt : PBEGIN stmt_list END { $$ = $2; }
			  ;

if_stmt : IF expression THEN stmt else_clause
		;

else_clause : ELSE stmt
			|
			;

repeat_stmt : REPEAT stmt_list UNTIL expression

while_stmt : WHILE expression DO stmt
		   ;

for_stmt : FOR ID ASSIGN expression direction expression DO stmt
		 ;

direction : TO
		  | DOWNTO
		  ;

case_stmt : CASE expression OF case_expr_list END
		  ;

case_expr_list : case_expr_list case_expr
			   | case_expr
			   ;

case_expr : const_value COLON stmt SEMI
          | ID COLON stmt SEMI
		  ;

goto_stmt : GOTO INTEGER
		  ;

expression_list : expression_list COMMA expression
				| expression
				;

expression : expression GE expr
		   | expression GT expr
		   | expression LE expr
		   | expression LT expr
		   | expression EQUAL expr
		   | expression UNEQUAL expr
		   | expr
		   ;

expr : expr PLUS term
	 | expr MINUS term
	 | expr OR term
	 | term
	 ;

term : term MUL factor
	 | term DIV factor
	 | term MOD factor
	 | term AND factor
	 | factor
	 ;

factor : ID
	   | ID LP args_list RP
	   | SYS_FUNCT
	   | SYS_FUNCT LP args_list RP
	   | const_value
	   | LP expression RP
	   | NOT factor
	   | MINUS factor
	   | ID LB expression RB
	   | ID DOT ID
	   ;

args_list : args_list COMMA expression
		  | expression
		  ;

%%

int main() {
	char FILENAME[100];
    printf("Please input the test file: ");
    scanf("%s", FILENAME);
    FILE* file = fopen(FILENAME, "r");
    yyin = file;

	return yyparse();
}

int yyerror(char* s) {
	fprintf(stderr, "%s\n", s);
}
