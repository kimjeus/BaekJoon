#include "binary_search_tree.h"

void makeTree(Node *node, int inVal)
{
	Node *next = (Node *)malloc(sizeof(Node));
	initNode(next);

	//적절한 위치의 tree에 추가될 때까지 반복
	while (node != NULL) {
		node = compareLR(node, inVal);
	}
	return;
}

Node *compareLR(Node *node, int inVal)
{
	//현재 노드보다 작으면 left 이동
	if (inVal < node->value) {
		//left 노드가 없으면 삽입
		if (node->left == NULL) {
			Node *temp = (Node *)malloc(sizeof(Node));
			initNode(temp);
			node->left = temp;
			node->left->value = inVal;

			return NULL;
		}
		//left 노드가 있으면 left 이동
		else {
			return node->left;
		}
	}
	//현재 노드보다 크면 right 이동
	else {
		//right 노드가 없으면 삽입
		if (node->right == NULL) {
			Node *temp = (Node *)malloc(sizeof(Node));
			initNode(temp);
			node->right = temp;
			node->right->value = inVal;

			return NULL;
		}
		//right 노드가 있으면 이동
		else {
			return node->right;
		}
	}
}

void postOrder(Node *node)
{
	//left right를 차례로 탐색하는데 전부 탐색해야 하므로 visit이 필요없음
	/*
		if (node == NULL)
			return;
		postOrder(node->left);
		postOrder(node->right);

	*/
	//이렇게 짜도 상관이 없음.
	if (node->left != NULL && node->left->visit == false) {
		postOrder(node->left);
	}
	if (node->right != NULL && node->right->visit == false) {
		postOrder(node->right);
	}

	printf("%d\n", node->value);
	node->visit = true;

	return;
}

void initNode(Node *node)
{
	node->value = 0;
	node->visit = false;
	Node *left = NULL;
	Node *right = NULL;
	return;
}
