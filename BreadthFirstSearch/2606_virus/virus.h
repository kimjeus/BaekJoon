#include <stdio.h>
#include <stdlib.h> //malloc, free
#include <string.h>	//strlen

#define MAX_QUEUE_SIZE 100

typedef struct _SQueue {
	int mArrQueue[MAX_QUEUE_SIZE];
	int front;
	int back;
} SQueue;
SQueue struQueue;

typedef struct _SVisit {
	int *mPtrVisit;
	int top;
} SVisit;
SVisit struVisit;

int computerCount = 0;
int netLinkCount = 0;

void isPush(SQueue *, int);
