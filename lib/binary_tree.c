//
// Created by BPanther on 2019/8/3.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <binary_tree.h>
#include <queue.h>
#include <stack.h>

#define MAXSIZE 100

BTREE create_bt(char *sentence, int sentence_len) {
    BTREE STACK[MAXSIZE], p = NULL, T = NULL;
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
                p = (BTREE) malloc(sizeof(BTNode));
                p->data = ch;
                p->l_child = NULL;
                p->r_child = NULL;
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

BTREE create_bt_node() {
    BTREE p = (BTREE) malloc(sizeof(BTNode));
    if (p != NULL) {
        p->data = 0;
        p->r_child = NULL;
        p->r_child = NULL;
    }
    return p;
}

void level_print_bt(BTREE T) {
    QUEUE *q = init_queue(20);
    BTREE p;
    push_queue(q, &T);
    while (!queue_is_empty(q)) {
        pop_queue(q, &p);
        if (p->l_child != NULL)
            push_queue(q, &p->l_child);
        if (p->r_child != NULL)
            push_queue(q, &p->r_child);
        printf("%c ", p->data);
    }
    del_queue(q);
}

int count_bt_leaf_recur(BTREE T) {
    if (T == NULL)
        return 0;
    if (T->l_child == NULL && T->r_child == NULL)
        return 1;
    return count_bt_leaf_recur(T->l_child) + count_bt_leaf_recur(T->r_child);
}

int count_bt_depth_recur(BTREE T) {
    if (T == NULL)
        return 0;
    else {
        int left_d = count_bt_depth_recur(T->l_child);
        int right_d = count_bt_depth_recur(T->r_child);
        return left_d > right_d ? left_d + 1 : right_d + 1;
    }
}

// 变长参数函数指针指向定长函数
void pre_order_recur(BTREE T, void visit(int, ...)) {
    if (T != NULL) {
        visit(1, T);
        pre_order_recur(T->l_child, visit);
        pre_order_recur(T->r_child, visit);
    }
}

// 前序遍历：放入stack的结点意味着其右子树还没有被处理(访问或者为空)，而每个节点的右子树都需要被处理，当stack绝对为空时全部递归结束，
//     当p != NULL时还会有结点放入stack，所以当p == NULL且stack is empty时stack绝对为空
void pre_order(BTREE T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    BTREE p = T;
    while (!(p == NULL && stack_is_empty(stack))) {
        while (p != NULL) {
            visit(1, p);
            push_stack(stack, &p);
            p = p->l_child;
        }
        pop_stack(stack, &p);
        p = p->r_child;
    }
    del_stack(stack);
}

// 出栈：访问该结点，并把右子树该结点放在下面，左子树放在该结点上面
void pre_order2(BTREE T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    push_stack(stack, &T);
    BTREE p = NULL;
    while (!stack_is_empty(stack)) {
        pop_stack(stack, &p);
        visit(1, p);
        if (p->r_child != NULL)
            push_stack(stack, &(p->r_child));
        if (p->l_child != NULL)
            push_stack(stack, &(p->l_child));
    }
    del_stack(stack);
}


void in_order_recur(BTREE T, void visit(int, ...)) {
    if (T != NULL) {
        in_order_recur(T->l_child, visit);
        visit(1, T);
        in_order_recur(T->r_child, visit);
    }
}

// 出栈：这个结点的左子树访问完了或者为空
// 开始：从根节点沿着左孩子的方向搜索，遇到的第一个左子树为空的结点是第一个结点
// 结束：从根节点沿着右孩子的方向搜索，遇到的第一个右子树为空的结点是最后一个结点
// 入栈：之后需要访问该结点和该结点的右子树
void in_order(BTREE T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    BTREE p = T;
    while (!(p == NULL && stack_is_empty(stack))) {
        while (p != NULL) {
            push_stack(stack, &p);
            p = p->l_child;
        }
        pop_stack(stack, &p);
        visit(1, p);
        p = p->r_child;
    }
    del_stack(stack);
}

// 中序遍历：stack存放的结点在之后他本身和其右子树需要被访问，而每个结点和右子树都需要被访问，当stack绝对为空时所有递归就结束了
//     当p != NULL时还会有结点放入stack，所以当p == NULL且stack is empty时stack绝对为空
void in_order2(BTREE T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    BTREE p = T;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            push_stack(stack, &p);
            p = p->l_child;
            continue;
        }
        pop_stack(stack, &p);
        visit(1, p);
        p = p->r_child;
    }
    del_stack(stack);
}

