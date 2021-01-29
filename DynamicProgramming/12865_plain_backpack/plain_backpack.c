#include "plain_backpack.h"


void DP(void)
{
	for (int i = 0; i <= N; i++) {
		for (int j = 0;j <= K; j++) {
			//물건이 0개이거나 가방 허용 무게가 0이면 아무것도 넣을 수 없음.
			if (i == 0 || j == 0) {
				DPmap[i][j] = 0;
				continue;
			}

			//새로 추가되는 물건의 무게가 현재 배낭 최대 무게보다 무거우면 새로 추가되는 물건은 절대 포함 될 수 없음.
			if (arrInput[i].mWeight > j) {
				DPmap[i][j] = DPmap[i - 1][j];
			}
			//새로 추가되는 물건의 무게가 현재 배낭 최대 무게는 넘지 않을 때
			else {
				//새로 추가되는 물건이 포함되지 않으면  value가 더 클 때
				if (DPmap[i - 1][j] > DPmap[i - 1][j - arrInput[i].mWeight] + arrInput[i].mValue) {
					DPmap[i][j] = DPmap[i - 1][j];
				}
				//새로 추가되는 물건이 포함되면 value가 더 클 때
				else {
					DPmap[i][j] = DPmap[i - 1][j - arrInput[i].mWeight] + arrInput[i].mValue;
				}
			}
		}
	}
	return;
}
/*
void weightBruteForce(Node *currentNode, int arrInputIdx)
{
	//현재 무게에서 인자의 무게까지 추가되면 배낭의 한계를 초과할 때
	if (currentNode->mWeight + arrInput[arrInputIdx].mWeight > K) {
		return;
	}
	//현재 무게, 가치 갱신
	currentNode->mWeight += arrInput[arrInputIdx].mWeight;
	currentNode->mValue += arrInput[arrInputIdx].mValue;

#if DEBUG
	printf("current W: %d, V: %d\n", currentNode->mWeight, currentNode->mValue);
	printf("result: %d, current idx: %d\n", result, arrInputIdx);
	printf("\n");
#endif

	//갱신된 현재 가치가 최대치라면 result 갱신
	if (result < currentNode->mValue) {
		result = currentNode->mValue;
	}

	//배열 순서대로 탐색
	for (int i = arrInputIdx + 1; i < N; i++) {
		if (currentNode->mWeight + arrInput[arrInputIdx + 1].mWeight > K) {
			break;
		}
		weightBruteForce(currentNode, i);
	}

	//현재 무게, 가치 backtracking
	currentNode->mWeight -= arrInput[arrInputIdx].mWeight;
	currentNode->mValue -= arrInput[arrInputIdx].mValue;

	return;
}

void sortArrInput(void)
{
	int tempWeight = 0, tempValue = 0;
	//배열의 맨 뒤부터 정렬이 되므로 0부터 i-1까지 정렬을 반복한다.
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			//앞에 있는 무게가 더 크면 swap 해준다.
			if (arrInput[j].mWeight > arrInput[j + 1].mWeight) {
				tempWeight = arrInput[j].mWeight;
				tempValue = arrInput[j].mValue;
				arrInput[j].mWeight = arrInput[j + 1].mWeight;
				arrInput[j].mValue = arrInput[j + 1].mValue;
				arrInput[j + 1].mWeight = tempWeight;
				arrInput[j + 1].mValue = tempValue;
			}
		}
	}
	return;
}
*/
