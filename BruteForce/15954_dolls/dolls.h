#include <stdio.h>
#include <math.h>

#define DEBUG 0
#define MAX_DOLL_COUNT 500

//input 값 저장
int arrInput[MAX_DOLL_COUNT];
//input에서 choiceBruteForce로 선택된 인형들 배열
int arrChoice[MAX_DOLL_COUNT];
//arrChoice 배열의 index
int arrChoiceIdx;
//N : 인형 개수, K : 최소 선택 인형 개수
int N, K;
//표준 편차의 최솟값
double result;

//input에서 표준편차를 계산할 인형 선택하는 함수
void choiceBruteForce(int);
//현재 arrChoice 에 들어있는 인형들의 표준편차를 계산하는 함수
void calcDeviation(void);
