#include <stdio.h>
#include <stdlib.h>

long long sum (int *a, int n) {
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}

	return ans;
}

int main(void)
{
	int n, ans = 0;
	int *a;

	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n);

	ans = sum(a, n);

	printf("%d\n", ans);

	return 0;
}
