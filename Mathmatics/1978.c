#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, count = 0;
	int *input;

	scanf("%d", &N);
	input = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < N; i++) {
		if (input[i] == 1)
			continue;
		else if (input[i] == 2) {
			count++;
			continue;
		}

		for (int j = 2; j < input[i]; j++) {
			if (input[i] % j == 0)
				break;
			else if (j == input[i] - 1)
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
