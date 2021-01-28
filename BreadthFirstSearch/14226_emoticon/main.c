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

	printf("%d\n", queue.arrQueue[queue.back].mSecond);

	return 0;
}
