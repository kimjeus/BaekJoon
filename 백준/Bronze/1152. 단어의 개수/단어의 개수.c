#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char sentence[1000002];
    bool word = false;
    int cnt = 0;

    fgets(sentence, sizeof(sentence), stdin);

    int i = 0;
    while (sentence[i] != '\n') {
        if (!word) {
            if (sentence[i] != ' ') {
                cnt++;
                word = true;
            }
        }
        else {
            if (sentence[i] == ' ')
                word = false;
        }
        i++;
    }

    printf("%d\n", cnt);

    return 0;
}