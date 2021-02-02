#include "wine_tasting.h"

int main(void)
{
	int n = 0;	//포도잔의 개수 n (1 <= n <= 10,000)
	int num = 0;	//n을 3으로 나눈 몫 (나머지가 있다면 +1)
	short arrInput[MAX_WINE_NUM + 1];	//[1]부터 사용하기 위해 +1
	short arrThird[MAX_WINE_NUM / 3 + 1][4];	//wine을 3잔 단위로 묶어서 저장하고 나머지가 있다면 0으로 채운다.
//	Node arrResult[MAX_WINE_NUM / 3 + 1][MAX_RESULT_SIZE];
	Node **arrResult;
	int *resultSize;
	int beforeSize = 1;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%hd", &arrInput[i]);
	}
	num = (n % 3 == 0) ? n / 3 : n / 3 + 1;

	//arrResult 메모리 할당
	resultSize = (int *)malloc(sizeof(int) * (num + 1));
	arrResult = (Node **)malloc(sizeof(Node *) * (num + 1));
	arrResult[0] = (Node *)malloc(sizeof(Node));
	for (int i = 1; i <= num; i++) {
		arrResult[i] = (Node *)malloc(sizeof(Node) * (beforeSize + i + 1) + 1);
		beforeSize += i + 1;
		resultSize[i] = beforeSize;
	}
	/*
	for (int i = 0; i <= num; i++) {
		for (int j = 0;j <= MAX_RESULT_SIZE; j++) {
			arrResult[i][j].value = 0;
			arrResult[i][j].judge = 0;
		}
	}
	*/

	if (n % 3 == 1) {
		arrInput[n + 1] = 0;
		arrInput[n + 2] = 0;
	}
	else if (n % 3 == 2) {
		arrInput[n + 1] = 0;
	}

	for (int i = 0; i < num; i++) {
		arrThird[i + 1][1] = arrInput[i * 3 + 1] + arrInput[i * 3 + 2];
		arrThird[i + 1][2] = arrInput[i * 3 + 1] + arrInput[i * 3 + 3];
		arrThird[i + 1][3] = arrInput[i * 3 + 2] + arrInput[i * 3 + 3];
	}

	arrResult[1][1].value = arrThird[1][1];
	arrResult[1][1].judge = 1;
	arrResult[1][2].value = arrThird[1][2];
	arrResult[1][2].judge = 2;
	arrResult[1][3].value = arrThird[1][3];
	arrResult[1][3].judge = 3;

//	printResult(arrResult, num);
	for (int i = 2; i <= num; i++) {
//		int bfIdx = 1;
		int curIdx = 1;
//		while (arrResult[i - 1][bfIdx].value != 0) {
		for (int bfIdx = 1; bfIdx <= resultSize[i - 1]; bfIdx++) {
			if (arrResult[i - 1][bfIdx].judge == 1) {
				arrResult[i][curIdx].value = arrResult[i - 1][bfIdx].value + arrThird[i][1];
				arrResult[i][curIdx++].judge = 1;
				arrResult[i][curIdx].value = arrResult[i - 1][bfIdx].value + arrThird[i][2];
				arrResult[i][curIdx++].judge = 2;
				arrResult[i][curIdx].value = arrResult[i - 1][bfIdx].value + arrThird[i][3];
				arrResult[i][curIdx++].judge = 3;
			}
			else if (arrResult[i - 1][bfIdx].judge == 2) {
				arrResult[i][curIdx].value = arrResult[i - 1][bfIdx].value + arrThird[i][2];
				arrResult[i][curIdx++].judge = 2;
				arrResult[i][curIdx].value = arrResult[i - 1][bfIdx].value + arrThird[i][3];
				arrResult[i][curIdx++].judge = 3;
			}
			else if (arrResult[i - 1][bfIdx].judge == 3) {
				arrResult[i][curIdx].value = arrResult[i - 1][bfIdx].value + arrThird[i][3];
				arrResult[i][curIdx++].judge = 3;
			}
//	printResult(arrResult, num);
//			bfIdx++;
		}
	}

//	int Idx = 1;
	int result = arrResult[num][1].value;
	
//	while (arrResult[num][Idx].value != 0) {
	for (int Idx = 1; Idx <= resultSize[num]; Idx++) {
		if (result < arrResult[num][Idx].value) {
			result = arrResult[num][Idx].value;
		}
	}

	printf("%d\n", result);

	free(resultSize);
	for (int i = 1; i < num; i++) {
		free(arrResult[i]);
	}
	free(arrResult);
	return 0;
}
