#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Node {
	char data;
	struct _Node *next[26];
	bool end;
} Node;

int result;

void makeTree(Node *,int);	//인자로 들어온 크기만큼 문자열을 받아서 tree 생성
void makeNode(Node *, char);	//인자로 들어온 char를 data로 갖는 node 생성
void searchTree(Node *, int);	//인자로 들어온 숫자 개수 = 탐색단어 갯수
