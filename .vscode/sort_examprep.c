#include <assert.h>

void swap(int *a, int *b) {
  assert(a);
  assert(b);
  int temp = *a;
  *a = *b;
  *b = temp;
}

// selection_sort(a, len) sorts the elements of a
//   in increasing order
// requires: len > 0
// effects: modifies a
// time: O(n^2)
void selection_sort(int a[], int len) {
  assert(a);
  assert(len > 0);
  for (int i = 0; i < len - 1; ++i) {
    int pos = i;
    for (int j = i + 1; j < len; ++j) {
      if (a[j] < a[pos]) {
        pos = j;
      }
    }
    swap(&a[i], &a[pos]);  // see Section 04
  }
}


// insertion_sort(a, len) sorts the elements of a
//   in increasing order
// requires: len > 0
// effects: modifies a
// time: O(n^2)
void insertion_sort(int a[], int len) {
  assert(a);
  assert(len > 0); 
  for (int i = 1; i < len; ++i) {
    for (int j = i; j > 0 && a[j - 1] > a[j]; --j) {
      swap(&a[j], &a[j - 1]);
    }
  }
}


// quick_sort_range(a, first, last) sorts the elements of
//   a in the range a[first]..a[last] (inclusive)
//   in ascending order
// requires: a is a valid array in the range first..last [not asserted]
// effects: modifies a
// time: O(n^2)
void quick_sort_range(int a[], int first, int last) {
  assert(a);
  if (last <= first) return;  // length is <= 1
  
  int pivot = a[first];       // first element is the pivot
  int pos = last;             // where to put next larger
  
  for (int i = last; i > first; --i) {
    if (a[i] > pivot) {
      swap(&a[pos], &a[i]);
      --pos;
    }
  }
  swap(&a[first], &a[pos]);   // put pivot in correct place
  quick_sort_range(a, first, pos - 1);
  quick_sort_range(a, pos + 1, last);
}

// quick_sort(a, len) sorts the elements of a in ascending order
// requires: len > 0
// effects: modifies a
void quick_sort(int a[], int len) {
  assert(a);
  assert(len > 0);  
  quick_sort_range(a, 0, len - 1);
}