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
#include <utils.h>

#define MAXSIZE 100
#define MAXWORDSLEN 32

BTree create_bt(STRING*words) {
    STACK *stack = init_stack(sizeof(BTree), 10);
    BTree p = NULL;
    BTree parent = NULL;
    BTree T = NULL;
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
            p = _create_bt_node(*sp);
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

BTree _create_bt_node(STRING string) {
    if (string != NULL) {
        BTree p = (BTree) malloc(sizeof(BTNode));
        if (p != NULL) {
            p->data = (STRING) malloc(strlen(string) + 1);
            if (p->data != NULL) {
                strcpy(p->data, string);
                p->l_child = NULL;
                p->r_child = NULL;
                return p;
            }
        }
    }
    return NULL;
}

void destroy_bt_node(BTree T) {
    if (T != NULL) {
        free(T->data);
        free(T);
    }
}

void clear_bt_node(BTree *T) {
    destroy_bt_node(*T);
    *T = NULL;
}

void build_bt(BTree *T) {
    STRING str = (STRING) malloc(MAXWORDSLEN);
    scanf("%s", str);
    if (!strcmp(",", str)) {
        (*T) = NULL;
    } else {
        (*T) = _create_bt_node(str);
        build_bt(&((*T)->l_child));
        build_bt(&((*T)->r_child));
    }
    free(str);
}

// 销毁树的时候，后序遍历最合适
void destroy_bt(BTree T) {
    if (T != NULL) {
        destroy_bt(T->l_child);
        destroy_bt(T->r_child);
        free(T->data);
        free(T);
    }
}

void clear_bt(BTree *T) {
    destroy_bt(*T);
    *T = NULL;
}

BTree delete_bt(BTree *T, STRING item) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    BTree p = *T;
    BTree parent = NULL;
    if (!strcmp((*T)->data, item)) {
        clear_bt(T);
        del_stack(stack);
        return NULL;
    } else {
        while (!(p == NULL && stack_is_empty(stack))) {
            if (p != NULL) {
                if (!strcmp(p->data, item)) {
                    if (parent->l_child == p)
                        parent->l_child = NULL;
                    else if (parent->r_child == p)
                        parent->r_child = NULL;
                    clear_bt(&p);
                    del_stack(stack);
                    return *T;
                }
                push_stack(stack, &p);
                parent = p;
                p = p->l_child;
            } else {
                pop_stack(stack, &p);
                parent = p;
                p = p->r_child;
            }
        }
    }
    del_stack(stack);
    return *T;
}

void level_print_bt(BTree T) {
    if (T != NULL) {
        QUEUE *q = init_queue(sizeof(BTree), 20);
        BTree p;
        push_queue(q, &T);
        while (!queue_is_empty(q)) {
            pop_queue(q, &p);
            if (p->l_child != NULL)
                push_queue(q, &p->l_child);
            if (p->r_child != NULL)
                push_queue(q, &p->r_child);
            printf("%s ", p->data);
        }
        del_queue(q);
    }
}

int count_bt_leaf_recur(BTree T) {
    if (T == NULL)
        return 0;
    if (T->l_child == NULL && T->r_child == NULL)
        return 1;
    return count_bt_leaf_recur(T->l_child) + count_bt_leaf_recur(T->r_child);
}

int count_bt_leaf(BTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int count = 0;
        BTree p = T;
        STACK *stack = init_stack(sizeof(BTree), 20);
        while (!(p == NULL && stack_is_empty(stack))) {
            if (p != NULL) {
                if (bt_node_is_leaf(p)) {
                    ++count;
                }
                push_stack(stack, &p);
                p = p->l_child;
            } else {
                pop_stack(stack, &p);
                p = p->r_child;
            }
        }
        del_stack(stack);
        return count;
    }
}

int count_bt_depth_recur(BTree T) {
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

int bt_node_is_leaf(BTree node) {
    if (node == NULL)
        return 0;
    else
        return node->l_child == NULL && node->r_child == NULL;
}

int count_bt_depth_pre(BTree T) {
    if (T == NULL)
        return 0;
    STACK *stack = init_stack(sizeof(BTree), 20);
    STACK *level = init_stack(sizeof(int), 20);
    BTree p = T;
    int cur_level = 0;
    int cur_max_level = 1;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            ++cur_level;
            if (cur_level > cur_max_level)
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

int count_bt_depth_in(BTree T) {
    if (T == NULL)
        return 0;
    STACK *stack = init_stack(sizeof(BTree), 20);
    STACK *level = init_stack(sizeof(int), 20);
    BTree p = T;
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
            if (cur_level > cur_max_level)
                cur_max_level = cur_level;
            p = p->r_child;
        }
    }
    del_stack(stack);
    del_stack(level);
    return cur_max_level;
}

