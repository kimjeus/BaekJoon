#include "card2.h"

bool empty(queue *qu)
{
	if (qu->Front == qu->Back) { return true; }
	else { return false; }
}
void pop(queue *qu)
{
	qu->Front++;
	qu->mem[qu->Front] = 0;
	return;
}
void push(queue *qu, int data)
{
	qu->Back++;
	qu->mem[qu->Back] = data;
	return;
}
size_t size(queue *qu) { return (size_t)(qu->Back - qu->Front); }
int front(queue *qu) { return qu->mem[qu->Front + 1]; }
int back(queue *qu) { return qu->mem[qu->Back]; }
void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		qu->mem[i] = 0;
	}
	qu->Front = -1;
	qu->Back = -1;
	return;
}
