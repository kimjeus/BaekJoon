#include <stdio.h>
#include <string.h>	//strcmp
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10000

typedef struct _SQueue {
	int mArrQueue[MAX_QUEUE_SIZE];
	int front;
	int back;
} SQueue;
SQueue struQueue;

void isPush(SQueue *, int);
int isPop(SQueue *);
int isSize(SQueue *);
bool isEmpty(SQueue *);
int isFront(SQueue *);
int isBack(SQueue *);
