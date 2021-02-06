#include "safe_area.h"

void raining(int rainHeight)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//현재 땅이 이미 잠겨있다면 확인할 필요가 없음
			if (arrInput[i][j].sink) {
				continue;
			}
			//현재 땅이 잠겨있지 않은데 현재 내린 비보다 높지 않으면 잠긴다
			if (arrInput[i][j].height <= rainHeight) {
				arrInput[i][j].sink = true;
			}
		}
	}
}

void countArea(void)
{
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//현재 땅이 잠겨있지 않고 && 방문한 적이 없으면 안전한 영역 count한다
			if (!arrInput[i][j].sink && !arrInput[i][j].visit) {
				count++;
				visit(i, j);
			}
		}
	}
	//최대 영역 개수 갱신
	if (count > resultCount) {
		resultCount = count;
	}
	//다음 높이 입력값 때 안전 영역 개수를 count 하기 위해서 visit을 false로 바꿈
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arrInput[i][j].visit = false;
		}
	}
	return;
}

void visit(int x, int y)
{
	arrInput[x][y].visit = true;

	//오른쪽 영역이 존재하고 && 물에 잠기지 않고 && 잠기지 않았는지 방문 안했으면
	if (++x < N && !arrInput[x][y].sink && !arrInput[x][y].visit) {
		visit(x, y);
	}
	x--;
	//왼쪽 영역이 존재하고 && 물에 잠기지 않고 && 잠기지 않았는지 방문 안했으면
	if (--x >= 0 && !arrInput[x][y].sink && !arrInput[x][y].visit) {
		visit(x, y);
	}
	x++;
	//위쪽 영역이 존재하고 && 물에 잠기지 않고 && 잠기지 않았는지 방문 안했으면
	if (++y < N && !arrInput[x][y].sink && !arrInput[x][y].visit) {
		visit(x, y);
	}
	y--;
	//아래쪽 영역이 존재하고 && 물에 잠기지 않고 && 잠기지 않았는지 방문 안했으면
	if (--y >= 0 && !arrInput[x][y].sink && !arrInput[x][y].visit) {
		visit(x, y);
	}
	y++;
	return;
}
#if DEBUG
void printVisit(void)
{
	printf("printVisit\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arrInput[i][j].visit);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
void printSink(void)
{
	printf("printSink\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arrInput[i][j].sink);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
#endif
