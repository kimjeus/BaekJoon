#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

int cntEratos(int, bool *);

int main(void)
{
    int cnt = 0;
    int *inArr = (int *)calloc(SIZE, sizeof(int));

    for (int i = 0; ; i++) {
        scanf("%d", &inArr[i]);
        if (!inArr[i])
            break;
        cnt++;
        if (cnt % SIZE == 0) {
            inArr = realloc(inArr, sizeof(int) * (cnt + SIZE));
            for (int j = cnt; j < cnt + SIZE; j++)
                inArr[j] = 0;
        }
    }
    for (int i = 0; i < cnt; i++) {
        bool *arr = (bool *)malloc(sizeof(bool) * inArr[i] * 2 + 1);
        for (int j = 0; j < inArr[i] * 2 + 1; j++)
            arr[j] = true;

        printf("%d\n", cntEratos(inArr[i], arr));

        free(arr);
    }

    free(inArr);
    return 0;
}

int cntEratos(int n, bool *arr)
{
    int cnt = 0;

    for (int i = 2; i <= 2 * n; i++) {
        if (i * i > 2 * n)
            break;
        if (arr[i]) {
            for (int j = i * i; j <= 2 * n; j += i)
                arr[j] = false;
        }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        if (arr[i])
            cnt++;
    }

    return cnt;
}