int count_bt_depth_post(BTree T) {
    if (T == NULL)
        return 0;
    STACK *stack = init_stack(sizeof(BTree), 10);
    STACK *flags = init_stack(sizeof(_Bool), 10);
    BTree p = T;
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
int calc_bt_node_layer(BTree T, STRING item) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    STACK *flags = init_stack(sizeof(_Bool), 20);
    _Bool flag = false;
    _Bool TRUE = true;
    _Bool FALSE = false;
    BTree p = T;
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
                if (!strcmp(p->data, item))
                    return (int) stack->size + 1;
                p = NULL;
            }
        }
    }
    del_stack(stack);
    del_stack(flags);
    return -1;
}

void exchange_bt(BTree T) {
    if (T != NULL) {
        QUEUE *queue = init_queue(sizeof(BTree), 10);
        BTree p = NULL;
        BTree temp = NULL;
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

void exchange_bt_pre(BTree T) {
    STACK *stack = init_stack(sizeof(BTree), 10);
    BTree p = T;
    BTree temp = NULL;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            temp = p->l_child;
            p->l_child = p->r_child;
            p->r_child = temp;
            push_stack(stack, &p);
            p = p->r_child;
        } else {
            pop_stack(stack, &p);
            p = p->l_child;
        }
    }
    del_stack(stack);
}

void exchange_bt_in(BTree T) {
    STACK *stack = init_stack(sizeof(BTree), 10);
    BTree p = T;
    BTree temp = NULL;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            push_stack(stack, &p);
            p = p->l_child;
        } else {
            pop_stack(stack, &p);
            temp = p->l_child;
            p->l_child = p->r_child;
            p->r_child = temp;
            p = p->l_child;
        }
    }
    del_stack(stack);
}

void exchange_bt_post(BTree T) {
    STACK *stack = init_stack(sizeof(BTree), 10);
    STACK *flags = init_stack(sizeof(_Bool), 10);
    BTree p = T;
    _Bool flag = false;
    _Bool TRUE = true;
    _Bool FALSE = false;
    BTree temp = NULL;
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
                temp = p->l_child;
                p->l_child = p->r_child;
                p->r_child = temp;
                p = NULL;
            }
        }
    }
    del_stack(stack);
    del_stack(flags);
}

void print_bt_node(int argc, BTree T) {
    printf("%s ", T->data);
}

// 变长参数函数指针指向定长函数
void pre_order_recur(BTree T, void visit(int, ...)) {
    if (T != NULL) {
        visit(1, T);
        pre_order_recur(T->l_child, visit);
        pre_order_recur(T->r_child, visit);
    }
}

// 前序遍历：放入stack的结点意味着其右子树还没有被处理(访问或者为空)，而每个节点的右子树都需要被处理，当stack绝对为空时全部递归结束，
//     当p != NULL时还会有结点放入stack，所以当p == NULL且stack is empty时stack绝对为空
void pre_order(BTree T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    BTree p = T;
    while (!(p == NULL && stack_is_empty(stack))) {
        if (p != NULL) {
            visit(1, p);
            push_stack(stack, &p);
            p = p->l_child;
        } else {
            pop_stack(stack, &p);
            p = p->r_child;
        }
    }
    del_stack(stack);
}

