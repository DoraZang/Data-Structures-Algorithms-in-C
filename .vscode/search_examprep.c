#include <assert.h>

// Linear search
// find(item, a, len) finds the index of item in a,
//   or returns -1 if it does not exist
// requires: len > 0
// time: O(n)
int find(int item, const int a[], int len) {
  assert(a);
  assert(len > 0);
	for (int i = 0; i < len; ++i) {
		if (a[i] == item) {
			return i;
		}
	}
	return -1;
}


// find_sorted(item, a, len) finds the index of item in a,
//   or returns -1 if it does not exist
// requires: a is sorted in ascending order [not asserted]
//           len > 0
// time: O(log n)
int find_sorted(int item, const int a[], int len) {
  assert(a);
  assert(len > 0); 
  int low = 0;
  int high = len - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == item) {
      return mid;
    } else if (a[mid] < item) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// Maximum subarray problem

// solution A: 外层循环控制前端点 中层控制后端点 内层控制加和 O(n^3)
// for every start position i and ending position j
//   loop between them (k) summing elements
int max_subarray(const int a[], int len) {
  assert(a);
  int maxsofar = 0;
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i; j < len; ++j) {
      sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += a[k]; 
      }
      maxsofar = max(maxsofar, sum);
    }
  }
  return maxsofar;
}

// solution B: 外层控制起始点 内层一边加一边往后遍历 O(n^2)
// for every start position i,
//   check if the sum from i...j is the max
int max_subarray(const int a[], int len) {
  assert(a);
  int maxsofar = 0;
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum = 0;
    for (int j = i; j < len; ++j) {
      sum += a[j];
      maxsofar = max(maxsofar, sum);
    }
  }
  return maxsofar;
}


// solution C: O(nlogn)
// 1.find the midpoint position m. 2.find (a)the maximum subarray from (0...m-1) (b)the maximum subarray from (m+1...len-1)
// 3.find (c) the maximum subarray that includes m. 4.find the maximum of (a)(b)(c)


//solution D: O(n)
// max(x, y) finds the max of x and y
int max(const int x, const int y){
  if(x > y){
    return x;
  } else{
    return y;
  }
}
// max_subarray(a, len) finds the maximum sum of any continguous subarray
//   of the elements of a
// requires: len > 0
// time: O(n)
int max_subarray(const int a[], int len) {
  assert(a);
  assert(len > 0);
  int maxsofar = 0;
  int maxendhere = 0;
  for (int i = 0; i < len; ++i) {
    maxendhere = max(maxendhere + a[i], 0);
    maxsofar = max(maxsofar, maxendhere);
  }
  return maxsofar;
}