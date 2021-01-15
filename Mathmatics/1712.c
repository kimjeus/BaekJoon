#include <stdio.h>

int main(void)
{
	int A, B, C;
	int result;

	scanf("%d %d %d", &A, &B, &C);

	if ((B >= C) || (A <= 0) || (B <= 0) || (C < 0))
		result = -1;

	else {
		result = A / (C - B) + 1;
	}

	printf("%d\n", result);

	return 0;
}
