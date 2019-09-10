//
// Created by BPanther on 2019/9/10.
//

#ifndef BASETEST_THREAD_BINARY_TREE_H
#define BASETEST_THREAD_BINARY_TREE_H

#include <mydef.h>
typedef struct _thr_bt_node {
    DATATYPE data;
    struct _thr_bt_node *l_child;
    struct _thr_bt_node *r_child;
    int l_bit;
    int r_bit;
} TBTNode, *TBTREE;


TBTREE create_tbt(char *sentence, int sentence_len);

void in_thread(TBTREE *HEAD);

TBTREE in_prior(TBTREE p);

TBTREE in_succ(TBTREE p);

void thr_in_order(TBTREE HEAD);


#endif //BASETEST_THREAD_BINARY_TREE_H
