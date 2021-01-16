#include "stack_sequence.h"

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
