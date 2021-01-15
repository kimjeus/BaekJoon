#include "queue.h"

void isPush(SQueue *ptrStruQueue, int pushValue)
{
	int front = ptrStruQueue->front;
	int back = ptrStruQueue->back;

	ptrStruQueue->mArrQueue[back + 1] = pushValue;
	back += 1;

	if (front == -1) {
		front = back;
	}

	ptrStruQueue->front = front;
	ptrStruQueue->back = back;

	return;
}

int isPop(SQueue *ptrStruQueue)
{
	int frontValue = ptrStruQueue->mArrQueue[ptrStruQueue->front];
	int front = ptrStruQueue->front;
	int back = ptrStruQueue->back;

	if (front == -1) {
		return -1;
	}
	else {
		if (front == back) {
			front = -1;
		}
		else {
			front += 1;
		}

		ptrStruQueue->front = front;
		ptrStruQueue->back = back;

		return frontValue;
	}
}

int isSize(SQueue *ptrStruQueue)
{
	if (ptrStruQueue->front == -1) {
		return 0;
	}
	else {
		return (ptrStruQueue->back - ptrStruQueue->front + 1);
	}
}

bool isEmpty(SQueue *ptrStruQueue)
{
	if (ptrStruQueue->front == -1) {
		return true;
	}
	else {
		return false;
	}
}

int isFront(SQueue *ptrStruQueue)
{
	if (ptrStruQueue->front == -1) {
		return -1;
	}
	else {
		return ptrStruQueue->mArrQueue[ptrStruQueue->front];
	}
}

int isBack(SQueue *ptrStruQueue)
{
	if (ptrStruQueue->front == -1) {
		return -1;
	}
	else {
		return ptrStruQueue->mArrQueue[ptrStruQueue->back];
	}
}
