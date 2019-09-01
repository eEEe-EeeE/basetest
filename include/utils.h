//
// Created by BPanther on 2019/8/3.
//

#ifndef BASETEST_UTILS_H
#define BASETEST_UTILS_H

// 函数返回指针，一定是指向堆中的内存
// 因而必须调用free释放函数返回的指针

int *fib_recur(int n);
int __fib_recur(int n, int *arr);

int fact_recur(int n);
int fact(int n);

void decompose_prime_factor(int n, int *prime_factors, int len, int *nums);


#endif //BASETEST_UTILS_H
