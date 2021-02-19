#include <stdio.h>
#include <stdbool.h>

#define MAX_GRAPH_ROW 101

int main(void)
{
	bool G[MAX_GRAPH_ROW][MAX_GRAPH_ROW];
	bool visit[MAX_GRAPH_ROW];
	int N = 0, input = 0;
	bool end = true;

	scanf("%d", &N);

	//입력값 graph G에 저장
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
		for (int j = 1; j<= N; j++) {
			scanf("%d", &input);
			if (input)
				G[i][j] = true;
			else
				G[i][j] = false;
		}
	}

	//경로 갱신
	while (1) {
		end = true;
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {	//방문한 적이 없는 row라면 실행
				for (int j = 1; j <= N; j++) {
					if (G[i][j]) {	//정점 i와 j가 연결되어 있다면
						//정점 i와 연결된 모든 정점은 j와도 연결된다
						for (int k = 1; k <= N; k++) {
							if (G[k][i] && !G[k][j]) {	//위에서 정점 i와 연결된 정점 k를 탐색하고 && 정점 k와 j가 연결되어 있지 않다면 연결
								G[k][j] = true;
								visit[k] = false;	//정점 k가 갱신되었으므로 재방문하기 위해 visit 변경
							}
						}
					}
				}
				visit[i] = true;	//지금까지 위에서 방문했으므로
			}
		}

		//모든 정점 방문했는지 check
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				end = false;
				break;
			}
		}
		if (!end) { continue; }
		else { break; }
	}

	//결과 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	return 0;
}
