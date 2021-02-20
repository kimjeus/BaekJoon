#include "greedy_panda.h"

void calculateDay(int x, int y)
{
	int nx = 0, ny = 0;		//판다가 이동할 다음 좌표 저장
	char newX[4] = {1, -1, 0, 0};
	char newY[4] = {0, 0, 1, -1};

	for (int i = 0; i < 4; i++) {
		nx = x + newX[i];
		ny = y + newY[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)		//숲 내부 좌표가 아니라면 건너뜀
			continue;

		if (forest[x][y].bamboo < forest[nx][ny].bamboo) {	//다음 좌표의 대나무 양이 현재 좌표의 대나무 양보다 많다면 이동
			if (!forest[nx][ny].day)	//이동한 다음 좌표의 day가 갱신되어 있지 않다면 갱신해주는 함수 실행
				calculateDay(nx, ny);
			if (forest[nx][ny].day) {	//이동한 다음 좌표의 day가 갱신되었다면 현재 좌표의 day 갱신
				if (forest[x][y].day < forest[nx][ny].day + 1)
					forest[x][y].day = forest[nx][ny].day + 1;
			}
		}
	}
	if (!forest[x][y].day)	//만약 상하좌우 어디로도 이동하지 못해서 (x, y)의 day가 갱신되지 않았다면 현재 좌표에서만 살고 끝이므로 1 저장
		forest[x][y].day = 1;

	return;
}
