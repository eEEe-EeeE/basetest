//
// Created by BPanther on 2019/11/7.
//

#ifndef BASETEST_BINARY_SEARCH_TREE_H
#define BASETEST_BINARY_SEARCH_TREE_H


#include <stddef.h>

typedef struct _bst_node {
    int key;
    struct _bst_node *left;
    struct _bst_node *right;
} BSTNode, *BSTree, *BSTNodePtr;

// 建立二叉查找树
BSTree create_bst(int *keys, size_t len);

// 建立结点
BSTNodePtr _create_bst_node(int key);

// 插入结点
BSTree insert_bst_recur(BSTree T, int key);

BSTree insert_bst(BSTree T, int key);

// 删除结点
BSTree delete_bst_recur(BSTree T, int key);

BSTree delete_bst(BSTree T, int key);

// 搜索结点
BSTNodePtr search_bst(BSTree T, int key);



#endif //BASETEST_BINARY_SEARCH_TREE_H
