#include "rainwater_on_the_tree.h"

void waterDFS(int node)
{
	arrStruVisit[node].mVisit = true;	//입력 node 방문 true로 변경

	for (int i = 1; i < nodeNum; i++) {
		int childCount = countChild(node);
		if (childCount != 0) {
		//입력 node의 자식 노드 찾고 &&
		//visit false로 방문하지 않았는지 확인
		if (arrStruInputTree[i].mNode1 == node && !arrStruVisit[arrStruInputTree[i].mNode2].mVisit && arrStruInputTree[i].mNode1 < arrStruInputTree[i].mNode2) {

#if DEBUG
			printf("if node: %d\tparent: %d\tchild: %d\n", node, arrStruInputTree[i].mNode1, arrStruInputTree[i].mNode2);
			printf("node visit: %d\tcount: %d\n", arrStruVisit[node].mVisit, childCount);
			printf("parent: %f\n", arrStruVisit[arrStruInputTree[i].mNode1].mDepth);
#endif

			arrStruVisit[arrStruInputTree[i].mNode2].mDepth = arrStruVisit[arrStruInputTree[i].mNode1].mDepth / childCount;	//자식 노드 거리 = 부모 노드 거리 +1 
			waterDFS(arrStruInputTree[i].mNode2);
		}
		else if (arrStruInputTree[i].mNode2 == node && !arrStruVisit[arrStruInputTree[i].mNode1].mVisit && arrStruInputTree[i].mNode2 < arrStruInputTree[i].mNode1) {

#if DEBUG
			printf("else if node: %d\tparent: %d\tchild: %d\n", node, arrStruInputTree[i].mNode2, arrStruInputTree[i].mNode1);
			printf("node visit: %d\tcount: %d\n", arrStruVisit[node].mVisit, childCount);
			printf("parent: %f\n", arrStruVisit[arrStruInputTree[i].mNode2].mDepth);
#endif

			arrStruVisit[arrStruInputTree[i].mNode1].mDepth = arrStruVisit[arrStruInputTree[i].mNode2].mDepth / childCount;	//자식 노드 거리 = 부모 노드 거리 +1 
			waterDFS(arrStruInputTree[i].mNode1);
		}
		}
	}
	return;
}

void countNodeLink(void)
{
	for (int i = 1; i < nodeNum; i++) {
		arrLinkCount[arrStruInputTree[i].mNode1]++;
		arrLinkCount[arrStruInputTree[i].mNode2]++;
	}
	return;
}

int countChild(int node)
{
	if(node == 1) {
		return arrLinkCount[node];
	}
	else {
	return arrLinkCount[node] - 1;
	}
}

void findResult(void)
{
	int resultCount = 1;

	for (int i = 1; i <= nodeNum; i++) {
		//link 개수가 하나(leaf node)인 노드 탐색
		if (arrLinkCount[i] == 1) {
			ptrResult[resultCount++] = arrStruVisit[i].mDepth;
		}
	}
	ptrResult[0] = resultCount - 1;		//1부터 nodeNum - 1까지는 leaf node를 저장한다.
	//이 때 root node는 무조건 leaf node가 될 수 없으므로 leaf node는 최대 nodeNum-1개이므로 0에는 leafnode의 개수를 저장한다.
#if DEBUG
	for (int i = 0; i < nodeNum; i++) {
		printf("result[%d]: %f\n", i, ptrResult[i]);
	}
#endif

	return;
}

void initArrStruVisit(void)
{
	for (int i = 0; i < MAX_INPUT_NODE + 1; i++) {
		arrStruVisit[i].mVisit = false;
		arrStruVisit[i].mDepth = 1;
	}

	return;
}
void initArrStruInputTree(void)
{
	for (int i = 0; i < MAX_INPUT_NODE; i++) {
		arrStruInputTree[i].mNode1 = 0;
		arrStruInputTree[i].mNode2 = 0;
	}

	return;
}
void initArrLinkCount(void)
{
	for (int i = 0; i < MAX_INPUT_NODE + 1; i++) {
		arrLinkCount[i] = 0;
	}

	return;
}

void printArrStruVisit(void)
{
	printf("\nprint arrStruVisit\n");
	for (int i = 1; i < nodeNum + 1; i++) {
		printf("node: %d\tvisit: %d\tdepth: %f\n", i, arrStruVisit[i].mVisit, arrStruVisit[i].mDepth);
	}
	return;
}
void printArrLinkCount(void)
{
	printf("\nprint arrLinkCount\n");
	for (int i = 1; i <= nodeNum; i++) {
		printf("node: %d\tlink count: %d\n", i, arrLinkCount[i]);
	}
	return;
}
