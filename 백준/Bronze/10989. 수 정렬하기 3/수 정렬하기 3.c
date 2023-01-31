#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void countingSort(int, int *);

int main(void)
{
    int N;
    scanf("%d", &N);
    short tmp;
    int *counting = (int *)calloc(MAX + 1, sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%hd", &tmp);
        counting[tmp]++;
    }
    countingSort(N, counting);

    free(counting);
    return 0;
}

void countingSort(int N, int *counting)
{
    int cnt = 0;
    for (int i = 0; cnt < N; i++) {
        while (counting[i] != 0) {
            printf("%d\n", i);
            counting[i]--;
            cnt++;
        }
    }

    return;
}