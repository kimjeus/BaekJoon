#include "inequality_sign.h"

int main(void)
{
	char *A;
	int a = 0;	//입력 받을 문자열 A의 크기

	scanf("%d", &a);
	getchar();	//위의 scanf에서 입력받고 입력버퍼에 남아있는 \n 제거
	A = (char *)malloc(sizeof(char) * (a + 1));	//'\0' 저장 위해 크기 a + 1

	//부등호 입력 받기
	for (int i = 0; i < a; i++) {
		A[i] = getchar();
		getchar();
	}
	A[a] = '\0';	//문자열로 저장해놓기 위해 마지막에 \0 저장

	printf("%s\n", maxComb(A, a));
	printf("%s\n", minComb(A, a));

	free(A);
	return 0;
}

