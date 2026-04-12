#include <stdlib.h>
#include <stdio.h>
// add your include here


// ================= DO NOT CHANGE THESE CODE ==================
struct Node {
    int val;
    struct Node* next;
};

// node_create(n):
//  creates a node in heap memory with val equals to n
// Effects: allocates memory
// Time: O(1)
static struct Node* node_create(int n) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = n;
    node->next = NULL;
    return node;
}

// node_destroy(node)
//  frees the linked list in heap memory
// Effects: de-allocates node
// Time: O(n)
static void node_destroy(struct Node* node) {
    while (node != NULL) {
        struct Node* temp = node->next;
        free(node);
        node = temp;
    }
}

// create_list(n)
//  converts arr into linked list by preserving the order of elements
// Effects: allocates memory, client must call node_destroy
// Time: O(n)
static struct Node* create_list(const int* arr, int len) {
    assert(len >= 1);

    struct Node* head = node_create(arr[0]);
    struct Node* tail = head;
    for (int i = 1; i < len; i++) {
        struct Node* node = node_create(arr[i]);
        tail->next = node;
        tail = node;
    }
    return head;
}

// print_list(node) prints the linked list
// Effects: produces output
// Time: O(n)
static void print_list(const struct Node* node) {
    if (node == NULL) return;
    printf("%d", node->val);
    const struct Node* curr = node->next;
    while (curr) {
        printf(" -> %d", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
// =============================================================

// reverse_list(root) reverses the linked list
// Effects: mutates *root
// Time: O(n)
void reverse_list(struct Node** root) {
    // your implementation goes here
}

// remove_duplicate(root) removes all nodes that contains duplicate val
// Effects: de-allocates memory
// Time: O(n)
void remove_duplicate(struct Node* root) {
    // your implementation goes here
}

// get_last(root) returns pointer to the last node in linked-list
// Time: O(n)
struct Node* get_last(struct Node* root) {
    // your implementation goes here
    return NULL;
}

// merge_two_sorted_lists(r1, r2)
//  combines two sorted linked-lists into one, and
//  returns the pointer to the head node of the combined linked-list
// Time: O(m + n)
struct Node* merge_two_sorted_lists(struct Node* r1, struct Node* r2) {
    // your implementation goes here
    return NULL;
}


// find_intersection(r1, r2) returns the pointer to the head node
//  of the intersection of two linked-list.
// Time: O(mn)
struct Node* find_intersection(struct Node* r1, struct Node* r2) {
    // your implementation goes here
    return NULL;
}

int main() {
    srand(time(NULL));
    printf("%d\n", rand() % 100);
}
