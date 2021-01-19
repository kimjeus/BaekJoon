#include <stdio.h>
#include <stdlib.h>	//malloc, free
#include <stdbool.h>

#define DEBUG 1
#define MAX_NODE_NUM 10000

typedef struct _SNode {
	int mParentNum;
	int mChildNum;
	int mLength;
} SNode;

typedef struct _SVisit {
	bool mVisit;
	int mLength;
} SVisit;

SNode arrInputTree[MAX_NODE_NUM - 1];
SVisit arrStruVisit[MAX_NODE_NUM];

int nodeNum;

void initSNode(SNode *);	//parent node, child node, length 포함한 SNode 초기화
void initInputTree(void);	//input tree 초기화
void initSVisit(SVisit *);	//visit여부 입력값과의 length 포함한 SVisit 초기화
void initArrStruVisit(void);	//SVisit 구조체 배열 초기화
void doDFS(int, int);
void checkVisit(int, int);
int findFarthestNum();
