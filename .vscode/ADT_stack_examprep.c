#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
// stack.c (IMPLEMENTATION)

struct stack {
  int len;
  int maxlen;
  int *data;
};

struct stack *create_stack(void) {
  struct stack *s = malloc(sizeof(struct stack));
  s->len = 0;
  s->maxlen = 1;
  s->data = malloc(s->maxlen * sizeof(int));
  return s;
}

// Time: O(1) [amortized]
void stack_push(int item, struct stack *s) {
  assert(s);
  if (s->len == s->maxlen) {
    s->maxlen *= 2;
    s->data = realloc(s->data, s->maxlen * sizeof(int));
  }
  s->data[s->len] = item;
  s->len += 1;
}

void stack_destroy(struct stack *s) {
  assert(s);
  free(s->data);
  free(s);
}

bool stack_is_empty(const struct stack *s) {
  assert(s);
  return s->len == 0;
}

int stack_top(const struct stack *s) {
  assert(s);
  assert(s->len);
  return s->data[s->len - 1];
}

int stack_pop(struct stack *s) {
  assert(s);
  assert(s->len);
  s->len -= 1;
  return s->data[s->len];
}

// quick sort for stack
// This is a DEMO of how to implement quicksort
// *WITHOUT* explicit recursion.

// we simulate recursion by using our own stack.
// we push the array range to be sorted (low & high)
// while stack is not empty, pop off a range and sort it

// swap(a, b) swaps the contents of *a and *b
// requires: a, b are valid pointers
// effects: modifies *a and *b
void swap(int *a, int *b) {
  assert(a);
  assert(b);
  int temp = *a;
  *a = *b;
  *b = temp;
}

// quick_sort(a, len) sorts the elements of a in ascending order
// requires: len > 0
// effects: modifies a
void quick_sort(int a[], int len) {
  assert(a);
  assert(len > 0);
  struct stack *s = create_stack();
  // PUSH low then high
  stack_push(0, s);            
  stack_push(len - 1, s);
  
  while (!stack_is_empty(s)) {
    // POP high then low (reverse order)
    int last = stack_pop(s);
    int first = stack_pop(s);
    
    // length is <= 1, so no need to sort
    if (last <= first) continue;
    
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // THIS PART IS IDENTICAL TO THE recursive quick_sort    
    int pivot = a[first];       // first element is the pivot
    int pos = last;             // where to put next larger
    for (int i = last; i > first; --i) {
      if (a[i] > pivot) {
        swap(&a[pos], &a[i]);
        --pos;
      }
    }
    swap(&a[first], &a[pos]);   // put pivot in correct place
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    // now we push the two sub-regions on to the stack
    stack_push(first, s);
    stack_push(pos-1, s);
    stack_push(pos+1, s);
    stack_push(last, s);
  }    
  stack_destroy(s);
}