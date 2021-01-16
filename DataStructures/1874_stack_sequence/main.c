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
	for (int i = 0; i < 100000; i++) {
		arrStack[i] = 0;
	}

	if (!judgeStackSequence(ptrSequence, n)) {
		printf("NO\n");
	}

	free(ptrSequence);

	return 0;
}
