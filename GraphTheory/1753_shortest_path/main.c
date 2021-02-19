#include "shortest_path.h"

int main(void)
{
	//정점의 개수 V, 간선의 개수 E, 시작 정점의 번호 K
	int V = 0, E = 0, K = 0;
	//입력 받는 간선의 출발 정점 start, 도착 정점 end, 간선의 가중치 weight
	int start = 0, end = 0, weight = 0;
	int minIdx = 0;
	node *cur = NULL;
	node *bf = NULL;

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	//graph 메모리 할당 및 초기화
	/*
	graph = (char **)malloc(sizeof(char *) * (V + 1));
	for (int i = 0; i <= V; i++) {
		graph[i] = (char *)malloc(sizeof(char) * (V + 1));
	}
	*/
	graph = (node *)malloc(sizeof(node) * (V + 1));
	cur = (node *)malloc(sizeof(node));
	bf = (node *)malloc(sizeof(node));
	initGraph(V);

	//result, visit 메모리 할당 및 초기화
	result = (int *)malloc(sizeof(int) * (V + 1));
	visit = (bool *)malloc(sizeof(bool) * (V + 1));
	initResult(V);

	for (int i = 0; i < E; i++) {
		node *temp = (node *)malloc(sizeof(node));

		scanf("%d %d %d", &start, &end, &weight);
//		graph[start][end] = weight;
		cur = &graph[start];
		while (cur->next != NULL) {
			bf = cur;
			cur = cur->next;
		}
		temp->weight = weight;
		temp->vertex = end;
		bf = cur;
		cur = temp;
		bf->next = cur;
#if DEBUG
		printf("start:%d ", start);
		print(&graph[start]);
#endif
	}
/*
#if DEBUG
	printf("%d, %d: %d\n", 1, graph[1].vertex, graph[1].weight);
	printf("%d, %d: %d\n", 1, graph[1].next->vertex, graph[1].next->weight);
	printf("%d, %d: %d\n", 2, graph[2].vertex, graph[2].weight);
	printf("%d, %d: %d\n", 2, graph[2].next->vertex, graph[2].next->weight);
	printf("%d, %d: %d\n", 3, graph[3].vertex, graph[3].weight);
	printf("%d, %d: %d\n", 5, graph[5].vertex, graph[5].weight);
#endif
*/
	renewResult(V, K, K);
#if DEBUG
		printf("%d :: ", K);
		for (int j = 1; j <= V; j++) {
			printf("%d:%d\t", j, result[j]);
		}
		printf("\n");
#endif
	for (int i = 1; i < V; i++) {
		findMin(V, &minIdx);
		renewResult(V, K, minIdx);
#if DEBUG
		printf("%d :: ", minIdx);
		for (int j = 1; j <= V; j++) {
			printf("%d:%d\t", j, result[j]);
		}
		printf("\n");
#endif
	}

	for (int i = 1; i <= V; i++) {
		if (result[i] != INF)
			printf("%d\n", result[i]);
		else
			printf("INF\n");
	}
	//메모리 해제
	/*
	for (int i = 0; i <= V; i++) {
		free(graph[i]);
	}
	*/
	free(graph);
//	free(cur);
	free(result);
	free(visit);
	return 0;
}

