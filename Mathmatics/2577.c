#include <stdio.h>
#include <math.h>
#define PRINT(x) printf(#x" = %d\n", x)

int main(void)
{
	int A, B, C;
	int result, digit;
	int count_array[10] = {0, };

	scanf("%d %d %d", &A, &B, &C);

	result = A * B * C;

	for (int i = 2; i < 10; i++) {
		if (result / (int)pow(10, i) == 0) {
			digit = i;
			break;
		}
	}
	
	for (int i = 1; i <= digit; i++) {
		count_array[result % (int)pow(10, i) / (int)pow(10, i - 1)]++;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", count_array[i]);
	}

	return 0;
}
