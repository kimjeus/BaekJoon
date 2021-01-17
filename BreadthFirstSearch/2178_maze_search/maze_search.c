#include "maze_search.h"

int searchMazeBFS(int row, int column)
{
	int front = struQueue.mFront;
	int depth = 1;

	front++;
	doRightDistance(row, column, depth);

	while (front < struQueue.mBack && !dArrVisit[N - 1][M - 1]) {
		row = struQueue.mArrQueue[front].mRow;
		column = struQueue.mArrQueue[front].mColumn;
		depth = struQueue.mArrQueue[front].mDepth;

		if (row + 1 < N && isRightDistance(row + 1, column)) {
			doRightDistance(row + 1, column, depth + 1);
		}
		if (row - 1 >= 0 && isRightDistance(row - 1, column)) {
			doRightDistance(row - 1, column, depth + 1);
		}
		if (column + 1 < M && isRightDistance(row, column + 1)) {
			doRightDistance(row, column + 1, depth + 1);
		}
		if (column - 1 >= 0 && isRightDistance(row, column - 1)) {
			doRightDistance(row, column - 1, depth + 1);
		}
		front++;
	}
	depth++;
	struQueue.mFront = front;

	return depth;
}

//입력값으로 지나갈 수 있는 경로인지 아닌지 확인하는 함수
bool isRightDistance(int row, int column)
{
	if (dArrInputMaze[row][column] && !dArrVisit[row][column]) {	//벽인지 아닌지 검사 && 이미 방문해서 거리를 저장한 좌표인지 아닌지 검사
		return true;
	}
	else
		return false;
}

void doRightDistance(int row, int column, int depth)
{
	dArrVisit[row][column] = true;	//visit 여부 check
	dArrDistance[row][column] = depth;	//visit check된 좌표 거리 저장
	pushQueue(row, column, depth);

	return;
}

//queue에 push하는 함수
void pushQueue(int row, int column, int depth)
{
	int back = struQueue.mBack;

	struQueue.mArrQueue[back].mRow = row;
	struQueue.mArrQueue[back].mColumn = column;
	struQueue.mArrQueue[back++].mDepth = depth;

	struQueue.mBack = back;

	return;
}
