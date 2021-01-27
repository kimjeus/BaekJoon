#include <stdio.h>
#include <stdbool.h>
#include <string.h>	//strlen

#define DEBUG 1
#define MAX_WORD_COUNT 50
#define MAX_WORD_SIZE 15

int N, K, depthCount;
char arrWord[MAX_WORD_COUNT][MAX_WORD_SIZE + 1];
char arrLetter[MAX_WORD_COUNT][MAX_WORD_SIZE - 4];	//a, n, t, i, c는 제외하므로 5를 뺀다.
char arrAllLetter[MAX_WORD_SIZE - 4];	//arrLetter에 저장된 모든 문자 저장
char visitedLetter[MAX_WORD_SIZE - 4];	//backtracking을 위해 방문을 체크하는 배열
char arrSelectLetter[MAX_WORD_SIZE - 4];	//탐색할 문자들의 조합을 저장하는 배열

void selectLetter(void);	//a, n, t, i, c를 제외한 글자를 arrLetter에 순서대로 저장
void countMakeWord(int, char);
bool checkLetter(char *word, char letter);
