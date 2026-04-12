#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "deque.h"
// your include goes here


// ================= DO NOT CHANGE THESE LINES =================
typedef void* (*Copy_data)    (const void*);
typedef void  (*Destroy_data) (void*);
typedef void  (*Print_data)   (const void*);
// =============================================================


struct Node {
    void* data;         // actual data stored
    struct Node* next;  // pointer to next node
    struct Node* prev;  // pointer to previous node
};


static struct Node* node_create(const void* data, Copy_data copy_func) {
    // your implementation goes here
    return NULL;
}


static void node_destroy(struct Node* node, Destroy_data destory_func) {
    // your implementation goes here
}


struct Deque {
    struct Node* head;
    struct Node* tail;
    Copy_data copy_func;
    Destroy_data destroy_func;
    Print_data print_func;
};


struct Deque* deque_create(Copy_data copy, Destroy_data destroy, Print_data print) {
    // your implementation goes here
    return NULL;
}


void deque_destroy(struct Deque* deq) {
    // your implementation goes here
}


bool deque_empty(const struct Deque* deq) {
    // your implementation goes here
    return false;
}


void insert_front(struct Deque* deq, const void* data) {
    // your implementation goes here
}


void insert_back(struct Deque* deq, const void* data) {
    // your implementation goes here
}


void remove_front(struct Deque* deq) {
    // your implementation goes here
}


void remove_back(struct Deque* deq) {
    // your implementation goes here
}


void* deque_front(const struct Deque* deq) {
    // your implementation goes here
    return NULL;
}


void* deque_back(const struct Deque* deq) {
    // your implementation goes here
    return NULL;
}


void deque_print_forward(const struct Deque* deq) {
    // your implementation goes here
}


void deque_print_backward(const struct Deque* deq) {
    // your implementation goes here
}
