#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_QUEUE_SIZE 100000

typedef struct _SNode {
	int mPosition;
	int mSecond;
} SNode;

typedef struct _SQueue {
	SNode mStruNode[MAX_QUEUE_SIZE];
	int mFront;
	int mBack;
} SQueue;

SQueue arrStruQueue;
SNode struResult;
bool visited[MAX_QUEUE_SIZE];
int K;

void DFS(int);
void checkChild(int, int);
void compareResult(SNode);

void initArrStruQueue(void);
void pushQueue(SNode *);
