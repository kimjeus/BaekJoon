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

	doDFS(1, 0);

#if DEBUG
	//arrStruVisit 결과 점검
	for (int i = 0; i < nodeNum; i++) {
		printf("%d: visit: %d, distance: %d\n", i, arrStruVisit[i].mVisit, arrStruVisit[i].mLength);
	}
#endif

	doDFS(

	return 0;
}
