#include <stdio.h>
#include <stdlib.h> //malloc, free
#include <stdbool.h>

bool judgeStackSequence(int *, int);
void makeStackSequence(int *, int);

int main(void)
{
	int n;
	int *ptrSequence;

	scanf("%d", &n);

	ptrSequence = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &ptrSequence[i]);
	}

	if (judgeStackSequence(ptrSequence, n)) {
		makeStackSequence(ptrSequence, n);
	}
	else {
		printf("NO\n");
	}

	free(ptrSequence);

	return 0;
}

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
