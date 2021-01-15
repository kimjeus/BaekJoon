#include "stack.h"

int main(void)
{
	int N, input;
	char arrCommand[20];

	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		struStack.mArrStack[i] = 0;
	}
	struStack.top = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", arrCommand);

		if (!strcmp("push", arrCommand)) {
			scanf("%d", &input);

			push(&struStack, input);
		}
		else if (!strcmp("pop", arrCommand)) {
			pop(&struStack);
		}
		else if (!strcmp("size", arrCommand)) {
			size(&struStack);
		}
		else if (!strcmp("empty", arrCommand)) {
			empty(&struStack);
		}
		else if (!strcmp("top", arrCommand)) {
			top(&struStack);
		}
	}

	return 0;
}
