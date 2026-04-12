#include <stdlib.h>
#include "circularArray.h"
// add your include here

// do not change the structure defintion
typedef struct CircularArray {
    int front;      // start index
    int back;       // end index
    int len;        // number of elements in array
    int cap;        // capacity of array
    int* data;      // dynamic array that stores data
} CA;

CA* ca_create() {
    // your implementation goes here
    return NULL;
}

void ca_destroy(struct CircularArray* ca) {
    // your implementation goes here
}

void insert_front(struct CircularArray* ca, const int num) {
    // your implementation goes here
}

void insert_back(struct CircularArray* ca, const int num) {
    // your implementation goes here
}

void remove_front(struct CircularArray* ca) {
    // your implementation goes here
}

void remove_back(struct CircularArray* ca) {
    // your implementation goes here
}

int get_front(const struct CircularArray* ca) {
    // your implementation goes here
    return 0;
}

int get_back(const struct CircularArray* ca) {
    // your implementation goes here
    return 0;
}

void ca_print(const struct CircularArray* ca) {
    // your implementation goes here
}

