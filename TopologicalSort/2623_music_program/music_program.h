#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_QUEUE_SIZE 1001

typedef struct _queue {
int mem[MAX_QUEUE_SIZE];
int front;
int back;
} queue;
queue *qu;

int N, M;
bool graph[MAX_QUEUE_SIZE][MAX_QUEUE_SIZE];	//가수 순서 규칙 저장
int arrResult[MAX_QUEUE_SIZE];	//최종 가수 순서 저장
int resultIdx;

void check(int);	//인자로 들어온 가수 이전에 해야하는 가수 없는지 검사
bool topologicalSorting(void);	//최종 가수 정렬하면서 정렬 가능 여부 반환

void initQueue(queue *);
bool empty(queue *);
void pop(queue *);
void push(queue *, int);
size_t size(queue *);
int front(queue *);
int back(queue *);

