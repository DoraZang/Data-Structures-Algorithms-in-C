#ifndef __BST_H__
#define __BST_H__

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

// bst_create() returns a pointer to heap allocated BST
// Effects: allocates memory, caller must free
// Time: O(1)
struct BST* bst_create();

// bst_insert(bst, num) inserts num into bst
//  if num exists in bst already, bst remains the same
// Effects: may mutate *bst
// Time: O(log n) if bst is balanced, otherwise O(n)
void bst_insert(struct BST* bst, const int num);

// bst_remove(bst, num) removes num from bst
// if num does not exist in bst, bst remains the same
// Effects: may mutate *bst
// Time: O(log n) if bst is balanced, otherwise O(n)
void bst_remove(struct BST* bst, const int num);

// count_leaf(bst, leaf) stores the number of leaf nodes of bst in leaf
// Effects: mutates *leaf
// Requires: bst is not NULL, leaf is not NULL
// Time: O(n)
void count_leaf(const struct BST* bst, int* leaf);

// count_all(bst, leaf, total)
//  stores the number of leaf nodes of bst in leaf
//  stores the total number of nodes of bst in total
// Effects: mutates *leaf and *total
// Requires: bst is not NULL, leaf is not NULL, total is not NULL
// Time: O(n)
void count_all(const struct BST* bst, int* leaf, int* total);

// bst_stats(bst, leaf, total) returns the height of bst
//  stores the number of leaf nodes of bst in leaf
//  stores the total number of nodes of bst in total
// Effects: mutates *leaf and *total
// Requires: bst is not NULL, leaf is not NULL, total is not NULL
// Time: O(n)
int bst_stats(const struct BST* bst, int* leaf, int* total);

// bst_deepest_node(bst) returns the pointer to the deepest node in bst
//  returns NULL is bst is empty
//  if mulitple nodes are with the same depth, returns the rightmost one
// Requires: bst is not NULL
// Time: O(n)
struct Node* bst_deepest_node(const struct BST* bst);

// bst_to_sorted_array(bst, len) 
//  returns a dynamic array containing all keys in bst in ascending order
//  stores the length of array in len
// Effects: allocates memory, caller must free
//          mutates len
// Requires: bst is not NULL and bst is not empty
// Time: O(n)
int* bst_to_sorted_array(const struct BST* bst, int* len);

// sorted_array_to_balanced_bst(arr, len)
//  returns a balanced BST containing all elements in arr
// Effects: allocates memory, caller must free
// Requires: len > 0
// Time: O(n)
struct BST* sorted_array_to_balanced_bst(int* arr, const int len);

// bst_destroy_recursive(bst) frees the heap allocated bst
// Effects: frees memory
// Requires: use recursion only
// Time: O(n)
void bst_destroy_recursive(struct BST* bst);

// bst_destroy_iterative(bst) frees the heap allocated bst
// Effects: frees memory
// Requires: use iteration only
// Time: O(n)
void bst_destroy_iterative(struct BST* bst);

#endif
