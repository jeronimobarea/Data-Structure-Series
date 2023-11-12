#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int value) {
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  if (newNode == NULL) {
    printf("Error: Unable to allocate memory for a new node.\n");
    exit(1);
  }
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

TreeNode *insertNode(TreeNode *root, int value) {
  if (root == NULL) {
    return createNode(value);
  }

  if (value < root->value) {
    root->left = insertNode(root->left, value);
  } else if (value > root->value) {
    root->right = insertNode(root->right, value);
  }

  return root;
}

void inOrderTraversal(TreeNode *root) {
  if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
  }
}

void preOrderTraversal(TreeNode *root) {
  if (root != NULL) {
    printf("%d ", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void postOrderTraversal(TreeNode *root) {
  if (root != NULL) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->value);
  }
}

int main() {
  TreeNode *root = NULL;
  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 70);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 60);
  insertNode(root, 80);

  printf("In-order Traversal: ");
  inOrderTraversal(root);
  printf("\n");

  printf("Pre-order Traversal: ");
  preOrderTraversal(root);
  printf("\n");

  printf("Post-order Traversal: ");
  postOrderTraversal(root);
  printf("\n");

  return 0;
}
