//
// Created by BPanther on 2019/6/18.
//

#ifndef BASETEST_TREE_H
#define BASETEST_TREE_H

#include <stdbool.h>

#define MaxTreeD 100

// 无限子节点的表示
typedef struct _bt_node {
    int data;
    struct _bt_node *child, *parent, *brother;
} TTREE;

// 有限子节点的表示

// 定长
typedef struct node1 {
    int data;
    struct node1 *child[MaxTreeD];
} DTREE;

// 不定长
typedef struct node2 {
    int data;
    int degree; // 节点的度
    struct node2 *child[MaxTreeD];
} NTREE;


/* 建立一棵空树 */
void setnull(TTREE *T);

/* 求节点x所在树的根节点 */
TTREE *root(TTREE *x);

/* 求树中节点x的父节点 */
TTREE *parent(TTREE *T, TTREE *x);

/* 求树中节点x的子节点 */
TTREE *child(TTREE *T, TTREE *x);

/* 求树中节点x的右边的兄弟节点 */
TTREE *rightsibling(TTREE *T, TTREE *x);

/* 把以S为根节点的树插入到树T中作为x节点的第i棵子树 */
bool insert(TTREE *T, TTREE *x, int i, TTREE *S);

/* 删除树中节点x的第i棵子树 */
bool delete(TTREE *T, TTREE *x, int i);

/*  遍历一棵树，得到一个由所有节点组成的序列，每个节点只被访问一次 */
TTREE *traverse(TTREE *T);


#endif //BASETEST_TREE_H
