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

	
	checkSide();	//섬의 가장자리가 될 수 있는 조건 중 하나가 옆에 0인 바다가 최소 한개 이상 붙어있어야 하므로 옆에 바다가 붙어있는지 여부를 true false로 저장
	sideLand();		//섬의 가장자리 육지만 필요하므로 뽑아서 따로 배열 생성

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			//현재 좌표의 섬 번호와 다른 섬 번호라면
			if (arrSideLand[j].length != arrSideLand[i].length) {
				initQueue();	//queue 초기화
				initVisited();	//방문 여부 초기화
				visited[arrSideLand[j].xPos][arrSideLand[j].yPos] = false;	//목표 섬은 방문되어 있다는 표시를 지워줘야 도달 가능
				temp = minRouteBFS(arrSideLand[i].xPos, arrSideLand[i].yPos, arrSideLand[j].xPos, arrSideLand[j].yPos);	//i 섬 좌표로부터 j 섬 좌표까지의 거리 계산
				//한 개의 섬에 둘러싸야 있는 경로는 목표에 도달하지 못하는 경우가 생김(옆이 바다가 있다고 해서 무조건 다른 섬에 도달 가능한 경우가 아니기 때문)
				if (temp == -1) {
					continue;
				}
				//섬 사이의 거리가 최소 2이므로 더 이상 탐색할 필요가 없을 때는 빠르게 프로그램 종료를 시켜준다.
				else if (temp == 2) {
					printf("1\n");
					return 0;
				}

				min = min > temp ? temp : min;	//최솟값 갱신
			}
		}
	}

	printf("%d\n", min - 1);

	return 0;
}
