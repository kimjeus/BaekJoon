#include <stdio.h>

int reward(int, int, int);

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", reward(a, b, c));

    return 0;
}

int reward(int a, int b, int c)
{
    if (a == b && b == c)
        return (10000 + a * 1000);
    else if (a == b || b == c || c == a) {
        if (a == b || c == a)
            return (1000 + a * 100);
        else
            return (1000 + b * 100);
    }
    else {
        if (a > b && a > c)
            return (a * 100);
        else if (b > c && b > a)
            return (b * 100);
        else
            return (c * 100);
    }
}