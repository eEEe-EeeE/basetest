//
// Created by BPanther on 2019/11/6.
//

#include <splay_tree.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void create_st(int *keys, size_t len) {
    int cnt = 0;
    STree T = NULL;
    while(cnt < len) {
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
        p->height = 1;
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
    T->height = MAX(T->left->height, T->right->height) + 1;
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

STNodePtr search_st_recur(STree T, int key) {
    if (T != NULL) {
        if (key < T->key) {
            return search_st_recur(T->left, key);
        } else if (key > T->key) {
            return search_st_recur(T->right, key);
        } else {

        }
    }
    return T;
}

STree zig_zag_st(STree T) {
    return NULL;
}

STree zig_zig_st(STree T) {
    return NULL;
}