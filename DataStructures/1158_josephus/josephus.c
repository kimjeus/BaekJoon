#include "josephus.h"

void isJosephus(int N, int K)
{
	int cur = 0, count = 0;

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		arrJosep[i] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		count = 0;

		while (count < K) {
			while (arrJosep[cur] == 0) {
				cur++;
			}
			count++;
		}

		arrJosep[cur] = 0;
	}
}
