#include "lets_go_travel.h"

int main(void)
{
	bool result = true;
	int inputNum = 0;
	int M = 0;	//여행 계획에 있을 도시의 수

	//도시간의 연결 입력값 저장
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &inputNum);
			inputCity[i][j] = inputNum;
		}
	}

	//여행할 첫 도시 저장
	scanf("%d", &inputNum);
	visit(inputNum);	//여행할 첫 도시로부터 연결된 도시를 arrCity에 저장

	//arrCity에 저장된(즉 여행할 첫 도시와 연결된) 도시인지 검사하고
	//모두 연결되어 있으면 여행 가능하므로 YES, 하나라도 연결 안되면 여행 불가능하므로 NO 출력
	for (int i = 2; i <= M; i++) {
		scanf("%d", &inputNum);
		if (!arrCity[inputNum]) {
			result = false;
			break;
		}
	}

	//결과 출력
	if (result) { printf("YES\n"); }
	else { printf("NO\n"); }

	return 0;
}
