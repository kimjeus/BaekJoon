#include "bridge_building.h"

//모든 섬에 2, 3, 4, ... 순서로 번호 부여하는 함수
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
			push(frontXPos - 1, frontYPos, 0);	//아래쪽 좌표를 queue에 삽입
			graph[frontXPos - 1][frontYPos].islandNum = islandNum;	//queue에 삽입하는 좌표의 섬 번호 부여(앞으로 탐색이 안됨)
		}
		//위쪽 좌표가 islandNum 1인 초기 육지일 때
		if (frontXPos + 1 < mapSize && graph[frontXPos + 1][frontYPos].islandNum == 1) {
			push(frontXPos + 1, frontYPos, 0);	//상동
			graph[frontXPos + 1][frontYPos].islandNum = islandNum;
		}
		//왼쪽 좌표가 islandNum 1인 초기 육지일 때
		if (frontYPos - 1 >= 0 && graph[frontXPos][frontYPos - 1].islandNum == 1) {
			push(frontXPos, frontYPos - 1, 0);	//상동
			graph[frontXPos][frontYPos - 1].islandNum = islandNum;
		}
		//오른쪽 좌표가 islandNum 1인 초기 육지일 때
		if (frontYPos + 1 < mapSize && graph[frontXPos][frontYPos + 1].islandNum == 1) {
			push(frontXPos, frontYPos + 1, 0);	//상동
			graph[frontXPos][frontYPos + 1].islandNum = islandNum;
		}
		queue.front++;	//queue에서 탐색할 다음 데이터 가리킴
	}

	return;
}

//바다와 연결된 모든 섬 좌표와 섬 번호를 arrSideLand 에 저장
void sideLand(void)
{
	for (int i = 0; i < mapSize * mapSize; i++) {
		arrSideLand[i].xPos = -1;
		arrSideLand[i].yPos = -1;
		arrSideLand[i].length = 0;
	}
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			//섬 번호가 2 이상으로 부여 받고 && 옆에 바다가 있는 좌표라면 배열에 저장
			if (graph[i][j].islandNum > 1 && graph[i][j].side) {
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

//섬 번호가 다른 두 좌표 사이의 최단 거리를 계산해서 return 하는 함수
//경로가 없으면 return -1
int minRouteBFS(int startX, int startY, int endX, int endY)
{
	push(startX, startY, 0);	//출발 좌표 queue에 삽입
	queue.front++;	//-1에 있던 front 0으로 증가

	//도착 좌표에 도달한다면 두 좌표 사이의 거리를 return 하지만
	//도착 좌표에 결국 도달하지 못하고 queue가 비어버린다면 경로가 섬 내부에 갇히는 것이므로 -1 return
	//1 1 1 0
	//1 0 1 0
	//1 1 1 0
	//0 0 0 1	에서 (0, 1) 좌표는 바다를 끼고 있지만 (3, 3)에 도달 불가능
	while (!empty()) {
		int frontXPos = queue.arrQueue[queue.front].xPos;
		int frontYPos = queue.arrQueue[queue.front].yPos;
		int frontLength = queue.arrQueue[queue.front].length;

		//현재 좌표가 위쪽 벽에 붙어있지 않고 && 위쪽 좌표가 경로계산을 위한 방문을 아직 하지 않았을 때
		if (frontXPos - 1 >= 0 && !visited[frontXPos - 1][frontYPos]) {
			push(frontXPos - 1, frontYPos, frontLength + 1);	//위쪽 좌표 값과 거리 1 증가시켜서  queue에 삽입 
			visited[frontXPos - 1][frontYPos] = true;	//queue에 넣은 좌표는 방문했다고 check
			//만약 위쪽 좌표가 최종 좌표라면 저장된 거리 반환
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}
		//아래쪽 좌표로 상동
		if (frontXPos + 1 < mapSize && !visited[frontXPos + 1][frontYPos]) {
			push(frontXPos + 1, frontYPos, frontLength + 1);
			visited[frontXPos + 1][frontYPos] = true;
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}
		//왼쪽 좌표로 상동
		if (frontYPos - 1 >= 0 && !visited[frontXPos][frontYPos - 1]) {
			push(frontXPos, frontYPos - 1, frontLength + 1);
			visited[frontXPos][frontYPos - 1] = true;
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}
		//오른쪽 좌표로 상동
		if (frontYPos + 1 < mapSize && !visited[frontXPos][frontYPos + 1]) {
			push(frontXPos, frontYPos + 1, frontLength + 1);
			visited[frontXPos][frontYPos + 1] = true;
			if (visited[endX][endY]) {
				return queue.arrQueue[queue.back].length;
			}
		}

		queue.front++;
	}
	return -1;
}

//바다와 붙어 있는 육지에는 side 변수에 true 저장
void checkSide(void)
{
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (graph[i][j].islandNum > 0) {
				//위쪽 좌표가 바다(= 0)라면 true 저장
				//네 방면중 한 곳이 있든 전부 있든 상관 없으므로 하나라도 통과되면 더 이상 검사 안함
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
