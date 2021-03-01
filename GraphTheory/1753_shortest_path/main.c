#include "shortest_path.h"

int main(void)
{
	//정점의 개수 V, 간선의 개수 E, 시작 정점의 번호 K
	int E = 0, K = 0;
	//입력 받는 간선의 출발 정점 start, 도착 정점 end, 간선의 가중치 weight
	int start = 0;
	pq = (priority_queue *)malloc(sizeof(priority_queue));
	Node tmpNode;

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

//	graph = (Node *)calloc(V + 1, sizeof(node));
	//initGraph(V);

	//result 메모리 할당 및 초기화
	vec = (vector *)malloc(sizeof(vector) * (V + 1));
	result = (int *)malloc(sizeof(int) * (V + 1));
//  visit = (bool *)calloc(V + 1, sizeof(bool));
	for (int i = 0; i < V + 1; i++)
		initVEC(&vec[i]);
	initResult(V);

    //입력 받을 E개의 간선 graph에 저장
	for (int i = 0; i < E; i++) {
		scanf("%d %d %hhd", &start, &tmpNode.vertex, &tmpNode.weight);
		tmpNode.next = NULL;

		push_back(&vec[start], tmpNode);
//		addList(&graph[start], tmpNode);
	}
	printVector(vec);

	result[K] = 0;    //자기 자신으로 가는 가중치는 0 저장
	Dijkstra(K);
	
	for (int i = 1; i <= V; i++) {
		if (result[i] != INF)
			printf("%d\n", result[i]);
		else
			printf("INF\n");
	}
	
	free(vec);
	free(pq);
//	free(graph);
	free(result);
//  free(visit);
	return 0;
}

