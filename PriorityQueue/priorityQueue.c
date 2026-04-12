#include <stdlib.h>
#include "priorityQueue.h"
// add your include here

// ======================DO NOT MODIFY STRUCTURE DEFINTIONS ============================
typedef struct Patient {
    int priority;
    int time_stamp;         // think the purpose of this field
    char* name;
} Patient;

typedef struct PriorityQueue {
    int len;
    int cap;
    int curr_time_stamp;    // think the purpose of this field
    struct Patient** patients;
} PQ;
// =====================================================================================

PQ* pq_create() {
    // your implementation goes here
    return NULL;
}

void pq_destroy(PQ* pq) {
    // your implementation goes here
}

int pq_size(const PQ* pq) {
    // your implementation goes here
    return 0;
}

void pq_insert(PQ* pq, int priority, const char* name) {
    // your implementation goes here
}

char* pq_remove(PQ* pq, int* priority) {
    // your implementation goes here
    return NULL;
}

void heap_sort(char** names, int* priorities, int len) {
    // your implementation goes here
}
