#include "minimal_heap.h"

int main(void)
{
	initPQ();	//priority_queue 초기화
	int opTotNum = 0;
	unsigned int opNum = 0;
	Node **treeNode;

	scanf("%d", &opTotNum);

	treeNode = (Node **)malloc(sizeof(Node *) *opTotNum);
	for (int i = 0; i < opTotNum; i++) {
		treeNode[i] = (Node *)malloc(sizeof(Node));
	}


	return 0;
}
