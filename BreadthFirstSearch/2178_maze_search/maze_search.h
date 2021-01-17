#include <stdio.h>
#include <stdbool.h>

#define MAX_ROW_SIZE 100

typedef struct _SCoordinate {
	int mRow;
	int mColumn;
	int mDepth;
} SCoordinate;

typedef struct _SQueue {
	SCoordinate mArrQueue[MAX_ROW_SIZE * MAX_ROW_SIZE];
	int mFront;
	int mBack;
} SQueue;
SQueue struQueue;

bool dArrInputMaze[MAX_ROW_SIZE][MAX_ROW_SIZE];
bool dArrVisit[MAX_ROW_SIZE][MAX_ROW_SIZE];
int dArrDistance[MAX_ROW_SIZE][MAX_ROW_SIZE];
int N, M;

int searchMazeBFS(int, int);
bool isRightDistance(int, int);
void doRightDistance(int, int, int);
void pushQueue(int, int, int);
