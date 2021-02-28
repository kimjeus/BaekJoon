#include "inequality_sign.h"

char *maxComb(const char *A, int a)
{
	char *result = (char *)calloc(a + 2, sizeof(char));	//'\0'저장 + 0부터 a까지 저장하기 위해 크기 1 + (a + 1)
	int right, left;

	result[0] = '9';	//제일 앞에 먼저 max저장
	for (int i = 0; i < a; i++) {
		right = i + 1;	//부등호 오른쪽
		left = i;		//부등호 왼쪽
		result[right] = (char)(9 - right + 48);	//그 다음 최댓값 저장
		
		if (A[i] == '<') {
			do {
				//부등호 양쪽 교환
				swap(&result[left--], &result[right--]);
			//부등호가 > 나올 때까지 계속 교환
			} while (left >= 0 && A[left] == '<');
		}
	}
	//결과를 출력하기 위해 마지막에 \0 저장
	result[a + 1] = '\0';

	return result;
}
char *minComb(const char *A, int a)
{
	char *result = (char *)calloc(a + 2, sizeof(char));	//'\0'저장 + 0부터 a까지 저장하기 위해 크기 1 + (a + 1)
	int right, left;

	result[0] = '0';	//제일 앞에 먼저 min저장
	for (int i = 0; i < a; i++) {
		right = i + 1;	//부등호 오른쪽
		left = i;		//부등호 왼쪽
		result[right] = (char)(right + 48);	//그 다음 최솟값 저장
		
		if (A[i] == '>') {
			do {
				//부등호 양쪽 교환
				swap(&result[left--], &result[right--]);
			//부등호가 < 나올 때까지 계속 교환
			} while (left >= 0 && A[left] == '>');
		}
	}
	//결과를 출력하기 위해 마지막에 \0 저장
	result[a + 1] = '\0';

	return result;
}
void swap(char *left, char *right)
{
	char temp;
	temp = *left;
	*left = *right;
	*right = temp;
	return;
}

