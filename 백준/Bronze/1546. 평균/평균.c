#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0, sum = 0, max = 0;
    double avg = 0.0;
    char *score;
    scanf("%d", &n);
    score = (char *)malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++) {
        scanf("%hhd", &score[i]);
        sum += score[i];
        if (max < score[i])
            max = score[i];
    }
    avg = (double)sum / n;

    printf("%lf\n", avg / max * 100);

    free(score);
    return 0;
}