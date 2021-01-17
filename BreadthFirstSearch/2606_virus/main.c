#include "virus.h"

int main(void)
{
	int inputNum1 = 0, inputNum2 = 0;

	scanf("%d", &computerCount);
	scanf("%d", &inputCount);

	//graph 메모리 할당
	ppInputGraph = (bool **)malloc(sizeof(bool *) * (computerCount));
	for (int i = 0; i < computerCount; i++) {
		ppInputGraph[i] = (bool *)malloc(sizeof(bool) * computerCount);
		for (int j = 0; j < computerCount; j++) {
			ppInputGraph[i][j] = 0;
		}
	}
	

	//visit 배열 메모리 할당
	ptrVisit = (bool *)malloc(sizeof(bool) * computerCount);
	//visit 배열 초기화
	for (int i = 0; i < computerCount; i++) {
		ptrVisit[i] = false;
	}

	//queue 배열 메모리 할당
	struQueue.mPtrQueue = (int *)malloc(sizeof(int) * computerCount);
	//Queue 구조체 초기화
	for (int i = 0; i < computerCount; i++) {
		struQueue.mPtrQueue[i] = 0;
	}
	struQueue.front = -1;
	struQueue.back = 0;

	//graph에 입력값 저장
	for (int i = 0; i < inputCount; i++) {
		scanf("%d", &inputNum1);
		scanf("%d", &inputNum2);
		ppInputGraph[inputNum1 - 1][inputNum2 - 1] = true;
		ppInputGraph[inputNum2 - 1][inputNum1 - 1] = true;
	}
/*
	printf("\n");
	for (int i = 0; i < computerCount; i++) {
		for (int j = 0; j < computerCount; j++) {
			printf("%d ", (int)ppInputGraph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
*/
	printf("%d\n", doBFS(1));
/*	
	printf("queue: ");
	for (int i = 0; i < computerCount; i++) {
		printf("%d ", struQueue.mPtrQueue[i]);
	}
	printf("\n");
*/

	//graph free
	for (int i = 0; i < computerCount - 1; i++) {
		free(ppInputGraph[i]);
	}
	free(ppInputGraph);
	//visit free
	free(ptrVisit);
	//queue free
	free(struQueue.mPtrQueue);

	return 0;
}
