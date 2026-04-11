#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// 1. Generic Algorithms: bsearch, map & max
// Purpose: bsearch is a built-in generic binary search function provided by <stdlib.h>. 
// It searches a sorted array for a key and returns a pointer to the found element (or NULL if not found). 
// It requires the same comparison function used to sort the array.
// Efficiency: O(\log n) time complexity
//bsearch直接调用就可以，但是保证数组是排好序的
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