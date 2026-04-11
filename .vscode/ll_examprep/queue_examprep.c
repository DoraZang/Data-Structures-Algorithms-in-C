#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 6. Augmentation (数据结构增强：Length & Queue with Back Pointer)。
// Purpose: llist (Augmented with length) modifies the list wrapper to cache the node count. 
// list_length returns this cached value, making length lookups extremely fast instead of having 
// to traverse the whole list.
// Efficiency: O(1) time complexity for list_length (down from O(n)).
struct llnode {
    int data;            // "first" 
    struct llnode *next; // "rest" 
};

struct llist {
    struct llnode *front;
    int length; // 增强字段：缓存链表长度
};

int list_length (const struct llist *lst) {
    return lst->length;
}
// (注意：如果在结构体里加了 length，那么在你之前写的所有 insert 和 remove 函数里，
// 都必须相应地加上 ll->length++ 和 ll->length--，否则数据就不一致了。)


// Purpose: queue struct wraps the linked list and augments it with a back pointer. 
// This allows direct access to the tail of the list.
// Efficiency: O(1) space overhead for the structure.
struct queue {
    struct llnode *front;
    struct llnode *back;
};

// Purpose: queue_create allocates a new empty queue wrapper, 
// initializing both front and back pointers to NULL.
// Efficiency: O(1)
struct queue *queue_create(void) {
    struct queue *q = malloc(sizeof(struct queue));
    q->front = NULL;
    q->back = NULL;
    return q;
}

// Purpose: queue_add_back inserts a new node at the back of the queue. 
// Thanks to the back pointer, it avoids the O(n) traversal completely. 
// It handles the special case where the queue is empty (q->front == NULL).
// Efficiency: O(1)
void queue_add_back(int i, struct queue *q) {
    struct llnode *node = cons(i, NULL);
    
    if (q->front == NULL) { 
        q->front = node; 
    } else { 
        q->back->next = node; 
    }
    
    q->back = node; // 更新尾指针指向新节点
}

// Purpose: queue_remove_front removes the front item of the queue. 
// Crucially, it must also update the back pointer to NULL if removing the 
// last element makes the queue empty, otherwise back becomes a dangling pointer (野指针).
// Efficiency: O(1)
int queue_remove_front (struct queue *q) {
    assert(q->front);
    int retval = q->front->data;
    struct llnode *old_front = q->front;
    
    q->front = q->front->next;
    free(old_front);
    
    // 极其重要的边界情况处理
    if (q->front == NULL) q->back = NULL; 
    
    return retval;
}


// Purpose: queue_is_empty and queue_destroy are utility functions to check if the 
// queue is empty and to safely free all nodes along with the wrapper.
// Efficiency: O(1) for queue_is_empty, O(n) for queue_destroy.
bool queue_is_empty(struct queue *q) {
    return q->front == NULL;
}

void queue_destroy(struct queue *q) {
    while (!queue_is_empty(q)) {
        queue_remove_front(q);
    }
    free(q);
}
