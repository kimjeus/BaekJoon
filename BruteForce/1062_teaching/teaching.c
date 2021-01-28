#include "teaching.h"

void bruteForce(int index)
{
	//탐색할 문자 조합이 이미 꽉 차서 더 이상 추가할 수 없을 때
	if (arrSelectLetterIdx == K - 5) {
		//반환한 반복문에서 문자를 하나 빼줘야 하므로 하나 강제로 추가한다.
		arrSelectLetter[arrSelectLetterIdx++] = arrAllLetter[index];
		return;
	}

	//탐색할 문자 조합을 추가하는데 아직 추가 안한 문자일 때 if문 실행
	if (!visited[index]) {
		arrSelectLetter[arrSelectLetterIdx++] = arrAllLetter[index];	//탐색할 문자 추가
		//추가했더니 문자 조합이 꽉차거나 || 넣을 수 있는 모든 문자를 이미 다 넣었을 때(추가로 넣을 것이 없으므로)
		if (arrSelectLetterIdx == K - 5 || (int)strlen(arrAllLetter) == arrSelectLetterIdx) {
#if DEBUG
			printf("%s : ", arrSelectLetter);
#endif
			countReadWord();	//만들 수 있는 단어 개수 계산 및 결과 갱신
		}
#if DEBUG
		printf("문자 추가\n");
		printf("index: %d\n", index);
		printf("%s\n", arrSelectLetter);
		printf("\n");
#endif
		visited[index] = true;	//문자 추가했음 체크한다.

		//배열의 순서대로 조합을 생각하고 있으므로 현재 입력받은 문자 이전 위치에 있는 문자들과의 조합은 이미 생각을 했으므로 index + 1부터 시작한다.
		for (int i = index + 1; i < (int)strlen(arrAllLetter); i++) {
			bruteForce(i);	//조합에 i추가할지 함수 대입
			arrSelectLetter[--arrSelectLetterIdx] = '\0';	//최종적으로 backtracking을 위해서 마지막에 추가한 문자를 제거하면서 돌아간다.

#if DEBUG
			printf("문자 감소\n");
			printf("i: %d\tstrlen: %d\n", index + 1, (int)strlen(arrAllLetter));
			printf("%s\n", arrSelectLetter);
			printf("\n");
#endif
		}
		visited[index] = false;	//문자 추가를 해제했음을 체크한다.
	}
	return;
}

void countReadWord(void)
{
	int count = 0;

	for (int i = 0; i < N; i++) {
		//arrLetter에 필요한 문자 개수가 K - 5보다 크면 어차피 못만드는 단어이다.
		if ((int)strlen(arrLetter[i]) <= K - 5) {

			int j;
			//조합한 문자에 포함되어 있는지 검사
			for (j = 0; j < (int)strlen(arrLetter[i]); j++) {
				if (!checkLetter(arrSelectLetter, arrLetter[i][j])) {
					break;
				}
			}
			//모든 문자가 selctLetter에 들어있으므로 만들 수 있는 단어이다.
			if (j == (int)strlen(arrLetter[i])) {
				count++;
			}
		}
	}

	//이번에 만들 수 있는 단어의 개수가 이전의 최대 갯수보다 많으면 갱신
	if (result < count) {
		result = count;
	}

	return;
}

void selectLetter(void)
{
	//N개의 단어에 필수 글자를 제외한 글자 저장
	for (int i = 0; i < N; i++) {
		//앞 뒤 필수 글자 각각 4글자는 제외
		for (int j = 4; j < (int)strlen(arrWord[i]) - 4; j++) {
			//필수로 필요한 문자 a, n, t, i, c가 아니라면
			if (arrWord[i][j] != 'a' && arrWord[i][j] != 'n' && arrWord[i][j] != 't' && arrWord[i][j] != 'i' && arrWord[i][j] != 'c') {
				//arrLetter에 이미 저장한 글자가 아닌지 검색
				if (!checkLetter(arrLetter[i], arrWord[i][j])) {
					//저장한 글자가 아니면 arrLetter[i]에 저장
					arrLetter[i][(int)strlen(arrLetter[i])] = arrWord[i][j];
				}
				//arrAllLetter에 이미 저장한 글자가 아닌지 검색
				if (!checkLetter(arrAllLetter, arrWord[i][j])) {
					//저장한 글자가 아니면 arrAllLetter에 저장
					arrAllLetter[(int)strlen(arrAllLetter)] = arrWord[i][j];
				}
			}
		}
	}
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

void countNecessary(void)
{
	selectLetter();

	for (int i = 0; i < N; i++) {
		if (arrLetter[i][0] == '\0') {
			result++;
		}
	}
	return;
}

void initArrSelectLetter(void)
{
	for (int i = 0; i < MAX_LETTER_COUNT - 3; i++) {
		arrSelectLetter[i] = '\0';
	}
	return;
}
void initVisited(void)
{
	for (int i = 0; i < MAX_LETTER_COUNT + 1; i++) {
		visited[i] = false;
	}
	return;
}
