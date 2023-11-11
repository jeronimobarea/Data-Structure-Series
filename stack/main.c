#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Defining the maximum size of the stack

typedef struct Stack {
  int items[MAX_SIZE];
  int top;
} Stack;

void initializeStack(Stack *stack) { stack->top = -1; }

int isEmpty(Stack *stack) { return stack->top == -1; }

// Function to add an element to the stack
void push(Stack *stack, int item) {
  if (stack->top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stack->items[++stack->top] = item;
}

// Function to remove the top element from the stack
int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack->items[stack->top--];
}

// Function to get the top element of the stack
int peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }
  return stack->items[stack->top];
}

int main() {
  Stack stack;
  initializeStack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("Top element is %d\n", peek(&stack));
  printf("Stack: ");
  while (!isEmpty(&stack)) {
    printf("%d ", pop(&stack));
  }
  printf("\n");

  return 0;
}
