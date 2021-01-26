#include "zero.h"

bool stackEmpty(void)
{
	if (st.Top == -1)
		return true;
	else
		return false;
}
void stackPop(void)
{
	if (st.Top == -1)
		return;

	st.memory[st.Top] = -1;
	st.Top--;

	return;
}
void stackPush(int value)
{
	if (st.Top == MAX_STACK_SIZE - 1)
		return;
	
	st.Top++;
	st.memory[st.Top] = value;

	return;
}
size_t stackSize(void)
{
	return (size_t)(st.Top + 1);
}
int stackTop(void)
{
	return st.memory[st.Top];
}
void initStack(void)
{
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		st.memory[i] = -1;
	}
	st.Top = -1;

	return;
}
