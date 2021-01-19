#include "tree_diameter.h"

int main(void)
{
	scanf("%d", &nodeNum);

	initInputTree();

	//arrInputTree 입력 받음
	for (int i = 0; i < nodeNum - 1; i ++) {
		scanf("%d", &arrInputTree[i].mParentNum);
		scanf("%d", &arrInputTree[i].mChildNum);
		scanf("%d", &arrInputTree[i].mLength);
	}

#if DEBUG
	//arrInputTree 입력 점검
	for (int i = 0; i < nodeNum - 1; i++) {
		printf("%d ", arrInputTree[i].mParentNum);
		printf("%d ", arrInputTree[i].mChildNum);
		printf("%d\n", arrInputTree[i].mLength);
	}
#endif

	doDFS(1, 0);	//최초 시작 노드 1, 최초 노드로부터의 거리 0 입력

#if DEBUG
	//arrStruVisit 결과 점검
	for (int i = 0; i < nodeNum; i++) {
		printf("%d: visit: %d, distance: %d\n", i, arrStruVisit[i].mVisit, arrStruVisit[i].mLength);
	}
#endif

	int farthestNum = findFarthestNode();
	initArrStruVisit();
	doDFS(farthestNum, 0);

#if DEBUG
	//arrStruVisit 결과 점검
	for (int i = 0; i < nodeNum; i++) {
		printf("%d: visit: %d, distance: %d\n", i, arrStruVisit[i].mVisit, arrStruVisit[i].mLength);
	}
#endif

	farthestNum = findFarthestNode();

	printf("%d\n", arrStruVisit[farthestNum - 1].mLength);

	return 0;
}
