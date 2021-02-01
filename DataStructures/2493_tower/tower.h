#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_STACK_SIZE 500000
#define MAX_TOWER_HEIGHT 10000000

typedef struct _node {
	int height;
	int position;
} Node;

typedef struct _stack {
	Node mem[MAX_STACK_SIZE];
	int Top;
} stack;

bool empty(stack *);
void pop(stack *);
void push(stack *, Node *);
size_t size(stack *);
Node *top(stack *);
void initStack(stack *);
