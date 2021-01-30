#include "stack_by_array.h"

int main(void)
{
	//stack 선언
	stack *st = (stack *)malloc(sizeof(stack));
	//stack의 memory 초기화
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		st->memory[i].xPos = -1;
		st->memory[i].yPos = -1;
	}
	st->Top = -1;

	//입력받은 명령어를 저장할 문자열
	char inputString[MAX_INPUT_SIZE];
	//push할 data는 여기에 저장해서 인자로 넘겨줌.
	stackMemNode *nodeData;
	//push 하기 위해 입력받은 data 임시 저장함.
	int temp;
	
	nodeData = (stackMemNode *)malloc(sizeof(stackMemNode));

	while (1) {
		printf("1.'empty'\n2.'pop'\n3.'push'\n4.'size'\n5.'top'\n6.'print'\n7.'exit'\n");
		printf("input order: ");
		scanf("%s", inputString); 
		nodeData->xPos = -1;
		nodeData->yPos = -1;
		
		//empty 명령이 들어올 때
		if (!strcmp(inputString, "empty")) {
			if (empty(st)) {
				printf("true\n");
			}
			else {
				printf("false\n");
			}
		}
		//pop 명령이 들어올 때
		else if (!strcmp(inputString, "pop")) {
			pop(st);
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

			push(st, nodeData);
		}
		//size 명령이 들어올 때
		else if (!strcmp(inputString, "size")) {
			printf("%zu\n", size(st));
		}
		//top 명령이 들어올 때
		else if (!strcmp(inputString, "top")) {
			nodeData = top(st);

			printf("xPos: %d, yPos: %d\n", nodeData->xPos, nodeData->yPos);
		}
		//print 명령이 들어올 때
		else if (!strcmp(inputString, "print")) {
			printStack(st);
		}
		else if (!strcmp(inputString, "exit")) {
			break;
		}
		//그 이외의 명령이 들어올 때
		else {
			printf("undefined order\n");
		}
		printf("\n");
	}

	free(nodeData);

	return 0;
}
