#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_QUEUE_SIZE 500001

typedef struct _queue {
	int mem[MAX_QUEUE_SIZE];
	int Front;
	int Back;
} queue;

bool empty(queue *);
void pop(queue *);
void push(queue *, int);
size_t size(queue *);
int front(queue *);
int back(queue *);
void initQueue(queue *);
