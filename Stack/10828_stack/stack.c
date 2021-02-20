#include "stack.h"

void push(SStack *struStack, int X)
{
	struStack->mArrStack[++struStack->top] = X;

	return;
}

void pop(SStack *struStack)
{
	if (struStack->top != -1) {
		printf("%d\n", struStack->mArrStack[struStack->top]);
		struStack->mArrStack[struStack->top--] = 0;
	}
	else {
		printf("-1\n");
	}

	return;
}

void size(SStack *struStack)
{
	printf("%d\n", struStack->top + 1);

	return;
}

void empty(SStack *struStack)
{
	if (struStack->top == -1) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}

	return;
}

void top(SStack *struStack)
{
	if (struStack->top == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", struStack->mArrStack[struStack->top]);
	}

	return;
}
