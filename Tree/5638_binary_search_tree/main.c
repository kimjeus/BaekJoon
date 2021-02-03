#include "binary_search_tree.h"

int main(void)
{
	int inVal = 0;	//입력 받은 트리의 키값
	Node *root = (Node *)malloc(sizeof(Node));
	initNode(root);

	scanf("%d", &(root->value));
	
	//EOF를 입력받을 때까지의 input 키값들을 트리 생성
	while (scanf("%d", &inVal) != EOF) {
		makeTree(root, inVal);
	}

	postOrder(root);	//생성된 tree를 후위 탐색

	free(root);
	return 0;
}
