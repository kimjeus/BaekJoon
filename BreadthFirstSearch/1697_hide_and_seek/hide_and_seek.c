#include "hide_and_seek.h"

void DFS(int position)
{
	SNode inputStruNode;
	inputStruNode.mPosition = position;
	inputStruNode.mSecond = 0;

	pushQueue(&inputStruNode);	//시작지점 push queue
	arrStruQueue.mFront++;

	//queue가 빌 때까지 반복
	while (arrStruQueue.mFront < arrStruQueue.mBack) {
		int curPosition = arrStruQueue.mStruNode[arrStruQueue.mFront].mPosition;
		int curSecond = arrStruQueue.mStruNode[arrStruQueue.mFront].mSecond;

		//현재 position에서 -1 갔을 때 자식 탐색
		if (curPosition - 1 >= 0 && !visited[curPosition - 1]) {
			visited[curPosition - 1] = true;
			checkChild(curPosition - 1, curSecond + 1);
		}
		//현재 position에서 +1 갔을 때 자식 탐색
		if (curPosition + 1 <= MAX_QUEUE_SIZE && !visited[curPosition + 1]) {
			visited[curPosition + 1] = true;
			checkChild(curPosition + 1, curSecond + 1);
		}
		//현재 position에서 *2 갔을 때 자식 탐색
		if (curPosition * 2 <= MAX_QUEUE_SIZE && !visited[curPosition * 2]) {
			visited[curPosition * 2] = true;
			checkChild(curPosition * 2, curSecond + 1);
		}

		arrStruQueue.mFront++;
	}

	return;
}

void checkChild(int position, int second)
{
	SNode tempStruNode;
	tempStruNode.mPosition = position;
	tempStruNode.mSecond = second;

#if DEBUG
	printf("\ncheckChild\n");
	printf("position: %d\tsecond: %d\n", position, second);
	printf("result position: %d\tresult second: %d\n", struResult.mPosition, struResult.mSecond);
	usleep(100000);
#endif

	if (struResult.mSecond <= second) {
		return;
	}

	if (position < K) { 
		pushQueue(&tempStruNode);
	}
	else if (position == K) {
		compareResult(tempStruNode);
	}
	else {
		while (position > 0) {
			position--;
			tempStruNode.mPosition--;
			tempStruNode.mSecond++;
			if (position == K) {
				compareResult(tempStruNode);
				break;
			}
		}
	}
	return;
}

void compareResult(SNode inputStruNode)
{
#if DEBUG
	printf("\ncompareResult\n");
	printf("input p: %d\tinput sec: %d\nresult p: %d\tresult sec: %d\n", inputStruNode.mPosition, inputStruNode.mSecond, struResult.mPosition, struResult.mSecond);
#endif
	if (struResult.mSecond > inputStruNode.mSecond) {
		struResult.mPosition = inputStruNode.mPosition;
		struResult.mSecond = inputStruNode.mSecond;
	}
	return;
}

void pushQueue(SNode *inputNode)
{
	arrStruQueue.mStruNode[arrStruQueue.mBack].mPosition = inputNode->mPosition;
	arrStruQueue.mStruNode[arrStruQueue.mBack].mSecond = inputNode->mSecond;
	arrStruQueue.mBack++;

	return;
}
/*
   SNode *popQueue(void)
   {
   SNode tempStruNode;

   tempStruNode.mPosition = arrStruQueue.mStruNode[arrStruQueue.mFront].mPosition;
   tempStruNode.mSecond = arrStruQueue.mStruNode[arrStruQueue.mFront].mSecond;
   arrStruQueue.mStruNode[arrStruQueue.mFront].mPosition = 0;
   arrStruQueue.mStruNode[arrStruQueue.mFront].mSecond = 0;
   arrStruQueue.mFront++;

   return &tempStruNode;
   }
 */
void initArrStruQueue(void)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		arrStruQueue.mStruNode[i].mPosition = 0;
		arrStruQueue.mStruNode[i].mSecond = 0;
	}
	arrStruQueue.mFront = -1;
	arrStruQueue.mBack = 0;

	return;
}
