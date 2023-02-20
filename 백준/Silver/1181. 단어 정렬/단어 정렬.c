#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eliminateRepeat(char **, char **, int);
void bubbleSort(char **, int *);
void mergeSort(char **, char **, int, int);
void merge(char **, char **, int, int);

int main(void)
{
    int N;
    int n;
    scanf("%d", &N);
    char **list = (char **)malloc(sizeof(char *) * N);
    char **sorted = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) {
        list[i] = (char *)malloc(sizeof(char) * 51);
        sorted[i] = (char *)malloc(sizeof(char) * 51);
        scanf("%s", list[i]);
    }
    n = eliminateRepeat(list, sorted, N);
//  bubbleSort(sorted, &n);
    mergeSort(list, sorted, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%s\n", sorted[i]);

    for (int i = 0; i < N; i++) {
        free(list[i]);
        free(sorted[i]);
    }
    free(list);
    free(sorted);
    return 0;
}

int eliminateRepeat(char **list, char **sorted, int N)
{
    char tmp[51];
    int sIdx = 0;

    for (int i = 0; i < N; i++) {
        if (list[i][0] != '\0') {
            strcpy(tmp, list[i]);
            for (int j = i; j < N; j++) {
                if (!strcmp(tmp, list[j])) {
                    list[j][0] = '\0';
                }
            }
            strcpy(sorted[sIdx++], tmp);
        }
    }
    for (int i = 0; i < sIdx; i++)
        strcpy(list[i], sorted[i]);

    return sIdx;
}

void mergeSort(char **list, char **sorted, int left, int right)
{
    int mid = (left + right) / 2;

    if (left < right) {
        mergeSort(list, sorted, left, mid);
        mergeSort(list, sorted, mid + 1, right);
        merge(list, sorted, left, right);
    }

    return;
}
void merge(char **list, char **sorted, int left, int right)
{
    int mid = (left + right) / 2;
    int sIdx = left;
    int lIdx = left;
    int rIdx = mid + 1;

    while (lIdx <= mid && rIdx <= right) {
        if (strlen(list[lIdx]) < strlen(list[rIdx]))
            strcpy(sorted[sIdx++], list[lIdx++]);
        else if (strlen(list[lIdx]) > strlen(list[rIdx]))
            strcpy(sorted[sIdx++], list[rIdx++]);
        else {
            if (strcmp(list[lIdx], list[rIdx]) < 0)
                strcpy(sorted[sIdx++], list[lIdx++]);
            else
                strcpy(sorted[sIdx++], list[rIdx++]);
        }
    }
    if (rIdx > right) {
        while (lIdx <= mid)
            strcpy(sorted[sIdx++], list[lIdx++]);
    }
    else {
        while (rIdx <= right)
            strcpy(sorted[sIdx++], list[rIdx++]);
    }
    for (int i = left; i <= right; i++)
        strcpy(list[i], sorted[i]);

    return;
}

void bubbleSort(char **list, int *n)
{
    char tmp[51];
    int N = *n;

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
//          if (strlen(list[j - 1]) == 0 || strlen(list[j] == 0))
//              continue;

            if (strlen(list[j - 1]) == strlen(list[j])) {
/*              if (!strcmp(list[j - 1], list[j])) {
                    list[j] = "\0";
                    for (int k = j; k < N - 1; k++) {
                        strcpy(list[k], list[k + 1]);
                    }
                    N = --(*n);
                }*/
                if (strcmp(list[j - 1], list[j]) > 0) {
                    strcpy(tmp, list[j - 1]);
                    strcpy(list[j - 1], list[j]);
                    strcpy(list[j], tmp);
                }
            }
            else if (strlen(list[j - 1]) > strlen(list[j])) {
                strcpy(tmp, list[j - 1]);
                strcpy(list[j - 1], list[j]);
                strcpy(list[j], tmp);
            }
        }

    }

    return;
}