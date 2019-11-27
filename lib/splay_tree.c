//
// Created by BPanther on 2019/11/6.
//

#include <splay_tree.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void create_st(int *keys, size_t len) {
    int cnt = 0;
    STree T = NULL;
    while (cnt < len) {
        T = insert_st_recur(T, keys[cnt]);
        ++cnt;
    }
}

STNodePtr _create_st_node(int key) {
    STNodePtr p = (STNodePtr) malloc(sizeof(STNode));
    if (p != NULL) {
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

STree insert_st_recur(STree T, int key) {
    if (T == NULL) {
        STNodePtr newNode = _create_st_node(key);
        return newNode;
    }
    if (key < T->key) {
        T->left = insert_st_recur(T->left, key);
    } else if (key > T->key) {
        T->right = insert_st_recur(T->right, key);
    }
    return T;
}

STNodePtr _min_value_st(STree T) {
    STNodePtr preT = T;
    while (T != NULL) {
        preT = T;
        T = T->left;
    }
    return preT;
}

STree delete_st_recur(STree T, int key) {
    if (T != NULL) {
        if (key < T->key) {
            T->left = delete_st_recur(T->left, key);
        } else if (key > T->key) {
            T->right = delete_st_recur(T->right, key);
        } else {
            if (T->left == NULL) {
                STNodePtr temp = T->right;
                free(T);
                return temp;
            } else if (T->right == NULL) {
                STNodePtr temp = T->left;
                free(T);
                return temp;
            } else {
                STNodePtr temp = _min_value_st(T->right);
                T->key = temp->key;
                T->right = delete_st_recur(T->right, temp->key);
            }
        }
    }
    return T;
}

// 伸展包含6种操作，目的是把访问结点移动到根结点
// 1.zig
// 2.zag
// 3.zig-zig
// 4.zag-zag
// 5.zig-zag
// 6.zag-zig
STree _splay(STree T, int key) {
    if (T == NULL || key == T->key) {
        return T;
    } else if (key < T->key) {
        if (T->left != NULL) {
            if (key < T->left->key) {
                T->left->left = _splay(T->left->left, key);
                T = zig_st(T);
            } else if (key > T->left->key){
                T->left->right = _splay(T->left->right, key);
                if (T->left->right != NULL) {
                    T->left = zag_st(T->left);
                }
            }
        }
        return T->left != NULL ? zig_st(T) : T;
    } else {
        if (T->right != NULL) {
            if (key > T->right->key) {
                T->right->right = _splay(T->right->right, key);
                T = zag_st(T);
            } else if (key < T->right->key) {
                T->right->left = _splay(T->right->left, key);
                if (T->right->left != NULL) {
                    T->right = zig_st(T->right);
                }
            }
        }
        return T->right != NULL ? zag_st(T) : T;
    }
}

STNodePtr search_st_recur(STree T, int key) {
    return _splay(T, key);
}

// 右旋，空树会出错
STree zig_st(STree T) {
    STree temp = T->left;
    T->left = temp->right;
    temp->right = T;
    return temp;
}

// 左旋，空树会出错
STree zag_st(STree T) {
    STree temp = T->right;
    T->right = temp->left;
    temp->left = T;
    return temp;
}

