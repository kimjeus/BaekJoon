#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define INF 200001

typedef struct _node {
	char weight;
	int vertex;
	struct _node *next;
} node;

//char **graph;
node *graph;
int *result;
bool *visit;

void findMin(int, int *);
void renewResult(int, int, int);
char searchList(int, int);
void initGraph(int);
void initResult(int);
void print(node *);

