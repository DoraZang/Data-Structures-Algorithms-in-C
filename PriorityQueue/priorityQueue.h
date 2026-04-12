#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

struct PriorityQueue;

// pq_create() creates a heap allocated priority queue
// Effects: allocates memory, caller must free
// Time: O(1)
struct PriorityQueue* pq_create();

// pq_destroy(pq) frees the heap allocated pq
// Effects: deallocates memory
// Time: O(n)
void pq_destroy(struct PriorityQueue* pq);

// pq_size(pq) returns the number of names stored in pq
// Requires: heap is not NULL
// Time: O(1)
int pq_size(const struct PriorityQueue* pq);

// pq_insert(pq, priority, name) inserts name and its priority into pq
//  priroity with 5 has a higher priority with 3
//  if priority already exists, then it follows "First in First Out" rule
// Effects: mutates *pq
// Requires: pq is not NULL, name is not NULL, priority >= 1
// Time: amoritized(log n + m)
void pq_insert(struct PriorityQueue* pq, int priority, const char* name);

// pq_remove(pq) removes and returns the name with the highest priority
//  writes the removed priority into *priority
// Effects: mutates *pq, mutates *priority
// Requires: pq is not NULL and not empty, priority is not NULL
//           caller must free returned pointer
// Time: O(log n)
char* pq_remove(struct PriorityQueue* pq, int* priority);

// heap_sort(names, priorities, len) uses heap to sort the two arrays
//  both arrays have same length, and each name in names is associated with the
//  priority at the same index in priorities
// Effects: mutates* names and *priorities
// Requires:names != NULL and priorities != NULL and len > 0
// Time: O(n log n)
void heap_sort(char** names, int* priorities, int len);

#endif

