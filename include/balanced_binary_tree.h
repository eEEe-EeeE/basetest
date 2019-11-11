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
    int height;
} BBTNode, *BBTree;

BBTree _create_bbt_node(STRING string);

BBTree create_bbt(STRING *keys);

void destroy_bbt(BBTree T);

void clear_bbt(BBTree *T);

void insert_bbt_recur(BBTree *T, STRING item);

int count_bbt_height(BBTree T);

void single_rotate_with_left(BBTree *T);

void single_rotate_with_right(BBTree *T);

void double_rotate_with_left(BBTree *T);

void double_rotate_with_right(BBTree *T);

#endif //BASETEST_BALANCED_BINARY_TREE_H
