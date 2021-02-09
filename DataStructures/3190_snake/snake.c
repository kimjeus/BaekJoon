#include "snake.h"

void move(void)
{
	int dirChgIdx = 0;
	Pos curPos;
	Pos bfPos;

	curPos.x = 1;
	curPos.y = 1;

	while (1) {
#if DEBUG
		/*
		printf("전환할 count: %d\n", dirChg[dirChgIdx].count);
		printf("현재 방향 x: %d, y: %d\n", input[curPos.x][curPos.y].dir.xChg, input[curPos.x][curPos.y].dir.yChg);
		printf("(%d, %d): %d\n", curPos.x, curPos.y, count);
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 9; j++) { 
				printf("%d:%d  ", j, input[i][j].snake);
			}
			printf("\n");
		}
		printf("\n");
		*/
				printf("(%d, %d)\n", curPos.x, curPos.y);
				printf("->%d, %d\n", input[curPos.x][curPos.y].dir.xChg, input[curPos.x][curPos.y].dir.yChg);
				printf("count:%d\n", count);
				printf("chC:%d\n", dirChg[dirChgIdx].count);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j<= N; j++)
				printf("a:%d%d\t", input[i][j].apple, input[i][j].apple);
			printf("\n");
			for (int j = 1; j<= N; j++)
				printf("sk:%d%d\t", input[i][j].snake, input[i][j].snake);
			printf("\n");
			printf("\n");
		}
		printf("==========================================\n");
#endif
		//방향 전환해야 하는지 검사
		if (dirChg[dirChgIdx].count == count) {
			input[curPos.x][curPos.y].dir = changeDir(input[curPos.x][curPos.y].dir, dirChg[dirChgIdx].dirC);
			dirChgIdx++;
		}
		//뱀의 머리 이동
		bfPos.x = curPos.x;
		bfPos.y = curPos.y;
		curPos.x += input[bfPos.x][bfPos.y].dir.xChg;
		curPos.y += input[bfPos.x][bfPos.y].dir.yChg;

		//뱀의 몸통(혹은 벽)이면 탈출
		if (input[curPos.x][curPos.y].snake) {
			count++;
			break;
		}
		//빈 공간이면 머리가 이동했으니까 뱀 몸통 있다고 갱신
		input[curPos.x][curPos.y].snake = true;

		//queue에 뱀 머리 갱신
		push(qu, curPos.x, curPos.y);

		//사과 없는지 검사
		if (!input[curPos.x][curPos.y].apple) {
			//queue에 뱀 꼬리 갱신
			Pos tmpPos = front(qu);
			pop(qu);
			//뱀 크기가 줄었으므로 꼬리부분 빈 공간으로 갱신
			input[tmpPos.x][tmpPos.y].snake = false;
		}
		else {
			input[curPos.x][curPos.y].apple = false;
		}

		//현재 좌표의 방향 갱신(지금 뱀 머리에는 아무 방향성이 저장 안되어 있으므로)
		input[curPos.x][curPos.y].dir = input[bfPos.x][bfPos.y].dir;
		count++;	//뱀의 이동 횟수 증가
	}
}

Dir changeDir(Dir dir, char way)
{
	Dir tmpDir;
	//왼쪽 방향 전환
	if (way == 'L') {
		//좌우로 움직이던 중이라면
		if (dir.xChg == 0) {
			tmpDir.xChg = dir.yChg * (-1);
			tmpDir.yChg = dir.xChg;
		}
		//위아래로 움직이던 중이라면
		else if (dir.yChg == 0) {
			tmpDir.xChg = dir.yChg;
			tmpDir.yChg = dir.xChg;
		}
	}

	//오른쪽 방향 전환
	else if (way == 'D') {
		//좌우로 움직이던 중이라면
		if (dir.xChg == 0) {
			tmpDir.xChg = dir.yChg;
			tmpDir.yChg = dir.xChg;
		}
		//위아래로 움직이던 중이라면
		else if (dir.yChg == 0) {
			tmpDir.xChg = dir.yChg;
			tmpDir.yChg = dir.xChg * (-1);
		}
	}
	return tmpDir;
}

bool empty(queue *qu)
{
	if (qu->front == qu->back) { return true; }
	else { return false; }
}
void pop(queue *qu)
{
	qu->front++;
	qu->mem[qu->front].x = 0;
	qu->mem[qu->front].y = 0;
	return;
}
void push(queue *qu, int x, int y)
{
	qu->back++;
	qu->mem[qu->back].x = x;
	qu->mem[qu->back].y = y;
	return;
}
size_t size(queue *qu) { return (size_t)(qu->back - qu->front); }
Pos front(queue *qu) { return qu->mem[qu->front + 1]; }
Pos back(queue *qu) { return qu->mem[qu->back]; }
void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_BOARD_SIZE; i++) {
		qu->mem[i].x = 0;
		qu->mem[i].y = 0;
	}
	qu->front = -1;
	qu->back = -1;
	return;
}
void initInput(void)
{
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			input[i][j].apple = false;
			input[i][j].snake = false;
			input[i][j].dir.xChg = 0;
			input[i][j].dir.yChg = 0;
			//Board의 외곽을 전부 뱀의 몸통이라고 생각하고 벽 대신 뱀의 몸통에 부딪히기만 하면 게임이 종료되도록 설정
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
				input[i][j].snake = true;
			}
		}
	}
	//출발 지점의 방향은 무조건 오른쪽이므로
	input[1][1].dir.yChg = 1;
	//출발 지점은 무조건 뱀이 있으므로
	input[1][1].snake = true;
	push(qu, 1, 1);
	return;
}
