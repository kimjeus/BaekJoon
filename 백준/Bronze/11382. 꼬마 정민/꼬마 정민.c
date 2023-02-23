#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(char *, char *);

int main(void)
{
    char A[14], B[14], C[14];
    char *tmp;
    scanf("%s", A);
    scanf("%s", B);
    scanf("%s", C);

    tmp = add(A, B);
    printf("%s\n", add(tmp, C));

    free(tmp);
    return 0;
}

char *add(char *A, char *B)
{
    char *tmp = (char *)malloc(sizeof(char) * 14);
    for (int i = 0; i < 14; i++) {
        tmp[i] = '0';
    }
    int dif = 0;
    int a = strlen(A);
    int b = strlen(B);
    int len = a;
    int sum = 0;

    if (a < b) {
        dif = b - a;
        A[b] = '\0';
        for (int i = a - 1; i >= 0; i--) {
            A[i + dif] = A[i];
        }
        for (int i = dif - 1; i >= 0; i--) {
            A[i] = '0';
        }
        len = b;
    }
    else if (a > b) {
        dif = a - b;
        B[a] = '\0';
        for (int i = b - 1; i >= 0; i--) {
            B[i + dif] = B[i];
        }
        for (int i = dif - 1; i >= 0; i--) {
            B[i] = '0';
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        sum = ((int)A[i] - 48) + ((int)B[i] - 48) + ((int)tmp[i + 1] - 48);
        tmp[i + 1] = sum % 10 + 48;
        tmp[i] = sum / 10 + 48;
    }
    if (tmp[0] == '0') {
        for (int i = 1; i <= len; i++)
            tmp[i - 1] = tmp[i];
        tmp[len] = '\0';
    }
    else
        tmp[len + 1] = '\0';

    return tmp;
}