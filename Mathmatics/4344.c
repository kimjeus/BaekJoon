#include <stdio.h>
#include <stdlib.h>
#define PRINTint(x) printf(#x" = %d\n", x)
#define PRINTdouble(x) printf(#x" = %lf\n", x)

struct Class {
	int student_count;
	double average;
	double average_over_rate;
	int *score;
};

int main(void)
{
	int C;	//테스트 개수 C개
	struct Class *class;	//각 테스트의 class
	int sum = 0;	//각 class에서 평균을 계산할 때 사용할 합산 점수
	int count = 0;	//각 class에서 평균을 넘는 학생의 숫자를 셀 때 사용

	scanf("%d", &C);
	class = (struct Class *)malloc(sizeof(struct Class) * C);	//테스트 개수만큼 class 메모리 할당

	for (int i = 0; i < C; i++) {
		scanf("%d", &class[i].student_count);	//해당 클래스의 학생 숫자 입력 받음
		class[i].score = (int *)malloc(sizeof(int) * class[i].student_count);	//해당 클래스의 학생 숫자만큼 성적 입력 받을 score 메모리 할당
		sum = 0;	//각 클래스마다 사용할 sum과 count 초기화
		count = 0;

		//해당 클래스의 학생 점수를 입력 받고 합산 점수 계산
		for (int j = 0; j < class[i].student_count; j++) {
			scanf("%d", &class[i].score[j]);
			sum += class[i].score[j];
		}

		class[i].average = sum / class[i].student_count;	//해당 클래스의 평균 계산

		//해당 클래스의 평균을 넘는 학생의 숫자 계산
		for (int j = 0; j < class[i].student_count; j++) {
			if ((double)class[i].score[j] > class[i].average) {
				count++;
			}
		}

		class[i].average_over_rate = (double)count / class[i].student_count * 100;	//평균을 넘는 학생의 비율 계산
	}

	//결과 출력
	for (int i = 0; i < C; i++) {
		printf("%.3lf%%\n", class[i].average_over_rate);
	}

	//메모리 해제
	for (int i = 0; i < C; i++)
		free(class[i].score);
	free(class);

	return 0;
}
