#include "queue2.h"

bool empty(queue *qu)
{
	if (qu->front == qu->back) { return true; }
	else { return false; }
}
void pop(queue *qu)
{
	qu->front++;
	qu->mem[qu->front] = 0;
	return;
}
void push(queue *qu, int data)
{
	qu->back++;
	qu->mem[qu->back] = data;
	return;
}
size_t size(queue *qu) { return (size_t)(qu->back - qu->front); }
int front(queue *qu) { return qu->mem[qu->front + 1]; }
int back(queue *qu) { return qu->mem[qu->back]; }
void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
		qu->mem[i] = 0;
	qu->front = -1;
	qu->back = -1;
	return;
}
