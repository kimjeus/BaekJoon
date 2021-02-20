#include "balanced_world.h"

int main(void)
{
	//모든 괄호 문자를 다루는 stack
	stack *st = (stack *)malloc(sizeof(stack));

	//input 한 줄 받을 문자열
	char inputStr[MAX_STRING_SIZE];
	int inputStrIdx = 0;
	//출력할 결과
	bool result = true;

	while(1) {
		
		initInputStr(inputStr);
		initStack(st);
		inputStrIdx = 0;	//index 초기화
		//input 한 줄 받아서 inputStr에 저장
		do {
			inputStr[inputStrIdx] = getchar();
		} while (inputStr[inputStrIdx++] != '.');
		//input buffer에서 개행 나올 때까지 비움
		while (getchar() != '\n') {}
#if DEBUG
		printf("inputStr: %s\n", inputStr);
#endif

		//'.' 하나만 들어왔을 때 반복문 종료
		if (!strcmp(inputStr, ".")) {
			break;
		}

		result = true;		//result 초기화
		for (int i = 0; i < (int)strlen(inputStr); i++) {
			//'('는 stack에 push
			if (inputStr[i] == '(') {
				push(st, inputStr[i]);
			}
			//'['는 stack에 push
			else if (inputStr[i] == '[') {
				push(st, inputStr[i]);
			}
			//')'는 stack의 top에 '('가 있으면 pop, 없으면 실패
			else if (inputStr[i] == ')') {
				if (top(st) != '(') {
					result = false;
					break;
				}
				pop(st);
			}
			//']'는 stack의 top에 '['가 있으면 pop, 없으면 실패
			else if (inputStr[i] == ']') {
				if (top(st) != '[') {
					result = false;
					break;
				}
				pop(st);
			}
		}
		//모든 괄호가 짝이 맞아서 stack이 전부 비워졌는지 검사
		if (!empty(st)) {
			result = false;
		}

		if (result) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	free(st);
	return 0;
}
