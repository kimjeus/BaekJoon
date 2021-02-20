#include "editor.h"

bool empty(stack *st)
{
	if (st->Top == -1)
		return true;
	else
		return false;
}
void pop(stack *st)
{
	if (st->Top == -1)
		return;

	st->memory[st->Top] = '\0';
	st->Top--;

	return;
}
void push(stack *st, char value)
{
	if (st->Top == MAX_STACK_SIZE - 1)
		return;

	st->Top++;
	st->memory[st->Top] = value;

	return;
}
size_t size(stack *st)
{
	return (size_t)(st->Top + 1);
}
char top(stack *st)
{
	if (st->Top == -1)
		return '\0';
	else
		return st->memory[st->Top];
}
void initStack(stack *st)
{
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		st->memory[i] = '\0';
	}
	st->Top = -1;

	return;
}
