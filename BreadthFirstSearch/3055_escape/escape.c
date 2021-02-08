#include "escape.h"

void bfs(queue *quS, queue *quW)
{
	Pos temp;
	int tempC = 0;

	//'D'에 도착하거나 || 도달하지 못해서 quS 가 비었을 때 탈출
	while (arrIn[endX][endY].input == 'D' && !empty(quS)) {
		
		//S가 지도에 없다면 queue도 결국 비어서 탈출
		while (!empty(quS)) {
			temp = front(quS);
			//S로 확장했지만 *의 확장으로 queue에 있는 S가 먹혔을 때
			if (arrIn[temp.x][temp.y].input != 'S') {
				pop(quS);
				continue;
			}
			//현재 count와 동일한 값들만 queue에서 pop하기 위해 queue count 값저장
			tempC = arrIn[temp.x][temp.y].count;

			//count보다 큰 값을 가진 queue node는 다음에 pop한다
			if (count < tempC)
				break;

			tempC++;
			pop(quS);
			//S 상하좌우가 . 이면 S 로 변경
			for (int i = 0; i < 4; i++) {
				int xPos = temp.x + aCase[i][0];
				int yPos = temp.y + aCase[i][1];
				if (arrIn[xPos][yPos].input == '.') {
					arrIn[xPos][yPos].input = 'S';
					arrIn[xPos][yPos].count = tempC;
					push(quS, xPos, yPos);
				}
				//만약 도착 지점이면 도착했음을 알리는 값으로 변경
				else if (arrIn[xPos][yPos].input == 'D') {
					arrIn[xPos][yPos].input = 'E';
					arrIn[xPos][yPos].count = tempC;
				}
			}
		}

		//*가 비었다면 탈출
		while (!empty(quW)) {
			temp = front(quW);
			tempC = arrIn[temp.x][temp.y].count;
			
			//queue node의 값이 count보다 크면 다음에 pop한다
			if (count < tempC)
				break;

			tempC++;
			pop(quW);
			//* 상하좌우가 D, X가 아니라면 * 로 변경
			for (int i = 0; i < 4; i++) {
				int xPos = temp.x + aCase[i][0];
				int yPos = temp.y + aCase[i][1];
				if (arrIn[xPos][yPos].input == '.' || arrIn[xPos][yPos].input == 'S') {
					arrIn[xPos][yPos].input = '*';
					arrIn[xPos][yPos].count = tempC;
					push(quW, xPos, yPos);
				}
			}
		}
		//이동 횟수 증가
		count++;
	}
	return;
}

void initCase(void)
{
	aCase[0][0] = 1;
	aCase[0][1] = 0;
	aCase[1][0] = -1;
	aCase[1][1] = 0;
	aCase[2][0] = 0;
	aCase[2][1] = 1;
	aCase[3][0] = 0;
	aCase[3][1] = -1;
	return;
}

#if DEBUG
void printInput(void)
{
	printf("graph\n");
	for (int i = 0; i <= R + 1; i++) {
		for (int j = 0; j <= C + 1; j++) {
			printf("%c", arrIn[i][j].input);
		}
		printf("\n");
	}
	printf("\n");
}
void printQueue(queue *qu)
{
	for (int i = 0; i < 15; i++) {
		printf("(%d, %d)\t", qu->mem[i].x, qu->mem[i].y);
	}
	printf("\n");
	for (int i = 0; i < 15; i++) {
		printf("%d\t", arrIn[qu->mem[i].x][qu->mem[i].y].count);
	}
	printf("\n");
	return;
}
#endif

bool empty(queue *qu)
{
	if (qu->Back == qu->Front) { return true; }
	else { return false; }
}
void pop(queue *qu)
{
	qu->mem[++qu->Front].x = 0;
	qu->mem[qu->Front].y = 0;
	return;
}
void push(queue *qu, int x, int y)
{
	qu->mem[++qu->Back].x = x;
	qu->mem[qu->Back].y = y;
	return;
}
size_t size(queue *qu) { return (size_t)(qu->Back - qu->Front); }
Pos front(queue *qu) { return qu->mem[qu->Front + 1]; }
Pos back(queue *qu) { return qu->mem[qu->Back]; }
void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		qu->mem[i].x = 0;
		qu->mem[i].y = 0;
	}
	qu->Front = -1;
	qu->Back = -1;
	return;
}
