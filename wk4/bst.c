#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int elem;
    struct node *left;
    struct node *right;
};

// returns the number of nodes in the binary search tree
int bstNumNodes(struct node *t) {
    if (t == NULL) return 0;

    return 1 + bstNumNodes(t->left) + bstNumNodes(t->right);
}

// returns the number of odd values in a binary search tree
int bstCountOdds(struct node *t) {
    if (t == NULL) return 0;

    if (t->elem % 2 == 1) {
        return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
    }

    return bstCountOdds(t->left) + bstCountOdds(t->right);
}

// count number of internal nodes in a given tree
// an internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// returns the level of the node containing a given key if such a node exists,
// otherwise the function returns -1
// (when a given key is not in the binary search tree)
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
    if (t == NULL) return -1;
    if (t->elem == key) return 0;

    if (key < t->elem) {
        int res = bstNodeLevel(t->left, key);
        if (res == -1) return -1;
        return 1 + res;
    } else {
        int res = bstNodeLevel(t->right, key);
        if (res == -1) return -1;
        return 1 + res;
    }
}

// counts the number of values that are greater than a given value.
// This function should avoid visiting nodes that it doesn't have to visit
int bstCountGreater(struct node *t, int val) {
    if (t == NULL) return 0;

    int count = bstCountGreater(t->right, val);

    if (val < t->elem) {
        count += bstCountGreater(t->left, val);
        return count + 1;
    }

    return count;
}

#define NOT_HEIGHT_BALANCED -99

// returns the height of a given binary tree if it is height - balanced,
// and NOT_HEIGHT_BALANCED otherwise.
// Height-balanced tree: We say that a basic binary tree is height-balanced if,
//      for every node, the absolute difference between the height of the left
//      subtree and the height of the right subtree is one or less. In other
//      words, every node needs to satisfy the following criteria:
//      abs(height(left) - height(right)) ≤ 1
int isHeightBalanced(struct node *t) {
    // TODO
    return 0;
}

// challenging question!

// return the kth smallest node in the binary search tree
// return -1 if no such node exists (e.g. the 5th smallest number
// if a tree with only 3 nodes)
int kthSmallest(struct node *t, int k) {
    // TODO
    return 0;
}
