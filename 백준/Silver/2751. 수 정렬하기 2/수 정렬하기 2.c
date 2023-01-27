#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int *, int, int);
void merge(int *, int*, int, int);

int main(void)
{
    int N;
    scanf("%d", &N);
    int *list = (int *)malloc(sizeof(int) * N);
    int *sorted = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
        sorted[i] = list[i];
    }

    mergeSort(list, sorted, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%d\n", list[i]);

    free(list);
    free(sorted);
    return 0;
}

void mergeSort(int *list, int *sorted, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(list, sorted, left, mid);
        mergeSort(list, sorted, mid + 1, right);
        merge(list, sorted, left, right);
    }

    return;
}

void merge(int *list,int *sorted, int left, int right)
{
    int sIdx = left;
    int lIdx = left;
    int rIdx = (left + right) / 2 + 1;
    int mid = (left + right) / 2;

    while (1) {
        if (lIdx == mid + 1) {
            while (rIdx < right + 1)
                sorted[sIdx++] = list[rIdx++];
            break;
        }
        else if (rIdx == right + 1) {
            while (lIdx < mid + 1)
                sorted[sIdx++] = list[lIdx++];
            break;
        }
        else {
            if (list[lIdx] < list[rIdx])
                sorted[sIdx++] = list[lIdx++];
            else
                sorted[sIdx++] = list[rIdx++];
        }
    }
    for (int i = left; i <= right; i++)
        list[i] = sorted[i];

    return;
}