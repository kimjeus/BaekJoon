#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char s[1000001];
    int alpha[26] = {0, };
    int maxNum = -1;
    char maxChar = -1;
    bool many = false;

    scanf("%s", s);

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] - 'A' < 26)
            alpha[s[i] - 'A']++;
        else
            alpha[s[i] - 'a']++;
        i++;
    }
    for (int i = 0; i < 26; i++) {
        if (maxNum == alpha[i])
            many = true;
        else if (maxNum < alpha[i]) {
            maxNum = alpha[i];
            maxChar = i + 'A';
            many = false;
        }
    }
    if (many)
        printf("?\n");
    else
        printf("%c\n", maxChar);

    return 0;
}