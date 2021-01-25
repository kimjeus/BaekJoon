#include "emoticon.h"

int main(void)
{
	Node tempNode;
	initNode(&tempNode);
	tempNode.mScreen = 1;

	initNode(&startNode);
	initQueue();
	initVisited();

	scanf("%d", &startNode.mScreen);

	BFS(tempNode);
/*
	int min = visited[startNode.mScreen][0];
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (min > visited[startNode.mScreen][i]) {
			min = visited[startNode.mScreen][i];
		}
	}
	printf("%d\n", min);
*/
	printf("%d\n", queue.arrQueue[queue.back].mSecond);
/*
	for (int i = 2; i <= 1000; i++) {
		initQueue();
		initVisited();
		startNode.mScreen = i;
		BFS(tempNode);
		printf("%d\t", i);
		printf("%d\n", queue.arrQueue[queue.back].mSecond);
	}
*/
	return 0;
}
