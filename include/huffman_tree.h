//
// Created by BPanther on 2019/10/13.
//

#ifndef BASETEST_HUFFMAN_TREE_H
#define BASETEST_HUFFMAN_TREE_H

#include <stddef.h>

void create_hfmt(int *weight, size_t len, int **parent, int **l_child, int **r_child);

int _compareWeight(const void *_arr, int i1, int i2);

void clear_hfmt(int **parent, int **l_child, int **r_child);

void create_hfm_code(char **code, int **start, size_t len, const int *parent, const int *l_child, const int *r_child);

void clear_hfm_code(char **code, int **start);


#endif //BASETEST_HUFFMAN_TREE_H
