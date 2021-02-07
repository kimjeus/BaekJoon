#include <stdio.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_CITY_SIZE 201

bool inputCity[MAX_CITY_SIZE][MAX_CITY_SIZE];	//도시들간의 연결 저장
bool arrCity[MAX_CITY_SIZE];	//여행할 첫 도시로부터 연결된 모든 도시 저장
int N;	//도시의 수

void visit(int);
