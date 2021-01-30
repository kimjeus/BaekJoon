#include "balanced_world.h"

bool empty(stack *st)
{
	if (st->Top == -1) {
		return true;
	}
	else {
		return false;
	}
}
void pop(stack *st)
{
	if (!empty(st)) {
		st->stackMem[st->Top--] = '\0';
	}
	return;
}
void push(stack *st, char inputCh)
{
	//Top <= MAX_STRING_SIZE - 1 만족해야함
	if (st->Top < MAX_STRING_SIZE - 1) {
		st->stackMem[++st->Top] = inputCh;
	}
	return;
}
size_t size(stack *st)
{
	return (size_t)(st->Top + 1);
}
char top(stack *st)
{
	return st->stackMem[st->Top];
}
void initStack(stack *st)
{
	for (int i = 0; i < MAX_STRING_SIZE + 1; i++) {
		st->stackMem[i] = '\0';
	}
	st->Top = -1;
}
void initInputStr(char *inputStr)
{
	//inputStr 초기화
	for (int i = 0; i < MAX_STRING_SIZE; i++) {
		inputStr[i] = '\0';
	}
	return;
}
