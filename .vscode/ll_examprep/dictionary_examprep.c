#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct bstnode {
  int item;                // key
  char *value;             // additional value (augmentation)
  struct bstnode *left;
  struct bstnode *right;
};

struct dictionary {
  struct bstnode *root;
};

static char *my_strdup(const char *src) {
  assert(src);
  char *dup = malloc(strlen(src) * sizeof(char) + 1);
  strcpy(dup, src);
  return dup;
}

struct dictionary *dict_create(void) {
  struct dictionary *d = malloc(sizeof(struct dictionary));
  d->root = NULL;
  return d;
}

static void free_bstnode(struct bstnode *node) {
  if (node) {
    free_bstnode(node->left);
    free_bstnode(node->right);
    free(node->value);
    free(node);
  }
}

void dict_destroy(struct dictionary *d) {
  assert(d);
  free_bstnode(d->root);
  free(d);
}

const char *dict_lookup(int key, const struct dictionary *d) {
  assert(d);
  struct bstnode *node = d->root;
  while (node) {
    if (node->item == key) {
      return node->value;
    }
    if (key < node->item) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return NULL;
}

static struct bstnode *new_leaf(int key, const char *val) {
  assert(val);
  struct bstnode *leaf = malloc(sizeof(struct bstnode));
  leaf->item = key;
  leaf->value = my_strdup(val);    // make a copy
  leaf->left = NULL;
  leaf->right = NULL;
  return leaf;
}

void dict_insert(int key, const char *val, struct dictionary *d) {
  assert(val);
  assert(d);
  struct bstnode *node = d->root;
  struct bstnode *parent = NULL;
  while (node && node->item != key) {
    parent = node;
    if (key < node->item) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  if (node != NULL) { // key already exists at node
    free(node->value);
    node->value = my_strdup(val);
  } else if (parent == NULL) { // empty tree
    d->root = new_leaf(key, val);
  } else if (key < parent->item) {
    parent->left = new_leaf(key, val);
  } else {
    parent->right = new_leaf(key, val);
  }
}

void dict_remove(int key, struct dictionary *d) {
  assert(d);
  struct bstnode *target = d->root;
  struct bstnode *target_parent = NULL;
  // find the target (and its parent)
  while (target && target->item != key) {
    target_parent = target;
    if (key < target->item) {
      target = target->left;
    } else {
      target = target->right;
    }
  }
  if (target == NULL) {
    return; // key not found
  }
  // find the node to "replace" the target
  struct bstnode *replacement = NULL;
  if (target->left == NULL) {
    replacement = target->right;
  } else if (target->right == NULL) {
    replacement = target->left;
  } else {
    // neither child is NULL:
    // find the replacement node and its parent
    replacement = target->right;
    struct bstnode *replacement_parent = target;
    while (replacement->left) {
      replacement_parent = replacement;
      replacement = replacement->left;
    }
    // update the child links for the replacement and its parent
    replacement->left = target->left;
    if (replacement_parent != target) {
      replacement_parent->left = replacement->right;
      replacement->right = target->right;
    }
  }
  // free the target, and update the target's parent
  free(target->value);
  free(target);
  if (target_parent == NULL) {
    d->root = replacement;
  } else if (key > target_parent->item) {
    target_parent->right = replacement;
  } else {
    target_parent->left = replacement;
  }
}