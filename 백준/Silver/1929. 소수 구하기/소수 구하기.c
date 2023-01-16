#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    bool *arr = (bool *)malloc(sizeof(bool) * (N + 1));
    for (int i = 0; i <= N; i++) {
        arr[i] = true;
    }
    arr[1] = false;
    for (int i = 1; i <= N; i++) {
        if (arr[i]) {
                if (i >= M) {
                    printf("%d\n", i);
                }
                for (int j = i + i; j <= N; j += i) {
                    arr[j] = false;
                }
        }
    }

    free(arr);
    return 0;
}