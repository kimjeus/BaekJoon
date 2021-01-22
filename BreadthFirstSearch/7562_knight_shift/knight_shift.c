#include "knight_shift.h"

void BFS(void)
{
	int xPos = startNode.xPos;
	int yPos = startNode.yPos;
	QueueNode tempNode;
	initQueueNode(&tempNode);

	push(startNode);
	dArrVisited[startNode.xPos][startNode.yPos]++;

	if (endNode.xPos == startNode.xPos && endNode.yPos == startNode.yPos) {
		return;
	}
	queue.front++;

	while (!isEmpty()) {
		xPos = queue.arrQueue[queue.front].xPos;
		yPos = queue.arrQueue[queue.front].yPos;

		if (compareChild(xPos + 2, yPos + 1) && dArrVisited[xPos + 2][yPos + 1] < 0)
			if (searchChild(xPos + 2, yPos + 1, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos + 2, yPos - 1) && dArrVisited[xPos + 2][yPos - 1] < 0)
			if (searchChild(xPos + 2, yPos - 1, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos + 1, yPos + 2) && dArrVisited[xPos + 1][yPos + 2] < 0)
			if (searchChild(xPos + 1, yPos + 2, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos + 1, yPos - 2) && dArrVisited[xPos + 1][yPos - 2] < 0)
			if (searchChild(xPos + 1, yPos - 2, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos - 1, yPos + 2) && dArrVisited[xPos - 1][yPos + 2] < 0)
			if (searchChild(xPos - 1, yPos + 2, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos - 1, yPos - 2) && dArrVisited[xPos - 1][yPos - 2] < 0)
			if (searchChild(xPos - 1, yPos - 2, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos - 2, yPos + 1) && dArrVisited[xPos - 2][yPos + 1] < 0)
			if (searchChild(xPos - 2, yPos + 1, dArrVisited[xPos][yPos]))
				return;
		if (compareChild(xPos - 2, yPos - 1) && dArrVisited[xPos - 2][yPos - 1] < 0)
			if (searchChild(xPos - 2, yPos - 1, dArrVisited[xPos][yPos]))
				return;
		queue.front++;
	}
	return;
}

bool searchChild(int xPos, int yPos, int length)
{
#if DEBUG
	printf("\nsearchChild\n");
	printf("xPos: %d\tyPos: %d\tlength: %d\n", xPos, yPos, length);
#endif
	QueueNode tempNode;
	initQueueNode(&tempNode);
	
			tempNode.xPos = xPos;
			tempNode.yPos = yPos;
			push(tempNode);
			dArrVisited[xPos][yPos] = length + 1;

			if (endNode.xPos == xPos && endNode.yPos == yPos) {
				endNode.xPos = xPos;
				endNode.yPos = yPos;

				return true;
			}
			return false;
}

bool compareChild(int xPos, int yPos)
{
	if (xPos >= 0 && xPos < chessLength && yPos >= 0 && yPos < chessLength) {
		return true;
	}
	else {
		return false;
	}
}

bool isEmpty(void)
{
	if (queue.front > queue.back) {
		return true;
	}
	else {
		return false;
	}
}
void push(QueueNode inputNode)
{
	queue.arrQueue[++queue.back].xPos = inputNode.xPos;
	queue.arrQueue[queue.back].yPos = inputNode.yPos;

	return;
}

void initQueueNode(QueueNode *inputNode)
{
	inputNode->xPos = -1;
	inputNode->yPos = -1;

	return;
}
void initQueue(void)
{
	for (int i = 0; i < MAX_CHESSBOARD_SIZE; i++ ) {
		queue.arrQueue[i].xPos = -1;
		queue.arrQueue[i].yPos = -1;
	}
	queue.front = -1;
	queue.back = -1;

	return;
}
void initVisited(void)
{
	for (int i = 0; i < MAX_CHESSBOARD_LENGTH; i++) {
		for (int j = 0; j < MAX_CHESSBOARD_LENGTH; j++) {
			dArrVisited[i][j] = -1;	
		}
	}
	return;
}
