#include <stdio.h>

int main(void)
{
    int a, b, c, bif;
    scanf("%d %d %d", &a, &b, &c);

    if (!(b < c))
        bif = -1;
    else
        bif = a / (c - b) + 1;

    printf("%d\n", bif);

    return 0;
}