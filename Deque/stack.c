#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "deque.h"
// your include goes here

typedef void* (*Copy_data) (const void*);
typedef void (*Destroy_data) (void*);
typedef void (*Print_data) (const void*);

struct Stack {
    struct Deque* deque;
};

struct Stack* stack_create(Copy_data copy, Destroy_data destroy, Print_data print) {
    // your implementation goes here
    return NULL;
}

void stack_destroy(struct Stack* stk) {
    // your implementation goes here
}

bool stack_empty(const struct Stack* stk) {
    // your implementation goes here
    return false;
}

void stack_push(struct Stack* stk, const void* data) {
    // your implementation goes here
}

void stack_pop(struct Stack* stk) {
    // your implementation goes here
}

void* stack_top(const struct Stack* stk) {
    // your implementation goes here
    return NULL;
}

void stack_print(const struct Stack* stk) {
    // your implementation goes here
}
