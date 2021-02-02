#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX_WINE_NUM 10002
#define MAX_RESULT_SIZE 300

typedef struct _Node {
	short value;
	char judge;
} Node;

#if DEBUG
void printResult(Node [][MAX_RESULT_SIZE], int);
#endif
