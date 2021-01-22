#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define DEBUG 0
#define MAX_CHESSBOARD_LENGTH 300
#define MAX_CHESSBOARD_SIZE 300 * 300

typedef struct _QueueNode {
	int xPos;
	int yPos;
} QueueNode;
QueueNode startNode;
QueueNode endNode;

typedef struct _Queue {
	QueueNode arrQueue[MAX_CHESSBOARD_SIZE];
	int front;
	int back;
} Queue;
Queue queue;

int chessLength;
int dArrVisited[MAX_CHESSBOARD_LENGTH][MAX_CHESSBOARD_LENGTH];	//방문한 체스판의 좌표에 출발점으로부터의 이동 횟수를 저장한다.

void BFS(void);
bool searchChild(int, int, int);	//이동할 수 있는 좌표라면 push queue 하고 최종 지점인지 확인
bool compareChild(int, int);	//이동할 수 있는 좌표인지 검사
void initQueueNode(QueueNode *);
void initQueue(void);
void initVisited(void);	//출발 지점은 이동 횟수가 0이면서 방문했다고 판단 할 수 있어야 하므로 -1로 초기화한다.
bool isEmpty(void);
void push(QueueNode);
