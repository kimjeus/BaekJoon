#include "maximum_heap.h"

int main(void)
{
	int N = 0;	//연산의 개수
	int x = 0;	//입력 받은 연산 정보
	priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d" ,&x);
		if (x) { push(pq, x); }
		else {
			printf("%d\n", top(pq));
			pop(pq);
		}
	}

	free(pq);
	return 0;
}

