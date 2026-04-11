#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>


// 0. Generic quick sort 
// on the exam, use qsort from stdlib.h instead 
// ----------------------------------------------------
// --------- OUR GENERIC QUICKSORT IMPLEMENTATION -----
// ----------------------------------------------------
qsort(void *base, len, size, int(*cmp)(const void *, const void *))
1. void *base: 指向要排序的数组的第一个元素的指针 。
2. len: 数组中元素的数量（也就是长度）
3. size_t size: 数组中每个单独元素的大小（通常使用 sizeof() 来获取）。
4. int (*compar)(const void *, const void *): 一个指向泛型比较函数的指针 。这个函数用于定义两个元素之间的大小关系。

void generic_swap(void *a, void *b, size_t size){
  void *temp = malloc(size);
  memcpy(temp, a, size); // Copy '*a' to *temp
  memcpy(a, b, size);    // Copy '*b' to '*a'
  memcpy(b, temp, size); // Copy '*temp' to '*b'
  free(temp);
}

void quick_sort_range(void *a, int first, int last,
    size_t size, int (*compare)(const void *, const void *)) {
  if (last <= first) return;
  void *pivot = a + first * size;
  int pos = last;
  for (int i = last; i > first; --i) {
    if (compare(a + i * size, pivot) > 0) {
      generic_swap(a + pos * size, a + i * size, size);
      --pos;
    }
  }
  generic_swap(a + first * size, a + pos * size, size);
  quick_sort_range(a, first, pos - 1, size, compare);
  quick_sort_range(a, pos + 1, last, size, compare);
}

void quick_sort(void *a, int len,
      size_t size,
      int (*compare)(const void *, const void *)) {
  quick_sort_range(a, 0, len - 1, size, compare);
}

// ----------------------------------------------------
// --------- SOME GENERIC COMPARISON FUNCTIONS --------
// ----------------------------------------------------

int alphcmp(const void *a, const void *b) {
  char * const *A = a;
  char * const *B = b;
  return strcmp(*A, *B);
}

int lencmp(const void *a, const void *b) {
  char *const *A = a;
  char *const *B = b;
  int diff = strlen(*A) - strlen(*B);
  if (diff) return diff;
  else return strcmp(*A, *B);
}

int int_cmp(const void *v0, const void *v1) {
  const int *i0 = v0;
  const int *i1 = v1;
  return *i0 - *i1;
}

int lastdigit_cmp(const void *v0, const void *v1) {
  const int *i0 = v0;
  const int *i1 = v1;
  int last0 = *i0 % 10;
  int last1 = *i1 % 10;
  return last0 - last1;
}

// ----------------------------------------------------
// --------------- SOME HELPER FUNCTIONS --------------
// ----------------------------------------------------

void print_string_array(char **words, int len) {
  printf("[");
  for (int i=0; i<len; ++i) printf(" %s", words[i]);
  printf(" ]\n");
}

void print_int_array(int *arr, int len) {
  printf("[");
  for (int i=0; i<len; ++i) printf(" %d", arr[i]);
  printf(" ]\n");
}

bool compare_int_array(int *a, int *b, int len){
  for (int i = 0; i < len; ++i){
    if (a[i] != b[i]) return false;
  }
  return true;
}

bool compare_string_array(char **a, char **b, int len){
  for (int i = 0; i < len; ++i){
    if (strcmp(a[i], b[i]) != 0) return false;
  }
  return true;
}

// 1. Generic Algorithms: bsearch, map & max
// Purpose: bsearch is a built-in generic binary search function provided by <stdlib.h>. 
// It searches a sorted array for a key and returns a pointer to the found element (or NULL if not found). 
// It requires the same comparison function used to sort the array.
// Efficiency: O(\log n) time complexity
//bsearch直接调用就可以，但是保证数组是排好序的
bsearch(const void *key, const void *base, len, size, int (*compar)(const void *, const void *))
1. const void *key (查找目标): 指向你想要查找的那个值的指针。
注意，必须传地址（比如 &target），因为 bsearch 不知道你的数据是什么类型，它只能拿着这个地址去找对应的字节对比。
2. const void *base (数组基址): 指向要被搜索的数组的第一个元素的指针（比如 arr）。
3. len (元素个数): 数组中元素的总数量。
4. size (元素大小): 数组中每个单独元素所占的字节数（通常用 sizeof() 来求）。
5. int (*compar)(const void *, const void *) (比较函数): 一个指向泛型比较函数的指针。
它负责告诉 bsearch，你的 key 和数组里的某个元素到底谁大谁小。
// Assume int_cmp is already defined
int arr[9] = {80, 64, 81, 97, 36, 88, 13, 51, 62};

