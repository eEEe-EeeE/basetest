//
// Created by someone on 2019/8/23.
//

#ifndef BASETEST_STACK_H
#define BASETEST_STACK_H

#include <stddef.h>

typedef struct _stack_elem {
    void *_data_arr;
    size_t size;
    // 以elem_size为单位
    int _top;
    size_t elem_size;
    // 以elem_size为单位
    size_t max_len;
} STACK;

STACK *init_stack(size_t elem_size, size_t stack_size);

void del_stack(STACK *stack);

_Bool stack_is_empty(STACK *stack);

_Bool stack_is_full(STACK *stack);

void push_stack(STACK *stack, void *data);

int pop_stack(STACK *stack, void *data);

int _resize_stack(STACK *stack, size_t max_len);


#endif //BASETEST_STACK_H
