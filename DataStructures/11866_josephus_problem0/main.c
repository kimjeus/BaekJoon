#include "josephus_problem0.h"

int main(void)
{
	int N = 0, K = 0;	//사람의 수 N, K번째 사람 제거
	int temp = 0;
	queue *qu = (queue *)malloc(sizeof(queue));

	initQueue(qu);
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		push(qu, i + 1);
	}

#if DEBUG
	printQueue(qu, N);
#endif

	printf("<");
	for (int i = 1; i <= N; i++) {
		if (i != 1) {
			printf(", ");
		}
		for (int j = 0; j < K - 1; j++) {
			temp = front(qu);
			pop(qu);
			push(qu, temp);
#if DEBUG
	printQueue(qu, N);
#endif
		}
		temp = front(qu);
		pop(qu);
		printf("%d", temp);
#if DEBUG
	printQueue(qu, N);
#endif
	}
	printf(">\n");

	free(qu);
	return 0;
}
