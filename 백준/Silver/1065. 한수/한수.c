#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	int count = 0;

	scanf("%d", &N);

	if (N < 100)
		count = N;
	else {
		count = 99;
		for (int i = 100; i <= N; i++) {
			int x = i / 100;
			int y = (i - 100*x) / 10;
			int z = i - 100*x - 10*y;

			if (x + z == 2 * y)
				count++;
		}
	}

	printf("%d\n", count);

	exit(0);
}