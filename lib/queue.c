//
// Created by someone on 2019/8/23.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <queue.h>

QUEUE *init_queue(size_t elem_size, size_t max_len) {
    QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
    void *data_arr = malloc(elem_size * (max_len + 1));
    if (queue != NULL && data_arr != NULL) {
        queue->_data_arr = data_arr;
        queue->_front = 0;
        queue->_rear = 0;
        queue->elem_size = elem_size;
        queue->size = 0;
        queue->max_len = max_len;
        return queue;
    }
    return NULL;
}

void del_queue(QUEUE *q) {
    free(q->_data_arr);
    free(q);
}

_Bool queue_is_empty(const QUEUE *q) {
    return q->size == 0;
}

_Bool queue_is_full(const QUEUE *q) {
    return q->size == (int) q->max_len;
}

void push_queue(QUEUE *queue, void *data) {
    int permit_push = 0;
    if (queue_is_full(queue))
        permit_push = _resize_queue(queue, queue->max_len * 2);
    if (permit_push == 0) {
        queue->_rear = (queue->_rear + 1) % (int) (queue->max_len + 1);
        memcpy(queue->_data_arr + queue->_rear * queue->elem_size, data, queue->elem_size);
        queue->size += 1;
    }
}

int pop_queue(QUEUE *queue, void *data) {
    if (queue_is_empty(queue))
        return -1;
    queue->_front = (queue->_front + 1) % (int) (queue->max_len + 1);
    memcpy(data, queue->_data_arr + queue->_front * queue->elem_size, queue->elem_size);
    queue->size -= 1;
    return 0;
}

int _resize_queue(QUEUE *queue, size_t max_len) {
    void *new_data_arr = malloc(queue->elem_size * (max_len + 1));
    if (new_data_arr != NULL) {
        if (queue->_front < queue->_rear) {
            memcpy(new_data_arr + queue->elem_size, queue->_data_arr + (queue->_front + 1) * queue->elem_size,
                   queue->size * queue->elem_size);
        } else {
            memcpy(new_data_arr + queue->elem_size, queue->_data_arr + (queue->_front + 1) * queue->elem_size,
                   (queue->max_len + 1 - queue->_front) * queue->elem_size);
            memcpy(new_data_arr + queue->elem_size + (queue->max_len + 1 - queue->_front) * queue->elem_size,
                   queue->_data_arr, (queue->_rear + 1) * queue->elem_size);
        }
        free(queue->_data_arr);
        queue->_front = 0;
        queue->_rear = queue->size;
        queue->max_len = max_len;
        queue->_data_arr = new_data_arr;
        return 0;
    }
    return -1;
}
