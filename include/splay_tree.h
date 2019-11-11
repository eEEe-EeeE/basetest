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
    int height;
} STNode, *STree, *STNodePtr;

void create_st(int *keys, size_t len);

STree insert_st_recur(STree T, int key);

STree delete_st_recur(STree T, int key);

STNodePtr search_st_recur(STree T, int key);

STree zig_zag_st(STree T);

STree zig_zig_st(STree T);

#endif //BASETEST_SPLAY_TREE_H
