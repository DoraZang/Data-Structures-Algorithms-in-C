#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

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


// merge_v1(dest, src1, len1, src2, len2) modifies dest to contain
//   the elements from both src1 and src2 in sorted order
// requires: length of dest is at least (len1 + len2) [not asserted]
//           src1 and src2 are sorted [not asserted]
// effects: modifies dest
// time: O(n), where n is len1 + len2
void merge_v1(int dest[], const int src1[], int len1,
                       const int src2[], int len2) {
  assert(dest);
  assert(src1);
  assert(src2);
  int pos1 = 0;
  int pos2 = 0;
  for (int i = 0; i < len1 + len2; ++i) {
    if (pos1 == len1 || (pos2 < len2 && src2[pos2] < src1[pos1])) {
      dest[i] = src2[pos2];
      ++pos2;
    } else {
      dest[i] = src1[pos1];
      ++pos1;
    }
  }
}

// merge_v2(dest, src1, len1, src2, len2)
void merge_v2(int dest[], const int src1[], int len1,
              const int src2[], int len2) {
  int dest_pos = 0;
  int pos1 = 0;
  int pos2 = 0;
  while (pos1 < len1 && pos2 < len2) {
    if (src1[pos1] <= src2[pos2]) {
      dest[dest_pos] = src1[pos1];
      pos1++;
      dest_pos++;
    } else {
      dest[dest_pos] = src2[pos2];
      pos2++;
      dest_pos++;
    }
  }
  while (pos1 < len1) {
    dest[dest_pos] = src1[pos1];
    pos1++;
    dest_pos++;
  }
  while (pos2 < len2) {
    dest[dest_pos] = src2[pos2];
    pos2++;
    dest_pos++;
  }
}

// merge_sort(a, len) sorts the elements of a in ascending order
// requires: a is a valid array with given len [not asserted]
// effects: modifies a
void merge_sort(int a[], int len) {
  assert(a);
  if (len <= 1) {
    return;
  }
  int llen = len / 2;
  int rlen = len - llen;
  
  int *left = malloc(llen * sizeof(int));
  int *right = malloc(rlen * sizeof(int));
  
  for (int i = 0; i < llen; ++i) {
    left[i] = a[i];
  }
  for (int i = 0; i < rlen; ++i) {
    right[i] = a[i + llen];
  }
  
  merge_sort(left, llen);
  merge_sort(right, rlen);
  
  merge_v1(a, left, llen, right, rlen);
  
  free(left);
  free(right);
}