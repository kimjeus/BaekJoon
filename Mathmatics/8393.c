#include <stdio.h>

int main(void)
{
	int input;
	int sum = 0;

	scanf("%d", &input);

	for (int i = 1; i <= input; i++) {
		sum += i;
	}

	printf("%d\n", sum);

	return 0;
}
