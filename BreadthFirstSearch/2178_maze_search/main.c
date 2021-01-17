#include "maze_search.h"

int main(void)
{
	//bool **ppInputMaze;

	scanf("%d", &N);
	scanf("%d", &M);
/*
	//ppInputMaze 메모리 할당
	ppInputMaze = (bool **)malloc(sizeof(bool *) * N);
	for (int i = 0; i < N; i++) {
		ppInputMaze[i] = (bool *)malloc(sizeof(bool) * M);
		//ppInputMaze 초기화
		for (int j = 0; j < M; j++) {
			ppInputMaze[i][j] = false;
		}
	}
*/
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
	}
	struQueue.mFront = -1;
	struQueue.mBack = 0;

	//ppInputMaze 값 대입
	for (int i = 0; i < N; i++) {
//		while (getchar() != EOF) {}	//buffer 비우기
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
/*
	printf("\n");
	for (int i = 0; i < N * M; i++) {
		printf("(%d, %d)\n", struQueue.mArrQueue[i].mRow, struQueue.mArrQueue[i].mColumn);
	}
*/
	return 0;
}
