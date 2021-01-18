#include <stdio.h>
#include <stdlib.h>	//malloc, free
#include <stdbool.h>

#define DEBUG 0
#define MAX_QUEUE_SIZE 101

typedef struct _SDocument {
	int mDocNum;	//1 <= <= 100
	int mImportNum;	//1 <= <= 9
} SDocument;

typedef struct _SQueue {
	SDocument mArrQueue[MAX_QUEUE_SIZE];
	int mFront;
	int mBack;
} SQueue;
SQueue struQueue;

int printingInOrder(int, int);
bool isMostImportant(int);
bool isEmptyQueue(void);
SDocument popQueue(void);
void pushQueue(SDocument);
