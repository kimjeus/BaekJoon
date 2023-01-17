#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Eratos(int, bool *);

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    bool *arr = (bool *)malloc(sizeof(bool) * (N + 1));
    for (int i = 0; i <= N; i++) {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    Eratos(N, arr);
    for (int i = M; i <= N; i++)
        if (arr[i])
            printf("%d\n", i);

    free(arr);
    return 0;
}

void Eratos(int n, bool *arr)
{
    if (n <= 1)
        return;
    for (int i = 2; i <= n; i++) {
        if (arr[i]) {
            if (i * i <= n) {
                for (int j = i * i; j <= n; j += i)
                    arr[j] = false;
            }
            else
                break;
        }
    }

    return;
}