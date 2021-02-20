#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_STACK_SIZE 600001

typedef struct {
	char memory[MAX_STACK_SIZE];
	int Top;
} stack;

bool empty(stack *st);
void pop(stack *st);
void push(stack *st, char);
size_t size(stack *st);
char top(stack *st);
void initStack(stack *st);
