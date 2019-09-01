//
// Created by someone on 2019/8/22.
//


#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <utils.h>
#include <stack.h>

int *fib_recur(int n) {
    if (n <= 0)
        return NULL;
    int *arr = (int *) malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);
    if (n == 1){
        arr[0] = 1;}
    else if (n >= 2) {
        arr[0] = 1;
        arr[1] = 1;
    }
    __fib_recur(n, arr);
    return arr;
}

int __fib_recur(int n, int *arr) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        if (arr[n - 1] > 0)
            return arr[n - 1];
        arr[n - 1] = __fib_recur(n - 1, arr) + __fib_recur(n - 2, arr);
        return arr[n - 1];
    }
}

int fact_recur(int n) {
    if (n == 1)
        return 1;
    else
        return n * fact_recur(n - 1);
}

int fact(int n) {
    STACK *stack = init_stack(sizeof(int), 1);
    int prod = 1;
    push_stack(stack, &prod);
    while (n >= 1) {
        pop_stack(stack, &prod);
        prod *= n;
        push_stack(stack, &prod);
        --n;
    }
    pop_stack(stack, &prod);
    return prod;
}

void decompose_prime_factor(int n, int *prime_factors, const int len, int *nums) {
    int merchant = n;
    int num = 2;
    int index = 0;

    while (num <= n / 2) {
        if (merchant % num == 0) {
            assert(index < len);
            prime_factors[index++] = num;
            merchant /= num;
        } else
            ++num;
    }
    *nums = index;
}