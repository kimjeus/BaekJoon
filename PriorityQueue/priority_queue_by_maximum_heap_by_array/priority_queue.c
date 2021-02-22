#include "priority_queue.h"

void initPQ(priority_queue *pq)
{
	for (int i = 0; i < MAX_PQ_SIZE; i++)
		initData(&pq->mem[i]);
	pq->back = 0;
}
void initData(Data *data)
{
	data->xPos = 0;
	data->yPos = 0;
	data->pri = 0;
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
	pq->mem[1] = pq->mem[pq->back];	//마지막 노드 루트로 이동
	initData(&pq->mem[pq->back--]);	//마지막 노드 pop
	if (empty(pq)) { return; }

	int curSize = (int)size(pq);
	int parent = 1;
	int child = parent * 2;

	while (child <= curSize) {
		if (child + 1 <= curSize && pq->mem[child].pri < pq->mem[child + 1].pri) { child++; }	//두 자식 중 우선순위가 높은 child 선택

		if (pq->mem[parent].pri < pq->mem[child].pri)	{	//자식의 우선순위가 높으면 부모와 변경
			swapData(&pq->mem[parent], &pq->mem[child]);
			parent = child;
			child = parent * 2;
		}
		else { break; }
	}
	return;
}
void push(priority_queue *pq, Data data)
{
	pq->mem[++pq->back] = data;
	if ((int)size(pq) == 1) { return; }

	int child = pq->back;
	int parent = child / 2;

	while (child != 1) {	//부모가 없을 때까지 반복
		if (pq->mem[parent].pri < pq->mem[child].pri) {
			swapData(&pq->mem[parent], &pq->mem[child]);
			child = parent;
			parent = child / 2;
		}
		else { break; }
	}
	return;
}
size_t size(priority_queue *pq) { return (size_t)pq->back; }
Data top(priority_queue *pq) { return pq->mem[1]; }
void swapData(Data *pData, Data *cData)
{
	Data tmpData;
	tmpData = *pData;
	*pData = *cData;
	*cData = tmpData;
	return;
}
