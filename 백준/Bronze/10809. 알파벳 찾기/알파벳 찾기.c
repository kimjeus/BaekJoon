#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[101] = {0, };
    char alpha[26];
    memset(alpha, -1, sizeof(char) * 26);

    scanf("%s", word);

    int i = 0;
    while (word[i] != '\0') {
        if (alpha[(int)word[i] - 'a'] == -1)
            alpha[(int)word[i] - 'a'] = i;
        i++;
    }

    for (int i = 0; i < 26; i++)
        printf("%d ", alpha[i]);
    printf("\n");

    return 0;
}