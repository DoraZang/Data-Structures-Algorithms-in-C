#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


// 1. Basic Linked List Node & Creation (基础链表节点与创建)
// Purpose: Defines the basic linked list node structure in C.
// Efficiency: O(1) space per node.
struct llnode {
    int data;            // "first" 
    struct llnode *next; // "rest" 
};

// Purpose: cons creates a new linked list node by dynamically allocating memory, 
// setting its data, and linking it to the rest of the list.
// Efficiency: O(1) time complexity.
struct llnode *cons(int first, struct llnode *rest) {
    struct llnode *node = malloc(sizeof(struct llnode));
    node->data = first; 
    node->next = rest; 
    return node;
}

// 2. Recursive vs Iterative Traversal (递归遍历 vs 循环遍历)
// Purpose: llnode_destroy recursively frees the memory allocated for the linked list.
// Efficiency: O(n)
void llnode_destroy(struct llnode *node) {
    if (node == NULL) {
        // Base case is empty.
    } else {
        llnode_destroy(node->next);
        free(node);
    }
}

// Purpose: llnode_destroy iteratively frees 
// the memory allocated for the linked list using a loop.
// Efficiency: O(n)
void llnode_destroy (struct llnode *node) {
    while (node != NULL) {
        struct llnode *next = node->next;
        free(node);
        node = next;
    }
}

// Purpose: llnode_print recursively prints the linked list in "Racket style".
// Efficiency: O(n)
void llnode_print(const struct llnode *node) {
    if (node == NULL) {
        printf("empty");
    } else {
        printf("(cons %d ", node->data);
        llnode_print(node->next);
        printf(")");
    }
}

// Purpose: square_each recursively returns a NEW 
// linked list where each item has been squared (Functional approach).
// Efficiency: O(n)
// square_each(node) returns a NEW linked list where each
// item has been squared
struct llnode *square_each (const struct llnode *node) {
    if (node == NULL) {
        return NULL;
    } else {
        return cons (node->data * node->data, square_each(node->next));
    }
}

// Purpose: square_each_mutate iteratively mutates an 
// existing linked list by squaring each item (Imperative approach).
// Efficiency: O(n)
void square_each_mutate (struct llnode *node) {
    while (node != NULL) {
        node->data *= node->data;
        node = node->next;
    }
}

// 递归版本：原地平方
void square_each_mutate_rec(struct llnode *node) {
    // Base Case: 走到头了，直接结束
    if (node == NULL) {
        return; 
    }
    
    // Recursive Step:
    // 1. 直接修改当前原节点的值
    node->data = node->data * node->data;
    
    // 2. 递归处理剩下的链表
    square_each_mutate_rec(node->next);
}

// 3. Insertion Pitfalls & Double Pointers
// Purpose: llnode_insert_back is an INCORRECT attempt to insert at the back of a list. 
// It fails to update the original list if it is initially empty because node is just 
// a local copy of the pointer (pass-by-value stack frame issue).
// Efficiency: O(n)
void llnode_insert_back(int n, struct llnode *node) {
    if (node == NULL) { // empty list
        node = cons(n, NULL);
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = cons (n, NULL);
    }
}

// Purpose: double_ptr_insert_back corrects the insertion pitfall by passing a pointer to the pointer 
// of the first node (**ptr_to_node_ptr). This allows the function to successfully modify the actual 
// head pointer in the caller's scope when the list is empty.
// Efficiency: O(n)
void double_ptr_insert_back(int n, struct llnode **ptr_to_node_ptr){
    if (*ptr_to_node_ptr == NULL) {
        *ptr_to_node_ptr = cons(n, NULL);
    } else {
        struct llnode *node = *ptr_to_node_ptr;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = cons(n, NULL);
    }
}

// 4. The List Wrapper Strategy
// Purpose: llist and llnode structures define an opaque wrapper strategy. 
// The client only interacts with llist, keeping the internal llnode implementation 
// hidden (module scope).
// Efficiency: O(1) space overhead for the wrapper.


// in file llist.h (Header file exposed to client)
struct llist; 
struct llist *list_create(void);
void list_destroy (struct llist *ll);

// in file llist.c (Implementation file hidden from client)
struct llnode {
    int data;
    struct llnode *next;
};

struct llist {
    struct llnode *front;
};

// Purpose: list_create returns a new, empty linked list wrapper. 
// It allocates heap memory which the caller must eventually free using list_destroy.
// Efficiency: O(1) time complexity.
struct llist *list_create(void) {
    struct llist *llst = malloc(sizeof(struct llist));
    llst->front = NULL;
    return llst;
}

// Purpose: list_destroy cleans up the wrapper and all 
// its internal nodes by calling the recursive node destruction function we defined earlier.
// Efficiency: O(n) where $n$ is the number of nodes.
void list_destroy(struct llist *ll) {
    llnode_destroy(ll->front); // 假设 llnode_destroy 已经定义过了
    free(ll);
}

// Purpose: list_print prints the wrapped list. 
// It uses a static helper function llnode_print to do the actual recursive work, 
// keeping the helper hidden from the client.
// Efficiency: O(n)
static void llnode_print(const struct llnode *node) {
    if (node == NULL) {
        printf("empty");
    } else {
        printf("(cons %d ", node->data);
        llnode_print(node->next);
        printf(")");
    }
}

// list_print(ll) Print ll, "Racket-style".
void list_print(const struct llist *ll) {
    llnode_print(ll->front);
}


