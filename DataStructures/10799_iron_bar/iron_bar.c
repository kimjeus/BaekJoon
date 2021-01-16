#include "iron_bar.h"

int countIronBar(char *arrInput)
{
	int countLeftParenthesis = 0;
	int count = 0;

	for (int i = 0; i < strlen(arrInput); i++) {
		if (arrInput[i] == '(') {
			if (arrInput[i + 1] == ')') {
				count += countLeftParenthesis;
				i++;
			}
			else {
				countLeftParenthesis++;
			}
		}
		else {
			countLeftParenthesis--;
			count++;
		}
	}

	return count;
}
