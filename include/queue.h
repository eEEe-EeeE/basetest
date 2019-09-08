//
// Created by someone on 2019/8/23.
//

#ifndef BASETEST_QUEUE_H
#define BASETEST_QUEUE_H

#include <stddef.h>
#include <binary_tree.h>

typedef struct _queue_elem {
    void *_data_arr;
    // front指向队首元素的前一个
    int _front;
    // rear指向队尾元素
    int _rear;
    size_t size;
    size_t elem_size;
    size_t max_len;
} QUEUE;

QUEUE *init_queue(size_t elem_size, size_t size);

void del_queue(QUEUE *q);

_Bool queue_is_empty(const QUEUE *q);

_Bool queue_is_full(const QUEUE *q);

void push_queue(QUEUE *q, void *data);

int pop_queue(QUEUE *q, void *data);

int _resize_queue(QUEUE *queue, size_t max_len);

#endif //BASETEST_QUEUE_H
