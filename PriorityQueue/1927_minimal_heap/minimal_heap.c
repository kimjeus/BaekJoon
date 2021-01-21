#include "minimal_heap.h"

void initPQ(void)
{
	pq.empty = empty;
	pq.pop = pop;
	pq.push = push;
	pq.size = size;
	pq.top = top;
	pq.mTop = -1;
	pq.mFront = -1;
	pq.mBack = -1;
	for (int i = 0; i < MAX_PQ_SIZE; i++) {
		pq.mArrValue[i] = 0;
	}

	return;
}

bool empty(void)
{
	if (pq.mBack < 0) {
		return true;
	}
	else {
		return false;
	}
}
void pop(void)
{
	return;
}
void push(unsigned int value)
{
	if (pq.mBack < MAX_PQ_SIZE) {
		pq.mArrValue[++pq.mBack] = value;
		pq.mSize++;
	}
	if (value < pq.mArrValue[pq.mTop]) {
		pq.mTop = pq.mBack;
	}
	return;
}
size_t size(void)
{
	return pq.mSize;
}
int top(void)
{
	if (pq.mSize > 0) {
		return pq.mArrValue[pq.mTop];
	}
	else {
		return 0;
	}
}
