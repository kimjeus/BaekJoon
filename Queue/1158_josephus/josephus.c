#include "josephus.h"

void isJosephus(int N, int K)
{
	int cur = -1, count = 0;

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		arrJosep[i] = i + 1;
	}

	printf("<");
	for (int i = 0; i < N; i++) {
		count = 0;

		while (count < K) {
			cur++;
			if (cur == N) {
				cur = 0;
			}
			while (arrJosep[cur] == 0) {
				cur++;
				if (cur == N) {
					cur = 0;
				}
			}
			count++;
		}

		printf("%d", arrJosep[cur]);
		arrJosep[cur] = 0;

		if (i != N - 1) {
			printf(", ");
		}
	}
	printf(">\n");

	return;
}
