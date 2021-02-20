#include "queue2.h"

int main(void)
{
	int N = 0;	//명령어의 개수
	int tmp = 0;
	char inStr[6];

	scanf("%d", &N);
	qu = (queue *)malloc(sizeof(queue));
	initQueue(qu);

	for (int i = 0; i < N; i++) {
		scanf("%s", inStr);
		if (!strcmp(inStr, "empty")) {
			if (empty(qu))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(inStr, "pop")) {
			if (empty(qu))
				printf("-1\n");
			else {
				tmp = front(qu);
				pop(qu);
				printf("%d\n", tmp);
			}
		}
		else if (!strcmp(inStr, "push")) {
			scanf("%d", &tmp);
			push(qu, tmp);
		}
		else if (!strcmp(inStr, "size")) {
			printf("%d\n", (int)size(qu));
		}
		else if (!strcmp(inStr, "front")) {
			if (empty(qu))
				printf("-1\n");
			else
				printf("%d\n", front(qu));
		}
		else if (!strcmp(inStr, "back")) {
			if (empty(qu))
				printf("-1\n");
			else
				printf("%d\n", back(qu));
		}
		else
			printf("unknown order\n");
	}

	free(qu);
	return 0;
}

