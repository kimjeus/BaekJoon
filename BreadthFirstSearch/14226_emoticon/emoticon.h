#include <stdio.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_QUEUE_SIZE 16000
#define MAX_INPUT_SIZE 1000

typedef struct _Node {
	int mScreen;
	int mClipBoard;
	int mSecond;
} Node;
Node startNode;

typedef struct _Queue {
	Node arrQueue[MAX_QUEUE_SIZE + 2];
	int front;
	int back;
} Queue;
Queue queue;

bool visited[MAX_INPUT_SIZE + 2][MAX_INPUT_SIZE + 2];

void BFS(Node);
void subNode(Node *, Node);
void push(Node);
bool empty(void);
void initNode(Node *);
void initQueue();
void initVisited();
#if DEBUG
	void printNode(Node);
	void printQueue(void);
#endif
