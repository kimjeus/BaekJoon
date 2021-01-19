#include "tree_diameter.h"

void doDFS(int inputNum, int length)
{
	checkVisit(inputNum, length);	//visit 구조체 배열에 방문 여부와 최초 재귀 함수 입력값으로부터의 거리 입력
	
	//visit해서 최초 함수 입력값으로부터의 거리를 입력 받은 노드는 방문을 안하고
	//방문 안한 노드는 방문해서 거리 입력하기
	for (int i = 0; i < nodeNum - 1; i++) {
		//재귀 함수 입력값과 inputTree의 paretNum값이 일치하고
		//visit하지 않았을 경우에 방문 체크 및 거리 저장하면서 재귀 호출
		if (inputNum == arrInputTree[i].mParentNum && !arrStruVisit[arrInputTree[i].mChildNum - 1].mVisit) {
			doDFS(arrInputTree[i].mChildNum, length + arrInputTree[i].mLength);
		}
		//재귀 함수 입력값과 inputTree의 childNum값이 일치하고
		//visit하지 않았을 경우에 방문 체크 및 거리 저장하면서 재귀 호출
		else if (inputNum == arrInputTree[i].mChildNum && !arrStruVisit[arrInputTree[i].mParentNum - 1].mVisit) {
			doDFS(arrInputTree[i].mParentNum, length + arrInputTree[i].mLength);
		}
	}
	return;
}

void checkVisit(int inputNum, int sumLength)
{
	arrStruVisit[inputNum - 1].mVisit = true;
	arrStruVisit[inputNum - 1].mLength = sumLength; 

	return;
}

void initSNode(SNode *struNode)
{
	struNode->mParentNum = 0;
	struNode->mChildNum = 0;
	struNode->mLength = 0;

	return;
}

void initInputTree(void)
{
	for (int i = 0; i < MAX_NODE_NUM - 1; i++) {
		initSNode(&arrInputTree[i]);
	}

	return;
}

void initSVisit(SVisit *struVisit)
{
	struVisit->mVisit = false;
	struVisit->mLength = 0;

	return;
}

void initArrStruVisit(void)
{
	for (int i = 0; i < MAX_NODE_NUM; i++) {
		initSVisit(&arrStruVisit[i]);
	}

	return;
}

int findFarthestNode()
{
	int farthestNum = 0;
	int farthestNode = 0;

	for (int i = 0; i < nodeNum; i++) {
		if (farthestNum < arrStruVisit[i].mLength) {
			farthestNum = arrStruVisit[i].mLength;
			farthestNode = i;
		}
	}

	return farthestNode + 1;	//arrStruVisit배열은 0부터 시작하는데 노드는 1부터 시작하므로 + 1
}
