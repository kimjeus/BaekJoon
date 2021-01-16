#include "virus.h"

int main(void)
{
	int *ptrArrNetLink[2];

	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		struQueue.mArrQueue[i] = 0;
	}
	struQueue.front = -1;
	struQueue.back = -1;

	scanf("%d", &computerCount);
	scanf("%d", &netLinkCount);

	struVisit.mPtrVisit = (int *)malloc(sizeof(int) * computerCount);
	struVisit.top = -1;

	ptrArrNetLink[0] = (int *)malloc(sizeof(int) * netLinkCount);
	ptrArrNetLink[1] = (int *)malloc(sizeof(int) * netLinkCount);

	for (int i = 0; i < netLinkCount; i++) {
		scanf("%d", ptrArrNetLink[0][i]);
		scanf("%d", ptrArrNetLink[1][i]);
	}
}
