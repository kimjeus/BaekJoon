#include "value_of_parentheses.h"

int main(void)
{
	int temp = 1, result = 0;
	char inputStr[MAX_STACK_SIZE];
	stack *st = (stack *)malloc(sizeof(stack));

	scanf("%s", inputStr);

	initStack(st);
	for (int i = 0; i < (int)strlen(inputStr); i++) {
		//여는 괄호는 temp 값 증가
		if (inputStr[i] == '(') {
			push(st, inputStr[i]);
			temp *= 2;
		}
		//여는 괄호는 temp 값 증가
		else if (inputStr[i] == '[') {
			push(st, inputStr[i]);
			temp *= 3;
		}
		//닫는 괄호는 temp 값 감소
		else if (inputStr[i] == ')') {
			if (top(st) == '(') {
				pop(st);
			}
			//stack이 비어있으면 정상적이지 않은 문자열임.
			else {
				result = 0;
				break;
			}
			//처음 등장하는 닫는 괄호였을 때 reuslt 값 증가
			if (inputStr[i - 1] == '(') {
				result += temp;
			}
			temp /= 2;
		}
		//닫는 괄호는 temp 값 감소
		else if (inputStr[i] == ']') {
			if (top(st) == '[') {
				pop(st);
			}
			//stack이 비어있으면 정상적이지 않은 문자열임.
			else {
				result = 0;
				break;
			}
			//처음 등장하는 닫는 괄호였을 때 reuslt 값 증가
			if (inputStr[i - 1] == '[') {
				result += temp;
			}
			temp /= 3;
		}
	}
	if (!empty(st)) {
		result = 0;
	}
	
	printf("%d\n", result);

	free(st);
	return 0;
}
