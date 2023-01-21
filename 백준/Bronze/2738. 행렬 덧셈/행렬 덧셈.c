#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    char **A = (char **)malloc(sizeof(char *) * N);
    char **B = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) {
        A[i] = (char *)malloc(sizeof(char) * M);
        B[i] = (char *)malloc(sizeof(char) * M);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%hhd", &A[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%hhd", &B[i][j]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", (int)A[i][j] + B[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);
    return 0;
}