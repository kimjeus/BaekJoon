#include "parenthesis.h"

int main(void)
{
	char arrInputString[MAX_STRING_LENGTH];
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%s", arrInputString);

		if (isVPS(arrInputString)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
