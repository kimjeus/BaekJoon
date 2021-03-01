#include "music_program.h"

/*========================================*/
int main(void)
{
    int inCount;
    
	qu = (queue *)malloc(sizeof(queue));
    scanf("%d %d", &N, &M);
    
	//필요한 값들 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = false;
            arrResult[j] = 0;
        }
    }
    resultIdx = 1;
    
	//입력 받아서 graph에 저장
    for (int i = 0; i < M; i++) {
        int before, after;
        
        scanf("%d", &inCount);
        scanf("%d", &before);
        
        for (int j = 0; j < inCount - 1; j++) {
            scanf("%d", &after);
            graph[before][after] = true;
            before = after;
        }
    }
    
	//i 이전에 해야하는 가수가 없는지 검사
    for (int i = 1; i <= N; i++)
        check(i);
    
	//모든 가수가 정렬 완료되면 결과 출력
    if (topologicalSorting()) {
        for (int i = 1; i <= N; i++)
            printf("%d\n", arrResult[i]);
	}
	//정렬이 불가능해지면 0 출력
    else {
        printf("0\n");
	}
    
	free(qu);
    return 0;
}
/*========================================*/

