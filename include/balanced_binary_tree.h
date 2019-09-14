//
// Created by BPanther on 2019/9/14.
//

#ifndef BASETEST_BALANCED_BINARY_TREE_H
#define BASETEST_BALANCED_BINARY_TREE_H

#include <mydef.h>

typedef struct _bbt_node {
    STRING data;
    struct _bbt_node *l_child;
    struct _bbt_node *r_child;
    int balance;
} BBTNode, *BBTREE;

BBTREE create_bbt(STRING*words);

BBTREE create_bbt_node(STRING string);

void destroy_bbt_node(BBTREE pNode);

void destroy_bbt(BBTREE T);

void clear_bbt(BBTREE *T);

#endif //BASETEST_BALANCED_BINARY_TREE_H
