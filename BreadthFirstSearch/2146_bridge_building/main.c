#include "bridge_building.h"

int main(void)
{
	scanf("%d", &mapSize);

	initQueue();	//queue 초기화
	initGraph();	//graph 초기화
	//graph 값 입력 받아서 저장
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			scanf("%d", &graph[i][j].islandNum);
		}
	}

	int islandNum = 2;	//각 섬에 부여할 숫자
	//1로 저장한 육지를 섬 단위로 숫자 2부터 부여
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0;j < mapSize; j++) {
			if (graph[i][j].islandNum == 1) {
				giveIslandNumBFS(i, j, islandNum);	//(i, j) 위치에 연결된 육지에 islandNum 값으로 섬에 숫자 부여
				islandNum++;	//다음 섬의 숫자
			}
		}
	}
	//graph 출력
#if DEBUG
	printGraph();
#endif

	int min = mapSize + mapSize - 2;	//다리 길이의 최솟값 저장
	int temp = min;

	
	checkSide();
	sideLand();
	/*
	int oneLand = 0;
	for (oneLand = 0; oneLand < count; oneLand++) {
		if (arrSideLand[oneLand].length == 3) {
			break;
		}
	}
	if (oneLand == count) {
		printf("0\n");
		return 0;
	}
	*/
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (arrSideLand[j].length != arrSideLand[i].length) {
				initQueue();
				initVisited();
				visited[arrSideLand[j].xPos][arrSideLand[j].yPos] = false;
				temp = minRouteBFS(arrSideLand[i].xPos, arrSideLand[i].yPos, arrSideLand[j].xPos, arrSideLand[j].yPos);
				if (temp == -1) {
					continue;
				}
				else if (temp == 1) {
					printf("1\n");
					return 0;
				}
#if DEBUG
				printf("%d, %d\t%d, %d\t%d\n", arrSideLand[i].xPos, arrSideLand[i].yPos, arrSideLand[j].xPos, arrSideLand[j].yPos, temp);
#endif
				min = min > temp ? temp : min;
			}
		}
	}

	printf("%d\n", min - 1);


/*	
	initQueue();
	initVisited();
	visited[1][1] = false;
	printf("%d\n", minRouteBFS(0, 2, 1, 1));
	
	initQueue();
	initVisited();
	visited[1][1] = false;
	printf("%d\n", minRouteBFS(3, 2, 6, 8));
*/	

	return 0;
}
