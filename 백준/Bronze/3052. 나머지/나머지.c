#include <stdio.h>

int main(void)
{
    int arr[10] = {0, };
    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        arr[i] = arr[i] % 42;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                cnt--;
                break;
            }
        }
        cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}