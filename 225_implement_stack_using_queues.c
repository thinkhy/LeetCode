#include <stdio.h>
#include <stdlib.h>

typedef int bool; 
#define MAXSIZE 10000
typedef struct {
 int *queue;   
 int front;
 int tail;
 int maxSize;
} Queue;

typedef struct {
  Queue *q;
} Stack;

/* Return whether the stack is empty */
bool queueEmpty(Queue *q) {
   return q->front == q->tail;
}

/* Create a queue */
void queueCreate(Queue *q, int maxSize) {
   q->front = 0; 
   q->tail = 0; 
   q->queue = (int*)malloc(maxSize);
   if (q->queue == NULL)
       return;
   q->maxSize = maxSize;
}

/* Push element x onto stack */
void queuePush(Queue *q, int element) {
   if (q->tail-q->front < q->maxSize)
      q->queue[q->tail++] = element;
}

/* Removes the element on top of the stack */
void queuePop(Queue *q) {
   if (!queueEmpty(q)) {
     q->front++;
   }
}

/* Get the top element */
int queueTop(Queue *q) {
   return q->queue[q->front];
}

/* Return size of queue */
bool queueSize(Queue *q) {
   if (q != NULL)
      return q->tail - q->front;
   else     
      return 0;
}


/* Destroy the stack */
void queueDestroy(Queue *q) {
   q->front = q->tail = 0;
   free(q->queue);
}

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
   stack->q = (Queue*)malloc(sizeof(Queue));
   if (stack->q != NULL)
   	queueCreate(stack->q, maxSize);
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    Queue *tmp = (Queue*)malloc(sizeof(Queue));
    queueCreate(tmp, stack->q->maxSize);
    while(!queueEmpty(stack->q)) {
         queuePush(tmp, queueTop(stack->q));
         queuePop(stack->q);
    }
    queuePush(stack->q, element);
    while(!queueEmpty(tmp)) {
         queuePush(stack->q, queueTop(tmp));
         queuePop(tmp);
    }
    queueDestroy(tmp);
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
   queuePop(stack->q); 
}

/* Get the top element */
int stackTop(Stack *stack) {
   return queueTop(stack->q);
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
   return queueEmpty(stack->q);
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
  queueDestroy(stack->q);
}

int main() {
  printf("225. Implement Stack using Queue\n");
  Stack *s = (Stack*)malloc(sizeof(Stack));
  stackCreate(s,3);
  stackPush(s, 1);
  stackPush(s, 2);
  stackPush(s, 3);
  printf("%d\n", stackTop(s));
  stackPop(s);
  printf("%d\n", stackTop(s));
  stackPop(s);
  printf("%d\n", stackTop(s));
  stackPop(s);
  stackDestroy(s);
  return 0;
}