// Purpose: list_insert_front safely inserts an item at the front 
// of the wrapped list. It uses a static helper cons to create the node. 
// Notice we don't need double pointers anymore!
// Efficiency: O(1)
static struct llnode *cons (int first, struct llnode *rest) {
    struct llnode *node = malloc(sizeof(struct llnode));
    node->data = first;
    node->next = rest;
    return node;
}

void list_insert_front (struct llist *ll, int item) {
    ll->front = cons(item, ll->front);
}

// insert(i, slst) inserts i into sorted list slst
// requires: slst is sorted [not asserted]
// effects:  modifies slst
// time:     O(n), where n is the length of slst
void insert(int i, struct llist *slst) {
  if (slst->front == NULL || i < slst->front->data) {
    add_front(i, slst);
  } else {
    // find the node that will be "before" our insert
    struct llnode *before = slst->front;
    while (before->next && i > before->next->data) {
      before = before->next;
    }
    // now do the insert
    struct llnode *newnode = malloc(sizeof(struct llnode)); 
    newnode->data = i;
    newnode->next = before->next;
    before->next = newnode;
  }
}

// 5. Traversing and Operating on Wrapped Lists
// Purpose: list_length iteratively calculates the length of the list by 
// traversing the internal nodes with a while loop.
// Efficiency: O(n)
int list_length (const struct llist *lst) { //用循环
    int len = 0;
    struct llnode *node = lst->front;
    while (node) {
        ++len;
        node = node->next;
    }
    return len;
}

// Purpose: length_nodes and list_length recursively calculate the 
// length of the list. It uses a static helper function to recurse 
// on the llnode pointers, not the wrapper itself.
// Efficiency: O(n)
static int length_nodes (struct llnode *node, int sofar) { //用accumulator递归+wrapper
    if (node == NULL) {
        return sofar;
    }
    return length_nodes (node->next, sofar+1);
}

int list_length (struct llist *lst) {
    return length_nodes(lst->front, 0);
}


// Purpose: list_remove_front safely removes the first node 
// in the wrapped list, frees its memory, and returns its value.
// Efficiency: O(1)
int list_remove_front(struct llist *ll) {
    assert(ll);        // list is valid
    assert(ll->front); // list is not empty
    
    struct llnode *oldfront = ll->front;
    ll->front = ll->front->next;
    int val = oldfront->data;
    free (oldfront);
    return val;
}

// Purpose: list_remove_value searches for a specific value and removes 
// its node. To remove a node, it must find and mutate the next pointer of 
// the node that comes before it (prevnode).
// Efficiency: O(n)
bool list_remove_value (struct llist *lst, int val) {
    if (lst->front == NULL) return false;
    
    if (lst->front->data == val) {
        list_remove_front(lst);
        return true;
    }
    
    struct llnode *prevnode = lst->front;
    while (prevnode->next && val != prevnode->next->data) {
        prevnode = prevnode->next;
    }
    
    if (prevnode->next == NULL) return false;
    
    struct llnode *old_node = prevnode->next;
    prevnode->next = prevnode->next->next;
    free(old_node);
    
    return true;
}

// Purpose: list_cp_bad demonstrates a BAD (shallow) copy 
// of a list wrapper. It only copies the front pointer, 
// meaning the original list and the new list now share the exact same nodes 
// (mutating one will corrupt the other).
// Efficiency: O(1)
struct llist *list_cp_bad(struct llist *ll){
    struct llist *newlist = malloc(sizeof(struct llist));
    newlist->front = ll->front;
    return newlist;
}

// 5.5 Deep Copying Lists (深拷贝链表)
// Purpose: llnode_cp is a static recursive helper function that creates a deep copy of the raw nodes. 
// It allocates a brand new node (using cons) for every item in the original list, ensuring no nodes 
// are shared.
// Efficiency: O(n) time complexity (must visit every node)
static struct llnode *llnode_cp(const struct llnode *node) {
    // Base Case: 触底反弹
    if (node == NULL) {
        return NULL;
    } else {
        // Recursive Step: 复制当前节点的值，并把下一个节点的复制任务交给递归
        // 这里用 cons 创建了全新的节点，而不是直接复用 node 的指针
        return cons(node->data, llnode_cp(node->next));
    }
}

// Purpose: list_cp is the wrapper function exposed to the client. 
// It creates a completely independent copy of the given list ll, 
// including a new wrapper structure and deep-copied internal nodes.
// Efficiency: O(n)
struct llist *list_cp(const struct llist *ll) {
    // 1. 为新链表的 wrapper 申请全新内存
    struct llist *new_list = list_create(); 
    
    // 2. 调用递归 helper 函数深拷贝所有的内部节点
    new_list->front = llnode_cp(ll->front);
    
    return new_list;
}

// hard copy a linked list (iterative approach)
struct llist *list_cp(const struct llist *oldlist) {
    struct llist *newlist = list_create();
    if (oldlist->front) {
        list_insert_front(newlist, oldlist->front->data);
        const struct llnode *oldnode = oldlist->front->next;
        struct llnode *newnode = newlist->front;
        while(oldnode) {
            newnode->next = malloc(sizeof(struct llnode));
            newnode = newnode->next;
            newnode->data = oldnode->data;
            newnode->next = NULL;
            oldnode = oldnode->next;
        }
    }
    return newlist;
}