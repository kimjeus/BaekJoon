#include "value_of_parentheses.h"

bool empty(stack *st)
{
	if (st->Top == -1) { return true; }
	else { return false; }
}
void pop(stack *st)
{
	st->mem[st->Top--] = '\0';
	return;
}
void push(stack *st, char inputCh)
{
	st->mem[++st->Top] = inputCh;
	return;
}
size_t size(stack *st) { return (size_t)(st->Top + 1); }
char top(stack *st) { return st->mem[st->Top]; }
void initStack(stack *st)
{
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		st->mem[i] = '\0';
	}
	st->Top = -1;
	return;
}
