# Data Structures & Algorithms in C

A collection of clean, well-documented implementations of core data structures and algorithms in C. Originally written as study material for a second-year computer science course (CS 136), this repository serves as a practical reference and portfolio demonstrating proficiency in C programming, memory management, and fundamental data structures.

---

## Contents

### Data Structures

| Structure | File | Description |
|---|---|---|
| Stack (int) | `.vscode/ADT_stack_examprep.c` | Array-backed stack with amortized O(1) push; includes iterative quicksort demo using an explicit stack |
| Stack (generic) | `.vscode/generic_examprep.c` | Type-safe `void*` stack with client-supplied free function |
| Singly Linked List | `.vscode/ll_examprep/ll_examprep.c` | Full linked list ADT: insert, remove, deep copy, recursive & iterative traversal |
| Queue | `.vscode/ll_examprep/queue_examprep.c` | O(1) enqueue/dequeue via front + back pointer augmentation |
| BST Dictionary | `.vscode/ll_examprep/dictionary_examprep.c` | Binary search tree keyed on `int`, storing `char*` values; full insert/lookup/remove |
| Binary Search Tree | `.vscode/ll_examprep/tree_examprep.c` | BST with height, leaf count, in-order validation, augmented count field, and O(h) `select` |
| Circular Array | `CircularArray/` | Deque-style circular buffer with amortized O(1) insert/remove at both ends |
| Doubly Linked Deque | `Deque/` | Generic doubly-linked deque with pluggable copy/destroy/print functions; Stack and Queue adapters built on top |
| Priority Queue | `PriorityQueue/` | Max-heap priority queue for a patient triage system; includes `heap_sort` |
| Trie | `Trie/` | 26-ary trie supporting insert, remove, membership test, and lexicographic retrieval |
| 2D Sequence | `Sequence/` | Generic 2D array-backed sequence with pluggable copy/destroy/print |

### Algorithms

| Algorithm | File | Time Complexity |
|---|---|---|
| Linear Search | `.vscode/search_examprep.c` | O(n) |
| Binary Search | `.vscode/search_examprep.c` | O(log n) |
| Maximum Subarray (Kadane's) | `.vscode/search_examprep.c` | O(n) |
| Selection Sort | `.vscode/sort_examprep.c` | O(n²) |
| Insertion Sort | `.vscode/sort_examprep.c` | O(n²) |
| Quicksort | `.vscode/sort_examprep.c` | O(n²) worst, O(n log n) avg |
| Merge Sort | `.vscode/sort_examprep.c` | O(n log n) |
| Generic Quicksort | `.vscode/generic_examprep.c` | O(n log n) avg |

### Programming Exercises

| File | Topics |
|---|---|
| `ProgrammingQuestions/arrays.c` | Array shrinking, in-place insertion, Pascal's triangle, dominance index |
| `ProgrammingQuestions/into-the-void.c` | Generic filter+sort, binary search, `and_map`, even-before-odd partition, deep copy |
| `ProgrammingQuestions/linked-lists.c` | Reversal, duplicate removal, merge of sorted lists, intersection |
| `ProgrammingQuestions/strings.c` | String appending, merge sort on strings, anagram detection, palindrome construction |

---

## Key Concepts Demonstrated

- **Manual memory management** — `malloc`, `realloc`, `free`; no memory leaks or dangling pointers
- **ADT design** — opaque structs, module-scoped helpers (`static`), clean separation of interface and implementation
- **Generics in C** — `void*` data, function pointers for compare/copy/destroy, mirroring `qsort`/`bsearch` conventions from `<stdlib.h>`
- **Pointer arithmetic** — byte-level traversal of generic arrays without VLAs
- **Recursion vs. iteration** — both styles shown side-by-side for destroy, traversal, and sort
- **Augmented data structures** — cached length, back pointer in queue, subtree count in BST for O(1)/O(h) queries

---

## Building

Each subdirectory contains its own `makefile`. To build any module:

```bash
cd BST          # or CircularArray, Deque, PriorityQueue, Trie, Sequence
make
```

All makefiles use `clang` with `-std=c99 -Wall -Werror=vla -fsanitize=address`.

**Requirements:** `clang`, `make`, and AddressSanitizer support (standard on macOS and most Linux distributions).

---

## Language & Tools

- **C99** (strict, no VLAs)
- **Clang** with AddressSanitizer
- Headers and implementations separated (`.h` / `.c`)
