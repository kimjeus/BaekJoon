#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	double *score;
	double max = 0, sum = 0;

	scanf("%d", &N);

	score = (double *)malloc(sizeof(double) * N);

	for (int i = 0; i < N; i++) {
		scanf("%lf", &score[i]);
		if (score[i] > max) {
			max = score[i];
		}
	}

	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}

	printf("%.3f\n", sum / N);

	free(score);

	return 0;
}
