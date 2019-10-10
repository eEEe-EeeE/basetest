//
// Created by BPanther on 2019/9/14.
//

#include <balanced_binary_tree.h>
#include <stack.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

BBTREE create_bbt_node(STRING string) {
    if (string != NULL) {
        BBTREE pNode = malloc(sizeof(BBTNode));
        if (pNode != NULL) {
            pNode->data = malloc(strlen(string) + 1);
            if (pNode->data != NULL) {
                strcpy(pNode->data, string);
                pNode->l_child = NULL;
                pNode->r_child = NULL;
                pNode->balance = 0;
                return pNode;
            }
        }
    }
    return NULL;
}

BBTREE create_bbt(STRING *keys) {
    BBTREE T = NULL;
    while (*keys != NULL) {
        insert_bbt(&T, *keys);
        ++keys;
    }
    return T;
}

void destroy_bbt(BBTREE T) {
    if (T != NULL) {
        destroy_bbt(T->l_child);
        destroy_bbt(T->r_child);
        free(T->data);
        free(T);
    }
}

void clear_bbt(BBTREE *T) {
    destroy_bbt(*T);
    *T = NULL;
}

void insert_bbt_recur(BBTREE *T, STRING item) {
    if (*T == NULL) {
        (*T) = create_bbt_node(item);
    } else if (strtol(item, NULL, 10) < strtol((*T)->data, NULL, 10)) {

    }
}