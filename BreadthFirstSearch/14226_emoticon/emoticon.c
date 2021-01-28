#include "emoticon.h"

void BFS(Node inputNode)
{
	Node tempNode;
	initNode(&tempNode);

	queue.front++;
	queue.back++;
	push(inputNode);	//인자로 들어온 node push
	while (!empty()) {
		inputNode = queue.arrQueue[queue.front];	//queue의 front에 있는 node값 가져옴
		tempNode = inputNode;	//inputNode 값 변경하기 전에 tempNode에 저장

		//화면에 있는 이모티콘 하나를 삭제하는 경우
		//화면에 이모티콘이 2개도 안되면 경우의 수를 따질 필요가 없고 &&
		//화면의 이모티콘 개수, 클립보드에 저장된 이모티콘 개수 조합이 동일한 곳을 탐색한 적이 없을 때 실행
		if (inputNode.mScreen - 1 >= 2 && !visited[inputNode.mScreen - 1][inputNode.mClipBoard]) {
			inputNode.mScreen--;	//화면 이모티콘 개수 한개 감소
			inputNode.mSecond++;	//1초 증가
			queue.back++;			//queue에 push하기 전 back 1 증가
			push(inputNode);		//queue에 화면 이모티콘 한 개 감소한 경우 push
			visited[inputNode.mScreen][inputNode.mClipBoard] = true;	//화면 이모티콘 한 개 감소하고, 클립보드에 저장된 이모티콘 개수는 그대로인 경우의 수 방문 체크
			
			//최종 화면 이모티콘 개수와 동일하면 BFS 함수 return
			if (inputNode.mScreen == startNode.mScreen) {
				return;
			}
		}

		inputNode = tempNode;	//위에서 inputNode 값이 변경되었으므로 변경 전 값으로 다시 저장

		//클립보드에 저장된 이모티콘 개수가 화면에 있는 이모티콘 개수와 다를 때 클립보드 갱신 && inputNode의 화면 이모티콘 개수를 클립보드에 갱신했을 때를 방문했었는지 체크
		if (inputNode.mScreen != inputNode.mClipBoard && !visited[inputNode.mScreen][inputNode.mScreen]) {
			inputNode.mClipBoard = inputNode.mScreen;	//클립보드 이모티콘 개수 갱신
			inputNode.mSecond++;	//1초 증가
			queue.back++;			//queue에 push하기 전 back 1 증가
			push(inputNode);		//queue에 클립보드 개수 갱신한 경우 push
			visited[inputNode.mScreen][inputNode.mScreen] = true;	//클립보드 이모티콘 개수와 현재 화면 개수와 동일한 경우 방문 체크
/*
			//최종 화면 이모티콘 개수와 동일하면 BFS 함수 return
			if (inputNode.mScreen == startNode.mScreen) {
				return;
			}
			*/
		}

		inputNode = tempNode;	//위에서 inputNode 값이 변경되었으므로 변경 전 값으로 다시 저장
		//클립보드에 저장된 이모티콘 개수만큼 화면에 추가했을 때 화면에 출력 가능한 최대 이모티콘 개수보다 적은 경우 &&
		//방문한적 있는지 체크
		if (inputNode.mScreen + inputNode.mClipBoard <= MAX_INPUT_SIZE && inputNode.mClipBoard > 0 && !visited[inputNode.mScreen + inputNode.mClipBoard][inputNode.mClipBoard]) {
			inputNode.mScreen += inputNode.mClipBoard;	//화면 이모티콘 개수 + 클립보드 이모티콘 개수로 갱신
			inputNode.mSecond++;	//1초 증가
			queue.back++;			//queue에 push하기 전 back 1 증가
			push(inputNode);		//queue에 클립보드 개수 갱신한 경우 push
			visited[inputNode.mScreen][inputNode.mClipBoard] = true;	//바뀐 경우 방문했다고 체크해줌.
			//최종 화면 이모티콘 개수와 동일하면 BFS 함수 return
			if (inputNode.mScreen == startNode.mScreen) {
				return;
			}
		}
		queue.front++;	//queue의 front 증가
	}

	return;
}

bool empty(void)
{
	if (queue.front > queue.back) {
		return true;
	}
	else {
		return false;
	}
}
void push(Node inputNode)
{
	queue.arrQueue[queue.back] = inputNode;
#if DEBUG
	printf("push\t");
	printNode(inputNode);
	printf("queue\n");
	printQueue();
#endif
	return;
}
void initNode(Node *inputNode)
{
	inputNode->mScreen = 0;
	inputNode->mClipBoard = 0;
	inputNode->mSecond = 0;
	return;
}

void initQueue()
{
	for (int i = 0; i < MAX_QUEUE_SIZE + 2; i++) {
		initNode(&queue.arrQueue[i]);
	}
	queue.front = -1;
	queue.back = -1;
	return;
}

void initVisited()
{
	for (int i = 0; i < MAX_INPUT_SIZE + 2; i++) {
		for (int j = 0; j < MAX_INPUT_SIZE + 2; j++) {
			visited[i][j] = false;
		}
	}
}
#if DEBUG
	void printNode(Node inputNode)
	{
		printf("node: %d\t%d\t%d\n", inputNode.mScreen, inputNode.mClipBoard, inputNode.mSecond);
		return;
	}
	void printQueue()
	{
		for (int i = 0; i < startNode.mScreen; i++) {
			printNode(queue.arrQueue[i]);
		}
		printf("front: %d, back: %d\n", queue.front, queue.back);
		return;
	}
#endif
