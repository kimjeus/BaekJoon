#include <stdio.h>
#include <string.h>

int scoring(char *);

int main(void)
{
    int n;
    char cases[80];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cases);
        printf("%d\n", scoring(cases));
    }

    return 0;
}

int scoring(char *cases)
{
    int before = 0, sum = 0;

    for (int i = 0; i < strlen(cases); i++) {
        if (cases[i] == 'O')
            sum += ++before;
        else
            before = 0;
    }

    return sum;
}