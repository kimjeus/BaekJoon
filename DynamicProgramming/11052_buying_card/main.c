#include "buying_card.h"

int main(void)
{
	int P[MAX_INPUT_SIZE];	//입력값
	int result[MAX_INPUT_SIZE];
	int size;	//입력 개수

	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
		scanf("%d", &P[i]);

	result[1] = P[1];
	for (int i = 2; i <= size; i++) {
		result[i] = P[i];
		calculate(result, i);
	}

	printf("%d\n", result[size]);

	return 0;
}

