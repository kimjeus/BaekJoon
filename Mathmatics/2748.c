#include <stdio.h>

int main(void)
{
	long long int firstFi = 0, secondFi = 1, resultFi;
	int n;

	scanf("%d", &n);

	if (n == 1)
		resultFi = secondFi;
	else {
		for (int i = 2; i <= n; i++) {
			resultFi = firstFi + secondFi;
			firstFi = secondFi;
			secondFi = resultFi;
		}
	}

	printf("%lld\n", resultFi);

	return 0;
}
