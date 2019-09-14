//
// Created by BPanther on 2019/9/14.
//

#include <balanced_binary_tree.h>
#include <stack.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

BBTREE create_bbt(STRING*words) {
    STACK *stack = init_stack(sizeof(BBTREE), 10);
    // 1: left 2: right
    int flag = 0;
    STRING*sp = words;
    BBTREE T = NULL;
    BBTREE p = NULL;
    BBTREE parent = NULL;
    while (sp != NULL) {
        if (!strcmp("@", *sp)) {
            del_stack(stack);
            return T;
        } else if (!strcmp("(", *sp)) {
            push_stack(stack, &p);
            flag = 1;
        } else if (!strcmp(",", *sp)) {
            flag = 2;
        } else if (!strcmp(")", *sp)) {
            pop_stack(stack, &p);
        } else {
            p = create_bbt_node(*sp);
            if (T == NULL) {
                T = p;
            } else if (flag == 1) {
                pop_stack(stack, &parent);
                parent->l_child = p;
                push_stack(stack, &parent);
            } else if (flag == 2) {
                pop_stack(stack, &parent);
                parent->r_child = p;
                push_stack(stack, &parent);
            }
        }
        ++sp;
    }
    del_stack(stack);
    return NULL;
}

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