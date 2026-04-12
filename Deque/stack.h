#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

struct Stack;

// stack_create(copy, desotry, print) 
//  returns a pointer to heap allocated Stack
// Effects: allocates memory, caller must free
// Time: O(1)
struct Stack* stack_create(void* (*Copy_data) (const void*),
                           void  (*Destroy_data) (void*),
                           void  (*Print_data) (const void*));
                           
// stack_destroy(stk) fress the heap allocated Stack
// Effects: frees memory
// Time: O(n)
void stack_destroy(struct Stack* stk);

// stack_empty(stk) returns true if stk is empty
// Requires: stk is not NULL
// Time: O(1)
bool stack_empty(const struct Stack* stk);

// stack_push(stk, data) pushes data onto stk
// Effects: mutates *stk
// Requires: stk is not NULL
// Time: O(1)
void stack_push(struct Stack* stk, const void* data);

// stack_pop(stk) pops and returns the top data from stk
// Effects: mutates *stk, de-allocates memory
// Requires: stk is not NULL and not empty
// Time: O(1)
void stack_pop(struct Stack* stk);

// stack_top(stk) returns the top data from stk
// Requires: stk is not NULL and not empty
//           client must call destroy on returned pointer
// Time: O(1)
void* stack_top(const struct Stack* stk);

// stack_print(stk) prints the stack from top to bottom
void stack_print(const struct Stack* stk);

#endif

