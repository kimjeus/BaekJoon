#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_ROW_SIZE 102
#define MAX_BOARD_SIZE 100 * 100 + 100
#define MAX_DIRCHG_SIZE 100

typedef struct _Dir {
	int xChg;
	int yChg;
} Dir;

typedef struct _DirChg {
	int count;
	char dirC;
} DirChg;

typedef struct _Pos {
	int x;
	int y;
} Pos;

typedef struct _Node{
	bool apple;
	bool snake;
	Dir dir;
} Node;

typedef struct _queue {
	Pos mem[MAX_BOARD_SIZE];
	int front;
	int back;
} queue;
queue *qu;

Node input[MAX_ROW_SIZE][MAX_ROW_SIZE];
DirChg dirChg[MAX_DIRCHG_SIZE];
int N;	//보드 한 변의 크기
int count;	//뱀의 이동 횟수

void move(void);
Dir changeDir(Dir, char);	//Dir 방향으로 가던 것을 char 방향으로 전환

bool empty(queue *);
void pop(queue *);
void push(queue *, int, int);
size_t size(queue *);
Pos front(queue *);
Pos back(queue *);
void initQueue(queue *);
void initInput();
