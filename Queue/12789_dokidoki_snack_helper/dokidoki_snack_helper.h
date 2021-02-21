#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_CONTAINER_SIZE 1001

typedef struct _stack {
	int mem[MAX_CONTAINER_SIZE];
	int top;
} stack;

typedef struct _queue {
	int mem[MAX_CONTAINER_SIZE];
	int front;
	int back;
} queue;

void sortingLine(int, bool *, stack *, queue *);

void initStack(stack *);
bool emptySt(stack *);
void popSt(stack *);
void pushSt(stack *, int);
size_t sizeSt(stack *);
int top(stack *);

void initQueue(queue *);
bool emptyQu(queue *);
void popQu(queue *);
void pushQu(queue *, int);
size_t sizeQu(queue *);
int front(queue *);
int back(queue *);

