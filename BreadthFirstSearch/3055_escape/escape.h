#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_ROW_SIZE 52
#define MAX_QUEUE_SIZE 50 * 50

//input 2차원 배열의 타입
typedef struct _Node {
	char input;
	int count;
} Node;

//Queue Node
typedef struct _Pos {
	int x;
	int y;
} Pos;

typedef struct _queue {
	Pos mem[MAX_QUEUE_SIZE];
	int Front;
	int Back;
} queue;

//현재 지도의 상황 저장
Node arrIn[MAX_ROW_SIZE][MAX_ROW_SIZE];
int aCase[4][2];
int R, C;	//Row, Column
int count;	//이동 횟수 저장
bool result;	//도착 가능 여부 저장
int endX, endY;	//도착 'D'지점 저장

void initCase(void);
void bfs(queue *, queue*);
#if DEBUG
	void printInput(void);
	void printQueue(queue *);
#endif

bool empty(queue *);
void pop(queue *);
void push(queue *, int, int);
size_t size(queue *);
Pos front(queue *);
Pos back(queue *);
void initQueue(queue *);
