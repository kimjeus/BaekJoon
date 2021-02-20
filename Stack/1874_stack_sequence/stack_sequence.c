#include "stack_sequence.h"

bool judgeStackSequence(int *ptrSequence, int n)
{
	int stackIndex = 0;
	int resultIndex = 0;
	int top = -1;
	int curStack = 1;

	for (int i = 0; i < n; i++) {
		//stack 비어있음
		if (top == -1) {
			arrStack[++top] = curStack++;
			arrResult[resultIndex++] = '+';
		}
		//stack 값이 같아질 때까지 push
		while (arrStack[top] < ptrSequence[i]) {
			arrStack[++top] = curStack++;
			arrResult[resultIndex++] = '+';
		}
		//stack 값과 같으면 pop
		if (arrStack[top] == ptrSequence[i]) {
			arrStack[top--] = 0;
			arrResult[resultIndex++] = '-';
		}
		//stack 값보다 크면 불가능 수열
		else {
			return false;
		}
	}

	for (int i = 0; i < 2 * n; i++) {
		printf("%c\n", arrResult[i]);
	}

	return true;
}
