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

//노드의 [screen에 출력된 이모티콘 개수][clipboard에 저장된 이모티콘 개수]로 노드의 방문 여부 체크
bool visited[MAX_INPUT_SIZE + 2][MAX_INPUT_SIZE + 2];

void BFS(Node);	//queue의 front 노드에 대해서 화면의 이모티콘 삭제 or 클립보드에 현재 화면의 이모티콘 개수 복사 or 클립보드에 있는 이모티콘을 화면에 복사 붙여넣기를 BreadthFirstSearch 알고리즘 방식을 탐색
void push(Node);
bool empty(void);
void initNode(Node *);
void initQueue();
void initVisited();
#if DEBUG
	void printNode(Node);
	void printQueue(void);
#endif
