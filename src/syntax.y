%{
#include <stdio.h>
#include "tree.h"
extern FILE * yyin;
static pTree root;
extern int yylineno;
extern int errorno;
%}

%code requires{
#include "tree.h"
#define YYSTYPE pTree
}

%locations

%token DOT PROGRAM ID SEMI CONST EQUAL
%token INTEGER REAL CHAR STRING SYS_CON
%token TYPE ARRAY LB RB OF RECORD END
%token COLON COMMA SYS_TYPE LP RP DOTDOT
%token MINUS VAR FUNCTION PROCEDURE ASSIGN
%token SYS_PROC READ PBEGIN IF THEN ELSE
%token REPEAT UNTIL WHILE DO FOR TO DOWNTO
%token CASE GOTO GE GT LE LT UNEQUAL PLUS
%token OR MUL DIV RDIV MOD AND SYS_FUNCT NOT

%%
program : program_head routine DOT {
			$$ = newTreeNode(tPROGRAM);
			$$->child[1] = $1;
			$$->child[2] = $2;
            root = $$;
		}
        | program_head routine error {
			$$ = newTreeNode(tPROGRAM);
			$$->child[1] = $1;
			$$->child[2] = $2;
            root = $$;
		}
		;

program_head : PROGRAM ID SEMI {
				$$ = $2;
			 }
             | PROGRAM ID error {
				$$ = $2;
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
					pTree temp = newTreeNode(CONST_DECL);
					temp->child[1] = $2;
					temp->child[2] = $4;
					
					pTree p = $1;
					while(p->child[0])
						p = p->child[0];
					p->child[0] = temp;

					$$ = $1;
				}
				| ID EQUAL const_value SEMI {
					$$ = newTreeNode(CONST_DECL);
					$$->child[1] = $1;
					$$->child[2] = $3;
				}
                | const_expr_list ID EQUAL const_value error {
					pTree temp = newTreeNode(CONST_DECL);
					temp->child[1] = $2;
					temp->child[2] = $4;
					
					pTree p = $1;
					while(p->child[0])
						p = p->child[0];
					p->child[0] = temp;

					$$ = $1;
				}
                | ID EQUAL const_value error {
					$$ = newTreeNode(CONST_DECL);
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
					$$ = newTreeNode(TYPE_DECL);
					$$->child[1] = $1;
					$$->child[2] = $3;
				}
                | ID EQUAL type_decl error {
					$$ = newTreeNode(TYPE_DECL);
					$$->child[1] = $1;
					$$->child[2] = $3;
				}
				;

type_decl : simple_type_decl { $$ = $1; }
		  | array_type_decl { $$ = $1; }
		  | record_type_decl { $$ = $1; }
		  ;

array_type_decl : ARRAY LB simple_type_decl RB OF type_decl {
                    $$ = newTreeNode(ARRAY_DECL);
                    $$->child[1] = $3;
                    $$->child[2] = $6;
                }
                | ARRAY LB simple_type_decl RB error type_decl {
                    $$ = newTreeNode(ARRAY_DECL);
                    $$->child[1] = $3;
                    $$->child[2] = $6;
                }
                | ARRAY LB simple_type_decl error OF type_decl {
                    $$ = newTreeNode(ARRAY_DECL);
                    $$->child[1] = $3;
                    $$->child[2] = $6;
                }
				;

record_type_decl : RECORD field_decl_list END {
                    $$ = $2;
                 }
                 | RECORD field_decl_list error {
                    $$ = $2;
                 }
				 ;

field_decl_list : field_decl_list field_decl {
                    $$ = createList($1, $2);
                }
				| field_decl { $$ = $1; }
				;

