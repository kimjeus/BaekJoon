#include "tower.h"

bool empty(stack *st)
{
	if (st->Top == -1) { return true; }
	else { return false; }
}
void pop(stack *st)
{
	st->mem[st->Top].height = 0;
	st->mem[st->Top--].position = 0;
	return;
}
void push(stack *st, Node *node)
{
	st->mem[++st->Top].height = node->height;
	st->mem[st->Top].position = node->position;
	return;
}
size_t size(stack *st) { return (size_t)(st->Top + 1); }
Node *top(stack *st)
{
	Node *tempNode = (Node *)malloc(sizeof(Node));
	(*tempNode) = st->mem[st->Top];
	return tempNode;
}
void initStack(stack *st)
{
	for (int i =  0; i < MAX_STACK_SIZE; i++) {
		st->mem[i].height = 0;
		st->mem[i].position = 0; 
	}
	st->Top = -1;
	return;
}
