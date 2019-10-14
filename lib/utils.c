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
    if (n == 1) {
        arr[0] = 1;
    } else if (n >= 2) {
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

/*
 * 质因数分解
 * @ n: 待分解的数
 * @ prime_factors: 用于返回质因数数组
 * @ len: 数组长度
 * @ nums: 用于返回质因数的数目
 */
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

/*
 * 二分搜索
 */
void *binary_search_recur(const void *key, const void *arr, size_t len, size_t elem_size,
                        int (*_PtFuncCompare)(const void *, const void *)) {
    return NULL;
}



/*
 * 线性搜索
 * arr是基本类型数组
 */
int linear_search(void *arr, size_t len, size_t elem_size, void *key) {
    void *cur_p;
    int index = -1;
    for (cur_p = arr; cur_p - arr != len; cur_p += elem_size) {
        ++index;
        if (!memcmp(cur_p, key, elem_size))
            return index;
    }
    return -1;
}

int linear_search_str(char **pString, char *string) {
    char **sp = NULL;
    int index = -1;
    for (sp = pString; *sp != NULL; ++sp) {
        ++index;
        if (!strcmp(string, *sp))
            return index;
    }
    return -1;
}

int str_num_cmp(STRING str1, STRING str2) {
    STRING end = NULL;
    return strtol(str1, &end, 10) - strtol(str2, &end, 10);
}

// 整数的快速排序
void qsort_by_arr(int *begin, size_t len, const void *_arr,
                  int (*_PtFuncCompare)(const void *, int, int)) {
    if (len > 1) {
        int base_point = _qsort_partition(begin, len, _arr, _PtFuncCompare);
        qsort_by_arr(begin, base_point, _arr, _PtFuncCompare);
        qsort_by_arr(begin + base_point + 1, len - (base_point + 1), _arr, _PtFuncCompare);
    }
}

int _qsort_partition(int *begin, size_t len, const void *_arr,
                     int (*_PtFuncCompare)(const void *, int, int)) {
    if (len > 1) {
        int base_point = (int) len - 1;
        int last_small = -1;
        int index = 0;

        int swap;

        while (index != (int) len) {
            if (_PtFuncCompare(_arr, begin[index], begin[base_point]) < 0) {
                swap = begin[++last_small];
                begin[last_small] = begin[index];
                begin[index] = swap;
            }
            ++index;
        }
        swap = begin[++last_small];
        begin[last_small] = begin[base_point];
        begin[base_point] = swap;
        return last_small;
    } else if (len == 1) {
        return 0;
    } else {
        return -1;
    }
}