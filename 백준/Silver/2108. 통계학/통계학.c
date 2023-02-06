#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int getMean(int, int);
int getMid(int, int *);
int getMode(int *);
int getRange(int, int);

int main(void)
{
    int N;
    scanf("%d", &N);
    int mean, mid, mode, range;
    int sum = 0, max = -4001, min = 4001;
    int *count = (int *)calloc(8001, sizeof(int));
    int tmp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        sum += tmp;     //입력값의 전체 합

        if (tmp < 0)    //입력값이 음수라면 절댓값 + 4000 자리에 count
            count[(tmp * -1) + 4000]++;
        else            //입력값이 양수라면 자기 자리에 count
            count[tmp]++;

        if (max < tmp)  //입력값의 전체 중 최댓값
            max = tmp;
        if (min > tmp)  //입력값의 전체 중 최솟값
            min = tmp;
    }

    mean = getMean(N, sum);
    if (N == 1)     //입력 개수가 1개라면 중앙값은 방금 입력값
        mid = tmp;
    else
        mid = getMid(N, count);
    mode = getMode(count);
    range = getRange(max, min);

    printf("%d\n%d\n%d\n%d\n", mean, mid, mode, range);

    free(count);
    return 0;
}

int getMean(int N, int sum)
{
    double mean;
    mean = (double)sum / N;     //산술평균 계산
    mean = floor(mean + 0.5);   //산술평균 반올림

    return (int)mean;           //소수점 아래 버림
}

int getMid(int N, int *count)
{
    int cnt = 0;

    //-4000 ~ -1 개수 계산
    for (int i = 8000; i > 4000; i--) {
        if (count[i] > 0) {
            cnt += count[i];
        }
        if (N % 2 == 0) {
            if (cnt >= N / 2 + 1)
                return (i - 4000) * -1;
        }
        else {
            if (cnt >= (N + 1) / 2)
                return (i - 4000) * -1;
        }
    }
    //0 ~ 4000 개수 계산
    for (int i = 0; i < 4001; i++) {
        if (count[i] > 0)
            cnt += count[i];
        if (N % 2 == 0) {
            if (cnt >= N / 2 + 1)
                return i;
        }
        else {
            if (cnt >= (N + 1) / 2)
                return i;
        }
    }
}

int getMode(int *count)
{
    bool first;
    int cnt = 0, mode;

    //-4000 ~ -1
    for (int i = 8000; i > 4000; i--) {
        if (cnt < count[i]) {   //최빈값 개수 비교 후 갱신
            first = true;       //최빈값 중 첫 번째로 작은 값
            cnt = count[i];
            if (i < 4001)
                mode = i;
            else
                mode = (i - 4000) * -1;
        }
        else if (cnt == count[i] && first) {    //최빈값 개수 같을 때
            first = false;  //최빈값 중 두 번째로 작은 값
            if (i < 4001)
                mode = i;
            else
                mode = (i - 4000) * -1;
        }
    }
    //0 ~ 4000
    for (int i = 0; i < 4001; i++) {
        if (cnt < count[i]) {
            first = true;
            cnt = count[i];
            if (i < 4001)
                mode = i;
            else
                mode = (i - 4000) * -1;
        }
        else if (cnt == count[i] && first) {
            first = false;
            if (i < 4001)
                mode = i;
            else
                mode = (i - 4000) * -1;
        }
    }

    return mode;
}

int getRange(int max, int min)
{
    return max - min;
}