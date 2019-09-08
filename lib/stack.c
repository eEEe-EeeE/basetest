//
// Created by someone on 2019/8/23.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <stack.h>

STACK *init_stack(size_t elem_size, size_t stack_size) {
    STACK *stack = (STACK *) malloc(sizeof(STACK));
    void *data_arr = malloc(elem_size * stack_size);
    if (stack != NULL && data_arr != NULL) {
        stack->_top = -1;
        stack->size = 0;
        stack->elem_size = elem_size;
        stack->max_len = stack_size;
        stack->_data_arr = data_arr;
        return stack;
    }
    return NULL;
}

void del_stack(STACK *stack) {
    free(stack->_data_arr);
    free(stack);
}

_Bool stack_is_empty(STACK *stack) {
    return stack->_top < 0;
}

_Bool stack_is_full(STACK *stack) {
    return stack->_top == stack->max_len - 1;
}

void push_stack(STACK *stack, void *data) {
    int permit_push = 0;
    if (stack_is_full(stack))
        permit_push = _resize_stack(stack, stack->max_len * 2);
    if (permit_push == 0) {
        memcpy(stack->_data_arr + (++(stack->_top) * stack->elem_size), data, stack->elem_size);
        stack->size += 1;
    }
}

int pop_stack(STACK *stack, void *data) {
    if (stack_is_empty(stack))
        return -1;
    memcpy(data, stack->_data_arr + ((stack->_top)-- * stack->elem_size), stack->elem_size);
    stack->size -= 1;
    return 0;
}

int _resize_stack(STACK *stack, size_t max_len) {
    void *new_data_arr = malloc(stack->elem_size * max_len);
    if (new_data_arr != NULL) {
        memcpy(new_data_arr, stack->_data_arr, stack->elem_size * stack->size);
        free(stack->_data_arr);
        stack->_data_arr = new_data_arr;
        stack->max_len = max_len;
        return 0;
    }
    return -1;
}
