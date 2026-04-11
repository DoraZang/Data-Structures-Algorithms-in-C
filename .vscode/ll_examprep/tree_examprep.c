#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 7. Binary Search Trees (BSTs)
// Purpose: bstnode and bst structures define the Binary Search Tree using a wrapper strategy.
// Efficiency: $O(1)$ space overhead per node.
struct bstnode {
    int item;
    struct bstnode *left;
    struct bstnode *right;
};

struct bst {
    struct bstnode *root;
};

struct bt {
    struct bstnode *root;
};

// Purpose: bst_make and bst_destroy create a new BST wrapper and clean up the tree and wrapper, 
// respectively. bstnode_destroy is the recursive helper function for destroying the tree nodes.
// Efficiency: Creation is O(1); 
//             Destruction is O(n) where n is the number of nodes.
void bstnode_destroy(struct bstnode *n) {
    if (n != NULL) {
        bstnode_destroy(n->left);
        bstnode_destroy(n->right);
        free(n);
    }
}

struct bst *bst_make(void) {
    struct bst *b = malloc(sizeof(struct bst));
    b->root = NULL;
    return b;
}

void bst_destroy (struct bst *b) {
    assert(b);
    bstnode_destroy(b->root);
    free(b);
}

// Purpose: bst_print and bstnode_print recursively print the contents of a BST, 
// indenting based on depth (prints sideways).
// Efficiency: O(n) since it visits every node.
void bstnode_print(struct bstnode *n, int depth) {
    if (n != NULL) {
        bstnode_print(n->right, depth + 1);
        // indent neatly:
        for (int i=0; i < depth; ++i) printf("  ");
        printf("%d\n", n->item);
        bstnode_print(n->left, depth + 1);
    }
}

void bst_print(struct bst *b) {
    if (b->root == NULL) printf("Empty tree\n");
    else bstnode_print(b->root, 0);
}


