#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_STACK_SIZE 30

typedef struct _stack {
	char mem[MAX_STACK_SIZE];
	int Top;
} stack;

bool empty(stack *);
void pop(stack *);
void push(stack *, char);
size_t size(stack *);
char top(stack *);
void initStack(stack *);
