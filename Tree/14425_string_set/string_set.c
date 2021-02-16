#include "string_set.h"

void makeTree(Node *root, int N)
{
	char ch;
	Node *curNode = NULL;

	for (int i = 0; i < N; i++) {
		//새로운 단어 입력 받기 시작
		curNode = root;

		//한 단어 입력 받는 동안 트리 생성
		while ((ch = getchar()) != '\n') {
			//현재 입력받은 문자의 노드를 생성한 적이 없으면 트리의 노드를 추가해줌
			if (!curNode->next[ch - 97]) {
				makeNode(curNode, ch);
				curNode = curNode->next[ch - 97];
			}
			//이미 노드를 생성한 적이 있으면 이동만 함
			else {
				curNode = curNode->next[ch - 97];
			}
		}

		//단어의 마지막에는 표시를 해준다.
		//만약 단어의 마지막을 표시해주지 않는다면 baekjoononlinejudge라는 단어가 집합S에 있을 때 baekjoon이라는 단어가 집합S에 없다는 것을 판단하지 못한다.
		curNode->end = true;
	}

	return;
}

void makeNode(Node *curNode, char ch)
{
	Node *tmpNode = (Node *)malloc(sizeof(Node));

	//입력값 새로 만든 node의 data에 저장
	tmpNode->data = ch;
	//현재 node와 새로 만든 node 연결
	curNode->next[ch - 97] = tmpNode;
	//현재 node 이동
	curNode = curNode->next[ch - 97];

	return;
}

void searchTree(Node *root, int M)
{
	char ch;
	bool include = true;
	Node *curNode = root;

	for (int i = 0; i < M; i++) {
		//탐색할 새로운 단어 시작
		curNode = root;
		include = true;

		while ((ch = getchar()) != '\n') {
			//만약 집합S의 tree를 따라가는데 끊겨 있다면 집합S에 없는 단어이다
			if (!curNode->next[ch - 97]) {
				//현재 입력받는 단어 끝까지 getchar()실행
				while ((ch = getchar()) != '\n') { }
				include = false;
				break;
			}
			//집합 S의 tree에 연결 되어있으면 단어의 마지막이 될때까지 이동하면서 다음 알파벳 확인한다.
			else
				curNode = curNode->next[ch - 97];
		}
		//tree에서 한 번도 끊기지 않고 단어의 길이까지 동일하다면 집합 S에 포함되어 있다.
		if (include && curNode->end)
			result++;
	}
}
