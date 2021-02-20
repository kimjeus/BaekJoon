#include "greedy_panda.h"

int main(void)
{
	n = 0;
	result = 1;

	//대나무 숲의 입력값 받아서 저장
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &forest[i][j].bamboo);
			forest[i][j].day = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!forest[i][j].day)	//(i, j) 위치의 day가 갱신되어 있지 않다면 갱신해주는 함수 실행
				calculateDay(i, j);
			if (forest[i][j].day > result)	//(i, j)위치의 day가 최대 일수라면 결과값 갱신
				result = forest[i][j].day;
		}
	}

	printf("%d\n", result);

	return 0;
}