field_decl : name_list COLON type_decl SEMI {
               $$ = newTreeNode(FIELD_DECL);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
           | name_list COLON type_decl error {
               $$ = newTreeNode(FIELD_DECL);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
           | name_list error type_decl SEMI {
               $$ = newTreeNode(FIELD_DECL);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   ;

name_list : name_list COMMA ID {
              $$ = createList($1, $3);
          }
		  | ID { $$ = $1; }
		  ;

simple_type_decl : SYS_TYPE { $$ = $1; }
				 | ID {
                    $$ = $1;
                    $$->type = tSIMPLE_ID;
                 }
				 | LP name_list RP {
                    $$ = newTreeNode(tSIMPLE_ENUM);
                    $$->child[1] = $2;
                 }
				 | const_value DOTDOT const_value {
                    $$ = newTreeNode(tSIMPLE_SUBRANGE);
                    $$->child[1] = $1;
                    $$->child[2] = $3;
                 }
				 | MINUS const_value DOTDOT const_value {
                    $$ = newTreeNode(tSIMPLE_SUBRANGE);
                    $$->child[1] = $2;
                    ($$->child[1]->data).intVal *= -1;
                    $$->child[2] = $4;
                 }
				 | MINUS const_value DOTDOT MINUS const_value {
                    $$ =newTreeNode(tSIMPLE_SUBRANGE);
                    $$->child[1] = $2;
                    ($$->child[1]->data).intVal *= -1;
                    $$->child[2] = $5;
                    ($$->child[2]->data).intVal *= -1;
                 }
				 | ID DOTDOT ID {
                    $$ =newTreeNode(tSIMPLE_SUBRANGE_ID);
                    $$->child[1] = $1;
                    $$->child[2] = $3;
                 }
				 ;

var_part : VAR var_decl_list {
             $$ = $2;
         }
		 | { $$ = NULL; }
		 ;

var_decl_list : var_decl_list var_decl {
                  $$ = createList($1, $2);
              }
			  | var_decl { $$ = $1; }
			  ;

var_decl : name_list COLON type_decl SEMI {
            $$ = newTreeNode(VAR_DECL);
            $$->child[1] = $1;
            $$->child[2] = $3;
         }
         | name_list COLON type_decl error {
            $$ = newTreeNode(VAR_DECL);
            $$->child[1] = $1;
            $$->child[2] = $3;
         }
         | name_list error type_decl SEMI {
            $$ = newTreeNode(VAR_DECL);
            $$->child[1] = $1;
            $$->child[2] = $3;
         }
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
              | function_head error sub_routine SEMI {
                  $$ = newTreeNode(FUNCTION_DECL);
                  $$->child[1] = $1;
                  $$->child[2] = $3;
              }
              | function_head SEMI sub_routine error {
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
              | FUNCTION ID parameters error simple_type_decl {
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
               | procedure_head error sub_routine SEMI {
                   $$ = newTreeNode(PROCEDURE_DECL);
                   $$->child[1] = $1;
                   $$->child[2] = $3;
               }
               | procedure_head SEMI sub_routine error {
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
           | LP para_decl_list error {
               $$ = $2;
           }
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
               | para_decl_list error para_type_list {
                   pTree p = $1;
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = $3;
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
               | var_para_list error simple_type_decl {
                   $$ = newTreeNode(VAR_PARA);
                   $$->child[1] = $1;
                   $$->child[2] = $3;
               }
               | val_para_list error simple_type_decl {
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
          | stmt_list stmt error {
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
		  ;

stmt : INTEGER COLON non_label_stmt {
        $$ = newTreeNode(LABEL_STMT);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | non_label_stmt { $$ = $1; }
     | INTEGER error non_label_stmt {
        $$ = newTreeNode(LABEL_STMT);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 ;

non_label_stmt : assign_stmt { $$ = $1; }
			   | proc_stmt { $$ = $1; }
			   | compound_stmt { $$ = $1; }
			   | if_stmt { $$ = $1; }
			   | repeat_stmt { $$ = $1; }
			   | while_stmt { $$ = $1; }
			   | for_stmt { $$ = $1; }
			   | case_stmt { $$ = $1; }
			   | goto_stmt { $$ = $1; }
			   ;

assign_stmt : ID ASSIGN expression {
                $$ = newTreeNode(ASSIGN_STMT_1);
                $$->child[1] = $1;
                $$->child[2] = $3;
            }
			| ID LB expression RB ASSIGN expression {
                $$ = newTreeNode(ASSIGN_STMT_2);
                $$->child[1] = $1;
                $$->child[2] = $3;
                $$->child[3] = $6;
            }
			| ID DOT ID ASSIGN expression {
                $$ = newTreeNode(ASSIGN_STMT_3);
                $$->child[1] = $1;
                $$->child[2] = $3;
                $$->child[3] = $5;
            }
            | ID LB expression error ASSIGN expression {
                $$ = newTreeNode(ASSIGN_STMT_2);
                $$->child[1] = $1;
                $$->child[2] = $3;
                $$->child[3] = $6;
            }
            | ID LB expression RB error expression {
                $$ = newTreeNode(ASSIGN_STMT_2);
                $$->child[1] = $1;
                $$->child[2] = $3;
                $$->child[3] = $6;
            }
            | ID DOT ID error expression {
                $$ = newTreeNode(ASSIGN_STMT_3);
                $$->child[1] = $1;
                $$->child[2] = $3;
                $$->child[3] = $5;
            }
            | ID error expression {
                $$ = newTreeNode(ASSIGN_STMT_1);
                $$->child[1] = $1;
                $$->child[2] = $3;
            }
			;

proc_stmt : ID {
              $$ = $1;
              $$->type = PROC_STMT_ID;
          }
          | ID LP args_list RP {
              $$ = newTreeNode(PROC_STMT_ID_ARGS);
              $$->child[1] = $1;
              $$->child[2] = $3;
          }
          | SYS_PROC { $$ = $1; }
          | SYS_PROC LP expression_list RP {
              $$ = newTreeNode(PROC_STMT_SYS_EXPR);
              $$->child[1] = $1;
              $$->child[3] = $3;
          }
          | READ LP factor RP {
              $$ = newTreeNode(PROC_STMT_READ);
              $$->child[1] = $3;
          }
          | ID LP args_list error {
              $$ = newTreeNode(PROC_STMT_ID_ARGS);
              $$->child[1] = $1;
              $$->child[2] = $3;
          }
          | SYS_PROC LP expression_list error {
              $$ = newTreeNode(PROC_STMT_SYS_EXPR);
              $$->child[1] = $1;
              $$->child[3] = $3;
          }
          | READ LP factor error {
              $$ = newTreeNode(PROC_STMT_READ);
              $$->child[1] = $3;
          }
		  ;

compound_stmt : PBEGIN stmt_list END { $$ = $2; }
              | PBEGIN stmt_list error { $$ = $2; }
			  ;

if_stmt : IF expression THEN stmt else_clause {
            $$ = newTreeNode(IF_STMT);
            $$->child[1] = $2;
            $$->child[2] = $4;
            $$->child[3] = $5;
        }
		;

else_clause : ELSE stmt {
                $$ = $2;
            }
			| { $$ = NULL; }
			;

repeat_stmt : REPEAT stmt_list UNTIL expression {
                $$ = newTreeNode(REPEAT_STMT);
                $$->child[1] = $2;
                $$->child[2] = $4;
            }
            | REPEAT stmt_list error expression {
                $$ = newTreeNode(REPEAT_STMT);
                $$->child[1] = $2;
                $$->child[2] = $4;
            }
            ;

while_stmt : WHILE expression DO stmt {
               $$ = newTreeNode(WHILE_STMT);
               $$->child[1] = $2;
               $$->child[2] = $4;
           }
           | WHILE expression error stmt {
               $$ = newTreeNode(WHILE_STMT);
               $$->child[1] = $2;
               $$->child[2] = $4;
           }
		   ;

for_stmt : FOR ID ASSIGN expression TO expression DO stmt {
            $$ = newTreeNode(FOR_STMT_TO);
            $$->child[1] = $2;
            $$->child[2] = $4;
            $$->child[3] = $6;
            $$->child[4] = $8;
         }
         | FOR ID ASSIGN expression DOWNTO expression DO stmt {
            $$ = newTreeNode(FOR_STMT_DOWNTO);
            $$->child[1] = $2;
            $$->child[2] = $4;
            $$->child[3] = $6;
            $$->child[4] = $8;
         }
         | FOR ID error expression error expression DO stmt {
            $$ = newTreeNode(FOR_STMT_TO);
            $$->child[1] = $2;
            $$->child[2] = $4;
            $$->child[3] = $6;
            $$->child[4] = $8;
         }
		 ;

case_stmt : CASE expression OF case_expr_list END {
              $$ = newTreeNode(CASE_STMT);
              $$->child[1] = $2;
              $$->child[2] = $4;
          }
          | CASE expression OF case_expr_list error {
              $$ = newTreeNode(CASE_STMT);
              $$->child[1] = $2;
              $$->child[2] = $4;
          }
          | CASE expression error case_expr_list END {
              $$ = newTreeNode(CASE_STMT);
              $$->child[1] = $2;
              $$->child[2] = $4;
          }
		  ;

case_expr_list : case_expr_list case_expr {
                   pTree p = $1;
                   while(p->child[0])
                       p = p->child[0];
                   p->child[0] = $2;
                   $$ = $1;
               }
			   | case_expr {
                   $$ = $1;
               }
			   ;

case_expr : const_value COLON stmt SEMI {
              $$ = newTreeNode(CASE_EXPR_CONST);
              $$->child[1] = $1;
              $$->child[2] = $3;
          }
          | ID COLON stmt SEMI {
              $$ = newTreeNode(CASE_EXPR_ID);
              $$->child[1] = $1;
              $$->child[2] = $3;
          }
          | const_value COLON stmt error {
              $$ = newTreeNode(CASE_EXPR_CONST);
              $$->child[1] = $1;
              $$->child[2] = $3;
          }
          | ID COLON stmt error {
              $$ = newTreeNode(CASE_EXPR_ID);
              $$->child[1] = $1;
              $$->child[2] = $3;
          }
		  ;

goto_stmt : GOTO INTEGER {
              $$ = newTreeNode(GOTO_STMT);
              $$->child[1] = $2;
          }
          | GOTO error {
              $$ = newTreeNode(GOTO_STMT);
              $$->child[1] = NULL;
          }
		  ;

expression_list : expression_list COMMA expression {
                    $$ = createList($1, $3);
                }
				| expression { $$ = $1; }
                | expression_list error expression {
                    $$ = createList($1, $3);
                }
				;

expression : expression GE expr {
               $$ = newTreeNode(eGE);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   | expression GT expr {
               $$ = newTreeNode(eGT);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   | expression LE expr {
               $$ = newTreeNode(eLE);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   | expression LT expr {
               $$ = newTreeNode(eLT);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   | expression EQUAL expr {
               $$ = newTreeNode(eEQUAL);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   | expression UNEQUAL expr {
               $$ = newTreeNode(eUNEQUAL);
               $$->child[1] = $1;
               $$->child[2] = $3;
           }
		   | expr {
               $$ = $1;
           }
		   ;

expr : expr PLUS term {
        $$ = newTreeNode(ePLUS);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | expr MINUS term {
        $$ = newTreeNode(eMINUS);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | expr OR term {
        $$ = newTreeNode(eOR);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | term {
        $$ = $1;
     }
	 ;

term : term MUL factor {
        $$ = newTreeNode(eMUL);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
     | term RDIV factor {
        $$ = newTreeNode(eRDIV);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | term DIV factor {
        $$ = newTreeNode(eDIV);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | term MOD factor {
        $$ = newTreeNode(eMOD);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | term AND factor {
        $$ = newTreeNode(eAND);
        $$->child[1] = $1;
        $$->child[2] = $3;
     }
	 | factor {
        $$ = $1;
     }
	 ;

factor : ID {
           $$ = $1;
           $$->type = FACTOR_ID;
       }
	   | ID LP args_list RP {
           $$ = newTreeNode(FACTOR_FUNC);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
	   | SYS_FUNCT { $$ = $1; }
	   | SYS_FUNCT LP args_list RP {
           $$ = newTreeNode(FACTOR_SYS_FUNC_ARGS);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
	   | const_value {
           $$ = newTreeNode(FACTOR_CONST);
           $$->child[1] = $1;
       }
	   | LP expression RP { $$ = $2; }
	   | NOT factor {
           $$ = newTreeNode(FACTOR_NOT);
           $$->child[1] = $2;
       }
	   | MINUS factor {
           $$ = newTreeNode(FACTOR_MINUS);
           $$->child[1] = $2;
       }
	   | ID LB expression RB {
           $$ = newTreeNode(FACTOR_ARRAY);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
	   | ID DOT ID {
           $$ = newTreeNode(FACTOR_RECORD);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
       | ID LP args_list error {
           $$ = newTreeNode(FACTOR_FUNC);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
       | SYS_FUNCT LP args_list error {
           $$ = newTreeNode(FACTOR_SYS_FUNC_ARGS);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
       | LP expression error { $$ = $2; }
       | ID LB expression error {
           $$ = newTreeNode(FACTOR_ARRAY);
           $$->child[1] = $1;
           $$->child[2] = $3;
       }
	   ;

args_list : args_list COMMA expression {
              $$ = createList($1, $3);
          }
		  | expression { $$ = $1; }
		  ;

%%

pTree parse(FILE * file) {
    yyin = file;
    
    yyparse();

    return root;
}

int yyerror(char* s) {
    errorno++;
	fprintf(stderr, "%s near line %d\n", s, yylineno);
}