// 必须先排序
qsort(arr, 9, sizeof(int), &int_cmp); // arr 变成 [13, 36, 51, 62, 64, 80, 81, 88, 97]

int target = 51;
// bsearch 返回的是匹配元素的指针 (void *)
assert(bsearch(&target, arr, 9, sizeof(int), &int_cmp) == &arr[2]); 

target = 52;
assert(bsearch(&target, arr, 9, sizeof(int), &int_cmp) == NULL);


// Purpose: map is a higher-order generic function. It applies a given mutation function 
// (map_func) to every item in a generic array. Because it operates on generic memory, it uses 
// manual pointer arithmetic (p += size) to advance to the next element.
// Efficiency: O(n) time complexity (assuming the applied function is O(1)).
// 泛型 map 函数实现
void map(void *arr, int arr_len, int size, void (*map_func) (void *)) {
    void *p = arr;
    for (int i = 0; i < arr_len; ++i) {
        map_func(p);
        p += size; // 核心：因为不知道具体类型，必须手动加上 size 个字节来移动指针
    }
}

// 具体的辅助函数：将传入的 void * 转换为 int * 并平方
void sqrm(void *v) {
    int *n = v; 
    *n = (*n) * (*n);
}

int main(void) {
    int arr[5] = {2, 4, 6, 0, 1};
    map(arr, 5, sizeof(int), sqrm);
    // arr 现在变成了 [4, 16, 36, 0, 1]
}

// Purpose: generic_max (Slide 20 Exercise) iterates through a generic array to find the largest item. 
// It uses the provided comparison function f to determine which element is strictly greater.
// Efficiency: O(n) time complexity.
void *generic_max(void *arr, int n, int size, int (*f)(const void *, const void *)) {
    if (n <= 0) return NULL;
    
    void *max_ptr = arr; // 初始假设第一个元素是最大值
    void *current_ptr = arr + size; // 从第二个元素开始比较
    
    for (int i = 1; i < n; ++i) {
        // 如果 current_ptr 指向的值大于 max_ptr 指向的值 (返回 > 0)
        if (f(current_ptr, max_ptr) > 0) {
            max_ptr = current_ptr; // 更新最大值指针
        }
        current_ptr += size; // 指针向后移动一个元素的字节数
    }
    
    return max_ptr;
}

// 2. Generic Stack ADT (泛型栈)
// Purpose: The stack structure uses an array of void pointers (void **data) to store generic items. 
// Crucially, it stores a function pointer free_item which dictates how each specific item should be freed when the stack is destroyed. 
// Efficiency: O(1) space overhead for the wrapper.
struct stack {
    int len;
    int maxlen;
    void **data;                 // Heap array storing void pointers
    void (*free_item)(void *);   // Function pointer to free individual items
};

// Purpose: stack_create initializes the generic stack. It requires the client to pass a free_function so 
// the ADT knows how to clean up the items later. 
// Efficiency: O(1) time complexity.
struct stack *stack_create(void (*free_function)(void *)) {
    assert(free_function); // 必须提供释放函数
    
    struct stack *s = malloc(sizeof(struct stack));
    s->len = 0;
    s->maxlen = 1;
    s->data = malloc(s->maxlen * sizeof(void *));
    s->free_item = free_function; // 保存这个“清理秘籍”
    
    return s;
}

// Purpose: stack_destroy safely cleans up all memory. It loops through every stored generic item and 
// calls the stored free_item function on it before freeing the array and the wrapper itself. 
// Efficiency: O(n) time complexity.
void stack_destroy(struct stack *s) {
    assert(s);
    
    // 1. 先用客户端提供的函数，把栈里装的每一个物品清理掉
    for (int i = 0; i < s->len; ++i) {
        s->free_item(s->data[i]); 
    }
    
    // 2. 释放装物品的数组
    free(s->data);
    
    // 3. 释放栈的包装器本身
    free(s);
}

// Purpose: stack_push adds a generic item (a void * pointer) to the stack, using the standard dynamic array doubling strategy. 
// Efficiency: O(1) amortized time complexity.
void stack_push(void *item, struct stack *s) {
    assert(item);
    assert(s);
    
    if (s->len == s->maxlen) {
        s->maxlen *= 2;
        s->data = realloc(s->data, s->maxlen * sizeof(void *));
    }
    
    s->data[s->len] = item;
    s->len += 1;
}