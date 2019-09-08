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

void build_bt(BTREE *T) {
    char ch;
    scanf("%c", &ch);
    if (ch == ' ') {
        (*T) = NULL;
    } else {
        (*T) = (BTREE) malloc(sizeof(BTNode));
        (*T)->data = ch;
        build_bt(&((*T)->l_child));
        build_bt(&((*T)->r_child));
    }
}

// 销毁树的时候，后序遍历最合适
void destroy_bt(BTREE T) {
    if (T != NULL) {
        destroy_bt(T->l_child);
        destroy_bt(T->r_child);
        free(T);
    }
}

void clear_bt(BTREE *T) {
    destroy_bt(*T);
    (*T) = NULL;
}

BTREE delete_bt(BTREE *T, char item) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    BTREE p = *T;
    BTREE q = NULL;
    if ((*T)->data == item) {
        clear_bt(T);
        return NULL;
    } else {
        while (!(p == NULL && stack_is_empty(stack))) {
            if (p != NULL) {
                if (p->data == item) {
                    if (q->l_child == p)
                        q->l_child = NULL;
                    else if (q->r_child == p)
                        q->r_child = NULL;
                    clear_bt(&p);
                    return *T;
                }
                push_stack(stack, &p);
                q = p;
                p = p->l_child;
            } else {
                pop_stack(stack, &p);
                q = p;
                p = p->r_child;
            }
        }
    }
    return *T;
}

void level_print_bt(BTREE T) {
    if (T != NULL) {
        QUEUE *q = init_queue(sizeof(BTREE), 20);
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
        int left_depth = count_bt_depth_recur(T->l_child);
        int right_depth = count_bt_depth_recur(T->r_child);
        if (left_depth > right_depth)
            return left_depth + 1;
        else
            return right_depth + 1;
    }
}

int bt_node_is_leaf(BTREE node) {
    if (node == NULL)
        return 0;
    else
        return node->l_child == NULL && node->r_child == NULL;
}

int count_bt_depth_pre(BTREE T) {
    if (T == NULL)
        return 0;
    STACK *stack = init_stack(sizeof(BTREE), 20);
    STACK *level = init_stack(sizeof(int), 20);
    BTREE p = T;
    int cur_level = 0;
    int cur_max_level = 1;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            ++cur_level;
            if (bt_node_is_leaf(p) && cur_level > cur_max_level)
                cur_max_level = cur_level;
            push_stack(stack, &p);
            push_stack(level, &cur_level);
            p = p->l_child;
            continue;
        } else {
            pop_stack(stack, &p);
            pop_stack(level, &cur_level);
            p = p->r_child;
        }
    }
    del_stack(stack);
    del_stack(level);
    return cur_max_level;
}

int count_bt_depth_in(BTREE T) {
    if (T == NULL)
        return 0;
    STACK *stack = init_stack(sizeof(BTREE), 20);
    STACK *level = init_stack(sizeof(int), 20);
    BTREE p = T;
    int cur_level = 0;
    int cur_max_level = 1;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            ++cur_level;
            push_stack(stack, &p);
            push_stack(level, &cur_level);
            p = p->l_child;
            continue;
        } else {
            pop_stack(stack, &p);
            pop_stack(level, &cur_level);
            if (bt_node_is_leaf(p) && cur_level > cur_max_level)
                cur_max_level = cur_level;
            p = p->r_child;
        }
    }
    del_stack(stack);
    del_stack(level);
    return cur_max_level;
}

int count_bt_depth_post(BTREE T) {
    if (T == NULL)
        return 0;
    STACK *stack = init_stack(sizeof(BTREE), 10);
    STACK *flags = init_stack(sizeof(_Bool), 10);
    BTREE p = T;
    _Bool flag = false;
    _Bool TRUE = true;
    _Bool FALSE = false;
    int cur_max_level = 1;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            push_stack(stack, &p);
            push_stack(flags, &FALSE);
            p = p->l_child;
        } else {
            pop_stack(stack, &p);
            pop_stack(flags, &flag);
            if (flag == false) {
                push_stack(stack, &p);
                push_stack(flags, &TRUE);
                p = p->r_child;
            } else {
                if (stack->size + 1 > cur_max_level)
                    cur_max_level = (int) stack->size + 1;
                p = NULL;
            }
        }
    }
    del_stack(stack);
    del_stack(flags);
    return cur_max_level;
}

