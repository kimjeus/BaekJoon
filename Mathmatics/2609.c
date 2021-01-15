#include <stdio.h>

int main(void)
{
	int num1, num2;
	int smaller, GCD, LCM;

	scanf("%d %d", &num1, &num2);

	if (num1 > num2)
		smaller = num2;
	else
		smaller = num1;

	for (int i = smaller; i > 0; i--) {
		if ((num1 % i == 0) && (num2 % i == 0)) {
			GCD = i;
			LCM = num1 * num2 / GCD;
			break;
		}
	}

	printf("%d\n%d\n", GCD, LCM);

	return 0;
}
