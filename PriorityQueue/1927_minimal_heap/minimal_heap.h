#include <stdio.h>
#include <stdbool.h>

#define DEBUG 0
#define MAX_PQ_SIZE 100000

typedef struct _TreeNode {
	int value;
	Node left;
	Node right;
} TreeNode;

typedef struct _priority_queue {
	bool (*empty)(void);
	void (*pop)(void);
	void (*push)(unsigned int);
	size_t (*size)(void);
	int (*top)(void);
	
	TreeNode *rootNode;
	int mTop;
	int mFront;
	int mBack;
	int mSize;
} priority_queue;
priority_queue pq;

void initPQ(void);
bool empty(void);
void pop(void);
void push(unsigned int);
size_t size(void);
int top(void);
