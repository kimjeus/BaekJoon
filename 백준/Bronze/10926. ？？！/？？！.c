#include <stdio.h>
#include <string.h>

char *checkID(char *, int);

int main(void)
{
        char strID[50];
        char* dupID;
        int lenID = 0;

        scanf("%s", strID);
        lenID = strlen(strID);

        dupID = checkID(strID, lenID);

        printf("%s\n", dupID);

        return 0;
}

char *checkID(char *inputID, int length)
{
        inputID[length] = '?';
        inputID[length + 1] = '?';
        inputID[length + 2] = '!';
        inputID[length + 3] = '\0';

        return inputID;
}