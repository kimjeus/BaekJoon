#include <stdio.h>

void bubbleSort(int, int *);

int main(void)
{
    int list[10];
    int idx = 0;
    int N;
    scanf("%d", &N);

    while (N > 0) {
        list[idx++] = N % 10;
        N /= 10;
    }
    bubbleSort(idx, list);
    for (int i = 0; i < idx; i++)
        printf("%d", list[i]);
    printf("\n");

    return 0;
}

void bubbleSort(int N, int *list)
{
    int tmp;
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (list[j] < list[j + 1]) {
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    return;
}