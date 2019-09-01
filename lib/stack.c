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
        stack->top = -1;
        stack->elem_size = elem_size;
        stack->max_len = stack_size;
        stack->data_arr = data_arr;
        return stack;
    }
    return NULL;
}

void del_stack(STACK *stack) {
    free(stack->data_arr);
    free(stack);
}

_Bool stack_is_empty(STACK *stack) {
    return stack->top < 0;
}

_Bool stack_is_full(STACK *stack) {
    return stack->top == stack->max_len - 1;
}

void push_stack(STACK *stack, void *data) {
    memcpy(stack->data_arr + (++(stack->top) * stack->elem_size), data, stack->elem_size);
}

void pop_stack(STACK *stack, void *data) {
    memcpy(data, stack->data_arr + ((stack->top)-- * stack->elem_size), stack->elem_size);
}
