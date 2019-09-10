//
// Created by BPanther on 2019/9/10.
//

#include <thread_binary_tree.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
TBTREE create_tbt(char *sentence, int sentence_len) {
    TBTREE STACK[MAXSIZE], p = NULL, T = NULL;
    int top = -1;
    int flag = 0;
    char ch = '\0';
    char *s = sentence;
    while (sentence_len != 0) {
        sscanf(s, "%c", &ch);
        switch (ch) {
            case '@':
                return T;
            case '(':
                STACK[++top] = p;
                flag = 1;
                break;
            case ',':
                flag = 2;
                break;
            case ')':
                --top;
                break;
            default:
                p = (TBTREE) malloc(sizeof(TBTNode));
                p->data = ch;
                p->l_child = NULL;
                p->r_child = NULL;
                p->l_bit = 1;
                p->r_bit = 1;
                if (T == NULL)
                    T = p;
                else if (flag == 1) {
                    STACK[top]->l_child = p;
                } else {
                    STACK[top]->r_child = p;
                }
                break;
        }
        s += 1;
        --sentence_len;
    }
    return NULL;
}


void _in_thread(TBTREE HEAD, TBTREE *prior) {
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

void in_thread(TBTREE *HEAD) {
    TBTREE temp = malloc(sizeof(TBTNode));
    if (temp != NULL) {
        temp->l_bit = 1;
        temp->r_bit = 1;
        temp->l_child = *HEAD;
        temp->r_child = NULL;
        *HEAD = temp;
        TBTREE prior = *HEAD;
        _in_thread(*HEAD, &prior);
        (*HEAD)->r_child = (*HEAD);
        (*HEAD)->r_bit = 1;
    }
}

TBTREE in_prior(TBTREE p) {
    TBTREE s;
    s = p->l_child;
    if (p->l_bit != 0) {
        while (s->r_bit != 0)
            s = s->r_child;
    }
    return s;
}

TBTREE in_succ(TBTREE p) {
    TBTREE s;
    s = p->r_child;
    if (p->r_bit != 0) {
        while (s->l_bit != 0)
            s = s->l_child;
    }
    return s;
}

void thr_in_order(TBTREE HEAD) {
    TBTREE p = HEAD;
    while (1) {
        p = in_succ(p);
        if (p == HEAD)
            break;
        printf("%c ", p->data);
    }
}