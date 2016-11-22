#include <stdio.h>
#include <stdlib.h>

typedef int bool;

typedef struct {
   int *p; 
   int top;
   int maxSize;
} Stack;

typedef struct {
   Stack *s; 
} Queue;

void stackCreate(Stack *s, int maxSize) {
   if (s == NULL) return;
   s->p = (int*)malloc(maxSize*sizeof(int));
   s->top = 0;
   s->maxSize = maxSize;
}

void stackPush(Stack *s, int element) {
   if (s->top < s->maxSize)
       s->p[s->top++] = element;
}

void stackPop(Stack *s) {
   s->top--;
}

int stackTop(Stack *s) {
   return s->p[s->top - 1];
}

bool stackEmpty(Stack *s) {
   return s->top == 0;
}

int stackSize(Stack *s) {
    return s->top;
}

void stackDestroy(Stack *s) {
   free(s->p);
   s->top = 0;
   s->maxSize = 0;
}

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
   queue->s = (Stack*)malloc(sizeof(Stack));
   stackCreate(queue->s, maxSize); 
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
   Stack *tmp = (Stack*)malloc(sizeof(Stack));
   stackCreate(tmp, queue->s->maxSize);

   while(!stackEmpty(queue->s)) { 
      stackPush(tmp, stackTop(queue->s));
      stackPop(queue->s);
   }

   stackPush(tmp, element);

   while(!stackEmpty(tmp)) { 
      stackPush(queue->s, stackTop(tmp));
      stackPop(tmp);
   }
   stackDestroy(tmp);
   free(tmp); 
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
   stackPop(queue->s); 
}

/* Get the front element */
int queuePeek(Queue *queue) {
   return stackTop(queue->s);
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
   return stackEmpty(queue->s); 
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
   stackDestroy(queue->s);
}


int main() {
   Queue *q = (Queue*)malloc(sizeof(Queue));    
   queueCreate(q, 4);
	
   queuePush(q, 1); 
   queuePush(q, 2); 
   queuePush(q, 3); 
   queuePush(q, 4); 

   while(!queueEmpty(q)) {
      printf("%d\n", queuePeek(q));
      queuePop(q);
   }

   queueDestroy(q);
   free(q);
}


