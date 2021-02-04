#include "card2.h"

int main(void)
{
	int N = 0;	//카드의 장수
	int temp = 0;
	queue *qu = (queue *)malloc(sizeof(queue));
	initQueue(qu);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		push(qu, i);
	}

	while ((int)size(qu) > 1) {
		pop(qu);
		if ((int)size(qu) > 1) {
			temp = front(qu);
			pop(qu);
			push(qu, temp);
		}
		else {
			break;
		}
	}

	printf("%d\n", back(qu));

	free(qu);
	return 0;
}
