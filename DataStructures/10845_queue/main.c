#include "queue.h"

int main(void)
{
	int N = 0;
	int pushValue = 0;
	char arrInputString[20];

	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		struQueue.mArrQueue[i] = 0;
	}
	struQueue.front = -1;
	struQueue.back = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", arrInputString);

		if (!strcmp("push", arrInputString)) {
			scanf("%d", &pushValue);

			isPush(&struQueue, pushValue);
		}
		else if (!strcmp("pop", arrInputString)) {
			printf("%d\n", isPop(&struQueue));
		}
		else if (!strcmp("size", arrInputString)) {
			printf("%d\n", isSize(&struQueue));
		}
		else if (!strcmp("empty", arrInputString)) {
			if (isEmpty(&struQueue)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!strcmp("front", arrInputString)) {
			printf("%d\n", isFront(&struQueue));
		}
		else if (!strcmp("back", arrInputString)) {
			printf("%d\n", isBack(&struQueue));
		}
	}

	return 0;
}
