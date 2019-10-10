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

BBTREE create_bbt_node(STRING string);

BBTREE create_bbt(STRING *keys);

void destroy_bbt(BBTREE T);

void clear_bbt(BBTREE *T);

void insert_bbt_recur(BBTREE *T, STRING item);

void insert_bbt(BBTREE *T, STRING item);

#endif //BASETEST_BALANCED_BINARY_TREE_H
