#include "stack_by_array.h"

int main(void)
{
	st.empty = stackEmpty;
	st.pop = stackPop;
	st.push = stackPush;
	st.size = stackSize;
	st.top = stackTop;
	//stack의 memory 초기화
	for (int i = 0; i < MAX_SIZE; i++) {
		st.memory[i].xPos = -1;
		st.memory[i].yPos = -1;
	}
	st.Top = -1;

	char inputString[10];
	stackMemNode *nodeData;
	int temp;
	
	nodeData = (stackMemNode *)malloc(sizeof(stackMemNode));

	while (1) {
		printf("1.'empty'\n2.'pop'\n3.'push'\n4.'size'\n5.'top'\n6.'exit'\n");
		printf("input order: ");
		scanf("%s", inputString); 
		nodeData->xPos = -1;
		nodeData->yPos = -1;
		
		//empty 명령이 들어올 때
		if (!strcmp(inputString, "empty")) {
			if (st.empty()) {
				printf("true\n");
			}
			else {
				printf("false\n");
			}
			printStack();
		}
		//pop 명령이 들어올 때
		else if (!strcmp(inputString, "pop")) {
			st.pop();
			printStack();
		}
		//push 명령이 들어올 때
		else if (!strcmp(inputString, "push")) {
			//stack에 들어갈 data 입력 받기
			printf("xPos: ");
			scanf("%d", &temp);
			nodeData->xPos = temp;

			printf("yPos: ");
			scanf("%d", &temp);
			nodeData->yPos = temp;

			st.push(nodeData);
			printStack();
		}
		//size 명령이 들어올 때
		else if (!strcmp(inputString, "size")) {
			printf("%zu\n", st.size());
			printStack();
		}
		//top 명령이 들어올 때
		else if (!strcmp(inputString, "top")) {
			nodeData = st.top();

			printf("xPos: %d, yPos: %d\n", nodeData->xPos, nodeData->yPos);
			printStack();
		}
		else if (!strcmp(inputString, "exit")) {
			break;
		}
		//그 이외의 명령이 들어올 때
		else {
			printf("undefined order\n");
			printStack();
		}
	}

	free(nodeData);

	return 0;
}
