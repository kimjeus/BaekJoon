#include <stdio.h>

int main(void)
{
	int input[10];
	int result[10];
	int count = 1;
	int j;

	//겹치지 않는 값을 넣을 배열을 -1로 초기화
	for (int i = 0; i < 10; i++)
		result[i] = -1;
	
	//입력값을 input 배열에 42로 나눈 나머지로 저장
	for (int i = 0; i < 10; i++) {
		scanf("%d", &input[i]);
		input[i] %= 42;
	}

	result[0] = input[0];	//첫 문자는 무조건 바로 result 배열에 입력

	//두 번째 문자부터 result 배열에 존재 유무 검사
	for (int i = 1; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			//result 배열에 있는 수라면 검사 종료
			if (input[i] == result[j])
				break;
		}
		//result 배열에 없다면 그 수를 result 배열에 추가
		if (j == 10) {
			result[count++] = input[i];
		}
	}

	printf("%d\n", count);

	return 0;
}
