#include <stdio.h>
#include <stdbool.h>
#include <string.h>	//strlen

#define DEBUG 0
#define MAX_WORD_COUNT 50
#define MAX_INPUT_WORD_SIZE 15
#define MAX_LETTER_COUNT 26

int N, K, result;
int arrSelectLetterIdx;
char arrWord[MAX_WORD_COUNT][MAX_INPUT_WORD_SIZE + 1];
	//초기에 입력 받은 단어를 arrWord[0]부터 arrWord[N-1]까지 차례대로 저장할 배열
	//단어는 15글자보다 작거나 같으므로 arrWord[i]의 size는 최대 16까지 필요함.
char arrLetter[MAX_WORD_COUNT][MAX_INPUT_WORD_SIZE - 8 + 1];
	//arrWord 배열에서 a, n, t, i, c를 제외하고 중복된 문자 없이 저장한다.
	//애초에 입력받은 문자가 15자인데 앞뒤 네글자는 무조건 제거되므로 최대 7글자만 필요함.
char arrAllLetter[MAX_LETTER_COUNT + 1];
	//arrLetter에 저장된 모든 문자를 중복되지 않게 저장
	//알파벳 소문자의 개수는 총 26개이므로 최대 26글자의 공간이 필요함
bool visited[MAX_LETTER_COUNT + 1];
	//가르칠 알파벳 문자를 조합할 때 이미 가르칠 예정인 문자는 중복해서 넣지 않도록 가르칠 문자에 이미 포함되어있는지 여부를 결정해주는 배열
	//입력 받은 알파벳 소문자의 최대 개수는 총 26개이므로 최대 26글자의 공간이 필요함
char arrSelectLetter[MAX_LETTER_COUNT - 5 + 1 + 1];	//탐색할 문자들의 조합을 저장하는 배열
	//가르칠 알파벳을 저장해 놓은 배열(a, n, t, i, c는 제외)
	//입력 받은 알파벳의 소문자의 최대 개수는 총 26개이므로 최대 21개의 공간이 필요함
	//꽉 차도 하나를 추가했다가 빼주는 명령이 있어서 하나 추가

void bruteForce(int);
	//arrAllLetter에 저장된 모든 문자들을 K - 5개만큼 조합해주는 함수
void countReadWord(void);
	//bruteForce() 함수에서 조합한 문자로 생성할 수 있는 단어의 개수를 계산해서 최댓값을 갱신해주는 함수

void selectLetter(void);
	//arrWord에서 a, n, t, i, c를 제외한 글자를 arrLetter에 중복되지 않도록 순서대로 저장
bool checkLetter(char *word, char letter);
	//인자로 받은 word 안에 문자 letter가 포함되는지 여부를 반환해주는 함수
void countNecessary(void);	
	//K == 5일 때 a, n, t, i, c로만 이루어진 단어를 계산해주는 함수
void initVisited(void);		//visited 배열을 초기화해주는 함수
void initArrSelectLetter(void);		//arrSelectLetter 배열을 초기화해주는 함수
