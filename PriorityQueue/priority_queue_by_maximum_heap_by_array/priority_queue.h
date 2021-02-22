#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PQ_SIZE 100001

typedef struct _Data {
	int xPos;
	int yPos;
	int pri;
} Data;

typedef struct _priority_queue {
	Data mem[MAX_PQ_SIZE];
	int back;
} priority_queue;

void initPQ(priority_queue *pq);
void initData(Data *);
bool empty(priority_queue *pq);
void pop(priority_queue *pq);
void push(priority_queue *pq, Data);
size_t size(priority_queue *pq);
Data top(priority_queue *pq);
void swapData(Data *, Data *);