// Purpose: bst_insert and bstnode_insert recursively insert a new value into the 
// BST while maintaining the ordering property (smaller values to the left, larger to the right).
// Efficiency: O(h) where h is the height of the tree.
struct bstnode *make_leaf (int item) {
    struct bstnode *leaf = malloc(sizeof(struct bstnode));
    leaf->item = item;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

void bstnode_insert(struct bstnode *n, int item) {
    if (item < n->item) { // must insert to the left
        if (n->left == NULL) {
            n->left = make_leaf(item);
        } else {
            bstnode_insert(n->left, item);
        } 
    } else if (item > n->item) { // must insert to the right
        if (n->right == NULL) {
            n->right = make_leaf (item);
        } else {
            bstnode_insert(n->right, item);
        } 
    }
}

void bst_insert(struct bst *b, int item) {
    if (b->root == NULL) {
        b->root = make_leaf(item);
    } else {
        bstnode_insert(b->root, item);
    }
}

// Purpose: bst_insert (Iterative Version) iteratively inserts a new 
// value into the BST. It tracks the parent node while traversing to correctly attach the new leaf.
// Efficiency: O(h) where $h$ is the height of the tree.
void bst_insert(int i, struct bst *t) { // 注意：这里的参数顺序和上面的递归版本不同
    struct bstnode *node = t->root;
    struct bstnode *parent = NULL;
    
    while (node) {
        if (node->item == i) return; // 假设不插入重复值
        parent = node;
        if (i < node->item) node = node->left;
        else node = node->right;
    }
    
    if (parent == NULL) { // tree was empty
        t->root = make_leaf(i); 
    } else if (i < parent->item) {
        parent->left = make_leaf(i);
    } else {
        parent->right = make_leaf(i);
    }
}

// is_bst determine if a bt is a bst
bool is_bst_helper(struct bstnode *node, int min, int max) {
    if (node == NULL) {
        return true;
    }
    if (node->item <=min || node->item >= max) {
        return false;
    }
    return is_bst_helper(node->left, min, node->item) && 
            is_bst_helper(node->right, node->item, max);
}

bool is_bst(struct bt *bt) {
    if (bt == NULL) {
        return true;
    }
    return is_bst_helper(bt->root, INT_MIN, INT_MAX);
}

// 方法二：中序遍历法 (In-order Traversal)
// Purpose: is_bst_inorder_helper recursively performs an in-order traversal. 
// It uses a double pointer prev to track the previously visited node and ensures 
// that every current node's item is strictly greater than the previous node's item.
// Efficiency: O(n) time complexity as it visits each node at most once

// 这是一个辅助函数，执行中序遍历并检查递增性质
// 参数 prev 是一个指向指针的指针，用于在递归调用中持续追踪上一个访问的节点
static bool is_bst_inorder_helper(struct bstnode *node, struct bstnode **prev) {
    // Base Case: 空节点是合法的
    if (node == NULL) {
        return true;
    }
    
    // 1. 遍历左子树 (Left)
    // 如果左子树已经发现不是 BST，直接返回 false，提前终止
    if (!is_bst_inorder_helper(node->left, prev)) {
        return false;
    }
    
    // 2. 检查当前节点 (Root)
    // 如果 prev 不是 NULL（说明这不是整棵树最左下的第一个节点）
    // 并且当前节点的值 <= 上一个节点的值，破坏了递增规则！
    if (*prev != NULL && node->item <= (*prev)->item) {
        return false;
    }
    
    // 检查通过，把当前节点变成新的 "上一个节点"，然后再去遍历右子树
    *prev = node;
    
    // 3. 遍历右子树 (Right)
    return is_bst_inorder_helper(node->right, prev);
}

// Purpose: `is_bst_inorder` is the wrapper function exposed to the client.
bool is_bst_inorder(struct bst *t) {
    if (t == NULL) return true;
    
    // 初始化 prev 为 NULL，因为还没开始遍历，没有"上一个节点"
    struct bstnode *prev = NULL;
    
    // 注意这里传入的是 prev 的地址 (&prev)，所以形参是 struct bstnode **
    return is_bst_inorder_helper(t->root, &prev);
}

void pre_order(struct bstnode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->item);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(struct bstnode *root) {
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    printf("%d ", root->item);
    in_order(root->right);
}

void post_order(struct bstnode *root) {
    if (root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->item);
}


// remove a node from a bst
struct bstnode *find_min(struct bstnode *node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct bstnode *remove_node(struct bstnode *node, int val) {
    if (node == NULL) {
        return node;
    }
    if (node->item == val) {
        if(node->left == NULL) {
            struct bstnode *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct bstnode *temp = node->left;
            free(node);
            return temp;
        }
        struct bstnode *temp = find_min(node->right);
        node->item = temp->item;
        node->right = remove_node(node->right, temp->item);

    } else if (val < node->item) {
        remove_node(node->left, val);
    } else {
        remove_node(node->right, val);
    }
    return node;
}

void bst_remove(struct bst *t, int val) {
    assert(t);
    t->root = remove_node(t->root, val);
}

// 对一个bt镜像翻转
void invert_tree(struct bstnode *node) {
    if (node == NULL) {
        return;
    }
    invert_tree(node->left);
    invert_tree(node->right);
    struct bstnode *temp = node->left;
    node->left = node->right;
    node->right = temp;

}

//计算bt的高度
int bst_height(struct bstnode *node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = bst_height(node->left);
    int right_height = bst_height(node->right);
    return 1 + max(left_height, right_height); 
}

//计算bt leaves的数量
int bt_leaf_count(struct bstnode *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    return bt_leaf_count(node->left) + bt_leaf_count(node->right);
}

//判断两个bt是否完全相同
bool is_tree_equal(struct bstnode *t1, struct bstnode *t2) {
    if (t1 == NULL && t2 == NULL) {
        return true;
    } else if ((t1 != NULL && t2 == NULL) || (t2 != NULL && t1 == NULL)) {
        return false;
    }
    return (t1->item == t2->item && is_tree_equal(t1->left, t2->left) && is_tree_equal(t1->right, t2->right));
}

int bt_sum(struct bstnode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->item + bt_sum(node->left) + bt_sum(node->right);
}
// 8. Augmented BST (增强二叉搜索树)

// Purpose: bstnode (Augmented with count) modifies the BST node to store the 
// count (number of nodes) in its entire subtree. This augmentation allows 
// retrieving the tree size in O(1) time and finding the $k$-th element efficiently.
// Efficiency: O(1) space overhead per node.
struct bstnode {
    int item;
    struct bstnode *left;
    struct bstnode *right;
    int count; //*****NEW
};

static struct bstnode *new_leaf(int i) {
  struct bstnode *leaf = malloc(sizeof(struct bstnode)); 
  leaf->item = i;
  leaf->count = 1;
  leaf->left = NULL;
  leaf->right = NULL;
  return leaf;
}


// update_count(node) updates the count augmentation
// effects: mutates node->count
static void update_count(struct bstnode *node) {
  if (node) {
    node->count = 1;
    if (node->left) node->count += node->left->count;
    if (node->right) node->count += node->right->count;
  }
}


// Purpose: select_node and bst_select find the item with index k in the tree, 
// where the index is the position in the sorted order of the items (e.g., select(0) finds the smallest item). 
// It cleverly uses the count of the left subtree to decide whether to search left, right, or return the current node, 
// bypassing the need to traverse the entire tree.
// Efficiency: O(h) where h is the height of the tree (down from O(n) if we had to do a full in-order traversal).
int select_node(int k, struct bstnode *node) {
    assert (node && 0 <= k && k < node->count);
    
    int left_count = 0;
    if (node->left) left_count = node->left->count;
    
    // 如果 k 小于左子树的节点数，说明目标一定在左子树
    if (k < left_count) return select_node (k, node->left);
    
    // 如果 k 恰好等于左子树的节点数，说明当前节点就是目标
    if (k == left_count) return node->item;
    
    // 否则，目标在右子树。并且要减去左子树的数量和当前节点本身 (1)
    return select_node(k - left_count - 1, node->right);
}

int bst_select(int k, struct bst *t) {
    return select_node(k, t->root);
}