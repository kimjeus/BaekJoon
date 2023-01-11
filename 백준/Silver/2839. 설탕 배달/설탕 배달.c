#include <stdio.h>

int main(void)
{
    int N, q, r;
    int count = 0;
    scanf("%d", &N);
    q = N / 5;
    r = N % 5;

    if (r == 0)
        count = q;
    else if (r == 3)
        count = q + 1;
    else if (r == 4) {
        if (q >= 1)
            count = q + 2;
        else
            count = -1;
    }
    else {
        if (q >= r)
            count = q + r;
        else
            count = -1;
    }
    printf("%d\n", count);

    return 0;
}