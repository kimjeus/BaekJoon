#include "stack_by_array.h"

bool empty(stack *st)
{
	if (st->Top == -1)	//stack이 비어있을 때
		return true;
	else
		return false;
}
void pop(stack *st)
{
	if (st->Top == -1)	//stack이 비어있어서 pop할 data가 없을 때
		return;

	st->memory[st->Top].xPos = -1;	//data를 -1로 초기화
	st->memory[st->Top].yPos = -1;
	st->Top--;	//data 개수가 하나 줄었으므로 top 1 감소

	return;
}
void push(stack *st, stackMemNode *node)
{
	st->Top++;	//data 개수가 하나 증가했으므로 top 1 증가
	st->memory[st->Top].xPos = node->xPos;	//data를 대입
	st->memory[st->Top].yPos = node->yPos;

	return;
}
size_t size(stack *st)
{
	return (size_t)(st->Top + 1);	//data가 배열에 저장되어 있어서 Top이 0부터 시작하므로 개수는 +1 해준다.
}
stackMemNode *top(stack *st)
{
	stackMemNode *pNode = malloc(sizeof(stackMemNode));	//구조체를 반환하기 위해서는 동적할당이 필요
	//stack이 비어있을 때
	if (st->Top == -1) {
		pNode->xPos = -1;
		pNode->yPos = -1;

		return pNode;
	}

	//top 위치의 값을 대입해서 반환
	pNode->xPos = st->memory[st->Top].xPos;
	pNode->yPos = st->memory[st->Top].yPos;

	return pNode;
}
void printStack(stack *st)	//stack 모든 data 출력
{
	for (int i = 0; i <= st->Top; i++) {
		printf("xPos: %d\tyPos: %d\n", st->memory[i].xPos, st->memory[i].yPos);
	}
	printf("\n");

	return;
}
