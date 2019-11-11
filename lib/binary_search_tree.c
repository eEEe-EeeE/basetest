//
// Created by BPanther on 2019/11/7.
//

#include <binary_search_tree.h>
#include <stdlib.h>

BSTNodePtr _create_bst_node(int key) {
    BSTNodePtr newNodePtr = (BSTNodePtr) malloc(sizeof(BSTNode));
    if (newNodePtr != NULL) {
        newNodePtr->key = key;
        newNodePtr->left = NULL;
        newNodePtr->right = NULL;

    }
    return newNodePtr;
}

BSTree create_bst(int *keys, size_t len) {
    int cnt = 0;
    BSTree T = NULL;
    while (cnt < len) {
        if (T == NULL)
            T = insert_bst(T, keys[cnt]);
        else
            insert_bst(T, keys[cnt]);
        ++cnt;
    }
    return T;
}

BSTree insert_bst_recur(BSTree T, int key) {
    if (T == NULL) {
        T = _create_bst_node(key);
    } else if (key < T->key) {
        T->left = insert_bst_recur(T->left, key);
    } else if (key > T->key) {
        T->right = insert_bst_recur(T->right, key);
    }
    // 返回插入结点后的树
    return T;
}

BSTree insert_bst(BSTree T, int key) {
    if (T == NULL) {
        return _create_bst_node(key);
    }
    BSTNodePtr nodePtr = T;
    BSTNodePtr preNodePtr = NULL;
    int isLeft = 0;
    while (nodePtr != NULL) {
        preNodePtr = nodePtr;
        if (key < nodePtr->key) {
            nodePtr = nodePtr->left;
            isLeft = 1;
        } else if (key > nodePtr->key) {
            nodePtr = nodePtr->right;
            isLeft = 0;
        } else {
            return T;
        }
    }
    if (isLeft) {
        preNodePtr->left = _create_bst_node(key);
    } else {
        preNodePtr->right = _create_bst_node(key);
    }
    return T;
}

BSTNodePtr _min_value_bst(BSTree T) {
    BSTNodePtr preT = NULL;
    while (T != NULL) {
        preT = T;
        T = T->left;
    }
    return preT;
}

BSTree delete_bst_recur(BSTree T, int key) {
    if (T == NULL) {
        return NULL;
    }
    if (key < T->key) {
        T->left = delete_bst_recur(T->left, key);
    } else if (key > T->key) {
        T->right = delete_bst_recur(T->right, key);
    } else {
        if (T->left == NULL) {
            BSTNodePtr temp = T->right;
            free(T);
            return temp;
        } else if (T->right == NULL) {
            BSTNodePtr temp = T->left;
            free(T);
            return temp;
        } else {
            BSTNodePtr temp = _min_value_bst(T->right);
            T->key = temp->key;
            T->right = delete_bst_recur(T->right, temp->key);
        }
    }
    return T;
}

// 类似线性表删除，先数据迁移，后释放结点。数据迁移包括数据域和指针域
BSTree delete_bst(BSTree T, int key) {

    BSTNodePtr preT = T;
    BSTNodePtr p = T;
    int isLeft = 0;
    while (p != NULL) {
        if (key < p->key) {
            preT = p;
            p = p->left;
            isLeft = 1;
        } else if (key > p->key) {
            preT = p;
            p = p->right;
            isLeft = 0;
        } else {
            if (p->left == NULL || p->right == NULL) {
                BSTNodePtr temp = p->left ? p->left : p->right;
                if (temp == NULL) {
                    if (isLeft) {
                        preT->left = NULL;
                    } else {
                        preT->right = NULL;
                    }
                    free(p);
                    break;
                } else {
                    p->left = NULL;
                    p->right = NULL;
                    p->key = temp->key;
                    free(temp);
                    break;
                }
            } else {
                BSTNodePtr minValuePtr = p->right;
                BSTNodePtr minValuePrePtr = p;
                while (minValuePtr->left != NULL) {
                    minValuePrePtr = minValuePtr;
                    minValuePtr = minValuePtr->left;
                }
                if (minValuePrePtr != p) {
                    minValuePrePtr->left = minValuePtr->right;
                } else {
                    minValuePrePtr->right = minValuePtr->right;
                }
                p->key = minValuePtr->key;
                free(minValuePtr);
                break;
            }
        }
    }
    return T;
}

BSTNodePtr search_bst(BSTree T, int key) {
    while (T != NULL) {
        if (key < T->key) {
            T = T->left;
        } else if (key > T->key) {
            T = T->right;
        } else {
            break;
        }
    }
    return T;
}