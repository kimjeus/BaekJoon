#include "virus.h"

void isPush(int pushValue)
{
	int front = struQueue.front;
	int back = struQueue.back;

	if (front == -1) {
		front++;
	}
	struQueue.ArrQueue[++back] = pushValue;

	struQueue.front = front;
	struQueue.back = back;

	return;
}

void isVisitQueue(void)
{
}

void pushVisitLinked(int **ptrArrNetLink)
{
	for (int i = 0; i < netLinkCount; i++) {
		for (int j = 0; j < 2; j++) {
			if (struVisit.mPtrVisit[struVisit.top] == ptrArrNetLink[i][j]) {
				if (struVisit
			}
		}
	}
	for (int i = 0; i < _msize(ptrVisit) / sizeof(int); i++) {
		s
	}
}
