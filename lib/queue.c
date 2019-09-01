//
// Created by someone on 2019/8/23.
//

#include <stdbool.h>
#include <malloc.h>

#include <queue.h>

QUEUE *init_queue(size_t size) {
    QUEUE * q = (QUEUE *)malloc(sizeof(QUEUE));
    q->front = -1;
    q->rear = -1;
    q->len = 0;
    q->max_len = size;
    q->data_arr = (QUEUE_TYPE *)calloc(size, sizeof(QUEUE_TYPE));
    return q;
}

void del_queue(QUEUE *q) {
    free(q->data_arr);
    free(q);
}

_Bool queue_is_empty(const QUEUE *q) {
    return q->front == q->rear;
}

_Bool queue_is_full(const QUEUE *q) {
    return q->len == (int)q->max_len - 1;
}

_Bool push_queue(QUEUE *q, const QUEUE_TYPE *data) {
    if (queue_is_full(q))
        return false;
    else {
        q->rear = (q->rear + 1) % (int)q->max_len;
        (q->data_arr)[q->rear] = *data;
        return true;
    }
}

_Bool pop_queue(QUEUE *q, QUEUE_TYPE *data) {
    if (queue_is_empty(q))
        return false;
    else {
        q->front = (q->front + 1) % (int)q->max_len;
        *data = (q->data_arr)[q->front];
        return true;
    }
}