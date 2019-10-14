//
// Created by BPanther on 2019/10/13.
//

#include <huffman_tree.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

void create_hfmt(int *weight, size_t len, int **parent, int **l_child, int **r_child) {
    // @n : haffuman树结点数目
    int n = 2 * (int) len - 1;
    *parent = (int *) malloc(n * sizeof(int));
    *l_child = (int *) malloc(n * sizeof(int));
    *r_child = (int *) malloc(n * sizeof(int));
    memset(*parent, 0, n * sizeof(int));
    memset(*l_child, 0, n * sizeof(int));
    memset(*r_child, 0, n * sizeof(int));
    int *index_sort = (int *) malloc(len * sizeof(int));

    int i;
    for (i = 0; i < (int) len; ++i) {
        index_sort[i] = i;
    }

    const int LEFT_CHILD = 0;
    const int RIGHT_CHILD = 1;
    for (i = len; i < n; ++i) {
        qsort_by_arr(index_sort, len, weight, _compareWeight);
        (*parent)[index_sort[LEFT_CHILD]] = i;
        (*parent)[index_sort[RIGHT_CHILD]] = i;
        weight[i] = weight[index_sort[LEFT_CHILD]] + weight[index_sort[RIGHT_CHILD]];
        (*l_child)[i] = index_sort[LEFT_CHILD];
        (*r_child)[i] = index_sort[RIGHT_CHILD];
        ++index_sort;
        *index_sort = i;
        --len;
    }
    (*parent)[n - 1] = -1;
}

int _compareWeight(const void *_arr, int i1, int i2) {
    if (((const int *) _arr)[i1] < ((const int *) _arr)[i2])
        return -1;
    else if (((const int *) _arr)[i1] == ((const int *) _arr)[i2])
        return 0;
    else
        return 1;
}

void clear_hfmt(int **parent, int **l_child, int **r_child) {
    free(*parent);
    free(*l_child);
    free(*r_child);
    *parent = NULL;
    *l_child = NULL;
    *r_child = NULL;
}

void create_hfm_code(char **code, int **start, size_t len, const int *parent, const int *l_child, const int *r_child) {
    *code = (char *) malloc(len * len * sizeof(char));
    *start = (int *) malloc(len * sizeof(int));

    int index;
    for (index = 0; index < (int) len; ++index) {
        int pre = parent[index];
        int cur = index;
        (*start)[index] = (int) len - 1;
        while (pre != -1) {
            if (l_child[pre] == cur) {
                (*code)[index * len + (*start)[index]] = 0;
            }
            if (r_child[pre] == cur) {
                (*code)[index * len + (*start)[index]] = 1;
            }
            cur = pre;
            pre = parent[pre];
            --(*start)[index];
        }
        ++(*start)[index];
    }
}

void clear_hfm_code(char **code, int **start) {
    free(*code);
    free(*start);
    *code = NULL;
    *start = NULL;
}