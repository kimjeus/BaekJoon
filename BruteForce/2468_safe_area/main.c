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

	for (int i = 1; i < maxHeight; i++) {
		raining(i);
		countArea();
	}

	printf("%d\n", resultCount);

	return 0;
}
