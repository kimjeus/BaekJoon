#include <iostream>
#include <stdio.h>

int main(void) {
	int T = 0;
	scanf("%d", &T);
	int a = 0, b = 0;
	int* result = new int[T];

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		result[i] = a + b;
	}
	for (int i = 0; i < T; i++)
		printf("%d\n", result[i]);

	return 0;
}