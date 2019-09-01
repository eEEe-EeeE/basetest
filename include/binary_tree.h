//
// Created by BPanther on 2019/8/3.
//

#ifndef BASETEST_BINARY_TREE_H
#define BASETEST_BINARY_TREE_H

#define DATATYPE char

typedef struct _bt_node {
    DATATYPE data;
    struct _bt_node *l_child;
    struct _bt_node *r_child;
} BTNode, *BTREE;

BTREE create_bt(char *sentence, int sentence_len);

void level_print_bt(BTREE T);

int count_bt_leaf_recur(BTREE T);

int count_bt_leaf(BTREE T);

// 前序遍历
void pre_order_recur(BTREE T, void visit(int argc, ...));

void pre_order(BTREE T, void visit(int, ...));

void pre_order2(BTREE T, void visit(int, ...));

void pre_order3(BTREE T, void visit(int, ...));

// 中序遍历
void in_order_recur(BTREE T, void visit(int argc, ...));

void in_order(BTREE T, void visit(int, ...));

void in_order2(BTREE T, void visit(int, ...));

void in_order3(BTREE T, void visit(int, ...));

// 后序遍历
void post_order_recur(BTREE T, void visit(int argc, ...));

void post_order(BTREE T, void visit(int, ...));

int count_bt_depth_recur(BTREE T);

void print_bt_node(int argc, BTREE T);

void post_order2(BTREE T, void visit(int, ...));

//void PostOrder(BTREE bt);

#endif //BASETEST_BINARY_TREE_H
