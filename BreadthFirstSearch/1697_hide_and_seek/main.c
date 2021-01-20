#include "hide_and_seek.h"

int main(void)
{
	int N = 0;

	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		visited[i] = false;
	}

	if (N == K) {
		printf("0\n");
		return 0;
	}
	else if (N > K) {
		printf("%d\n", N - K);
		return 0;
	}

	struResult.mPosition = 0;
	struResult.mSecond = MAX_QUEUE_SIZE;

	initArrStruQueue();
	DFS(N);

	printf("%d\n", struResult.mSecond);

	return 0;
}
