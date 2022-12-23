#include <stdio.h>

int main(void)
{
	int N, temp, min, max;

	scanf("%d", &N);
	scanf("%d", &temp);
	min = temp;
	max = temp;

	for (int i = 1; i < N; i++) {
		scanf("%d", &temp);
		if (min > temp)
			min = temp;
		if (max < temp)
			max = temp;
	}

	printf("%d %d\n", min, max);

	return 0;
}