#include <stdlib.h>
#include "sequence.h"
// add your include here

// ================= DO NOT CHANGE THESE LINES =================
typedef void* (*Copy_data)    (const void*);
typedef void  (*Destroy_data) (void*);
typedef void  (*Print_data)   (const void*);
// =============================================================


struct Sequence {
    Copy_data copy;
    Print_data print;
    Destroy_data destroy;
    // additional field definitions goes here
};


struct Sequence* seq_create(const int row, const int col, 
                            Copy_data copy, Print_data print, Destroy_data destroy) {
    // your implementation goes here
    return NULL;
}


void seq_destroy(struct Sequence* seq) {
    // your implementation goes here
}


void seq_insert_at(struct Sequence* seq, void* data, const int r, const int c) {
    // your implementation goes here
}


void* seq_remove_at(struct Sequence* seq, const int r, const int c) {
    // your implementation goes here
    return NULL;
}


void* seq_at(const struct Sequence* seq, const int r, const int c) {
    // your implementation goes here
    return NULL;
}


void seq_print(const struct Sequence* seq) {
    // your implementation goes here
}
