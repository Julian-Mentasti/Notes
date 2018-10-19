#include <stdlib.h>
#include <stdio.h>

/**
 * A node of the binary tree containing the node's integer value
 * and pointers to its right and left children (or null).
 */
struct Node {
    struct Node *left;
    struct Node *right;
    int value;
};

/**
 * Create a new node with no children.
 */
struct Node* create (int value) {
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL)
        return NULL;
    
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Insert the node n into the binary tree rooted by toNode.
 */
void insert (struct Node* toNode, struct Node* n) {
    if (n->value <= toNode->value) {
        if (toNode->left == NULL) {
            toNode->left = n;
        } else {
            insert(toNode->left, n);
        }
    } else {
        if (toNode->right == NULL) {
            toNode->right = n;
        } else {
            insert(toNode->right, n);
        }
    }
}


/**
 * Print the contents entire binary tree in order of ascending integer value.
 */
void printInOrder (struct Node* node) {
    if (node->left != NULL)
        printInOrder(node->left);
    printf("%d\n", node->value);
    if (node->right != NULL)
        printInOrder(node->right);
}

/**
 * Create a new tree populated with values provided on the command line and
 * print it in depth-first order.
 */
int main (int argc, char* argv[]) {
  // read values from command line and add them to the tree
  struct Node *root = NULL;
  for (int i=1; i<argc; i++) {
    if (i == 1) {
      int firstVal = atoi (argv[1]);
      root = create(firstVal);
    } else {
        int value = atoi (argv [i]);
        struct Node *node = create(value);
        insert(root, node);
    }
  }
  //struct Node *root = create(100);
  //struct Node *ten = create(50);
  //struct Node *onef = create(150);
  //insert(root, ten);
  //insert(root, onef);
  if (root != NULL)
    printInOrder(root);
  
}
