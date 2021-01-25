#include <stdio.h>
#include <stdbool.h>

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

int count;	//arrSideLand에 실제 저장된 데이터 개수
int mapSize;	//입력될 좌표의 한 변 길이
Node graph[MAX_MAP_SIZE][MAX_MAP_SIZE];	//graph 크기는 mapSize * mapSize
bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE];	//방문을 체크하는 배이므로 graph와 동일한 크기
QueueNode arrSideLand[MAX_MAP_SIZE * MAX_MAP_SIZE];	//최대 섬의 개수는 전체 좌표 개수보다 작다.

void giveIslandNumBFS(int, int, int);	//섬에 숫자를 부여해주는 함수
int minRouteBFS(int, int, int, int);
void checkSide(void);	//graph의 모든 좌표에 대해 옆에 바다(= 0)이 붙어 있는지 없는지에 대해 저장
void sideLand(void);	//arrSideLand에 0이 붙어있는 모든 육지 좌표 저장
void push(int, int, int);
bool empty(void);
void initNode(Node *);
void initGraph(void);
void initVisited(void);
void initQueue(void);
#if DEBUG
void printGraph(void);	//graph 출력하는 함수
#endif
