#include "safe_area.h"

int main(void)
{
	int maxHeight = 1;	//안전한 영역의 최대 높이

	//input 값 저장
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arrInput[i][j].height);
			//안전한 영역의 최대 높이 갱신
			maxHeight = arrInput[i][j].height > maxHeight ? arrInput[i][j].height : maxHeight;
			arrInput[i][j].visit = false;
			arrInput[i][j].sink = false;
		}
	}
	resultCount = 1;	//아무 곳도 잠기지 않으면 안전한 영역 1개

	//비오는 양 i
	for (int i = 1; i < maxHeight; i++) {
		raining(i);	//비와서 잠긴 영역은 sink 변수에 true 대입하고 앞으로 탐색 안함
		countArea();	//i만큼 비가 왔을 때 잠기지 않은 안전한 영역의 개수 계산
	}

	printf("%d\n", resultCount);

	return 0;
}
