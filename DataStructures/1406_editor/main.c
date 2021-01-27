#include "editor.h"

int main(void)
{
	int N = 0, M = 0;
	char inputOrder = '\0';
	char inputCh = '\0';
	stack frontSt;
	stack backSt;
	initStack(&frontSt);
	initStack(&backSt);

	scanf("%s", frontSt.memory);	//초기 입력 문자열
	N = strlen(frontSt.memory);	//문자열 길이 저장
	frontSt.Top += N;	//초기 입력 문자열 길이만큼 front stack의 Top 값 증가

	scanf("%d", &M);	//명령어의 개수 M
	for (int i = 0; i < M; i++) {
		getchar();
		scanf("%c", &inputOrder);	//명령어 입력 받음
		//커서 왼쪽에 있는 문자 삭제 = front stack pop
		if (inputOrder == 'B') {
			pop(&frontSt);
#if DEBUG
			printf("front: %s\n", frontSt.memory);
			printf("back: %s\n", backSt.memory);
			printf("\n");
#endif
		}
		//커서 왼쪽에 문자 추가 = front stack push
		else if (inputOrder == 'P') {
			getchar();
			scanf("%c", &inputCh);
			push(&frontSt, inputCh);
#if DEBUG
			printf("front: %s\n", frontSt.memory);
			printf("back: %s\n", backSt.memory);
			printf("\n");
#endif
		}
		//커서를 왼쪽으로 한 칸 옮김 = front stack top, pop && back stack push
		else if (inputOrder == 'L') {
			inputCh = top(&frontSt);
			//front stack이 비어있어서 움직일 필요가 없을 때
			if (inputCh != '\0') {
				pop(&frontSt);
				push(&backSt, inputCh);
			}
#if DEBUG
			printf("front: %s\n", frontSt.memory);
			printf("back: %s\n", backSt.memory);
			printf("\n");
#endif
		}
		else if (inputOrder == 'D') {	//back top. pop && front push
			inputCh = top(&backSt);
			//back stcak이 비어있어서 움직일 필요가 없을 때
			if (inputCh != '\0') {
				pop(&backSt);
				push(&frontSt, inputCh);
			}
#if DEBUG
			printf("front: %s\n", frontSt.memory);
			printf("back: %s\n", backSt.memory);
			printf("\n");
#endif
		}
		else {
			printf("error\n");
		}
	}

	while (!empty(&backSt)) {
		inputCh = top(&backSt);
		pop(&backSt);
		push(&frontSt, inputCh);
	}

	printf("%s\n", frontSt.memory);

	return 0;
}
