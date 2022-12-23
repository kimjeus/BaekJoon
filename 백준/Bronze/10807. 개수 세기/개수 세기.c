#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, v;
    int *arr;
    int cnt = 0;

    scanf("%d", &n);

    arr = malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &v);
    for (int i = 0; i < n; i++)
        if (arr[i] == v)
            cnt++;

    printf("%d\n", cnt);

    return 0;
}