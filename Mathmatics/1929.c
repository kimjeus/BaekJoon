#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int M, N;
	int *prime_array;

	scanf("%d %d", &M, &N);
	prime_array = (int *)malloc(sizeof(int) * (N + 1));

	prime_array[0] = 0;
	prime_array[1] = 0;
	for (int i = 2; i < N + 1; i++)
		prime_array[i] = 1;

	for (int i = 2; i * i <= N; i++) {
		if (prime_array[i] == 1) {
			for (int j = i * i; j <= N; j += i) {
				prime_array[j] = 0;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (prime_array[i] == 1) {
			printf("%d\n", i);
		}
	}

	return 0;
}
