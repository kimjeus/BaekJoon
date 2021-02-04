#include "queue_by_array.h"

bool empty(queue *qu)
{
	if (qu->Front == qu->Back) { return true; }
	else { return false; }
}
void pop(queue *qu)
{
	if (empty(qu)) {
		printf("queue is empty\n");
		return;
	}
	qu->Front = (qu->Front + 1) % MAX_QUEUE_SIZE;
	qu->mem[qu->Front].xPos = -1;
	qu->mem[qu->Front].yPos = -1;
	return;
}
void push(queue *qu, Data *data)
{
	if ((qu->Back + 1) % MAX_QUEUE_SIZE == qu->Front) {
		printf("queue is full\n");
		return;
	}
	qu->Back = (qu->Back + 1) % MAX_QUEUE_SIZE;
	qu->mem[qu->Back].xPos = data->xPos;
	qu->mem[qu->Back].yPos = data->yPos;
	return;
}
size_t size(queue *qu)
{
	return (size_t)((qu->Back >= qu->Front) ? qu->Back - qu->Front : qu->Back - qu->Front + MAX_QUEUE_SIZE);
}
Data front(queue *qu)
{
	if (empty(qu)) {
		printf("queue is empty\n");
	}
	return qu->mem[(qu->Front + 1) % MAX_QUEUE_SIZE];
}
Data back(queue *qu)
{
	if (empty(qu)) {
		printf("queue is empty\n");
	}
	return qu->mem[qu->Back];
}
void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		qu->mem[i].xPos = -1;
		qu->mem[i].yPos = -1;
	}
	qu->Front = MAX_QUEUE_SIZE - 1;
	qu->Back = MAX_QUEUE_SIZE - 1;

	return;
}
