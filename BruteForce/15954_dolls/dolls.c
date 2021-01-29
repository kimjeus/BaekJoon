#include "dolls.h"

void choiceBruteForce(int dollIdx)
{
	//arrChoice 배열 길이가 최소 선택 인형 개수보다 크거나 같을 때
	if (arrChoiceIdx >= K) {
		calcDeviation();
	}

	//dollIdx 위치의 인형 개수를 arrChoice에 추가
	arrChoice[arrChoiceIdx++] = arrInput[dollIdx];

	//연속된 위치에 있는 인형을 선택하므로 바로 다음 인형을 선택하거나 안하거나 둘 중 하나임.
	if (dollIdx < N) {
		choiceBruteForce(dollIdx + 1);
	}

	//backtracking을 위해 위에서 추가한 arrChoice 값 뺀다.
	arrChoice[--arrChoiceIdx] = 0;
	return;
}

void calcDeviation(void)
{
	int sum = 0;
	double avg = 0, varianceSum = 0, variance = 0, deviation = 0;

	//arrChoice의 합산 구함.
	for (int i = 0; i < arrChoiceIdx; i++) {
		sum += arrChoice[i];
	}
	//arrChoice의 평균 구함.
	avg = (double)sum / arrChoiceIdx;
	//분산 합 구함.
	for (int i = 0; i < arrChoiceIdx; i++) {
		varianceSum += pow(arrChoice[i] - avg, 2.0);
	}
	//분산 구함.
	variance = varianceSum / arrChoiceIdx;
	//표준 편차 구함.
	deviation = sqrt(variance);

#if DEBUG
	/*
	printf("arrChoice : ");
	for (int i = 0; i < arrChoiceIdx; i++) {
		printf("%d\t", arrChoice[i]);
	}
	*/
	printf("\nsum: %d, avg: %lf, variance: %lf, deviation: %lf\tresult: %lf", sum, avg, variance, deviation, result);
#endif

	//표준 편차를 처음 계산했을 때는 바로 result에 대입한다.
	if (result == -1) {
		result = deviation;
	}
	//표준 편차 최솟값 갱신
	if (result > deviation) {
		result = deviation;
	}

	return;
}
