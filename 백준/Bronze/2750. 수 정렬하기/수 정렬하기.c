#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int, int *);

int main(void)
{
    int N;
    scanf("%d", &N);
    int *inArr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &inArr[i]);
    bubbleSort(N, inArr);
    for (int i = 0; i < N; i++)
        printf("%d\n", inArr[i]);

    free(inArr);
    return 0;
}

void bubbleSort(int N, int *inArr)
{
    int temp;
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (inArr[j] > inArr[j + 1]) {
                temp = inArr[j];
                inArr[j] = inArr[j + 1];
                inArr[j + 1] = temp;
            }
        }
    }
    return;
}