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

typedef struct _SDepth {
	int mParentNode;
	int mChildNode;
	int mDepth;
} SDepth;

SNode arrInputTree[MAX_NODE_NUM];

int nodeNum;
int *ptrArrInputTree[3];
int temp[3][30];
int result[30];
int k;
int xRow;
int xColumn;

void initSNode(SNode *);	//parent node, child node, length 포함한 SNode 초기화
void initInputTree(void);	//input tree 초기화

void findPartOfDiameterDFS(int);
void initSDepth(SDepth *);	//SDepth 값 0으로 초기화
void inputSDepth(SDepth *, int, int, int);	//SDepth에 input 값으로 이루어진 depth까지 저장
int countChildNode(int);
void dfs_1(SDepth *);
void dfs_2(int);
