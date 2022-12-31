#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("%d\n", n);
        return 0;
    }
    int quotient = (n - 2) / 6;
    int remainder = (n - 2) % 6;
    int i = 0, sum = 0;

    while (sum <= quotient) {
        sum += ++i;
    }
    printf("%d\n", i + 1);

    return 0;
}