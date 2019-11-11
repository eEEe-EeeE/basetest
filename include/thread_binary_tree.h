//
// Created by BPanther on 2019/9/10.
//

#ifndef BASETEST_THREAD_BINARY_TREE_H
#define BASETEST_THREAD_BINARY_TREE_H

#include <mydef.h>

typedef struct _thr_bt_node {
    STRING data;
    struct _thr_bt_node *l_child;
    struct _thr_bt_node *r_child;
    int l_bit;
    int r_bit;
} TBTNode, *TBTree;


TBTree create_tbt(STRING*words);

TBTree create_tbt_node(STRING string);

void in_thread(TBTree *HEAD);

TBTree in_prior(TBTree p);

TBTree in_succ(TBTree p);

void thr_in_order(TBTree HEAD);


#endif //BASETEST_THREAD_BINARY_TREE_H
