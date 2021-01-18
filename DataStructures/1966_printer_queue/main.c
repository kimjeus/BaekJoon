#include "printer_queue.h"

int main(void)
{
	int T = 0;
	int *ptrResult;


	scanf("%d", &T);

	//ptrResult 메모리 할당
	ptrResult = (int *)malloc(sizeof(int) * T);
	//ptrResult 메모리 초기화
	for (int i = 0; i < T; i++) {
		ptrResult[i] = 0;
	}

	for (int i = 0; i < T; i++) {
		int N = 0, goalNum = 0;

		//queue 초기화
		for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			struQueue.mArrQueue[i].mDocNum = 0;
			struQueue.mArrQueue[i].mImportNum = 0;
		}
		struQueue.mFront = -1;
		struQueue.mBack = 0;

		scanf("%d", &N);
		scanf("%d", &goalNum);
		goalNum++;	//queue는 0번째부터 세지만 문서 N은 1부터 세기 때문

#if DEBUG
		printf("\nTest T: %d, Total Documents N: %d, goalNum: %d\n", T, N, goalNum);
#endif

		for (int i = 0; i < N; i++) {
			struQueue.mArrQueue[i].mDocNum = i + 1;
			scanf("%d", &struQueue.mArrQueue[i].mImportNum);
		}
		struQueue.mBack = N;
		struQueue.mFront++;
#if DEBUG
		printf("goalNum importance: %d\n", struQueue.mArrQueue[goalNum - 1].mImportNum);
#endif

		ptrResult[i] = printingInOrder(goalNum, struQueue.mArrQueue[goalNum - 1].mImportNum);
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", ptrResult[i]);
	}

	free(ptrResult);
	return 0;
}
