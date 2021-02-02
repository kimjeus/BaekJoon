#include "wine_tasting.h"

#if DEBUG
void printResult(Node arrResult[][MAX_RESULT_SIZE], int num)
{
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= 20; j++) {
			printf("%d ", arrResult[i][j].value);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
#endif
