#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_PQ_SIZE 300001
#define INF 200001

//입력값을 저장할 Node
typedef struct _Node {
	char weight;
	int vertex;
	struct _Node *next;
} Node;

typedef struct _vector {
	Node *mem;
	int memSize;
	int back;
} vector;

//시작 정점 K로부터 연결된 정점(vertex)과 그 가중치(weight)가 저장된 priorityQueue의 Data
typedef struct _Data {
	int weight;
	int vertex;
} Data;

typedef struct _priority_queue {
	Data mem[MAX_PQ_SIZE];
	int back;
} priority_queue;

int V;

//입력값 간선이 5 1 2 라면 graph[5]의 마지막 next에
//vertex = 1, weight = 2, next = NULL인 노드를 추가한다
//Node *graph;
int *result;    //시작 정점 K로부터 연결된 정점 1이 가중치 2로 연결되어있다면 result[1] = 2 저장
//bool *visit;
vector *vec;
priority_queue *pq;

void initData(Data *);
void initPQ(priority_queue *);
bool empty(priority_queue *);
void pop(priority_queue *);
void push(priority_queue *, Data);
size_t size(priority_queue *);
Data top(priority_queue *);
void swapData(Data *, Data *);

void initNode(Node *);
void initVEC(vector *);
void vectorFull(vector *);
void push_back(vector *, Node);
size_t sizeV(vector *);

void Dijkstra(int);
void initGraph(int);
void initResult(int);
void addList(Node *, Node);
#if DEBUG
void printVector(vector *);
#endif

