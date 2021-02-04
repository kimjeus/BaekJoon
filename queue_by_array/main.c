#include "queue_by_array.h"

int main(void)
{
	char inString[MAX_INPUT_SIZE];
	Data tempData;
	queue *qu = (queue *)malloc(sizeof(queue));
	initQueue(qu);

	printf("Program Start\n\n");
	printf("Input Order\n");
	printf("empty , pop , push , size , front , back , print , exit\n");
	while (1) {
		//input이 EOF 이거나 exit 이면 프로그램 종료
		if (scanf("%s", inString) == EOF || !strcmp("exit", inString)) {
			printf("Program End\n");
			break;
		}
		else if (!strcmp("empty", inString)) {
			if (empty(qu)) {
				printf("true\n");
			}
			else {
				printf("false\n");
			}
		}
		else if (!strcmp("pop", inString)) {
			pop(qu);
		}
		else if (!strcmp("push", inString)) {
			scanf("%d %d", &tempData.xPos, &tempData.yPos);
			push(qu, &tempData);
		}
		else if (!strcmp("size", inString)) {
			printf("%zd\n", size(qu));
		}
		else if (!strcmp("front", inString)) {
			tempData = front(qu);
			printf("(%d, %d)\n", tempData.xPos, tempData.yPos);
		}
		else if (!strcmp("back", inString)) {
			tempData = back(qu);
			printf("(%d, %d)\n", tempData.xPos, tempData.yPos);
		}
		else if (!strcmp("print", inString)) {
			for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
				printf("(%d, %d)\n", qu->mem[i].xPos, qu->mem[i].yPos);
			}
		}
		else {
			printf("invalid order\n");
		}
		printf("\nInput Order\n");
		printf("empty , pop , push , size , front , back , print , exit\n");
	}

	free(qu);
	return 0;
}
