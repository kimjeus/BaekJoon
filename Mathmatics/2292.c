#include <stdio.h>

int main(void)
{
	int N;
	int quotient, remainder;
	int sum = 0;

	scanf("%d", &N);
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	quotient = N / 6;
	remainder = N % 6;

	for (int i = 1; ; i++) {
		sum += i;
		//경계가 아닐 때 방 개수
		if (quotient < sum) {
			printf("%d\n", i + 1);
			break;
		}
		//경계일 때 방 개수
		else if (quotient == sum) {
			if (remainder <= 1) {
				printf("%d\n", i + 1);
				break;
			}
			//경계가 넘어간 순간 방 개수 1개 증가
			else {
				printf("%d\n", i + 2);
				break;
			}
		}
	}

	return 0;
}
