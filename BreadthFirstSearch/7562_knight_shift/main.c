#include "knight_shift.h"

int main(void)
{
	int testNum = 0;

	//변수, 구조체, 배열 초기화
	initQueueNode(&startNode);
	initQueueNode(&endNode);
	initQueue();
	initVisited();

	scanf("%d", &testNum);

	for (int i = 0; i < testNum; i++) {
		scanf("%d", &chessLength);
		scanf("%d", &startNode.xPos);
		scanf("%d", &startNode.yPos);
		scanf("%d", &endNode.xPos);
		scanf("%d", &endNode.yPos);

		BFS();
		printf("%d\n", dArrVisited[endNode.xPos][endNode.yPos]);

		initVisited();
		initQueue();
	}

	return 0;
}
