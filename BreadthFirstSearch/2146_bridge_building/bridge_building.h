#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define DEBUG 0
#define MAX_MAP_SIZE 100

typedef struct _Node {
	int islandNum;	//0은 바다, 1은 번호 안 준 육지, 2부터 번호 부여한 육지
	bool side;	//true이면 side(다리를 놓을 수 있음), false이면 다리를 놓을 수 없음
} Node;

typedef struct _QueueNode {
	int xPos;
	int yPos;
	int length;
} QueueNode;

typedef struct _Queue {
	QueueNode arrQueue[MAX_MAP_SIZE * MAX_MAP_SIZE];
	int front;
	int back;
} Queue;
Queue queue;

int count;
int mapSize;
Node graph[MAX_MAP_SIZE][MAX_MAP_SIZE];
bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
QueueNode arrSideLand[MAX_MAP_SIZE];

void giveIslandNumBFS(int, int, int);	//섬에 숫자를 부여해주는 함수
int minRouteBFS(int, int, int, int);
void checkSide(void);
void sideLand(void);
void push(int, int, int);
bool empty(void);
void initNode(Node *);
void initGraph(void);
void initVisited(void);
void initQueue(void);
#if DEBUG
void printGraph(void);	//graph 출력하는 함수
#endif
