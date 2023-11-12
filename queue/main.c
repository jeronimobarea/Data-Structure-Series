#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the queue

typedef struct Queue {
  int items[MAX_SIZE];
  int front, rear;
} Queue;

void initializeQueue(Queue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

int isEmpty(Queue *queue) { return queue->rear == -1; }

int isFull(Queue *queue) { return queue->rear == MAX_SIZE - 1; }

// Adding an element to the queue
void enqueue(Queue *queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full\n");
    return;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->rear++;
  queue->items[queue->rear] = item;
}

// Removing an element from the queue
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }
  int item = queue->items[queue->front];
  queue->front++;
  if (queue->front > queue->rear) {
    // Reset the queue after the last dequeue
    initializeQueue(queue);
  }
  return item;
}

// Get the front element of the queue
int peek(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue->items[queue->front];
}

int main() {
  Queue queue;
  initializeQueue(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  printf("Front element is %d\n", peek(&queue));
  printf("Queue: ");
  while (!isEmpty(&queue)) {
    printf("%d ", dequeue(&queue));
  }
  printf("\n");

  return 0;
}
