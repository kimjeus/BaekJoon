#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 1000
#define MAX_INPUT_SIZE 100

//stack에 들어갈 data 구조체
typedef struct {
	int xPos;
	int yPos;
} stackMemNode;

//stack 구조체
typedef struct {
	stackMemNode memory[MAX_STACK_SIZE];	//data가 저장될 배열
	int Top;	//stack의 top 위치를 가리키는 변수

} stack;

bool empty(stack *);
void pop(stack *);
void push(stack *, stackMemNode *);
size_t size(stack *);
stackMemNode *top(stack *);
void printStack(stack *);