// 第一次出栈：把右子树放在结点之下，把左子树放在结点之上
// 第二次出栈：访问这个结点
void in_order3(BTREE T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    STACK *flags = init_stack(sizeof(_Bool), 20);
    _Bool flag = false;
    _Bool TRUE = true;
    _Bool FALSE = false;
    BTREE p = NULL;
    push_stack(stack, &T);
    push_stack(flags, &FALSE);
    while (!stack_is_empty(stack)) {
        pop_stack(stack, &p);
        pop_stack(flags, &flag);
        if (flag) {
            visit(1, p);
        } else {
            if (p->r_child != NULL) {
                push_stack(stack, &(p->r_child));
                push_stack(flags, &FALSE);
            }
            push_stack(stack, &p);
            push_stack(flags, &TRUE);
            if (p->l_child != NULL) {
                push_stack(stack, &(p->l_child));
                push_stack(flags, &FALSE);
            }
        }
    }
    del_stack(stack);
    del_stack(flags);
}


void post_order_recur(BTREE T, void visit(int, ...)) {
    if (T != NULL) {
        post_order_recur(T->l_child, visit);
        post_order_recur(T->r_child, visit);
        visit(1, T);
    }
}

// 开始：从根结点沿着左孩子的方向遇到没有左子树的结点，如果这个结点有右子树则在右子树中继续从根节点沿着左孩子的方向遇到没有左子树的结点，
//     如果这个结点没有左子树和右子树，则该结点为第一个结点
// 结束：根节点为最后一个结点
void post_order(BTREE T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    STACK *flags = init_stack(sizeof(_Bool), 20);
    _Bool TRUE = true;
    _Bool FALSE = false;
    _Bool flag = false;
    BTREE p = T;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            push_stack(stack, &p);
            push_stack(flags, &FALSE);
            p = p->l_child;
            continue;
        }
        pop_stack(stack, &p);
        pop_stack(flags, &flag);
        if (flag == true) {
            visit(1, p);
            // p == NULL 表明以这个结点为根的树处理完毕，不需要在下一次迭代时处理了
            p = NULL;
        } else {
            push_stack(stack, &p);
            push_stack(flags, &TRUE);
            p = p->r_child;
        }
    }
    del_stack(stack);
    del_stack(flags);
}

void post_order2(BTREE T, void visit(int, ...)) {
    STACK *stack1 = init_stack(sizeof(BTREE), 20);
    STACK *stack2 = init_stack(sizeof(BTREE), 20);
    BTREE bt = NULL;
    push_stack(stack1, &T);
    while (!stack_is_empty(stack1)) {
        pop_stack(stack1, &bt);
        push_stack(stack2, &bt);

        if (bt->l_child != NULL) {
            push_stack(stack1, &(bt->l_child));
        }
        if (bt->r_child != NULL) {
            push_stack(stack1, &(bt->r_child));
        }
    }
    while (!stack_is_empty(stack2)) {
        pop_stack(stack2, &bt);
        visit(1, bt);
    }
    del_stack(stack1);
    del_stack(stack2);
}

void print_bt_node(int argc, BTREE T) {
    printf("%c ", T->data);
}

void recover_bt_by_pre_in(BTREE *T, char *pre_seq, size_t pre_len, char *in_seq, size_t in_len) {
    if (pre_len == 0) {
        *T = NULL;
        return;
    }
    *T = create_bt_node();
    (*T)->data = *pre_seq;
    char *in_root = (char *) memchr(in_seq, (*T)->data, sizeof(char) * in_len);

    char *in_left_sub_seq;
    size_t in_left_sub_seq_len;
    if (in_root == in_seq) {
        in_left_sub_seq = NULL;
        in_left_sub_seq_len = 0;
    } else {
        in_left_sub_seq = in_seq;
        in_left_sub_seq_len = in_root - in_seq;
    }

    char *in_right_sub_seq;
    size_t in_right_sub_seq_len;
    if (in_root == (in_seq + in_len - 1)) {
        in_right_sub_seq = NULL;
        in_right_sub_seq_len = 0;
    } else {
        in_right_sub_seq = in_root + 1;
        in_right_sub_seq_len = (in_seq + in_len - 1) - in_root;
    }

    char *pre_left_sub_seq;
    size_t pre_left_sub_seq_len = in_left_sub_seq_len;
    if (pre_left_sub_seq_len == 0) {
        pre_left_sub_seq = NULL;
        (*T)->l_child = NULL;
    } else {
        pre_left_sub_seq = pre_seq + 1;
        BTREE left = create_bt_node();
        left->data = *pre_left_sub_seq;
        (*T)->l_child = left;
    }

    char *pre_right_sub_seq;
    size_t pre_right_sub_seq_len = in_right_sub_seq_len;
    if (pre_right_sub_seq_len == 0) {
        pre_right_sub_seq = NULL;
    } else {
        pre_right_sub_seq = pre_left_sub_seq + pre_left_sub_seq_len;
    }



}