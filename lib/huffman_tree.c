//
// Created by BPanther on 2019/10/13.
//

#include <huffman_tree.h>
#include <stdlib.h>
#include <string.h>

void create_hmt(int *weight, size_t len, int *parent, int *l_child, int *r_child) {
    int n = 2 * (int) len - 1;
    parent = (int *) malloc(n * sizeof(int));
    l_child = (int *) malloc(n * sizeof(int));
    r_child = (int *) malloc(n * sizeof(int));
    memset(parent, 0, n * sizeof(int));
    memset(l_child, 0, n * sizeof(int));
    memset(r_child, 0, n * sizeof(int));

}

void _merge_hmt(int *weight, size_t len, int *parent, int *l_child, int *r_child) {

}

void clear_hmt(int **parent, int **l_child, int **r_child) {

}