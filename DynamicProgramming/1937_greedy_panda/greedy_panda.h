#include <stdio.h>

#define DEBUG 0
#define MAX_FOREST_SIZE 500

typedef struct _node {
	int bamboo;	//입력 받은 대나무 양
	int day;	//현재 위치에서 판다가 살기 시작할 때 살 수 있는 최대 일수
} node;
node forest[MAX_FOREST_SIZE][MAX_FOREST_SIZE];

int n;	//대나무 숲의 크기
int result;	//판다가 최대한 살 수 있는 일수

void calculateDay(int, int);	//인자로 들어온 좌표에서 판다가 시작했을 때 살 수 있는 최대 일수를 저장하는 함수

