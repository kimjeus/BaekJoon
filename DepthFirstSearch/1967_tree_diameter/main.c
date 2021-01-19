#include "tree_diameter.h"

int main(void)
{
	scanf("%d", &nodeNum);

	initInputTree();

	//arrInputTree 입력 받음
	for (int i = 0; i < nodeNum - 1; i ++) {
		scanf("%d", &arrInputTree[i]->mParentNode);
		scanf("%d", &arrInputTree[i]->mChildNode);
		scanf("%d", &arrInputTree[i]->mDepth);
	}
/*
#if DEBUG
	//arrInputTree 입력 점검
	for (int i = 0; i < nodeNum - 1; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arrInputTree[i]->mParentNode);
			printf("%d", arrInputTree[i]
		}
		printf("\n");
	}
#endif
*/
/*
	SDepth tempDepth;
	initSDepth(&tempDepth);
	inputSDepth(&tempDepth, 3, 6, 9);
	dfs_1(&tempDepth);
*/
	dfs_2(1);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 30; j++) {
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
	//ptrArrInputTree 메모리 해제
	for (int i = 0; i < 3; i++) {
		free(ptrArrInputTree[i]);
	}

	return 0;
}
