//
// Created by BPanther on 2019/10/13.
//

#ifndef BASETEST_HUFFMAN_TREE_H
#define BASETEST_HUFFMAN_TREE_H

#include <stddef.h>

void create_hmt(int *weight, size_t len, int *parent, int *l_child, int *r_child);

void _merge_hmt(int *weight, size_t len, int *parent, int *l_child, int *r_child);

void clear_hmt(int **parent, int **l_child, int **r_child);


#endif //BASETEST_HUFFMAN_TREE_H
