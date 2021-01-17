#include <stdio.h>
#include <stdlib.h> //malloc, free
#include <stdbool.h>

typedef struct _SQueue {
	int *mPtrQueue;
	int front;
	int back;
} SQueue;
SQueue struQueue;

bool *ptrVisit;
bool **ppInputGraph;
int computerCount, inputCount;

int doBFS(int);
