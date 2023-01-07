#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    int H, W, N, result;

    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &H, &W, &N);
        result = 0;
        if (N % H == 0) {
            result += H * 100;
            result += N / H;
        }
        else {
            result += (N % H) * 100;
            result += (N / H) + 1;
        }
        printf("%d\n", result);
    }

    return 0;
}