#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

int *inSet;

void unionSet(int, int);	//두 인자에 대해 합집합 실행
void checkSet(int, int);	//두 인자에 대해 같은 집합인지 검사
int findParent(int);		//최상위 부모를 찾아서 그 값을 return
void initSet(int);			//inSet 배열 초기화

