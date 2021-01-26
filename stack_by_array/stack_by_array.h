#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10

//stack에 들어갈 data 구조체
typedef struct {
	int xPos;
	int yPos;
} stackMemNode;

//stack 구조체
typedef struct {
	stackMemNode memory[MAX_SIZE];	//data가 저장될 배열
	int Top;	//stack의 top 위치를 가리키는 변수

	bool (*empty)(void);
	void (*pop)(void);
	void (*push)(stackMemNode *);
	size_t (*size)(void);
	stackMemNode *(*top)(void);
	//void (*emplace)(stackNode);
	//void (*swap)(stack);
} stack;
stack st;

bool stackEmpty(void);
void stackPop(void);
void stackPush(stackMemNode *);
size_t stackSize(void);
stackMemNode *stackTop(void);
void printStack(void);
