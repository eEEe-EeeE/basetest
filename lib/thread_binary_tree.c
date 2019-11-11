//
// Created by BPanther on 2019/9/10.
//

#include <thread_binary_tree.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stack.h>

#define MAXSIZE 100

TBTree create_tbt(STRING*words) {
    STACK *stack = init_stack(sizeof(TBTree), 10);
    TBTree p = NULL;
    TBTree parent = NULL;
    TBTree T = NULL;
    int flag = 0;
    STRING*sp = words;
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
            p = create_tbt_node(*sp);
            if (T == NULL)
                T = p;
            else if (flag == 1) {
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


TBTree create_tbt_node(STRING string) {
    if (string != NULL) {
        TBTree pNode = (TBTree) malloc(sizeof(TBTNode));
        if (pNode != NULL) {
            pNode->data = (STRING) malloc(strlen(string) + 1);
            if (pNode->data != NULL) {
                strcpy(pNode->data, string);
                pNode->l_child = NULL;
                pNode->l_bit = 1;
                pNode->r_child = NULL;
                pNode->r_bit = 1;
                return pNode;
            }
        }
    }
    return NULL;
}

void _in_thread(TBTree HEAD, TBTree *prior) {
    if (HEAD != NULL) {
        _in_thread(HEAD->l_child, prior);
        if (HEAD->l_child == NULL) {
            HEAD->l_bit = 0;
            HEAD->l_child = *prior;
        }
        if (HEAD->r_child == NULL) {
            HEAD->r_bit = 0;
        }
        if ((*prior)->r_bit == 0) {
            (*prior)->r_child = HEAD;
        }
        *prior = HEAD;
        _in_thread(HEAD->r_child, prior);
    }
}

void in_thread(TBTree *HEAD) {
    TBTree temp = create_tbt_node("HEAD");
    if (temp != NULL) {
        temp->l_child = *HEAD;
        *HEAD = temp;
        TBTree prior = *HEAD;
        _in_thread(*HEAD, &prior);
        (*HEAD)->r_child = *HEAD;
        (*HEAD)->r_bit = 1;
    }
}

TBTree in_prior(TBTree p) {
    TBTree s;
    s = p->l_child;
    if (p->l_bit != 0) {
        while (s->r_bit != 0)
            s = s->r_child;
    }
    return s;
}

TBTree in_succ(TBTree p) {
    TBTree s;
    s = p->r_child;
    if (p->r_bit != 0) {
        while (s->l_bit != 0)
            s = s->l_child;
    }
    return s;
}

void thr_in_order(TBTree HEAD) {
    TBTree p = HEAD;
    while (1) {
        p = in_succ(p);
        if (p == HEAD)
            break;
        printf("%s ", p->data);
    }
}