#include "shortest_path.h"

void findMin(int V, int *minIdx)
{
	int min = INF;
	*minIdx = 0;

	for (int i = 1; i <= V; i++) {
		if (!visit[i] && min > result[i]) {
			min = result[i];
			*minIdx = i;
		}
	}
	return;
}

void renewResult(int V, int K, int minIdx)
{
	visit[minIdx] = true;
	/*
	   for (int i = 1; i <= V; i++) {
	   if (graph[K][minIdx] <= 10 && graph[minIdx][i] <= 10)
	   if (result[i] > graph[K][minIdx] + graph[minIdx][i])
	   result[i] = graph[K][minIdx] + graph[minIdx][i];
	   }
	 */

	char tempa = 0;
	char tempb = 0;

	for (int i = 1; i <= V; i++) {
		tempa = searchList(K, minIdx);
		if (tempa > 0) {
			tempb = searchList(minIdx, i);
			if (result[i] > tempa + tempb)
				result[i] = tempa + tempb;
		}
	}
	return;
}

char searchList(int i, int minIdx)
{
	node *temp = (node *)malloc(sizeof(node));

	temp = &graph[i];
	while (1) {
		if (temp->vertex == minIdx)
			return temp->weight;
		else if (temp->next == NULL)
			return -1;
		else
			temp = temp->next;
	}
}

void initGraph(int V)
{
	/*
	   for (int i = 1; i <= V; i++) {
	   for (int j = 1; j <= V; j++) {
	   if (i == j)
	   graph[i][j] = 0;
	   else
	   graph[i][j] = 11;
	   }
	   }
	 */
	for (int i = 1; i <= V; i++) {
		graph[i].weight = 0;
		graph[i].vertex = 0;
		graph[i].next = NULL;
	}
	return;
}
void initResult(int V)
{
	for (int i = 1; i <= V; i++) {
		result[i] = INF;
		visit[i] = false;
	}
	return;
}
void print(node *temp)
{
	printf("%d : %d\t", temp->vertex, temp->weight);
	while (temp->next != NULL) {
		temp = temp->next;
		printf("%d : %d\t", temp->vertex, temp->weight);
	}
	printf("\n");
	return;
}
