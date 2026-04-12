#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
// add your include here


// ================= DO NOT CHANGE THESE LINES =================
typedef bool (*Predicate) (const void*, const void*);
// =============================================================


// shrink_array(arr, len, pred)
//  removes elements from arr that do not meeting the condition for pred
// Effects: may mutate *arr and *len
// Time: O(n)
void shrink_array(int** arr, int* len, Predicate pred) {
    // your implementation goes here
}


// insert_k(arr, len, k)
//  inserts k into the middle of every consecutive elemnts in arr
//  returns the new length of arr
// Effects: mutates *arr
// Time: O(n)
int insert_k(int* arr, int len, int k) {
    // your implementation goes here
    return 0;
}


// additiona(arr1, len1, arr2, len2, len)
//  returns a new array by adding arr1 and arr2
// Effects: allocates memory, mutates* len
// Time: O(n)
int* addition(const int* arr1, int len1, const int* arr2, int len2, int* len) {
    // your implementation goes here
    return NULL;
}


// pascal_triangle_row(n, len)
//  returns the nth row of pascal triangle
// Effects: allocates memory, mutates *len
// Time: O(n^2)
int* pascal_triangle_row(int n, int* len) {
    assert(n >= 1);
    // your implementation goes here
    return NULL;
}

// dominantIndex(arr, len)
//  returns the index of the largest element 
//  if it is at least twice as much as every other elements in arr, or returns -1 otherwise
// Time: O(n)
int dominantIndex(const int* arr, int len) {
    // your implementation goes here
    return -1;
}

int main(void) {

}
