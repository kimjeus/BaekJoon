#include <stdio.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_STACK_SIZE 100000

typedef struct {
	int memory[MAX_STACK_SIZE];
	int Top;

	bool (*empty)(void);
	void (*pop)(void);
	void (*push)(int);
	size_t (*size)(void);
	int (*top)(void);
	//void (*emplace)(void);
	//void (*swap)(&stack);
} stack;
stack st;

bool stackEmpty(void);
void stackPop(void);
void stackPush(int);
size_t stackSize(void);
int stackTop(void);
void initStack(void);
