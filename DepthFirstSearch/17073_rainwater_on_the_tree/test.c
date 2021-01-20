#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, temp, count = 0;
	double W;
	int *ptrResult;
	
	scanf("%d", &N);
	scanf("%lf", &W);
	ptrResult = (int *)malloc(sizeof(int) * (N + 1));

    //tree를 입력 받을 때 node가 입력된 횟수와 link의 개수가 같으므로 입력된 횟수를 저장해준다.
	//link 개수 = node 개수 - 1
    //입력된 데이터 개수 = 2 * link개수
    for (int i = 0; i < 2 * (N - 1); i++) {
		scanf("%d", &temp);
		ptrResult[temp]++;
	}

    //leaf node만 link가 1개이므로 leaf node의 개수를 count에 저장한다.
	for (int i = 1; i <= N; i++) {
		if (ptrResult[i] == 1) {
			count++;
		}
	}
	
    //root node는 link가 1개여도 leaf node가 아니므로 count-- 해준다.
	if (ptrResult[1] == 1) {
		count--;
	}

	printf("%f\n", W / count);

    free(ptrResult);
	return 0;
}
