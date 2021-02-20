#include "josephus.h"

int main(void)
{
	int N = 0, K = 0;

	scanf("%d %d", &N, &K);

	isJosephus(N, K);

	return 0;
}
