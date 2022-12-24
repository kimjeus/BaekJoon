#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int selfNum(int);

int main(void)
{
    bool check[10001] = {0, };
    memset(check, 1, 10001 * sizeof(bool));

    for (int i = 1; i <= 10000; i++) {
        int nextNum = 0;
        if (check[i] == false)
            continue;

        nextNum = selfNum(i);
        while (nextNum <= 10000) {
            if (check[nextNum] == true)
                check[nextNum] = false;
            nextNum = selfNum(nextNum);
        }
    }
    for (int i = 1; i <= 10000; i++)
        if (check[i] == true)
            printf("%d\n", i);

    return 0;
}

int selfNum(int n)
{
    int digit = 0, sum = n;

    while (n % 10 != 0 || n / 10 != 0) {    //추출할 일의 자리가 있는지 없는지 확인 && 추출할 십의 자리 이상이 없는지 확인
        digit = n % 10;     //일의 자리 추출
        sum += digit;
        n /= 10;            //십의 자리를 일의 자리로 내림
    }

    return sum;
}