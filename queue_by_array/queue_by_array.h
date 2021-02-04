#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 1
#define MAX_QUEUE_SIZE 10
#define MAX_INPUT_SIZE 20

//queue에 들어갈 data 구조체
typedef struct _Data {
	int xPos;
	int yPos;
} Data;

//queue 구조체
typedef struct _queue {
	Data mem[MAX_QUEUE_SIZE];
	int Front;
	int Back;
} queue;

bool empty(queue *);
void pop(queue *);
void push(queue *, Data *);
size_t size(queue *);
Data front(queue *);
Data back(queue *);
void initQueue(queue *);
