#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

struct Sequence;

// seq_create(row, col, print, destroy)
//  returns a pointer to heap allocated Sequence
// Effects: allocates memory, caller must free
// Time: O(row * col)
struct Sequence* seq_create(const int row, const int col,
                            void* (*Copy_data) (const void*),
                            void  (*Print_data) (const void*),
                            void  (*Destroy_data) (void*));

// seq_destroy(seq) fress the heap allocated seq
// Effects: frees memory
// Time: O(r * c * k) where O(k) is destroy
void seq_destroy(struct Sequence* seq);

// seq_insert_at(seq, data, r, c) inserts data at given row and column
//  data will be replaced if such position already contains an element
// Effects: mutates *seq
// Requires: seq is not NULL, 0 <= r < row, 0 <= c < col
// Time: O(k)
void seq_insert_at(struct Sequence* seq, void* data,
                   const int r, const int c);

// seq_remove_at(seq, r, c) removes and returns the data at given row and column
//  returns NULL if no element is at such position
// Effects: may mutate *seq
// Requires: seq is not NULL, 0 <= r < row, 0 <= c < col
// Time: O(k)
void* seq_remove_at(struct Sequence* seq, const int r, const int c);

// seq_at(seq, r, c) returns the data at given row and column
//  returns NULL if no element is at such position
// Requires: seq is not NULL, 0 <= r < row, 0 <= c < col
// Time: O(1)
void* seq_at(const struct Sequence* seq, const int r, const int c);

// seq_print(seq) prints the seq row by row
// Time: O(r * c * k) where O(k) is print
void seq_print(const struct Sequence* seq);

#endif

