#include "emoticon.h"

void BFS(Node inputNode)
{
	Node tempNode;
	initNode(&tempNode);

	queue.front++;
	queue.back++;
	push(inputNode);
	while (!empty()) {
		inputNode = queue.arrQueue[queue.front];
		/*
		init x = 0;
		for (x = 2; x < MAX_QUEUE_SIZE + 1; x++) {
			if (visited[startNode.mScreen][x] == 0) {
				break;
			}
			else
				continue;
		}
		if (x == MAX_QUEUE_SIZE + 1) {
			return;
		}
	*/	
#if DEBUG
		printf("\n");
		printNode(inputNode);
#endif
		subNode(&tempNode, inputNode);
		if (inputNode.mScreen - 1 >= 2 && !visited[inputNode.mScreen - 1][inputNode.mClipBoard]) {
#if DEBUG
			printf("-1\n");
#endif
			inputNode.mScreen--;
			inputNode.mSecond++;
			queue.back++;
			push(inputNode);
			visited[inputNode.mScreen][inputNode.mClipBoard] = true;
			if (inputNode.mScreen == startNode.mScreen) {
				return;
			}
		}

		subNode(&inputNode, tempNode);
		if (inputNode.mScreen != inputNode.mClipBoard && !visited[inputNode.mScreen][inputNode.mScreen]) {
#if DEBUG
			printf("복사\n");
#endif
			inputNode.mClipBoard = inputNode.mScreen;
			inputNode.mSecond++;
			queue.back++;
			push(inputNode);
			visited[inputNode.mScreen][inputNode.mScreen] = true;
			if (inputNode.mScreen == startNode.mScreen) {
				return;
			}
		}

		subNode(&inputNode, tempNode);
		if (inputNode.mScreen + inputNode.mClipBoard <= MAX_INPUT_SIZE && inputNode.mClipBoard > 0 && !visited[inputNode.mScreen + inputNode.mClipBoard][inputNode.mClipBoard]) {
#if DEBUG
			printf("출력\n");
#endif
			inputNode.mScreen += inputNode.mClipBoard;
			inputNode.mSecond++;
			queue.back++;
			push(inputNode);
			visited[inputNode.mScreen][inputNode.mClipBoard] = true;
			if (inputNode.mScreen == startNode.mScreen) {
				return;
			}
		}
		queue.front++;
		//BFS(queue.arrQueue[queue.front]);
	}

	return;
}

void subNode(Node *tempNode, Node inputNode)
{
	tempNode->mScreen = inputNode.mScreen;
	tempNode->mClipBoard = inputNode.mClipBoard;
	tempNode->mSecond = inputNode.mSecond;
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
	subNode(&queue.arrQueue[queue.back], inputNode);
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
