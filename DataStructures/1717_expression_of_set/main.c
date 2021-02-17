#include "expression_of_set.h"

int main(void)
{
	//집합의 개수는 n + 1개, 연산의 개수 m개
	int n = 0, m = 0;
	//연산 종류 op, 연산의 좌항 a, 연산의 우항 b
	int op = -1, a = -1, b = -1;

	scanf("%d %d", &n, &m);
	//입력 받은 크기만큼의 집합과 결과 메모리 할당
	inSet = (int *)malloc(sizeof(int) * (n + 1));

	//집합의 index와 동일한 data값을 갖고 모두 최상위 부모인 집합으로 초기화
	initSet(n);

	//m번의 명령어 실행
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &op, &a, &b);
		//a, b의 inSet에 자신의 최고 부모를 갱신한다.
		inSet[a] = findParent(a);
		inSet[b] = findParent(b);
		//합집합 실행
		if (!op)
			unionSet(a, b);
		//같은 집합인지 확인
		else
			checkSet(a, b);
	}

	free(inSet);
	return 0;
}
