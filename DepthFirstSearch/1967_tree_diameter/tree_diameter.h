#include <stdio.h>
#include <stdlib.h>	//malloc, free
#include <stdbool.h>

#define DEBUG 0
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

SNode arrInputTree[MAX_NODE_NUM - 1];	//간선 개수 = 노드 개수 - 1
SVisit arrStruVisit[MAX_NODE_NUM];

int nodeNum;
void initSNode(SNode *);	//parent node, child node, length 포함한 SNode 초기화
void initInputTree(void);	//input tree 초기화
void initSVisit(SVisit *);	//visit여부 입력값과의 length 포함한 SVisit 초기화
void initArrStruVisit(void);	//SVisit 구조체 배열 초기화
void doDFS(int, int);	//입력 노드로부터의 거리를 구하는 함수
void checkVisit(int, int);	//방문했는지 여부와 거리를 저장해주는 함수
int findFarthestNode();
