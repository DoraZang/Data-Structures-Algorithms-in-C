#ifndef __CIRCULAR_ARRAY_H__
#define __CIRCULAR_ARRAY_H__

struct CircularArray;

// ca_create() returns a pointer to heap allocated Circular Array
// Effects: allocates memory, caller must free
// Time: O(1)
struct CircularArray* ca_create();

// ca_destroy(ca) fress the heap allocated Circular Array
// Effects: frees memory
// Time: O(1)
void ca_destroy(struct CircularArray* ca);

// insert_front(ca, num) inserts num in front of ca
// Effects: mutates *ca
// Requires: ca is not NULL
// Time: amoritized O(1)
void insert_front(struct CircularArray* ca, const int num);

// insert_back(ca, num) inserts num at back of ca
// Effects: mutates *ca
// Requires: ca is not NULL
// Time: amoritized O(1)
void insert_back(struct CircularArray* ca, const int num);

// remove_front(ca) removes the elements from back
// Effects: mutates *ca
// Requires: ca is not NULL
// Time: amoritized O(1)
void remove_front(struct CircularArray* ca);

// remove_back(ca) removes the elements in front
// Effects: mutates *ca
// Requires: ca is not NULL;
// Time: amortized O(1)
void remove_back(struct CircularArray* ca);

// get_front(ca) returns the front element of ca
// Requires: ca is not NULL and not empty
// Time: O(1)
int get_front(const struct CircularArray* ca);

// get_back(ca) returns the back element of ca
// Requires: ca is not NULL and not empty
// Time: O(1)
int get_back(const struct CircularArray* ca);

// ca_print(ca) prints all elements in ca from front to back
// Requires: ca is not NULL
// Time: O(n)
void ca_print(const struct CircularArray* ca);

#endif

