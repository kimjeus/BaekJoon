#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DEBUG 0
#define MAX_STRING_SIZE 100

typedef struct _stack {
	//문자열의 마지막에 NULL이 들어갈 자리때문에 +1
	char stackMem[MAX_STRING_SIZE + 1];
	int Top;
} stack;

bool empty(stack *);
void pop(stack *);
void push(stack *, char);
size_t size(stack *);
char top(stack *);
void initStack(stack *);
void initInputStr(char *);
