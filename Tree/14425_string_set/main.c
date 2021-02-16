#include "string_set.h"

int main(void)
{
	int N = 0, M = 0;
	Node *root = (Node *)malloc(sizeof(Node));

	scanf("%d %d", &N, &M);
	getchar();

	makeTree(root, N);	
	searchTree(root, M);

	printf("%d\n", result);

	free(root);
	return 0;
}
