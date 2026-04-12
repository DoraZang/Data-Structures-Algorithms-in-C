#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

#define CMD_LEN 20
#define MAX_WORD_LEN 31

int main() {
    struct Trie* trie = trie_create();
    char input[CMD_LEN];
    char word[MAX_WORD_LEN];
    while (scanf("%s", input) > 0) {
        if (strcmp(input, "insert") == 0) {
            scanf("%s", word);
            insert_word(trie, word);
        } else if (strcmp(input, "remove") == 0) {
            scanf("%s", word);
            remove_word(trie, word);
        } else if (strcmp(input, "print") == 0) {
            int len = 0;
            char** words = get_all_words(trie, &len);
            for (int i = 0; i < len; i++) {
                printf("%s\n", words[i]);
                free(words[i]);
            }
            free(words);
        }
    }
    trie_destroy(trie);
}
