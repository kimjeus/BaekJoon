#include "plain_backpack.h"

int main(void)
{
	//arrInput의 index
	//int arrInputIdx = 0;
	//지속적으로 배낭 상황을 저장할 현재 Node
	Node *currentNode;
	currentNode = (Node *)malloc(sizeof(Node));
	currentNode->mWeight = 0;
	currentNode->mValue = 0;

	//input 저장하기
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &arrInput[i].mWeight, &arrInput[i].mValue);
	}
//Brute Force 방법으로 풀 때
/*
	//arrInput 오름차순으로 정렬
	sortArrInput();
	//가방에 넣을 수 있는 모든 경우의 수 탐색하기
	for (int i = 0; i < N; i++) {
		weightBruteForce(currentNode, i);
	}
	printf("%d\n", result);
*/
	DP();
	printf("%d\n", DPmap[N][K]);

	free(currentNode);
	return 0;
}
