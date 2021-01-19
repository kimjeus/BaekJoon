#include "tree_diameter.h"

  /* 
void dfs_1 (SDepth *struDepth)
{
	
#if DEBUG
	//input SDepth 점검
	printf("dfs_1 input SDepth\n");
	printf("parentNode: %d, childNode: %d, depth: %d\n\n", struDepth->mParentNode, struDepth->mChildNode, struDepth->mDepth);
#endif	
	 
	SDepth tempDepth;
	initSDepth(&tempDepth);

	//childNode의 child 개수만큼 반복
	if (countChildNode(struDepth->mChildNode) != 0) {
		//childNode의 child를 찾아서 순서대로 재귀함수 호출
		for (int j = 0; j < nodeNum - 1; j++) {
			if (ptrArrInputTree[0][j] == struDepth->mChildNode) {
				inputSDepth(&tempDepth, struDepth->mParentNode, ptrArrInputTree[1][j], struDepth->mDepth + ptrArrInputTree[2][j]);
				
#if DEBUG
				//다음 재귀 함수 입력 값 확인
				printf("next function input\n");
				printf("parentNode: %d, childNode: %d, depth: %d\n\n", tempDepth.mParentNode, tempDepth.mChildNode, tempDepth.mDepth);
#endif
				 
				dfs_1 (&tempDepth);
			}
		}
	}
	else {
		printf("저장: parent: %d, child: %d, depth: %d\n", struDepth->mParentNode, struDepth->mChildNode, struDepth->mDepth);
		temp[xRow][xColumn++] = struDepth->mDepth;
		return;
	}
	return;
}
*/
void doDFS(int inputNum, int length)
{
	checkVisit(inputNum, length);	//visit 구조체 배열에 방문 여부와 최초 재귀 함수 입력값으로부터의 거리 입력
	
	for (int i = 0; i < nodeNum - 1; i++) {
		if (inputNum == arrInputTree[i].mParentNum) {	//재귀 함수 입력값과 inputTree에서 parentNum값이 일치하는 tree 지점 탐색
			doDFS(arrInputTree[i].mChildNum, length + arrInputTree[i].mLength);
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

SNode findFarthestNum()
{
	SNode
	 farthestNum = 0;

	for (int i = 0; i < nodeNum; i++) {
		if (farthestNum < arrStruVisit[i].mLength) {
			farthestNum = arrStruVisit[i].mLength;
		}
	}

	return farthestNum;
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
