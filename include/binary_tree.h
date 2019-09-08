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


void build_bt(BTREE *T);

void destroy_bt(BTREE T);

void clear_bt(BTREE *T);

BTREE delete_bt(BTREE *T, char item);

BTREE create_bt(char *sentence, int sentence_len);

BTREE create_bt_node();

void level_print_bt(BTREE T);

int count_bt_leaf_recur(BTREE T);

int count_bt_leaf(BTREE T);

int calc_bt_node_layer(BTREE T, char item);

// 交换左右子树
void exchange_bt(BTREE T);

void exchange_bt_pre(BTREE T);

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

// 二叉树深度
int count_bt_depth_recur(BTREE T);

int count_bt_depth_pre(BTREE T);

int count_bt_depth_in(BTREE T);

int count_bt_depth_post(BTREE T);

// 等价
int btrees_are_equal_recur(BTREE T1, BTREE T2);

// 相似
int btrees_are_similar_recur(BTREE T1, BTREE T2);

// 是叶节点
int bt_node_is_leaf(BTREE node);

// visit函数
void print_bt_node(int argc, BTREE T);

BTREE copy_bt(BTREE T);

void copy_bt2(BTREE T, BTREE *T2);


#endif //BASETEST_BINARY_TREE_H