// 后序遍历访问某个结点时，该结点的所有先祖节点依次都在栈里，其他遍历方式不存在这种情况
// 其他遍历方式也可以做
int calc_bt_node_layer(BTREE T, char item) {
    STACK *stack = init_stack(sizeof(BTREE), 20);
    STACK *flags = init_stack(sizeof(_Bool), 20);
    _Bool flag = false;
    _Bool TRUE = true;
    _Bool FALSE = false;
    BTREE p = T;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            push_stack(stack, &p);
            push_stack(flags, &FALSE);
            p = p->l_child;
        } else {
            pop_stack(stack, &p);
            pop_stack(flags, &flag);
            if (flag == false) {
                push_stack(stack, &p);
                push_stack(flags, &TRUE);
                p = p->r_child;
            } else {
                if (p->data == item)
                    return (int) stack->size + 1;
                p = NULL;
            }
        }
    }
    del_stack(stack);
    del_stack(flags);
    return -1;
}

void exchange_bt(BTREE T) {
    if (T != NULL) {
        QUEUE *queue = init_queue(sizeof(BTREE), 10);
        BTREE p = NULL;
        BTREE temp = NULL;
        push_queue(queue, &T);
        while (!queue_is_empty(queue)) {
            pop_queue(queue, &p);
            temp = p->l_child;
            p->l_child = p->r_child;
            p->r_child = temp;
            if (p->l_child != NULL)
                push_queue(queue, &(p->l_child));
            if (p->r_child != NULL)
                push_queue(queue, &(p->r_child));
        }
        del_queue(queue);
    }
}

void exchange_bt_pre(BTREE T) {

}

