#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error: Unable to allocate memory for a new node.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtHead(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to delete a node from the list
void deleteNode(Node **head, int key) {
  Node *temp = *head, *prev = NULL;

  // If head node itself holds the key
  if (temp != NULL && temp->data == key) {
    *head = temp->next; // Change head
    free(temp);         // Free old head
    return;
  }

  // Search for the key to be deleted
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  // If key was not present in the list
  if (temp == NULL)
    return;

  // Unlink the node from the list
  prev->next = temp->next;
  free(temp);
}

// Function to search for a node in the list
Node *searchNode(Node *head, int key) {
  Node *current = head;
  while (current != NULL) {
    if (current->data == key)
      return current;
    current = current->next;
  }
  return NULL; // Not found
}

// Function to print the linked list
void printList(Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// Main function
int main() {
  Node *head = NULL;

  insertAtHead(&head, 10);
  insertAtHead(&head, 20);
  insertAtHead(&head, 30);

  printf("Linked List: ");
  printList(head);

  deleteNode(&head, 20);
  printf("Linked List after deletion of 20: ");
  printList(head);

  Node *found = searchNode(head, 10);
  if (found != NULL) {
    printf("Node with data 10 found.\n");
  } else {
    printf("Node with data 10 not found.\n");
  }

  return 0;
}
