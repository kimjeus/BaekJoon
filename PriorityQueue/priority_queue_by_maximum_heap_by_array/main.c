#include "priority_queue.h"

int main(void)
{
	char inStr[20];
	Data inData;
	priQueue *pQu = (priQueue *)malloc(sizeof(priQueue));
	initPriQueue(pQu);
	initData(&inData);

	while (1) {
		printf("Input Command: ");
		scanf("%s", inStr);

		if (!strcmp(inStr, "empty")) {
			if (empty(pQu)) { printf("true\n"); }
			else { printf("false\n"); }
		}
		else if (!strcmp(inStr, "pop"))
			pop(pQu);
		else if (!strcmp(inStr, "push")) {
			printf("Input Data: ");
			scanf("%d %d %d", &inData.xPos, &inData.yPos, &inData.pri);
			push(pQu, inData);
		}
		else if (!strcmp(inStr, "size"))
			printf("%d\n", (int)size(pQu));
		else if (!strcmp(inStr, "top")) {
			inData = top(pQu);
			printf("(%d, %d): %d\n", inData.xPos, inData.yPos, inData.pri);
		}
		else if (!strcmp(inStr, "print")) {
			int cur = 1;

			for (int i = 1; i <= (int)size(pQu); i++) {
				if (i >= cur * 2) {
					printf("\n");
					cur *= 2;
				}
				printf("(%d, %d): %d\t", pQu->mem[i].xPos, pQu->mem[i].yPos, pQu->mem[i].pri);
			}
			printf("\n");
		}
		else if (!strcmp(inStr, "exit"))
			break;
		else
			printf("Unknown Command\n");
	}

	free(pQu);
	return 0;
}