void print_bt_node(int argc, BTREE T) {
    printf("%c ", T->data);
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
        if (p != NULL) {
            visit(1, p);
            push_stack(stack, &p);
            p = p->l_child;
            continue;
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

BTREE recover_bt_by_pre_in_recur(const char *pre_seq, const char *in_seq, size_t seq_len) {
    if (seq_len == 0) {
        return NULL;
    }

    BTREE T = create_bt_node();
    T->data = *pre_seq;
    char *in_root = (char *) memchr(in_seq, T->data, sizeof(char) * seq_len);

    T->l_child = recover_bt_by_pre_in_recur(pre_seq + 1, in_seq,
                                            in_root - in_seq);

    T->r_child = recover_bt_by_pre_in_recur(pre_seq + 1 + (in_root - in_seq), in_root + 1,
                                            (in_seq + seq_len - 1) - in_root);

    return T;
}

// 转非递归的要素：1.是否满足递归终止条件  2.进递归前做了哪些事情  3.出递归做了哪些事情
// 分两方面 1.问题还未解决，问题已经解决
// 问题还未解决包括 1.递归前做了哪些事情并进入递归
// 有返回值时问题已经解决包括 1.达到终止条件出递归 2.未达到终止条件出递归 (都是回退到先祖函数不同的点，做不同的事情)
BTREE recover_bt_by_pre_in(const char *pre_seq, const char *in_seq, const size_t seq_len) {
    STACK *stack_b = init_stack(sizeof(BTREE), 20);
    STACK *stack_pre = init_stack(sizeof(char *), 20);
    STACK *stack_in = init_stack(sizeof(char *), 20);
    STACK *stack_root = init_stack(sizeof(char *), 20);
    STACK *stack_u = init_stack(sizeof(size_t), 20);
    // 0表示左，1表示右
    STACK *stack_f = init_stack(sizeof(_Bool), 20);
    STACK *stack_return = init_stack(sizeof(BTREE), 20);
    BTREE T;

    char *in_root;
    const char *p_seq = pre_seq;
    const char *i_seq = in_seq;
    const char *temp_i_seq;
    size_t s_len = seq_len;
    BTREE return_value;

    _Bool flag = false;
    _Bool FALSE = false;
    _Bool TRUE = true;
    // s_len是否为零表示当前子问题是否已经解决
    // stack_u是否为空表示当前子问题的先祖问题是否已经解决
    while (!(s_len == 0 && stack_is_empty(stack_u))) {
        // len == 0 && flag == 0表示问题已解决且问题规模为零
        // len == 0 && flag == 1表示问题已解决且问题规模不为零
        if (s_len != 0) {
            // 此时处于一个非空节点上，问题的规模不为零，前序序列和中序序列不为零，可建立结点
            T = create_bt_node();
            T->data = *p_seq;
            in_root = (char *) memchr(i_seq, T->data, sizeof(char) * s_len);
            push_stack(stack_b, &T);
            push_stack(stack_pre, &p_seq);
            push_stack(stack_in, &i_seq);
            push_stack(stack_root, &in_root);
            push_stack(stack_u, &s_len);
            push_stack(stack_f, &FALSE);
            p_seq = p_seq + 1;
            s_len = in_root - i_seq;
            // 此时进入子函数
            continue;
        } else {
            // 此时处于一个空结点上，前序序列和中序序列不存在
            if (flag == false) {
                return_value = NULL;
                push_stack(stack_return, &return_value);
            }
            pop_stack(stack_b, &T);
            pop_stack(stack_pre, &p_seq);
            pop_stack(stack_in, &i_seq);
            pop_stack(stack_root, &in_root);
            pop_stack(stack_u, &s_len);
            pop_stack(stack_f, &flag);
            pop_stack(stack_return, &return_value);
            // 此时回退到父函数
            if (flag == false) {
                T->l_child = return_value;
                push_stack(stack_b, &T);
                push_stack(stack_pre, &p_seq);
                push_stack(stack_in, &i_seq);
                push_stack(stack_root, &in_root);
                push_stack(stack_u, &s_len);
                push_stack(stack_f, &TRUE);
                p_seq = p_seq + 1 + (in_root - i_seq);
                temp_i_seq = i_seq;
                i_seq = in_root + 1;
                s_len = (temp_i_seq + s_len - 1) - in_root;
                // 此时进入子函数
            } else {
                // 进入这里表示问题已解决且规模不为零
                T->r_child = return_value;
                return_value = T;
                push_stack(stack_return, &return_value);
                s_len = 0;
            }
        }
    }
    pop_stack(stack_return, &return_value);
    return return_value;
}

int btrees_are_equal_recur(BTREE T1, BTREE T2) {
    if (T1 == NULL && T2 == NULL) {
        return 1;
    } else if (T1 != NULL && T2 != NULL
               && T1->data == T2->data
               && btrees_are_equal_recur(T1->l_child, T2->l_child)
               && btrees_are_equal_recur(T1->r_child, T2->r_child)) {
        return 1;
    } else {
        return 0;
    }
}

int btrees_are_similar_recur(BTREE T1, BTREE T2) {
    if (T1 == NULL && T2 == NULL) {
        return 1;
    } else if (T1 != NULL && T2 != NULL
               && btrees_are_similar_recur(T1->l_child, T2->l_child)
               && btrees_are_similar_recur(T1->r_child, T2->r_child)) {
        return 1;
    } else {
        return 0;
    }
}

BTREE copy_bt(BTREE T) {
    if (T == NULL)
        return NULL;
    else {
        BTREE T2 = (BTREE) malloc(sizeof(BTNode));
        T2->data = T->data;
        T2->l_child = copy_bt(T->l_child);
        T2->r_child = copy_bt(T->r_child);
        return T2;
    }
}

void copy_bt2(BTREE T, BTREE *T2) {
    if (T == NULL) {
        (*T2) = NULL;
    } else {
        (*T2) = (BTREE) malloc(sizeof(BTNode));
        (*T2)->data = T->data;
        copy_bt2(T->l_child, &((*T2)->l_child));
        copy_bt2(T->r_child, &((*T2)->r_child));
    }
}