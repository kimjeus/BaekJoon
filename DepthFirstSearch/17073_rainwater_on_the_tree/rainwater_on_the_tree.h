#include <stdio.h>
#include <stdlib.h>	//malloc, free
#include <stdbool.h>
#include <math.h>	//pow

#define DEBUG 0
#define MAX_INPUT_NODE 500000

typedef struct _SVisit {
	bool mVisit;
	double mDepth;
} SVisit;

typedef struct _SNode {
	int mNode1;
	int mNode2;
	int mCountNode;
} SNode;

SVisit arrStruVisit[MAX_INPUT_NODE + 1];	//노드가 1부터 시작하므로 배열의 1부터 쓰기 위해서 +1
SNode arrStruInputTree[MAX_INPUT_NODE];	//링크 개수 = 노드 개수 -1 이고 노드가 1부터 시작하므로 배열의 1부터 쓰기 위해 +1
int arrLinkCount[MAX_INPUT_NODE + 1];	//노드가 1부터 시작하므로 배열의 1부터 쓰기 위해서 +1
int nodeNum;
double *ptrResult;

void waterDFS(int);
void countNodeLink(void);
int countChild(int);
void findResult(void);

void initArrStruVisit(void);
void initArrStruInputTree(void);
void initArrLinkCount(void);

void printArrStruVisit(void);
void printArrLinkCount(void);
