#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c = 0, n = 0;
    scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        scanf("%d", &n);
        char *score = (char *)malloc(sizeof(char) * (n + 1));
        int sum = 0, cnt = 0;
        double avg = 0.0;

        for (int j = 0; j < n; j++) {
            scanf("%hhd", &score[j]);
            sum += score[j];
        }
        avg = (double)sum / n;
        for (int j = 0; j < n; j++) {
            if (avg < score[j])
                cnt++;
        }
        printf("%.3f%%\n", (double)cnt / n * 100);

        free(score);
    }

    return 0;
}