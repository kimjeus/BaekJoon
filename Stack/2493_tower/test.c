#include <stdio.h>

int main(void)
{
	int N;	//tower의 개수
	//0에는 최대 크기의 벽이 있다고 생각하고 1부터 입력 받은 tower의 높이 저장
	int arrInputTower[MAX_STACK_SIZE + 1];
	int arrResultTower[MAX_STACK_SIZE + 1];

	scanf("%d", &N);
	//제일 앞의 타워에 부딪히면 수신할 탑이 없는거로 인식
	arrInputTower[0] = MAX_TOWER_HEIGHT;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arrInputTower[i]);
	}

	for (int i = N; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (arrInputTower[i] < arrInputTower[j]) {
				arrResultTower[i] = j;
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", arrResultTower[i]);
	}

	return 0;
}
