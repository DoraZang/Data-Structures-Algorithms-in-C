#ifndef __DEQUE_H__
#define __DEQUE_H__

/**
 * Doubly Linked-List
 * Working with void*
 */

#include <stdbool.h>

struct Deque;

// deque_create(copy, destroy, print) returns a pointer to heap allocated Deque
// Effects: allocates memory, caller must free
// Time: O(1)
struct Deque* deque_create(void* (*Copy_data) (const void*),
                           void  (*Destroy_data) (void*),
                           void  (*Print_data) (const void*));

// destroy_deque(deq) fress the heap allocated Deque
// Effects: frees memory
// Time: O(n)
void deque_destroy(struct Deque* deq);

// deque_empty(deq) returns true if deq is empty, and false otherwise
// Requires: deq is not NULL
// Time: O(1)
bool deque_empty(const struct Deque* deq);

// insert_front(deq, data) inserts data in front of deq
// Effects: mutates *deq
// Requires: deq is not NULL
// Time: O(1)
void insert_front(struct Deque* deq, const void* data);

// insert_back(deq, data) inserts data at back of deq
// Effects: mutates *deq
// Requires: deq is not NULL
// Time: O(1)
void insert_back(struct Deque* deq, const void* data);

// remove_front(deq) removes the front data from deq
// Effects: mutates *deq, de-allocates memory
// Requires: deq is not NULL and not empty
// Time: O(1)
void remove_front(struct Deque* deq);

// remove_back(deq) removes the back data from deq
// Effects: mutates *deq, de-allocates memory
// Requires: deq is not NULL and not empty
// Time: O(1)
void remove_back(struct Deque* deq);

// deque_front(deq) returns the front data of deq
// Effects: allocates memory
// Requires: deq is not NULL and not empty
//           client must call destroy on the returned pointer
// Time: O(1)
void* deque_front(const struct Deque* deq);

// deque_back(deq) returns the back data of deq
// Effects: allocates memory
// Requires: deq is not NULL and not empty
//           client must call destroy on the returned pointer
// Time: O(1)
void* deque_back(const struct Deque* deq);

// deque_print_forward(deq) prints the data in order
// Requires: deq is not NULL
// Time: O(n)
void deque_print_forward(const struct Deque* deq);

// deque_print_backward(deq) prints the data in reverse order
// Requires: deq is not NULL
// Time: O(n)
void deque_print_backward(const struct Deque* deq);

#endif

