#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX_OBJECT_COUNT 100
#define MAX_WEIGHT_BAG 100000

typedef struct _Node {
	int mWeight;
	int mValue;
} Node;

//input 물품과 무게를 저장하는 배열
Node arrInput[MAX_OBJECT_COUNT + 1];
//arrInput에서 가지고 갈 수 있는 물건의 조합으로 가장 큰 value값
int DPmap[MAX_OBJECT_COUNT + 1][MAX_WEIGHT_BAG];
//N : 물품의 수량, K : 배낭이 버틸 수 있는 최대 무게
int N, K;
//Brute Force 알고리즘으로도 해결이 가능하나 시간 부족 발생
/*
//arrInput에 저장된 순서대로 물품을 넣을 수 있는 모든 방식을 넣어보고 최댓값을 계속 갱신하는 함수
//인자 Node: 현재 무게와 가치 상황이 저장된 Node
//인자 int: 함수 내에서 배낭에 넣을지 말지 고민할 무게, 가치의 index
void weightBruteForce(Node *, int);
void sortArrInput(void);
*/
//Dynamic Programming 알고리즘으로 N, K까지 DPmap을 채움
void DP(void);
