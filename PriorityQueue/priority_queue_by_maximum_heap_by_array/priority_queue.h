#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct _Data {
	int xPos;
	int yPos;
	int pri;
} Data;

typedef struct _priQueue {
	Data mem[MAX_QUEUE_SIZE];
	int back;
} priQueue;

void initPriQueue(priQueue *pQu);
void initData(Data *);
bool empty(priQueue *pQu);
void pop(priQueue *pQu);
void push(priQueue *pQu, Data);
size_t size(priQueue *pQu);
Data top(priQueue *pQu);
void swapData(Data *, Data *);

