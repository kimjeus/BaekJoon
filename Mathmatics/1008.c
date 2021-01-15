#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input1, input2;

	scanf("%d %d", &input1, &input2);
	printf("%.9f", (double)input1 / input2);

	return 0;
}
