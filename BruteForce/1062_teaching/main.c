#include "teaching.h"

int main(void)
{
	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		scanf("%s", arrWord[i]);
	}

	if (K < 5) {
		printf("0\n");
	}

	selectLetter();

	if (K <= (int)strlen(arrAllLetter)) {
	}

#if DEBUG
	for (int i = 0; i < N; i++) {
		printf("%s\n", arrLetter[i]);
	}
	printf("%s\n", arrAllLetter);
#endif

	return 0;
}
