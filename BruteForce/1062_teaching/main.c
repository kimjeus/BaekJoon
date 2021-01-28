#include "teaching.h"

int main(void)
{
	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		scanf("%s", arrWord[i]);
	}

	//배울 수 있는 문자가 5개 미만이면 단 한개의 단어도 읽을 수 없다.
	if (K < 5) {
		printf("0\n");
		return 0;
	}
	//배울 수 있는 문자가 5개라면 정확히 a, n, t, i, c를 배워야 한다.
	else if (K == 5) {
		countNecessary();
	}
	//배울 수 있는 문자가 26개라면 모든 알파벳을 아는 것이므로 모든 단어를 읽을 수 있다.
	else if (K == 26) {
		result = N;
	}
	//배울 수 있는 문자가 5개보다 많고 26개보다 적을 때
	else {
		initArrSelectLetter();
		selectLetter();
#if DEBUG
		printf("arrAllL: %s\n", arrAllLetter);
#endif
		initVisited();
		//입력 받은 모든 단어가 a, n, t, i, c로만 이루어져 있을 때
		if (arrAllLetter[0] == '\0') {
			result = N;
		}

		//필요한 문자를 차례대로 brute force 알고리즘 방식으로 탐색한다.
		for (int i = 0; i < (int)strlen(arrAllLetter); i++) {
			bruteForce(i);
			arrSelectLetter[--arrSelectLetterIdx] = '\0';
		}
	}

	printf("%d\n", result);

#if DEBUG
	printf("arrLetter\n");
	for (int i = 0; i < N; i++) {
		printf("%s\n", arrLetter[i]);
	}
	printf("arrAllLetter\n");
	printf("%s\n", arrAllLetter);
#endif

	return 0;
}
