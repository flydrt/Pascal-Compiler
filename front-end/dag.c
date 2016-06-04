//
//  main.c
//  DAG
//
//  Created by bay on 16/6/2.
//  Copyright © 2016年 libaiyu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "tree.h"
#include <stdlib.h>

struct dag *new_node(Type type,int num,pTree child0,pTree child1,pTree child2,pTree child3,pTree child4,pTree parent);
pTree traverse(pTree syntax);
int get_num(Type type);

/* hash function. */
int node_hash(int num){
    return num & 15;
}

static struct dag
{
    pTree node;
    struct dag *hlink;
    
}
*hash[16];


pTree find_node(Type type,int num,pTree child0,pTree child1,pTree child2,pTree child3,pTree child4,pTree parent)
{
    int i,flag;
    struct dag *p;
    
    i = node_hash(num);

    for (p = hash[i]; p; p = p->hlink)
        if (p->node->type == type && p->node->child[0] == child0
            &&  p->node->child[1] == child1  && p->node->child[2] == child2  && p->node->child[3] == child3  && p->node->child[4] == child4)
        {
            flag = 0;
            if(type == tINTEGER || type == tREAL ||type == tCHAR ||type == tSTRING ||type == tID ){
                
                switch (type) {
                    case tINTEGER:
                        if(p->node->data.intVal == parent->data.intVal)
                            flag =1;
                        break;
                    case tREAL:
                        if(p->node->data.realVal == parent->data.realVal)
                            flag =1;
                        break;
                    case tCHAR:
                        if(p->node->data.charVal == parent->data.charVal)
                            flag =1;
                        break;
                    case tSTRING:
                    case tID:
                        if(strcmp(p->node->data.stringVal,parent->data.stringVal)==1)
                            flag =1;
                        break;
            
                    default:
                        break;
                }
                if(flag == 1){
                    printf("found num: %d \n",num);
                    return p->node;
                }
                
            }
            else
            {
                printf("found num: %d \n",num);
                return p->node;
            }
            
        }
    p = new_node(type,num,child0,child1,child2,child3,child4,parent);
    p->hlink = hash[i];
    hash[i] = p;
    
    return p->node;
}

struct dag *new_node(Type type,int num,pTree child0,pTree child1,pTree child2,pTree child3,pTree child4,pTree parent){
    
    struct dag *new_dag;
    new_dag = (struct dag*)malloc(sizeof(struct dag));
    
    pTree tmp;
    tmp = newTreeNode(type);
    tmp->child[0] = child0;
    tmp->child[1] = child1;
    tmp->child[2] = child2;
    tmp->child[3] = child3;
    tmp->child[4] = child4;
    if(type == tINTEGER || type == tREAL ||type == tCHAR ||type == tSTRING ||type == tID ){
        
        switch (type) {
            case tINTEGER:
                tmp->data.intVal = parent->data.intVal;
                break;
            case tREAL:
                tmp->data.realVal = parent->data.realVal;
                   
                break;
            case tCHAR:
                tmp->data.charVal = parent->data.charVal;
                break;
            case tSTRING:
            case tID:
                tmp->data.stringVal = copyString(parent->data.stringVal);
                break;
            default:
                break;
        }
    }
    new_dag->hlink = NULL;
    new_dag->node = tmp;
    return new_dag;
    
}


pTree traverse(pTree syntax)
{
    pTree p = NULL, kid0,kid1,kid2,kid3,kid4;
    Type type;
    int num=0;
    if (syntax == NULL)
        return NULL;
    
    kid0 = kid1 = kid2 = kid3 = kid4 = NULL;
    
    type = syntax->type;
    num = get_num(syntax->type);
    kid0 = traverse(syntax->child[0]);
    kid1 = traverse(syntax->child[1]);
    kid2 = traverse(syntax->child[2]);
    kid3 = traverse(syntax->child[3]);
    kid4 = traverse(syntax->child[4]);
   
    p = find_node(type, num, kid0, kid1, kid2, kid3, kid4, syntax);
    
    return p;
    
}
int get_num(Type type){
    int numl=0;
    switch (type) {
        case	tPROGRAM: numl = 1;break;
        case	tROUTINE : numl = 2;break;
        case	tSUB_ROUTINE: numl = 3;break;
        case	tROUTINE_HEAD: numl = 4;break;
        case	CONST_DECL: numl = 5;break;
        case	TYPE_DECL: numl = 6;break;
        case	ARRAY_DECL: numl = 7;break;
        case	FIELD_DECL: numl = 8;break;
        case	VAR_DECL: numl = 9;break;
        case	FUNCTION_DECL: numl = 10;break;
        case	FUNCTION_HEAD : numl = 11;break;
        case	PROCEDURE_DECL: numl = 12;break;
        case	PROCEDURE_HEAD: numl = 13;break;
        case	VAR_PARA: numl = 14;break;
        case	VAL_PARA: numl = 15;break;
        case	LABEL_STMT : numl = 16;break;
        case	ASSIGN_STMT_1: numl = 17;break;
        case	ASSIGN_STMT_2: numl = 18;break;
        case	ASSIGN_STMT_3: numl = 19;break;
        case	IF_STMT: numl = 20;break;
        case	REPEAT_STMT : numl = 21;break;
        case	WHILE_STMT : numl = 22;break;
        case	FOR_STMT_TO : numl = 23;break;
        case	FOR_STMT_DOWNTO: numl = 24;break;
        case	CASE_STMT: numl = 25;break;
        case	CASE_EXPR_CONST: numl = 26;break;
        case	CASE_EXPR_ID: numl = 27;break;
        case	GOTO_STMT: numl = 28;break;
        case	eGE: numl = 29;break;
        case	eGT: numl = 30;break;
        case	eLE: numl = 31;break;
        case	eLT : numl = 32;break;
        case	eEQUAL: numl = 33;break;
        case	eUNEQUAL: numl = 34;break;
        case	ePLUS: numl = 35;break;
        case	eMINUS: numl = 36;break;
        case	eOR: numl = 37;break;
        case    eMUL: numl = 38;break;
        case	eDIV: numl = 39;break;
        case	eMOD: numl = 40;break;
        case	eAND: numl = 41;break;
        case	FACTOR_FUNC: numl = 42;break;
        case	tSYS_TYPE : numl = 43;break;
        case	tSIMPLE_ID: numl = 44;break;
        case	tSIMPLE_ENUM : numl = 45;break;
        case	tSIMPLE_SUBRANGE: numl = 46;break;
        case	tSIMPLE_SUBRANGE_1: numl = 47;break;
        case	tSIMPLE_SUBRANGE_2: numl = 48;break;
        case	tINTEGER: numl = 49;break;
        case	tREAL: numl = 50;break;
        case	tCHAR : numl = 51;break;
        case	tSTRING: numl = 52;break;
        case	tID: numl = 53;break;
        default:
            break;
    }
    return numl;
    
}
int main(int argc, const char * argv[]) {
    
    printf("\n");
    return 0;
}
