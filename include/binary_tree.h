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

BTREE create_bt_node();

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

void post_order2(BTREE T, void visit(int, ...));

// 前中序列恢复二叉树
BTREE recover_bt_by_pre_in_recur(const char *pre_seq, const char *in_seq, size_t seq_len);

BTREE recover_bt_by_pre_in(const char *pre_seq, const char *in_seq, size_t seq_len);

int count_bt_depth_recur(BTREE T);

void print_bt_node(int argc, BTREE T);


#endif //BASETEST_BINARY_TREE_H
