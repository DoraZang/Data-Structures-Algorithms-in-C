#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"

// ================= DO NOT CHANGE THESE LINES =================
static struct Node* node_create(const int num) {
    struct Node* node = malloc(sizeof(struct Node));
    node->key = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void node_destroy(struct Node* node) {
    if (node) {
        node_destroy(node->left);
        node_destroy(node->right);
        free(node);
    }
}

struct BST* bst_create() {
    struct BST* bst = malloc(sizeof(struct BST));
    bst->root = NULL;
    return bst;
}

void bst_insert(struct BST* bst, const int num) {
    assert(bst);

    struct Node* node = node_create(num);       // creates a new node
    // check if tree is empty
    if (bst->root == NULL) {
        bst->root = node;
        return;
    }

    struct Node* curr = bst->root;
    while (curr != NULL) {
        if (curr->key == num) {         // key exists
            node_destroy(node);
            break;
        } else if (curr->key < num) {   // go right
            if (curr->right != NULL) {
                curr = curr->right;
            } else {
                curr->right = node;
                break;
            }
        } else {                        // go left
            if (curr->left != NULL) {
                curr = curr->left;
            } else {
                curr->left = node;
                break;
            }
        }
    }
}

static struct Node* node_remove_key(struct Node* node, const int num) {
    if (node == NULL) return node;

    if (node->key < num) {          // go right
        node->right = node_remove_key(node->right, num);
    } else if (node->key > num) {   // go left
        node->left = node_remove_key(node->left, num);
    } else {                        // found the key
        if (node->left == NULL && node->right == NULL) {        // removing leaf node
            free(node);
            return NULL;
        }
        if (node->right == NULL) {                              // node does not have right child
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        if (node->left == NULL) {                               // node does not have left child
            struct Node* temp = node->right;
            free(node);
            return temp;
        }
        // neither child is not NULL, find left-most child in the right subtree
        struct Node* prev = NULL;
        struct Node* curr = node->right;
        while (curr->left != NULL) {
            prev = curr;
            curr = curr->left;
        }
        node->key = curr->key;
        if (prev == NULL) {
            node->right = curr->right;
        } else {
            prev->left = curr->right;
        }
        free(curr);
    }
    return node;
}

void bst_remove(struct BST* bst, const int num) {
    assert(bst);

    bst->root = node_remove_key(bst->root, num);
}
// =============================================================

void count_leaf(const struct BST* bst, int* leaf) {
    // your implementation goes here
}

void count_all(const struct BST* bst, int* leaf, int* total) {
    // your implementation goes here
}

struct Node* deepest_node(const struct BST* bst) {
    // your implementation goes here
    return NULL;
}

int bst_stats(const struct BST* bst, int* leaf, int* total) {
    // your implementation goes here
    return 0;
}

struct Node* bst_deepest_node(const struct BST* bst) {
    // your implementation goes here
    return NULL;
}

int* bst_to_sorted_array(const struct BST* bst, int* len) {
    // your implementation goes here
    return NULL;
}

struct BST* sorted_array_to_balanced_bst(int* arr, const int len) {
    // your implementation goes here
    return NULL;
}

void bst_destroy_recursive(struct BST* bst) {
    // your implementation goes here
}

void bst_destroy_iterative(struct BST* bst) {
    // your implementation goes here
}

