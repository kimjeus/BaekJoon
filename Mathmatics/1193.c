#include <stdio.h>

int main(void)
{
	int X;
	int cur = 1;

	scanf("%d", &X);

	for (int i = 0; i <= X; i++) {
		cur += i;
		if (cur > X) {
			if (i % 2 == 0) {
				printf("%d/%d\n", 1 + (X - (cur - i)), i - (X - (cur - i)));
				break;
			}
			else {
				printf("%d/%d\n", i - (X - (cur - i)), 1 + (X - (cur - i)));
				break;
			}
		}
	}

	return 0;
}
