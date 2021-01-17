#include "maze_search.h"

int main(void)
{
	scanf("%d", &N);
	scanf("%d", &M);

	//dArrInputMaze 초기화
	//dArrVisit 초기화
	//dArrDistance 초기화
	for (int i = 0; i < MAX_ROW_SIZE; i++) {
		for (int j = 0; j < MAX_ROW_SIZE; j++) {
			dArrInputMaze[i][j] = false;
			dArrVisit[i][j] = false;
			dArrDistance[i][j] = 0;
		}
	}

	//struQueue 초기화
	for (int i = 0; i < MAX_ROW_SIZE * MAX_ROW_SIZE; i++) {
		struQueue.mArrQueue[i].mRow = 0;
		struQueue.mArrQueue[i].mColumn = 0;
		struQueue.mArrQueue[i].mDepth = 0;
	}
	struQueue.mFront = -1;
	struQueue.mBack = 0;

	//dArrInputMaze 값 대입
	for (int i = 0; i < N; i++) {
		getchar();	//개행 비우기
		for (int j = 0; j < M; j++) {
			dArrInputMaze[i][j] = (bool)(getchar() - 48);
		}
	}
/*
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", dArrInputMaze[i][j]);
		}
		printf("\n");
	}
*/
	printf("%d\n", searchMazeBFS(0, 0));

	return 0;
}
