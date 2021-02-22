#include "minimal_heap.h"

int main(void)
{
	int N = 0;	//연산의 개수
	int x = 0;	//입력받은 연산의 값
	priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));
	initPQ(pq);	//priority_queue 초기화

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
#if DEBUG
		printPQ(pq);
#endif
		scanf("%d", &x);
		if (x)
			push(pq, x);
		else {
			printf("%d\n", top(pq));
			pop(pq);
		}
	}

	free(pq);
	return 0;
}

