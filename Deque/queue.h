#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

struct Queue;

// queue_create(copy, destroy, print)
//  returns a pointer to heap allocated Queue
// Effects: allocates memory
// Time: O(1)
struct Queue* queue_create(void* (*Copy_data) (const void*),
                           void  (*Destroy_data) (void*),
                           void  (*Print_data) (const void*));

// queue_destroy(q) fress the heap allocated Queue
// Effects: frees memory
// Time: O(n);
void queue_destroy(struct Queue* q);

// queue_empty(q) returns true if q is empty
// Requires: q is not NULL
// Time: O(1)
bool queue_empty(const struct Queue* q);

// queue_enqueue(q, data) enqueues data onto q
// Effects: mutates *q
// Requires: q is not NULL
// Time: O(1)
void queue_enqueue(struct Queue* q, const void* data);

// queue_dequeue(q) pops the front data from q
// Effects: mutates *q, de-allocates memory
// Requires: q is not NULL and not empty
// Time: O(1)
void queue_dequeue(struct Queue* q);

// queue_front(q) returns the front data from q
// Requires: q is not NULL and not empty
//           client must call destroy on returned pointer
// Time: O(1)
void* queue_front(const struct Queue* q);

// queue_print(q) prints the queue from front to back
// Effects: produces output
// Requires: q is not NULL
// Time: O(n)
void queue_print(const struct Queue* q);

#endif

