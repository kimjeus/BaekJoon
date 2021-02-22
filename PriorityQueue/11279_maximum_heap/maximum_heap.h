#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_PQ_SIZE 100001

typedef struct _priority_queue {
	int mem[MAX_PQ_SIZE];
	int back;
} priority_queue;

void initPQ(priority_queue *);
bool empty(priority_queue *);
void pop(priority_queue *);
void push(priority_queue *, int);
size_t size(priority_queue *);
int top(priority_queue *);
void swapData(int *, int *);

