//
//  dag.h
//  DAG
//
//  Created by 李佰余 on 16/6/2.
//  Copyright © 2016年 libaiyu. All rights reserved.
//

#ifndef dag_h
#define dag_h
struct dag *new_node(Type type,int num,pTree child0,pTree child1,pTree child2,pTree child3,pTree child4,pTree parent);
pTree traverse(pTree syntax);
int get_num(Type type);
void print_dag(pTree dag);
void add_queue(pTree node);
int node_hash(int num);
void initial_print_dag(pTree mydag);
pTree get_head();
void print_dag(pTree mydag);


#endif /* dag_h */
