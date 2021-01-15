#include <stdio.h>

int main(void)
{
	int N;
	int five_kilo, three_kilo;

	scanf("%d", &N);

	if (N == 4 || N == 7) {
		printf("-1\n");
		
		return 0;
	}

	switch(N % 5) {
		case 0:
			five_kilo = N / 5;
			three_kilo = 0;
			break;
		case 1:
			five_kilo = N / 5 - 1;
			three_kilo = 2;
			break;
		case 2:
			five_kilo = N / 5 - 2;
			three_kilo = 4;
			break;
		case 3:
			five_kilo = N / 5;
			three_kilo = 1;
			break;
		case 4:
			five_kilo = N / 5 - 1;
			three_kilo = 3;
			break;
	}

	printf("%d\n", five_kilo + three_kilo);

	return 0;
}
