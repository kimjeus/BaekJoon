#include <stdio.h>

int main(void)
{
	char ch;
	int A, B;

	while ((ch = getchar()) != EOF) {
		A = (int)ch - 48;
		getchar();
		ch = getchar();
		B = (int)ch - 48;
		printf("%d\n", A + B);
		getchar();
	}

	return 0;
}
