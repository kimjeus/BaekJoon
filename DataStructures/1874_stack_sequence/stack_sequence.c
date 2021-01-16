#include "stack_sequence.h"

bool judgeStackSequence(int *ptrSequence, int n)
{
	int maxLocation = 0;

	for (int i = 0; i < n; i++) {
		if (ptrSequence[i] == n) {
			maxLocation = i;
		}
	}

	for (int i = 0; i < maxLocation; i++) {
		if (ptrSequence[i] > ptrSequence[i + 1] + 1) {
			return false;
		}
	}

	for (int i = maxLocation + 1; i < n; i++) {
		if (ptrSequence[i] >= ptrSequence[i - 1]) {
			return false;
		}
	}

	return true;
}

void makeStackSequence(int *ptrSequence, int n)
{
	int topValue = 0, popCount = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= ptrSequence[i]; j++) {
			if (topValue + popCount < ptrSequence[i]) {
				topValue++;
				printf("+\n");
			}
			else {
				topValue--;
				popCount++;
				printf("-\n");
				break;
			}
		}
	}
}
