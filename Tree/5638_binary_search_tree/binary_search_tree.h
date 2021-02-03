#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1

typedef struct _Node {
	int value;
	bool visit;	//어차피 모든 노드를 탐색하기 때문에 필요없는 멤버 변수임.
	struct _Node *left;
	struct _Node *right;
} Node;

void makeTree(Node *, int);	//input 키값으로 트리 생성
Node *compareLR(Node *, int);	//input 키값을 넣을 위치를 찾기 위해 left, right 자식을 비교해보는 함수
void postOrder(Node *);	//생성된 tree를 후위탐색하는 함수
void initNode(Node *);	//node를 초기화해주는 함수
