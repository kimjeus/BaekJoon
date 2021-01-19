#include "tree_diameter.h"

void dfs_2 (int parentNode)
{
	xRow = 0;
	xColumn = 0;
	SDepth struDepth;
	initSDepth(&struDepth);

	for (int j = 0; j < nodeNum - 1; j++) {
		if (parentNode == ptrArrInputTree[0][j]) {
			inputSDepth(&struDepth, parentNode, ptrArrInputTree[1][j], ptrArrInputTree[2][j]);
			dfs_1(&struDepth);
			xRow++;
		}

		//	for (int i = 0; i < countChildNode(struDepth.mChildNode); i++) {
		for (int j = 0; j < nodeNum - 1; j++) {
			if (ptrArrInputTree[0][j] == struDepth.mChildNode) {
				//	inputSDepth(&tempDepth, struDepth.mParentNode, ptrArrInputTree[1][j], struDepth.mDepth + ptrArrInputTree[2][j]);
				dfs_2 (ptrArrInputTree[1][j]);
				//	}
			}
		}
	}
	for (int i = 0; temp[0][i] == 0; i++) {
		for (int j = 0; temp[1][j] == 0; j++) {
			result[k++] = temp[0][i] + temp[0][i];
		}
	}
	return;
}

void dfs_1 (SDepth *struDepth)
{
	/*
#if DEBUG
	//input SDepth 점검
	printf("dfs_1 input SDepth\n");
	printf("parentNode: %d, childNode: %d, depth: %d\n\n", struDepth->mParentNode, struDepth->mChildNode, struDepth->mDepth);
#endif	
	 */
	SDepth tempDepth;
	initSDepth(&tempDepth);

	//childNode의 child 개수만큼 반복
	if (countChildNode(struDepth->mChildNode) != 0) {
		//childNode의 child를 찾아서 순서대로 재귀함수 호출
		for (int j = 0; j < nodeNum - 1; j++) {
			if (ptrArrInputTree[0][j] == struDepth->mChildNode) {
				inputSDepth(&tempDepth, struDepth->mParentNode, ptrArrInputTree[1][j], struDepth->mDepth + ptrArrInputTree[2][j]);
				/*
#if DEBUG
				//다음 재귀 함수 입력 값 확인
				printf("next function input\n");
				printf("parentNode: %d, childNode: %d, depth: %d\n\n", tempDepth.mParentNode, tempDepth.mChildNode, tempDepth.mDepth);
#endif
				 */
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

void initSDepth(SDepth *struDepth)
{
	struDepth->mParentNode = 0;
	struDepth->mChildNode = 0;
	struDepth->mDepth = 0;

	return;
}

void inputSDepth(SDepth *struDepth, int parentNode, int childNode, int depth)
{
	struDepth->mParentNode = parentNode;
	struDepth->mChildNode = childNode;
	struDepth->mDepth = depth;
	/*
#if DEBUG
	//inputSDepth 값 점검
	printf("inputSDepth\n");
	printf("parentNode: %d, childNode: %d, depth: %d\n\n", parentNode, childNode, depth);
#endif
	 */
	return;
}

int countChildNode(int node)
{
	int count = 0;

	if (node <= ptrArrInputTree[0][nodeNum - 2]) {	//간선의 개수는 nodeNum보다 1개 적고 배열은 0부터 시작해서 -1을 두번함.
		for (int i = 0; i < nodeNum - 1; i++) {
			if (ptrArrInputTree[0][i] == node) {
				count++;
			}
		}
		return count;
	}
	else {
		return 0;
	}
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
	SNode tempNode;
	initSNode(&tempNode);

	for (int i = 0; i < MAX_NODE_NUM; i++) {
		initSNode(arrInputTree[i]);
	}

	return;
}
