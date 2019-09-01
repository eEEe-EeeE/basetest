//
// Created by someone on 2019/8/23.
//

#ifndef BASETEST_QUEUE_H
#define BASETEST_QUEUE_H

#include <stddef.h>
#include <binary_tree.h>

#define QUEUE_TYPE BTREE

typedef struct __queue_elem {
    QUEUE_TYPE *data_arr;
    int front;
    int rear;
    size_t len;
    size_t max_len;
} QUEUE;

QUEUE *init_queue(size_t size);

void del_queue(QUEUE *q);

_Bool queue_is_empty(const QUEUE *q);

_Bool queue_is_full(const QUEUE *q);

_Bool push_queue(QUEUE *q, const QUEUE_TYPE *data);

_Bool pop_queue(QUEUE *q, QUEUE_TYPE *data);


#endif //BASETEST_QUEUE_H
