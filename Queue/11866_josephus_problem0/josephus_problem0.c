#include "josephus_problem0.h"

bool empty(queue *qu)
{
	if (qu->Front == qu->Back) { return true; }
	else { return false; }
}
void pop(queue *qu)
{
	qu->Front = (qu->Front + 1) % MAX_QUEUE_SIZE;
	qu->mem[qu->Front] = 0;
	return;
}
void push(queue *qu, int data)
{
	qu->Back = (qu->Back + 1) % MAX_QUEUE_SIZE;
	qu->mem[qu->Back] = data;
	return;
}
size_t size(queue *qu)
{
	if (qu->Back >= qu->Front)
		return qu->Back - qu->Front;
	else
		return (qu->Back - qu->Front) + MAX_QUEUE_SIZE;
}
int front(queue *qu) { return qu->mem[(qu->Front + 1) % MAX_QUEUE_SIZE]; }
int back(queue *qu) { return qu->mem[qu->Back]; }
void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		qu->mem[i] = 0;
	}
	qu->Front = MAX_QUEUE_SIZE - 1;
	qu->Back = MAX_QUEUE_SIZE - 1;
	return;
}

#if DEBUG
	void printQueue(queue *qu, int N)
	{
		printf("\nprintQueue\n");
		for (int i = 0; i < 2 * N; i++) {
			printf("%d ", qu->mem[i]);
		}
		printf("\nfront(%d): %d, back(%d): %d\n", qu->Front, front(qu), qu->Back, back(qu));
		return;
	}
#endif
