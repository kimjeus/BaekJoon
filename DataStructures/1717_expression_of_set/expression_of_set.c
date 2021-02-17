#include "expression_of_set.h"

void unionSet(int a, int b)
{
	//합집합을 실행할 두 집합이 나뉘어져 있을 때
	if (inSet[a] != inSet[b]) {
		//a나 b 둘 중 하나의 최고 부모를 상대편의 최고 부모와 연결한다.
		inSet[inSet[a]] = inSet[b];
//or	inSet[inSet[b]] = inSet[a];
	}
	return;
}

void checkSet(int a, int b)
{
	//두 집합의 최고 부모가 같다는 것은 한 집합에 포함된다는 의미이다
	if (inSet[a] == inSet[b])
		printf("YES\n");
	else
		printf("NO\n");
	return;
}

int findParent(int cur)
{
	//저장된 최상위 부모가 자기 자신이면 return한다.
	if (cur == inSet[cur])
		return cur;
	//최상위 부모를 찾을 때까지 올라가면서 만나는 노드들을 모두 최상위 부모로 갱신해준다.
	return inSet[cur] = findParent(inSet[cur]);
}

void initSet(int n)
{
	for (int i = 0; i <= n; i++) {
		inSet[i] = i;
	}
	return;
}
