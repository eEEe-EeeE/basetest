//
// Created by BPanther on 2019/6/18.
//

#ifndef BASETEST_TREE_H
#define BASETEST_TREE_H

#include <stdbool.h>

// 无限子节点的表示
typedef struct _tree_node {
    int key;
    struct _tree_node *child, *parent, *brother;
} TREE;

/* 建立一棵空树 */
void setnull(TREE *T);

/* 求节点x所在树的根节点 */
TREE *root(TREE *x);

/* 求树中节点x的父节点 */
TREE *parent(TREE *T, TREE *x);

/* 求树中节点x的子节点 */
TREE *child(TREE *T, TREE *x);

/* 求树中节点x的右边的兄弟节点 */
TREE *rightsibling(TREE *T, TREE *x);

/* 把以S为根节点的树插入到树T中作为x节点的第i棵子树 */
bool insert(TREE *T, TREE *x, int i, TREE *S);

/* 删除树中节点x的第i棵子树 */
bool delete(TREE *T, TREE *x, int i);

/*  遍历一棵树，得到一个由所有节点组成的序列，每个节点只被访问一次 */
TREE *traverse(TREE *T);


#endif //BASETEST_TREE_H