// 出栈：访问该结点，并把右子树该结点放在下面，左子树放在该结点上面
void pre_order2(BTree T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    push_stack(stack, &T);
    BTree p = NULL;
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


void in_order_recur(BTree T, void visit(int, ...)) {
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
void in_order(BTree T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    BTree p = T;
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
void in_order2(BTree T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    BTree p = T;
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
void in_order3(BTree T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    STACK *flags = init_stack(sizeof(_Bool), 20);
    _Bool flag = false;
    _Bool TRUE = true;
    _Bool FALSE = false;
    BTree p = NULL;
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


void post_order_recur(BTree T, void visit(int, ...)) {
    if (T != NULL) {
        post_order_recur(T->l_child, visit);
        post_order_recur(T->r_child, visit);
        visit(1, T);
    }
}

// 开始：从根结点沿着左孩子的方向遇到没有左子树的结点，如果这个结点有右子树则在右子树中继续从根节点沿着左孩子的方向遇到没有左子树的结点，
//     如果这个结点没有左子树和右子树，则该结点为第一个结点
// 结束：根节点为最后一个结点
void post_order(BTree T, void visit(int, ...)) {
    STACK *stack = init_stack(sizeof(BTree), 20);
    STACK *flags = init_stack(sizeof(_Bool), 20);
    _Bool TRUE = true;
    _Bool FALSE = false;
    _Bool flag = false;
    BTree p = T;
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

void post_order2(BTree T, void visit(int, ...)) {
    STACK *stack1 = init_stack(sizeof(BTree), 20);
    STACK *stack2 = init_stack(sizeof(BTree), 20);
    BTree bt = NULL;
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

BTree recover_bt_by_pre_in_recur(STRING*pre_seq, STRING*in_seq, size_t seq_len) {
    if (seq_len == 0) {
        return NULL;
    } else {

        BTree T = _create_bt_node(*pre_seq);

        size_t in_root_offset = linear_search_str(in_seq, T->data);

        T->l_child = recover_bt_by_pre_in_recur(pre_seq + 1, in_seq, in_root_offset);

        T->r_child = recover_bt_by_pre_in_recur(pre_seq + 1 + in_root_offset, in_seq + in_root_offset + 1,
                                                (seq_len - 1) - in_root_offset);

        return T;
    }
}

// 转非递归的要素：1.是否满足递归终止条件  2.进递归前做了哪些事情  3.出递归做了哪些事情
// 分两方面 1.问题还未解决，问题已经解决
// 问题还未解决包括 1.递归前做了哪些事情并进入递归
// 有返回值时问题已经解决包括 1.达到终止条件出递归 2.未达到终止条件出递归 (都是回退到先祖函数不同的点，做不同的事情)
BTree recover_bt_by_pre_in(STRING*pre_seq, STRING*in_seq, size_t seq_len) {
    STACK *stack_b = init_stack(sizeof(BTree), 20);
    STACK *stack_pre = init_stack(sizeof(STRING*), 20);
    STACK *stack_in = init_stack(sizeof(STRING*), 20);
    STACK *stack_root = init_stack(sizeof(size_t), 20);
    STACK *stack_u = init_stack(sizeof(size_t), 20);
    // 0表示左，1表示右
    STACK *stack_f = init_stack(sizeof(_Bool), 20);
    STACK *stack_return = init_stack(sizeof(BTree), 20);
    BTree T;

    size_t in_root_offset;
    STRING*p_seq = pre_seq;
    STRING*i_seq = in_seq;
    size_t s_len = seq_len;
    BTree return_value;

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
            T = _create_bt_node(*p_seq);
            in_root_offset = linear_search_str(i_seq, T->data);
            push_stack(stack_b, &T);
            push_stack(stack_pre, &p_seq);
            push_stack(stack_in, &i_seq);
            push_stack(stack_root, &in_root_offset);
            push_stack(stack_u, &s_len);
            push_stack(stack_f, &FALSE);
            p_seq = p_seq + 1;
            s_len = in_root_offset;
            // 此时进入子函数
        } else {
            // 此时处于一个空结点上，前序序列和中序序列不存在
            if (flag == false) {
                return_value = NULL;
                push_stack(stack_return, &return_value);
            }
            pop_stack(stack_b, &T);
            pop_stack(stack_pre, &p_seq);
            pop_stack(stack_in, &i_seq);
            pop_stack(stack_root, &in_root_offset);
            pop_stack(stack_u, &s_len);
            pop_stack(stack_f, &flag);
            pop_stack(stack_return, &return_value);
            // 此时回退到父函数
            if (flag == false) {
                T->l_child = return_value;
                push_stack(stack_b, &T);
                push_stack(stack_pre, &p_seq);
                push_stack(stack_in, &i_seq);
                push_stack(stack_root, &in_root_offset);
                push_stack(stack_u, &s_len);
                push_stack(stack_f, &TRUE);
                p_seq = p_seq + 1 + in_root_offset;
                i_seq = i_seq + in_root_offset + 1;
                s_len = (s_len - 1) - in_root_offset;
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

    del_stack(stack_b);
    del_stack(stack_f);
    del_stack(stack_in);
    del_stack(stack_pre);
    del_stack(stack_return);
    del_stack(stack_root);
    del_stack(stack_u);
    return return_value;
}

int btrees_are_equal_recur(BTree T1, BTree T2) {
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

int btrees_are_similar_recur(BTree T1, BTree T2) {
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

BTree copy_bt(BTree T) {
    if (T == NULL)
        return NULL;
    else {
        BTree T2 = (BTree) malloc(sizeof(BTNode));
        T2->data = T->data;
        T2->l_child = copy_bt(T->l_child);
        T2->r_child = copy_bt(T->r_child);
        return T2;
    }
}

void copy_bt2(BTree T, BTree *T2) {
    if (T == NULL) {
        (*T2) = NULL;
    } else {
        (*T2) = (BTree) malloc(sizeof(BTNode));
        (*T2)->data = T->data;
        copy_bt2(T->l_child, &((*T2)->l_child));
        copy_bt2(T->r_child, &((*T2)->r_child));
    }
}

void _delete_bst(BTree *T, BTree *p, BTree parent) {
    BTree subs = NULL;
    BTree subs_parent = NULL;
    if ((*p)->l_child != NULL && (*p)->r_child != NULL) {
        subs_parent = *p;
        subs = (*p)->r_child;
        while (subs->l_child != NULL) {
            subs_parent = subs;
            subs = subs->l_child;
        }
        subs->l_child = (*p)->l_child;
        if (subs_parent != *p) {
            subs_parent->l_child = subs->r_child;
            subs->r_child = (*p)->r_child;
        }
    } else {
        if ((*p)->l_child == NULL) {
            subs = (*p)->r_child;
        } else if ((*p)->r_child == NULL) {
            subs = (*p)->l_child;
        }
    }
    if (parent != NULL) {
        if (*p == parent->l_child)
            parent->l_child = subs;
        else if (*p == parent->r_child)
            parent->r_child = subs;
    } else {
        *T = subs;
    }
    clear_bt_node(p);
}
