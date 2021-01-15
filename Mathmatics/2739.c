#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;

	scanf("%d", &input);

	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", input, i, input * i);
	}

	return 0;
}
