#include "parenthesis.h"

int isVPS(char *input)
{
	int leftPS = 0, rightPS = 0;

	for (int i = 0; i < MAX_STRING_LENGTH; i++) {
		if (input[i] == '(') {
			leftPS++;
		}
		else if (input[i] == ')') {
			if (leftPS == rightPS) {
				return 0;
			}
			rightPS++;
		}
		else {
			break;
		}
	}

	if (leftPS == rightPS) {
		return 1;
	}
	else {
		return 0;
	}
}
