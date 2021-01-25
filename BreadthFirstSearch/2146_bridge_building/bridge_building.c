#include "bridge_building.h"

void giveIslandNumBFS(int xPos, int yPos, int islandNum)
{
	initQueue();	//queue 초기화
	push(xPos, yPos, 0);	//숫자 부여할 섬의 첫 육지를 queue에 push
	graph[xPos][yPos].islandNum = islandNum;	//queue에 push한 좌표는 islandNum 숫자 부여
	queue.front++;	//queue의 front 증가

	while (!empty()) {
		int frontXPos = queue.arrQueue[queue.front].xPos;
		int frontYPos = queue.arrQueue[queue.front].yPos;

		//아래쪽 좌표가 islandNum 1인 초기 육지일 때
		if (frontXPos - 1 >= 0 && graph[frontXPos - 1][frontYPos].islandNum == 1) {
			push(frontXPos - 1, frontYPos, 0);
			graph[frontXPos - 1][frontYPos].islandNum = islandNum;
		}
		//위쪽 좌표가 islandNum 1인 초기 육지일 때
		if (frontXPos + 1 < mapSize && graph[frontXPos + 1][frontYPos].islandNum == 1) {
			push(frontXPos + 1, frontYPos, 0);
			graph[frontXPos + 1][frontYPos].islandNum = islandNum;
		}
		//위쪽 좌표가 islandNum 1인 초기 육지일 때
		if (frontYPos - 1 >= 0 && graph[frontXPos][frontYPos - 1].islandNum == 1) {
			push(frontXPos, frontYPos - 1, 0);
			graph[frontXPos][frontYPos - 1].islandNum = islandNum;
		}
		if (frontYPos + 1 < mapSize && graph[frontXPos][frontYPos + 1].islandNum == 1) {
			push(frontXPos, frontYPos + 1, 0);
			graph[frontXPos][frontYPos + 1].islandNum = islandNum;
		}
		queue.front++;
	}

	return;
}

int minRouteBFS(int startX, int startY, int endX, int endY)
{
#if DEBUG
	printf("BFS\n");
#endif
	push(startX, startY, 0);
	queue.front++;

	while (!empty()) {
		int frontXPos = queue.arrQueue[queue.front].xPos;
		int frontYPos = queue.arrQueue[queue.front].yPos;
		int frontLength = queue.arrQueue[queue.front].length;

		if (frontXPos - 1 >= 0 && !visited[frontXPos - 1][frontYPos]) {
			push(frontXPos - 1, frontYPos, frontLength + 1);
			visited[frontXPos - 1][frontYPos] = true;
#if DEBUG
			
#endif
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}
		if (frontXPos + 1 < mapSize && !visited[frontXPos + 1][frontYPos]) {
			push(frontXPos + 1, frontYPos, frontLength + 1);
			visited[frontXPos + 1][frontYPos] = true;
#if DEBUG
			printf("%d\t%d\n", frontXPos + 1, frontYPos);
#endif
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}
		if (frontYPos - 1 >= 0 && !visited[frontXPos][frontYPos - 1]) {
			push(frontXPos, frontYPos - 1, frontLength + 1);
			visited[frontXPos][frontYPos - 1] = true;
#if DEBUG
			printf("%d\t%d\n", frontXPos, frontYPos - 1);
#endif
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}
		if (frontYPos + 1 < mapSize && !visited[frontXPos][frontYPos + 1]) {
			push(frontXPos, frontYPos + 1, frontLength + 1);
			visited[frontXPos][frontYPos + 1] = true;
#if DEBUG
			printf("%d\t%d\n", frontXPos, frontYPos + 1);
#endif
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}

		queue.front++;
	}
	return -1;
}

void checkSide(void)
{
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (graph[i][j].islandNum > 0) {
				if (i - 1 >= 0 && graph[i - 1][j].islandNum == 0) {
					graph[i][j].side = true;
				}
				else if (i + 1 < mapSize && graph[i + 1][j].islandNum == 0) {
					graph[i][j].side = true;
				}
				else if (j - 1 >= 0 && graph[i][j - 1].islandNum == 0) {
					graph[i][j].side = true;
				}
				else if (j + 1 < mapSize && graph[i][j + 1].islandNum == 0) {
					graph[i][j].side = true;
				}
			}
		}
	}
	return;
}
void sideLand(void)
{
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		arrSideLand[i].xPos = -1;
		arrSideLand[i].yPos = -1;
		arrSideLand[i].length = 0;
	}
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			if (graph[i][j].islandNum > 1/* && graph[i][j].side*/) {
				arrSideLand[count].xPos = i;
				arrSideLand[count].yPos = j;
				arrSideLand[count].length = graph[i][j].islandNum;
				count++;
			}
		}
	}
#if DEBUG
	printf("sideLand\n");
	for (int i = 0; i < count; i++) {
		printf("%d %d\t%d\n", arrSideLand[i].xPos, arrSideLand[i].yPos, arrSideLand[i].length);
	}
#endif
	return;
}
void push(int xPos, int yPos, int length)
{
	queue.back++;	//queue의 back 증가
	queue.arrQueue[queue.back].xPos = xPos;
	queue.arrQueue[queue.back].yPos = yPos;
	queue.arrQueue[queue.back].length = length;

	return;
}
bool empty()
{
	if (queue.front > queue.back) {
		return true;
	}
	else {
		return false;
	}
}

void initNode(Node *inputNode)
{
	inputNode->islandNum = 0;
	inputNode->side = false;
	return;
}
void initGraph()
{
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			initNode(&graph[i][j]);
		}
	}
	return;
}
void initVisited(void)
{
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			if (graph[i][j].islandNum > 0) {
				visited[i][j] = true;
			}
			else {
				visited[i][j] = false;
			}
		}
	}
	return;
}
void initQueue()
{
	for (int i = 0; i < MAX_MAP_SIZE * MAX_MAP_SIZE; i++) {
		queue.arrQueue[i].xPos = -1;
		queue.arrQueue[i].yPos = -1;
		queue.arrQueue[i].length = -1;
	}
	queue.front = -1;
	queue.back = -1;

	return;
}
#if DEBUG
void printGraph(void)
{
	printf("graph\n");
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			printf("%d ", graph[i][j].islandNum);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
#endif
