#include <stdbool.h>
#include <stdlib.h>
// add your include here


// ================= DO NOT CHANGE THESE LINES =================
typedef int  (*Compare)   (const void*, const void*);
typedef bool (*Predicate) (const void*, const void*);
// =============================================================


// filter_greater_sort(arr, len, size, data, compare)
//  modifies arr by only keeping and sorting elements that are strictly greater than data
//  returns the new length of arr
// Effects: mutates arr
// Time: O(n log n)
int filter_greater_sort(void* arr, int len, int size, const void* data, Compare compare) {
    // your implementation goes here
    return 0;
}


// find_index(arr, len, size, data, compare)
//  returns the index of data in arr if exists, otherwise returns -1
// Time: O(log n)
int find_index(const void* arr, int len, int size, const void* data, Compare compare) {
    // your implementation goes here
    return 0;
}


// and_map(arr, len, size, pred)
//  returns true if every two consecutive elements in the array meet the condition for pred
// Time: O(n)
bool and_map(const void* arr, int len, int size, Predicate pred) {
    // your implementation goes here
    return false;
}


// even_before_odd(arr, len)
//  sorts arr by meeting the following criteria:
//  1. all integers are sorted in ascending orders
//  2. all even integers are before all odd integers
// Time: O(n log n)
void even_before_odd(void* arr, int len) {
    // your implementation goes here
}


// deep_copy_arr(arr, len, size)
//  returns a new array that contains exactly the same data as arr
// Effects: allocates memory
// Time: O(n)
void* deep_copy_arr(const void* arr, int len, int size) {
    // your implementation goes here
    return NULL;
}

int main(void) {
    // Test your code here
}
