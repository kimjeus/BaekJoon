#include "dokidoki_snack_helper.h"

void sortingLine(int N, bool *result, stack *st, queue *qu)
{
	//간식번호 1부터 N까지의 번호표
	for (int i = 1; i <= N; i++) {
		//대기열 왼쪽의 공간의 제일 앞에 있는 사람이 간식 받을 차례의 번호표라면 간식을 받고 다음 간식 번호로 넘어간다
		if (!emptySt(st)) {
			if (top(st) == i) {
				popSt(st);
				continue;
			}
		}
		int j;
		int size = sizeQu(qu);
		for (j = 0; j < size; j++) {
			//대기열의 제일 앞에 있는 사람이 간식 받을 차례의 번호표일 때
			if (front(qu) == i) {
				popQu(qu);
				break;
			}
			//대기열의 제일 앞사람을 대기열 옆 라인으로 보내고 대기열의 다음 사람 번호표 검사ㄷ
			else {
				pushSt(st, front(qu));
				popQu(qu);
			}
		}
		//대기열의 끝까지 검사했는데 현재 순서의 번호표가 없다면 더 이상 진행 불가
		if (j == size) {
			*result = false;
			break;
		}
	}

	return;
}

void initStack(stack *st)
{
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++)
		st->mem[i] = 0;
	st->top = -1;
	return;
}
bool emptySt(stack *st)
{
	if (st->top == -1) { return true; }
	else { return false; }
}
void popSt(stack *st)
{
	if (!emptySt(st))
		st->mem[st->top--] = 0;
	return;
}
void pushSt(stack *st, int data)
{
	st->mem[++st->top] = data;
	return;
}
size_t sizeSt(stack *st) { return (size_t)(st->top + 1); }
int top(stack *st) { return st->mem[st->top]; }

void initQueue(queue *qu)
{
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++)
		qu->mem[i] = 0;
	qu->front = -1;
	qu->back = -1;
	return;
}
bool emptyQu(queue *qu)
{
	if (!(qu->back - qu->front)) { return true; }
	else { return false; }
}
void popQu(queue *qu)
{
	if (!emptyQu(qu))
		qu->mem[++qu->front] = 0;
	return;
}
void pushQu(queue *qu, int data)
{
	qu->mem[++qu->back] = data;
	return;
}
size_t sizeQu(queue *qu) { return (size_t)(qu->back - qu->front); }
int front(queue *qu) { return qu->mem[qu->front + 1]; }
int back(queue *qu) { return qu->mem[qu->back]; }
