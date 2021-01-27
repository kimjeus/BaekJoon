#include "teaching.h"

void selectLetter(void)
{
//	int arrAllLetterIdx = 0;
	//N개의 단어에 필수 글자를 제외한 글자 저장
	for (int i = 0; i < N; i++) {
//		int arrLetterIdx = 0;
		//앞 뒤 필수 글자 각각 4글자는 제외
		for (int j = 4; j < (int)strlen(arrWord[i]) - 4; j++) {
			if (arrWord[i][j] != 'a' && arrWord[i][j] != 'n' && arrWord[i][j] != 't' && arrWord[i][j] != 'i' && arrWord[i][j] != 'c') {
				//arrLetter에 이미 저장한 글자가 아닌지 검색
				if (!checkLetter(arrLetter[i], arrWord[i][j])) {
					arrLetter[i][(int)strlen(arrLetter[i])] = arrWord[i][j];
				}
				//arrAllLetter에 이미 저장한 글자가 아닌지 검색
				if (!checkLetter(arrAllLetter, arrWord[i][j])) {
					arrAllLetter[(int)strlen(arrAllLetter)] = arrWord[i][j];
				}
			}
		}
	}

	return;
}

void countMakeWord(char letter)
{
	if (depthCount == K) {
		return;
	}
	if (!checkLetter(arrAllLetter, letter) && !checkLetter(visitedLetter, letter)) {
		arrSelectLetter[(int)strlen(arrSelectLetter)] = letter;
		depthCount++;
		for (int i = 0; i < ; i++) {
			countMakeWord(arrAllLetter[i]);
		}
	}
	if (letter == '\0') {}
	printf("1\n");	

	return;
}

bool checkLetter(char *word, char letter)
{
	for (int i = 0; i < (int)strlen(word); i++) {
		if (word[i] == letter) {
			return true;
		}
	}
	return false;
}
