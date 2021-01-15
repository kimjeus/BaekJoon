#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

typedef struct _SStack {
	int mArrStack[MAX_STACK_SIZE];
	int top;
} SStack;
SStack struStack;

void push(SStack *, int);
void pop(SStack *);
void size(SStack *);
void empty(SStack *);
void top(SStack *);
