#include "virus.h"

int doBFS(int start)
{
	int front = struQueue.front;
	int back = struQueue.back;

	ptrVisit[start - 1] = true;	//start 컴퓨터 visit check
	struQueue.mPtrQueue[back] = start;	//visit computer queue 삽입
	front++;
	back++;

	while (front < back) {	//queue의 마지막에 도달할 때까지
		int frontValue = struQueue.mPtrQueue[front];
		
		//graph에서 queue의 front computer에 연결된 computer search
		for (int i = 0; i < computerCount; i++) {
			if (ppInputGraph[i][frontValue - 1] && !ptrVisit[i]) {
				ptrVisit[i] = true;	//search된 computer visit check
				struQueue.mPtrQueue[back++] = i + 1;	//visit computer queue 삽입
			}
		}
		front++;
	}

	return front - 1;	//감염된 computer 개수 front에서 초기 감염 컴퓨터 1개 빼줌
}
