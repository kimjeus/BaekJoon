#include <stdio.h>

int main(void)
{
	int N, temp;
	int front, back;
	int length = 0;

	scanf("%d", &N);
	temp = N;

	do {
		front = N / 10;
		back = N % 10;
		N = (back * 10) + ((front + back) % 10);
		length++;
	} while (temp != N);

	printf("%d\n", length);

	return 0;
}
