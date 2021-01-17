#include "maze_search.h"

int searchMazeBFS(int row, int column)
{
	int front = struQueue.mFront;
	int back = struQueue.mBack;
	int depth = 1;

	dArrVisit[row][column] = true;
	struQueue.mArrQueue[back].mRow = row;
	struQueue.mArrQueue[back++].mColumn = column;
	dArrDistance[row][column] = depth;
	front++;
	struQueue.mArrQueue[front].mDepth = depth;

	while (front < back && !dArrVisit[N - 1][M - 1]) {
		row = struQueue.mArrQueue[front].mRow;
		column = struQueue.mArrQueue[front].mColumn;
		depth = struQueue.mArrQueue[front].mDepth;

		if (row + 1 < N && dArrInputMaze[row + 1][column] && !dArrVisit[row + 1][column]) {
			dArrVisit[row + 1][column] = true;	//visit 여부 check
			//printf("(%d, %d): visit\n", row + 1, column);
			struQueue.mArrQueue[back].mRow = row + 1;	//queue에 삽입
			struQueue.mArrQueue[back].mColumn = column;	//queue에 삽입
			struQueue.mArrQueue[back++].mDepth = depth + 1;
		//printf("1depth: %d, (%d, %d)\n", depth, row, column);
			dArrDistance[row + 1][column] = depth + 1;		//visit check된 좌표 거리 저장
		}
		if (row - 1 >= 0 && dArrInputMaze[row - 1][column] && !dArrVisit[row - 1][column]) {
			dArrVisit[row - 1][column] = true;	//visit 여부 check
			//printf("(%d, %d): visit\n", row - 1, column);
			struQueue.mArrQueue[back].mRow = row - 1;	//queue에 삽입
			struQueue.mArrQueue[back].mColumn = column;	//queue에 삽입
			struQueue.mArrQueue[back++].mDepth = depth + 1;
//			struQueue.mDepth = depth + 1;
		//printf("2depth: %d, (%d, %d)\n", depth, row, column);
			dArrDistance[row - 1][column] = depth + 1;		//visit check된 좌표 거리 저장
		}
		if (column + 1 < M && dArrInputMaze[row][column + 1] && !dArrVisit[row][column + 1]) {
			dArrVisit[row][column + 1] = true;	//visit 여부 check
			//printf("(%d, %d): visit\n", row, column + 1);
			struQueue.mArrQueue[back].mRow = row;	//queue에 삽입
			struQueue.mArrQueue[back].mColumn = column + 1;	//queue에 삽입
			struQueue.mArrQueue[back++].mDepth = depth + 1;
//k			struQueue.mDepth = depth + 1;
		//printf("3depth: %d, (%d, %d)\n", depth, row, column);
			dArrDistance[row][column + 1] = depth + 1;		//visit check된 좌표 거리 저장
		}
		if (column - 1 >= 0 && dArrInputMaze[row][column - 1] && !dArrVisit[row][column - 1]) {
			dArrVisit[row][column - 1] = true;	//visit 여부 check
			//printf("(%d, %d): visit\n", row, column - 1);
			struQueue.mArrQueue[back].mRow = row;	//queue에 삽입
			struQueue.mArrQueue[back].mColumn = column - 1;	//queue에 삽입
			struQueue.mArrQueue[back++].mDepth = depth + 1;
//			struQueue.mDepth = depth + 1;
		//printf("4depth: %d, (%d, %d)\n", depth, row, column);
			dArrDistance[row][column - 1] = depth + 1;		//visit check된 좌표 거리 저장
		}
		//printf("depth: %d, (%d, %d)\n", depth, row, column);
		front++;
	}
	depth++;

	struQueue.mFront = front;
	struQueue.mBack = back;

	return depth;
}
