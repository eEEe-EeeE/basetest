//
// Created by BPanther on 2019/8/3.
//

#ifndef BASETEST_UTILS_H
#define BASETEST_UTILS_H

// 函数返回指针，一定是指向堆中的内存
// 因而必须调用free释放函数返回的指针

// 泛型编程的三个要素：通用指针void *，mem函数，sizeof(elem)元素字节数目

int *fib_recur(int n);
int __fib_recur(int n, int *arr);

int fact_recur(int n);
int fact(int n);

void decompose_prime_factor(int n, int *prime_factors, int len, int *nums);

int binary_search_recur(void *arr, size_t len, size_t elem_size, int left, int right, void *key(void *));

int linear_search(void *arr, size_t len, size_t elem_size, void *key, void *elem_key(void *));


#endif //BASETEST_UTILS_H
