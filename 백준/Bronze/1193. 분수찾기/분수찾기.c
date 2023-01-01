#include <stdio.h>

int main(void)
{
    int x = 0;
    scanf("%d", &x);
    int i = 1;

    for (i = 1; x > 0; i++) {
        x -= i;
    }
    i--;
    if (i % 2 == 0)
        printf("%d/%d\n", i + x, 1 - x);
    else
        printf("%d/%d\n", 1 - x, i + x);

    return 0;
}