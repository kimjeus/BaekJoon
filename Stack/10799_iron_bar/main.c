#include "iron_bar.h"

int main(void)
{
	char arrInput[INPUT_MAX_SIZE];
	int count = 0;

	scanf("%s", arrInput);

	count = countIronBar(arrInput);

	printf("%d\n", count);

	return 0;
}
