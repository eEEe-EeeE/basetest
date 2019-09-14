//
// Created by BPanther on 2019/8/3.
//

#ifndef BASETEST_UTILS_H
#define BASETEST_UTILS_H

// 函数返回指针，一定是指向堆中的内存
// 因而必须调用free释放函数返回的指针

// 泛型编程的三个要素：通用指针void *，mem函数，sizeof(elem)元素字节数目

#include <mydef.h>

int *fib_recur(int n);

int __fib_recur(int n, int *arr);

int fact_recur(int n);

int fact(int n);

void decompose_prime_factor(int n, int *prime_factors, int len, int *nums);

int binary_search_recur(void *arr, size_t len, size_t elem_size, int left, int right, void *key(void *));

int linear_search(void *arr, size_t len, size_t elem_size, void *key);

// 字符串数组中查找字符串
int linear_search_str(char **pString, char *string);

// 字符串数字比较大小
int str_num_cmp(STRING str1, STRING str2);


#endif //BASETEST_UTILS_H
