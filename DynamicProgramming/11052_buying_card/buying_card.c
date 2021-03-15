#include "buying_card.h"

void calculate(int *result, int i)
{
	for (int j = 1; j <= i / 2; j++) {
		if (result[j] + result[i - j] > result[i])
			result[i] = result[j] + result[i - j];
	}
	return;
}
