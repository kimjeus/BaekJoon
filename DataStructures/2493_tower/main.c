#include "tower.h"

int main(void)
{
	int N;	//tower의 개수
	//0에는 최대 크기의 벽이 있다고 생각하고 1부터 입력 받은 tower의 높이 저장
	int arrInputTower[MAX_STACK_SIZE + 1];
	int arrResultTower[MAX_STACK_SIZE + 1];
	stack *st = (stack *)malloc(sizeof(stack));
	Node tempNode;

	scanf("%d", &N);
	//제일 앞의 타워에 부딪히면 수신할 탑이 없는거로 인식
	arrInputTower[0] = MAX_TOWER_HEIGHT + 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arrInputTower[i]);
	}

	for (int i = N; i >= 0; i--) {
		//stack이 비어있으면 현재 높이와 위치를 push하고 다음 for문으로
		while (!empty(st)) {
			//stack의 top이 현재 높이의 타워에 수신된다면 result에 저장
			if (top(st)->height < arrInputTower[i]) {
				arrResultTower[top(st)->position] = i;
				pop(st);
			}
			//stack의 top이 현재 높이의 타워에 수신되지 않는다면(stack의 top 높이보다 현재 높이가 더 낮다면) 더 이상 탐색할 필요가 없음
			//(과거에 stack에 쌓인 높이보다 낮은 높이만 stack에 쌓이기 때문)
			else {
				break;
			}
		}
		tempNode.height = arrInputTower[i];
		tempNode.position = i;
		push(st, &tempNode);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", arrResultTower[i]);
	}

	free(st);
	return 0;
}
