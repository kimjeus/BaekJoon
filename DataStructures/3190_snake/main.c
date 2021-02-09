#include "snake.h"

int main(void)
{
	int K = 0;	//사과의 개수
	int L = 0;	//방향 전환 개수
	int tmpX = 0, tmpY = 0;
	qu = (queue *)malloc(sizeof(queue));
	initQueue(qu);

	//입력값 받아서 저장하기
	scanf("%d", &N);
	getchar();
	scanf("%d", &K);
	getchar();
	initInput();
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &tmpX, &tmpY);
		getchar();
		input[tmpX][tmpY].apple = true;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &dirChg[i].count, &dirChg[i].dirC);
		getchar();
	}

	move();

	printf("%d\n", count);

	free(qu);
	return 0;
}
