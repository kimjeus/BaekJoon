#include "maximum_heap.h"

void initPQ(priority_queue *pq)
{
	for (int i = 0; i < MAX_PQ_SIZE; i++)
		pq->mem[i] = 0;
	pq->back = 0;
	return;
}
bool empty(priority_queue *pq)
{
	if (!pq->back) { return true; }
	else { return false; }
}
void pop(priority_queue *pq)
{
	if (empty(pq)) { return; }
	pq->mem[1] = pq->mem[pq->back];
	pq->mem[pq->back--] = 0;
	if (empty(pq)) { return; }

	int parent = 1;
	int child = parent * 2;
	int pqSize = (int)size(pq);

	while (child <= pqSize) {
		if (child + 1 <= pqSize && pq->mem[child] < pq->mem[child + 1])
			child++;

		if (pq->mem[parent] < pq->mem[child]) {
			swapData(&pq->mem[parent], &pq->mem[child]);
			parent = child;
			child = parent * 2;
		}
		else { break; }
	}
	return;
}
void push(priority_queue *pq, int data)
{
	pq->mem[++pq->back] = data;
	if ((int)size(pq) == 1) { return; }

	int child = pq->back;
	int parent = child / 2;

	while (child > 1) {
		if (pq->mem[parent] < pq->mem[child]) {
			swapData(&pq->mem[parent], &pq->mem[child]);
			child = parent;
			parent = child / 2;
		}
		else { break; }
	}
	return;
}
size_t size(priority_queue *pq) { return (size_t)pq->back; }
int top(priority_queue *pq) { return pq->mem[1]; }
void swapData(int *pData, int *cData)
{
	int temp = 0;
	temp = *pData;
	*pData = *cData;
	*cData = temp;
	return;
}
