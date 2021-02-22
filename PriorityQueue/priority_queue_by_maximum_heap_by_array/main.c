#include "priority_queue.h"

int main(void)
{
	char inStr[20];
	Data inData;
	priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));
	initPQ(pq);
	initData(&inData);

	while (1) {
		printf("Input Command: ");
		scanf("%s", inStr);

		if (!strcmp(inStr, "empty")) {
			if (empty(pq)) { printf("true\n"); }
			else { printf("false\n"); }
		}
		else if (!strcmp(inStr, "pop")) { pop(pq); }
		else if (!strcmp(inStr, "push")) {
			printf("Input Data: ");
			scanf("%d %d %d", &inData.xPos, &inData.yPos, &inData.pri);
			push(pq, inData);
		}
		else if (!strcmp(inStr, "size")) { printf("%d\n", (int)size(pq)); }
		else if (!strcmp(inStr, "top")) {
			inData = top(pq);
			printf("(%d, %d): %d\n", inData.xPos, inData.yPos, inData.pri);
		}
		else if (!strcmp(inStr, "print")) {
			int cur = 1;

			for (int i = 1; i <= (int)size(pq); i++) {
				if (i >= cur * 2) {
					printf("\n");
					cur *= 2;
				}
				printf("(%d, %d): %d\t", pq->mem[i].xPos, pq->mem[i].yPos, pq->mem[i].pri);
			}
			printf("\n");
		}
		else if (!strcmp(inStr, "help")) { printf("empty\npop\npush\nsize\ntop\nprint\nhelp\nexit\n"); }
		else if (!strcmp(inStr, "exit")) { break; }
		else { printf("Unknown Command\n"); }
	}

	free(pq);
	return 0;
}

