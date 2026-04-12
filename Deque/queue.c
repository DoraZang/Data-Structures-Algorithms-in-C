#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "deque.h"

typedef void* (*Copy_data) (const void*);
typedef void (*Destroy_data) (void*);
typedef void (*Print_data) (const void*);

struct Queue {
    struct Deque* deque;
};

struct Queue* queue_create(Copy_data copy, Destroy_data destroy, Print_data print) {
    // your implementation goes here
    return NULL;
}

void queue_destroy(struct Queue* q) {
    // your implementation goes here
}

bool queue_empty(const struct Queue* q) {
    // your implementation goes here
    return false;
}

void queue_enqueue(struct Queue* q, const void* data) {
    // your implementation goes here
}

void queue_dequeue(struct Queue* q) {
    // your implementation goes here
}

void* queue_front(const struct Queue* q) {
    // your implementation goes here
    return NULL;
}

void queue_print(const struct Queue* q) {
    // your implementation goes here
}
