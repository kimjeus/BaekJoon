#include "rainwater_on_the_tree.h"

int main(void)
{
	int amountWater = 0;

	scanf("%d", &nodeNum);
	scanf("%d", &amountWater);

	//ptrResult 메모리 할당 및 초기화
	ptrResult = (double *)malloc(sizeof(double) * nodeNum);
	for (int i = 0; i < nodeNum; i++) {
		ptrResult[i] = 0;
	}

	initArrStruVisit();
	initArrStruInputTree();
	
	//Tree 입력 받아서 arrStruInputTree에 node1, node2에 저장
	for (int i = 1; i < nodeNum; i++) {
		scanf("%d", &arrStruInputTree[i].mNode1);
		scanf("%d", &arrStruInputTree[i].mNode2);
	}

	countNodeLink();
#if DEBUG
	printArrLinkCount();
#endif
	//waterDFS(1);
#if DEBUG
	printArrStruVisit();
#endif
	//findResult();
/*
	double sum = 0;
	for (int i = 1; i <= ptrResult[0]; i++) {
		sum += ptrResult[i];
	}
	*/
	int count = 0;
	for (int i = 1; i <= nodeNum; i++) {
		if (arrLinkCount[i] == 1) {
			count++;
		}
	}
	printf("%f\n", (double)amountWater / count);

//	printf("%f\n", (double)amountWater * sum / ptrResult[0]);

	free(ptrResult);
	return 0;
}
