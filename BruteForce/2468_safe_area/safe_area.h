#include <stdio.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_ROW_SIZE 100

typedef struct _Node {
	int height;
	bool visit;
	bool sink;
} Node;
Node arrInput[MAX_ROW_SIZE][MAX_ROW_SIZE];
int N;	//2차원 배열의 행과 열의 개수
int resultCount;	//안전한 영역의 개수

//비와서 잠긴 영역의 sink변수에 true 대입
//비오는 양은 증가하기만 하므로 한 번 잠기면 더 이상 그 영역 탐색 안함
void raining(int);
void countArea(void);	//i만큼 비가 왔을 때 잠기지 않은 영역의 개수 계산
void visit(int, int);	//인자로 입력된 영역과 연결된 모든 잠기지 않은 영역의 방문 체크
#if DEBUG
	void printVisit(void);
	void printSink(void);
#endif
