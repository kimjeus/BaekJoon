#include "zero.h"

int main(void)
{
	st.empty = stackEmpty;
	st.pop = stackPop;
	st.push = stackPush;
	st.size = stackSize;
	st.top = stackTop;
	initStack();

	int K = 0;
	int inputNum = 0;
	int sum = 0;

	scanf("%d", &K);
	for(int i = 0; i < K; i++) {
		scanf("%d", &inputNum);
		if (inputNum == 0) {
			st.pop();
		}
		else if (inputNum > 0) {
			st.push(inputNum);
		}
	}

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	printf("%d\n", sum);

	return 0;
}
