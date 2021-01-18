#include "printer_queue.h"

int printingInOrder(int goalNum, int goalNumImport)
{
	int count = 0;
	SDocument tempDoc;

	tempDoc.mDocNum = 0;
	tempDoc.mImportNum = 0;

	while (tempDoc.mDocNum != goalNum || !isMostImportant(goalNumImport)) {
#if DEBUG
	printf("@@@count@@@: %d\n", count);
#endif
		if (isMostImportant(struQueue.mArrQueue[struQueue.mFront].mImportNum)) {
			tempDoc = popQueue();	
			count++;
			if (isEmptyQueue()) {
				break;
			}
		}
		else {
			tempDoc = popQueue();	
			pushQueue(tempDoc);
		}
	}

	return count;
}

bool isMostImportant(int importNum)
{
#if DEBUG
	printf("isMostImoprtant\n");
	printf("importNum: %d\n", importNum);
#endif
	if (struQueue.mFront < struQueue.mBack) {

		for (int i = struQueue.mFront; i < struQueue.mBack; i++) {
#if DEBUG
			printf("queue[%d] importNum: %d\n", i, struQueue.mArrQueue[i].mImportNum);
#endif
			if (importNum < struQueue.mArrQueue[i].mImportNum) {
				return false;
			}
		}
	}
	else {
		for (int i = 0; i < struQueue.mBack; i++) {
#if DEBUG
			printf("queue[%d] importNum: %d\n", i, struQueue.mArrQueue[i].mImportNum);
#endif
			if (importNum < struQueue.mArrQueue[i].mImportNum) {
				return false;
			}
		}
		for (int i = struQueue.mFront; i < MAX_QUEUE_SIZE; i++) {
#if DEBUG
			printf("queue[%d] importNum: %d\n", i, struQueue.mArrQueue[i].mImportNum);
#endif
			if (importNum < struQueue.mArrQueue[i].mImportNum) {
				return false;
			}
		}

	}
	return true;
}

bool isEmptyQueue(void)
{
#if DEBUG
	printf("isEmptyQueue\n");
	printf("front: %d, back: %d\n", struQueue.mFront, struQueue.mBack);
#endif
	if (struQueue.mFront == struQueue.mBack) {
		return true;
	}
	else {
		return false;
	}
}

SDocument popQueue(void)
{
	SDocument tempStruDoc;
	tempStruDoc.mDocNum = struQueue.mArrQueue[struQueue.mFront].mDocNum;
	tempStruDoc.mImportNum = struQueue.mArrQueue[struQueue.mFront].mImportNum;
	struQueue.mArrQueue[struQueue.mFront].mDocNum = 0;
	struQueue.mArrQueue[struQueue.mFront].mImportNum = 0;

#if DEBUG
	printf("popQueue\nfront: %d, docNum: %d, importNum: %d\n", struQueue.mFront, tempStruDoc.mDocNum, tempStruDoc.mImportNum);
#endif

	struQueue.mFront++;
	struQueue.mFront %= MAX_QUEUE_SIZE;

	return tempStruDoc;
}

void pushQueue(SDocument inputStruDoc)
{
	struQueue.mArrQueue[struQueue.mBack].mDocNum = inputStruDoc.mDocNum;
	struQueue.mArrQueue[struQueue.mBack].mImportNum = inputStruDoc.mImportNum;

#if DEBUG
	printf("pushQueue\nback: %d, docNum: %d, importNum: %d\n", struQueue.mBack, inputStruDoc.mDocNum, inputStruDoc.mImportNum);
#endif

	struQueue.mBack++;
	struQueue.mBack %= MAX_QUEUE_SIZE;

	return;
}
