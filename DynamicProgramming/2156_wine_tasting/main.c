#include "wine_tasting.h"

int main(void)
{
	int n = 0; //포도주 잔의 개수	1 <= n <= 10,000
	int arrInput[MAX_WINE_NUM + 1];	//인자 번호에 들어 있는 포도주 양
	int arrDP[MAX_WINE_NUM + 1];	//인자 번호까지 마신 포도주 누적 최대량

	scanf("%d", &n);

	//포도주 양 입력값 저장(arrInput 초기화), arrDP 초기화
	arrInput[0] = 0;
	arrDP[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arrInput[i]);
		arrDP[i] = 0;
	}

	//1번과 2번 잔은 무조건 마실 수 있다.
	arrDP[1] = arrInput[1];
	arrDP[2] = arrInput[1] + arrInput[2];
	for (int i = 3; i <= n; i++) {
		//i번째 잔을 마시고 i - 1번째 잔을 안마셨을 때
		int drinkOne = arrDP[i - 2] + arrInput[i];
		//i번째 잔과 i - 1번째 잔을 마시고 i - 2번째 잔을 안마셨을 때
		int drinkTwo = arrDP[i - 3] + arrInput[i] + arrInput[i - 1];

		arrDP[i] = arrDP[i - 1];	//i번째 잔을 안마셨을 때
		arrDP[i] = (arrDP[i] > drinkOne) ? arrDP[i] : drinkOne;	//i번째 잔 마셨을 때
		arrDP[i] = (arrDP[i] > drinkTwo) ? arrDP[i] : drinkTwo;	//i, i-1 번째 잔 마셨을 때

#if DEBUG
		printf("i: %d\n", i);
		for (int j = 0; j <= i; j++) {
			printf("%d ", arrDP[j]);
		}
		printf("\n\n");
#endif
	}

	printf("%d\n", arrDP[n]);

	return 0;
}
