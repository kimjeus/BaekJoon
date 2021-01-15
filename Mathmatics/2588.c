#include <stdio.h>

int main(void)
{
	int input1, input2;
	
	scanf("%d %d", &input1, &input2);

	printf("%d\n", input1 * (input2 % 10));
	printf("%d\n", input1 * ((input2 % 100) / 10));
	printf("%d\n", input1 * (input2 / 100));
	printf("%d\n", input1 * input2);

	return 0;
}
