#ifndef __TRIE_H__
#define __TRIE_H__

#include <stdbool.h>

struct Trie;

// trie_create() returns a pointer to heapp allocated Trie
// Effects: allocates memory, caller must free
// Time: O(1)
struct Trie* trie_create();

// trie_destroy(trie) fress the heap allocated Trie
// Effects: frees memory
// Time: O(n * m) where
//  n is the number of words, 
//  m is maximum length of thw word
void trie_destroy(struct Trie* trie);

// count_word(trie) returns the number of words stored in trie
// Requires: trie is not NULL
// time: O(1)
int count_word(const struct Trie* trie);

// insert_word(trie, word) inserts word into trie
// Effects: may mutate *trie
// Requires: trie is not NULL, word is not NULL
// Time: O(m)
void insert_word(struct Trie* trie, const char* word);

// remove_word(trie, word) removes word from trie
//  also removes all useless nodes from trie
// Effects: may mutate *trie
// Requires: trie is not NULL, word is not NULL
// Time: O(m)
void remove_word(struct Trie* trie, const char* word);

// contain_word(trie, word)
//  returns true if word is in trie, otherwise false
// Requires: trie is not NULL, word is not NULL
// Time: O(m)
bool contain_word(const struct Trie* trie, const char* word);

// get_all_words(trie, len) returns all words stored in trie
//  words will be returned in ascending order
//  number of words will be stored in len
// Effects: allocates memory, caller must free
// Requires: trie is not NULL, len is not NULL
//           trie contains at least one word
// Time: O(n * m)
char** get_all_words(const struct Trie* trie, int* len);

#endif

