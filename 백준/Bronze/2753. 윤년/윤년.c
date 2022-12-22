#include <stdio.h>

int yoon(int);

int main(void)
{
    int year;

    scanf("%d", &year);

    printf("%d\n", yoon(year));

    return 0;
}

int yoon(int year)
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 != 0 && year % 4 == 0)
        return 1;
    else
        return 0;
}