#include <stdio.h>

int main(void)
{
        int king, queen, look, bishop, knight, pawn;

        scanf("%d %d %d %d %d %d", &king, &queen, &look, &bishop, &knight, &pawn);
        printf("%d %d %d %d %d %d\n", 1 - king, 1 - queen, 2 - look, 2 - bishop, 2 - knight, 8 - pawn);

        return 0;
}