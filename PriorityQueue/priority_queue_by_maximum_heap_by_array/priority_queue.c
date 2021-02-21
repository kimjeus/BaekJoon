#include "priority_queue.h"

void initPriQueue(priQueue *pQu)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
		initData(&pQu->mem[i]);
	pQu->back = 0;
}
void initData(Data *data)
{
	data->xPos = 0;
	data->yPos = 0;
	data->pri = 0;
	return;
}
bool empty(priQueue *pQu)
{
	if (!pQu->back) { return true; }
	else { return false; }
}
void pop(priQueue *pQu)
{
	if (!empty(pQu)) {
		pQu->mem[1] = pQu->mem[pQu->back];	//마지막 노드 루트로  이동
		initData(&pQu->mem[pQu->back--]);		//마지막 노드 pop

		int curSize = (int)size(pQu);
		int parent = 1;
		int child = 2;

		while (child <= curSize) {
			if (child + 1 <= curSize && pQu->mem[child].pri < pQu->mem[child + 1].pri)	//두 자식 중 우선순위가 높은 child 선택
				child++;
			if (pQu->mem[parent].pri < pQu->mem[child].pri)	{	//자식의 우선순위가 높으면 부모와 변경
				swapData(&pQu->mem[parent], &pQu->mem[child]);
				parent = child;
				child = parent * 2;
			}
			else
				break;
		}
	}
	return;
}
void push(priQueue *pQu, Data data)
{
	pQu->mem[++pQu->back] = data;
	if (!empty(pQu)) {
		int child = pQu->back;
		int parent = child / 2;

		while (child != 1) {	//부모가 없을 때까지 반복
			if (pQu->mem[parent].pri < pQu->mem[child].pri) {
				swapData(&pQu->mem[parent], &pQu->mem[child]);
				child = parent;
				parent = child / 2;
			}
			else
				break;
		}
	}
	return;
}
size_t size(priQueue *pQu) { return (size_t)pQu->back; }
Data top(priQueue *pQu) { return pQu->mem[1]; }
void swapData(Data *pData, Data *cData)
{
	Data tmpData;
	
	tmpData = *pData;
	*pData = *cData;
	*cData = tmpData;

	return;
}
