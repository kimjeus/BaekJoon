#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char input_char[2];
	int N;
	int sum = 0;

	scanf("%d", &N);

	getchar();

	for (int i = 0; i < N; i++) {
		input_char[0] = getchar();
		input_char[1] = NULL;
		sum += atoi(input_char);
	}
	
	printf("%d", sum);

	return 0;
}
