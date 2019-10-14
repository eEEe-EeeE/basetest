//
// Created by BPanther on 2019/8/3.
//

#ifndef BASETEST_UTILS_H
#define BASETEST_UTILS_H

// 函数返回指针，一定是指向堆中的内存
// 因而必须调用free释放函数返回的指针

// 泛型编程的三个要素：通用指针void *，mem函数，sizeof(elem)元素字节数目

#include <mydef.h>

// 斐波那契
int *fib_recur(int n);

int __fib_recur(int n, int *arr);

// 阶乘
int fact_recur(int n);

int fact(int n);

// 分解质因数
void decompose_prime_factor(int n, int *prime_factors, int len, int *nums);

// 二分查找
void *binary_search_recur(const void *key, const void *arr, size_t len, size_t elem_size,
                          int (*)(const void *, const void *));

// 线性查找
int linear_search(void *arr, size_t len, size_t elem_size, void *key);

// 字符串数组中查找字符串
int linear_search_str(char **pString, char *string);

// 字符串数字比较大小
int str_num_cmp(STRING str1, STRING str2);

// 整数的快速排序，通过另一个数组对该数组排序
void qsort_by_arr(int *begin, size_t len, const void *_arr, int (*)(const void *, int, int));

int _qsort_partition(int *begin, size_t len, const void *_arr, int (*)(const void *, int, int));


#endif //BASETEST_UTILS_H
