//
// Created by BPanther on 2019/11/6.
//

#ifndef BASETEST_SPLAY_TREE_H
#define BASETEST_SPLAY_TREE_H

#include <stddef.h>

typedef struct _st_node {
    int key;
    struct _st_node *left;
    struct _st_node *right;
} STNode, *STree, *STNodePtr;

void create_st(int *keys, size_t len);

STree insert_st_recur(STree T, int key);

STree delete_st_recur(STree T, int key);

STNodePtr search_st_recur(STree T, int key);

STree zig_st(STree T);

STree zag_st(STree T);

STNodePtr _min_value_st(STree T);

STree _splay(STree T, int key);

#endif //BASETEST_SPLAY_TREE_H
