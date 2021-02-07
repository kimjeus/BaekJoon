#include "lets_go_travel.h"

void visit(int cityNum)
{
	arrCity[cityNum] = true;
	for (int i = 1; i <= N; i++) {
		if (inputCity[cityNum][i] && !arrCity[i]) {
			visit(i);
		}
	}
}
