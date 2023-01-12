#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addition(char *, char *, char *);

int main(void)
{
    char *a = (char *)calloc(10001, sizeof(char));
    char *b = (char *)calloc(10001, sizeof(char));
    char *tmp = (char *)calloc(10002, sizeof(char));

    scanf("%s %s", a, b);
    (strlen(a) > strlen(b)) ? addition(a, b, tmp) : addition(b, a, tmp);
    printf("%s\n", tmp);

    free(a);
    free(b);
    free(tmp);
    return 0;
}

void addition(char *a, char *b, char *tmp)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int dif = lenA - lenB;
    int tmpA = 0, tmpB = 0;
    bool digit = 0;
    strcpy(tmp + dif, b);

    for (int i = 0; i < dif; i++) {
        tmp[i] = '0';
    }
    strcpy(b, tmp);
    for (int i = lenA - 1; i >= 0; i--) {
        tmpA = (int)(a[i] - '0');
        tmpB = (int)(b[i] - '0');
        if ((tmpA + tmpB + digit) >= 10) {
            tmp[i] = ((tmpA + tmpB + digit) - 10) + '0';
            digit = 1;
        }
        else {
            tmp[i] = (tmpA + tmpB + digit) + '0';
            digit = 0;
        }
    }
    if (digit == 1) {
        strcpy(a, tmp);
        tmp[0] = digit + '0';
        strcpy(tmp + 1, a);
    }
}