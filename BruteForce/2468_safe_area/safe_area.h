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

void raining(int);
void countArea(void);
void visit(int, int);
#if DEBUG
	void printVisit(void);
	void printSink(void);
#endif
