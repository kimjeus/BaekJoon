#include "escape.h"

int main(void)
{
	queue *quS = (queue *)malloc(sizeof(queue));
	queue *quW = (queue *)malloc(sizeof(queue));
	initQueue(quS);
	initQueue(quW);
	initCase();

	count++;
	//input graph 입력 받기
	scanf("%d %d", &R, &C);
	
	//테두리 전부 벽 'X' 로 채움
	for (int i = 0; i <= R + 1; i++) {
		arrIn[i][0].input = 'X';
		arrIn[i][C + 1].input = 'X';
	}
	for (int i = 0; i <= C + 1; i++) {
		arrIn[0][i].input = 'X';
		arrIn[R + 1][i].input = 'X';
	}

	getchar();	//scanf로 인한 입력 버퍼의 \n 제거

	//graph 입력 받아서 저장
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%c", &arrIn[i][j].input);

			//시작 좌표 push
			if (arrIn[i][j].input == 'S') {
				push(quS, i, j);
				arrIn[i][j].count = count;
			}
			//끝 좌표 저장
			if (arrIn[i][j].input == 'D') {
				endX = i;
				endY = j;
			}
			//물 좌표 push
			if (arrIn[i][j].input == '*') {
				push(quW, i, j);
				arrIn[i][j].count = count;
			}
		}
		getchar();	//scanf로 인한 입력 버퍼의 \n 제거
	}

	bfs(quS, quW);

	if (arrIn[endX][endY].input == 'E')
		printf("%d\n", arrIn[endX][endY].count - 1);
	else
		printf("KAKTUS\n");

	free(quS);
	free(quW);
	return 0;
}
