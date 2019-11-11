//
// Created by BPanther on 2019/8/3.
//

#ifndef BASETEST_BINARY_TREE_H
#define BASETEST_BINARY_TREE_H

#include <mydef.h>

typedef struct _bt_node {
    STRING data;
    struct _bt_node *l_child;
    struct _bt_node *r_child;
} BTNode, *BTree;

// 建立二叉树
BTree create_bt(STRING*words);

// 建立结点
BTree _create_bt_node(STRING string);

// 前序遍历建立二叉树
void build_bt(BTree *T);

// 后序遍历销毁二叉树
void destroy_bt(BTree T);
void clear_bt(BTree *T);

// 销毁结点
void destroy_bt_node(BTree T);
void clear_bt_node(BTree *T);

// 删除以item为根节点的子树
BTree delete_bt(BTree *T, STRING item);

// 层序遍历打印结点
void level_print_bt(BTree T);

// 计算叶子结点数目
int count_bt_leaf_recur(BTree T);

int count_bt_leaf(BTree T);

// 计算结点的层级
int calc_bt_node_layer(BTree T, STRING item);

// 交换左右子树
void exchange_bt(BTree T);

void exchange_bt_pre(BTree T);

void exchange_bt_in(BTree T);

void exchange_bt_post(BTree T);

// 前序遍历
void pre_order_recur(BTree T, void visit(int argc, ...));

void pre_order(BTree T, void visit(int, ...));

void pre_order2(BTree T, void visit(int, ...));

// 中序遍历
void in_order_recur(BTree T, void visit(int argc, ...));

void in_order(BTree T, void visit(int, ...));

void in_order2(BTree T, void visit(int, ...));

void in_order3(BTree T, void visit(int, ...));

// 后序遍历
void post_order_recur(BTree T, void visit(int argc, ...));

void post_order(BTree T, void visit(int, ...));

void post_order2(BTree T, void visit(int, ...));

// 前中序列恢复二叉树
BTree recover_bt_by_pre_in_recur(STRING*pre_seq, STRING*in_seq, size_t seq_len);

BTree recover_bt_by_pre_in(STRING*pre_seq, STRING*in_seq, size_t seq_len);

// 二叉树深度
int count_bt_depth_recur(BTree T);

int count_bt_depth_pre(BTree T);

int count_bt_depth_in(BTree T);

int count_bt_depth_post(BTree T);

// 等价
int btrees_are_equal_recur(BTree T1, BTree T2);

// 相似
int btrees_are_similar_recur(BTree T1, BTree T2);

// 是叶节点
int bt_node_is_leaf(BTree node);

// visit函数
void print_bt_node(int argc, BTree T);

// 复制二叉树
BTree copy_bt(BTree T);

void copy_bt2(BTree T, BTree *T2);


#endif //BASETEST_BINARY_TREE_H
