#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[9];
    int max = 0, order = 0;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) {
            max = arr[i];
            order = i + 1;
        }
    }
    printf("%d\n%d\n", max, order);

    return 0;
}