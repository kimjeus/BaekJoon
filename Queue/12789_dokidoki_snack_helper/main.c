#include "dokidoki_snack_helper.h"

int main(void)
{
	int N = 0;	//간식을 받는 학생들의 수
	int input = 0;
	bool result = true;
	stack *st = (stack *)malloc(sizeof(stack));
	queue *qu = (queue *)malloc(sizeof(queue));

	initStack(st);
	initQueue(qu);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		pushQu(qu, input);
	}

	sortingLine(N, &result, st, qu);
	if (result)
		printf("Nice\n");
	else
		printf("Sad\n");

	free(st);
	free(qu);
	return 0;
}

