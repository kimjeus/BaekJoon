#include "dolls.h"

int main(void)
{
	//input 받기
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arrInput[i]);
	}
	result = -1;

	//표준 편차를 계산할 인형들 선택하기
	for (int i = 0; i < N; i++) {
		choiceBruteForce(i);
	}
	
	printf("%.7lf\n", result);

	return 0;
}
