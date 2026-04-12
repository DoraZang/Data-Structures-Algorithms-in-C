#include <stdlib.h>
#include "trie.h"
// add your include here

// ======================DO NOT MODIFY STRUCTURE DEFINTIONS ============================
typedef struct Node {
    bool end_word;
    struct Node* children[26];      // 26 lowercase letters
} Node;

typedef struct Trie {
    struct Node* root;
    int count;
} Trie;
// =====================================================================================

Trie* trie_create() {
    // your implementation goes here
    return NULL;
}

void trie_destroy(struct Trie* trie) {
    // your implementation goes here
}

int count_word(const struct Trie* trie) {
    // your implementation goes here
    return 0;
}

void insert_word(struct Trie* trie, const char* word) {
    // your implementation goes here
}

void remove_word(struct Trie* trie, const char* word) {
    // your implementation goes here
}

bool contain_word(const struct Trie* trie, const char* word) {
    // your implementation goes here
    return false;
}

char** get_all_words(const struct Trie* trie, int* len) {
    // your implementation goes here
    return NULL;
}
