#include <stdio.h>

int main(void)
{
    int apart[15][15] = {0, };
    int T, k, n;
    scanf("%d", &T);

    for (int i = 0; i < 15; i++) {
        apart[0][i] = i;
    }
    for (int i = 0; i < T; i++) {
        scanf("%d", &k);
        scanf("%d", &n);
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= n; l++) {
                apart[j][l] = apart[j - 1][l] + apart[j][l - 1];
            }
        }
        printf("%d\n", apart[k][n]);
    }

    return 0;
}