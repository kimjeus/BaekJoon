#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, x;
    int *arr;
    scanf("%d %d", &n, &x);
    arr = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        if (arr[i] < x)
            printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}