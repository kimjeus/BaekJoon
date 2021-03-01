#include "shortest_path.h"

void initData(Data *data)
{
	data->weight = 0;
	data->vertex = 0;
	return;
}
void initPQ(priority_queue *pq)
{
	for (int i = 0; i < MAX_PQ_SIZE; i++) { initData(&pq->mem[i]); }
	pq->back = 0;
	return;
}
bool empty(priority_queue *pq)
{
	if (!pq->back) { return true; }
	else { return false; }
}
void pop(priority_queue *pq)
{
	if (empty(pq)) { return; }
	pq->mem[1] = pq->mem[pq->back];
	initData(&pq->mem[pq->back--]);
	if (empty(pq)) { return; }

	int parent = 1;
	int child = parent * 2;
	int pqSize = (int)size(pq);

	while (child <= pqSize) {
		if (child + 1 <= pqSize && pq->mem[child].weight > pq->mem[child + 1].weight) { child++; }

		if (pq->mem[parent].weight > pq->mem[child].weight) {
			swapData(&pq->mem[parent], &pq->mem[child]);
			parent = child;
			child = parent * 2;
		}
		else { break; }
	}
	return;
}
void push(priority_queue *pq, Data data)
{
	pq->mem[++pq->back] = data;
	if ((int)size(pq) == 1) { return; }

	int child = pq->back;
	int parent = child / 2;

	while (child > 1) {
		if (pq->mem[parent].weight > pq->mem[child].weight) {
			swapData(&pq->mem[parent], &pq->mem[child]);
			child = parent;
			parent = child / 2;
		}
		else { break; }
	}
	return;
}
size_t size(priority_queue *pq) { return (size_t)pq->back; }
Data top(priority_queue *pq) { return pq->mem[1]; }
void swapData(Data *pData, Data *cData)
{
	Data temp;
	initData(&temp);
	temp = *pData;
	*pData = *cData;
	*cData = temp;
	return;
}

void initNode(Node *node)
{
	node->weight = 0;
	node->vertex = 0;
	node->next = NULL;
	return;
}
void initVEC(vector *vec)
{
	vec->mem = (Node *)malloc(sizeof(Node) * 10);
	for (int i = 0; i < 10; i++) { initNode(&vec->mem[i]); } 
	vec->memSize = 10;
	vec->back = 0;
	return;
}
void vectorFull(vector *vec)
{
	vec->memSize *= 2;
	vec->mem = (Node *)realloc(vec->mem, sizeof(Node) * (vec->memSize));
	for (int i = vec->memSize / 2; i < vec->memSize; i++) { initNode(&vec->mem[i]); }
	return;
}
void push_back(vector *vec, Node node)
{
	if (vec->back == vec->memSize)
		vectorFull(vec);
	vec->mem[vec->back++] = node;
	return;
}
size_t sizeV(vector *vec) { return (size_t)vec->back; }

void Dijkstra(int K)
{
//	Node *tmpNode;
	vector *tmpVec;
	Data tmpData;
	tmpData.vertex = K;
	tmpData.weight = result[K];

	push(pq, tmpData);	//먼저 자기 자신으로 가는 것을 검사한다

	while (!empty(pq)) {
        //priorityQueue에서 시작 정점 K로부터 가장 가까운 정점과 가중치 가져옴
		int curV = top(pq).vertex;
		int curW = top(pq).weight;
		pop(pq);

        //정점 K에서 정점 curV까지의 가중치가 curW가 최소가 아니라면 필요가 없다
		if (result[curV] < curW) { continue; }
//      if (visit[curV]) { continue; }
//      visit[curV] = true;

//		tmpNode = &graph[curV];
		tmpVec = &vec[curV];

		for (int i = 0; i < (int)sizeV(tmpVec); i++) {
//			printf("vertex: %d, result: %d, curW: %d, weight: %d\n", tmpVec->mem[i].vertex, result[tmpVec->mem[i].vertex], curW, tmpVec->mem[i].weight);
			if (result[tmpVec->mem[i].vertex] > curW + tmpVec->mem[i].weight) {
				result[tmpVec->mem[i].vertex] = curW + tmpVec->mem[i].weight;

				tmpData.vertex = tmpVec->mem[i].vertex;
				tmpData.weight = result[tmpData.vertex];
				push(pq, tmpData);
			}
		}
		/*
		//정점curV 로부터 연결된 모든 정점들을 검사한다.
		while (tmpNode->next) {
			tmpNode = tmpNode->next;

            //정점 K에서 tmpData->vertex 정점으로
            //직접 가는 가중치와 curV 정점을 거쳐 가는 가중치의 크기 비교
			if (result[tmpNode->vertex] > curW + tmpNode->weight) {
				result[tmpNode->vertex] = curW + tmpNode->weight;

				tmpData.vertex = tmpNode->vertex;
				tmpData.weight = result[tmpNode->vertex];
				push(pq, tmpData);
			}
		}
		*/
	}
	return;
}
void addList(Node *stNode, Node temp)
{
    //추가할 tmpNode생성
	Node *tmpNode = (Node *)malloc(sizeof(Node));
	tmpNode->vertex = temp.vertex;
	tmpNode->weight = temp.weight;
	tmpNode->next = temp.next;
    
    //startNode에 연결된 Node의 개수가 0일 때
	if (!stNode->vertex) {
		stNode->next = tmpNode;
		stNode->vertex++;
		return;
	}

	Node *curNode;
	curNode = stNode;

	while (curNode->next != NULL) {
        curNode = curNode->next;
		//대입하려는 vertex가 이미 존재하면 추가가 아니라 값만 변경해준다.
		if (curNode->vertex == tmpNode->vertex) {
			if (curNode->weight > tmpNode->weight)
			   	curNode->weight = tmpNode->weight;
			break;
		}
	}
    //대입하려는 vertex가 존재하지 않으면 Node를 새로 추가해준다.
	if (curNode->vertex != tmpNode->vertex)
		curNode->next = tmpNode;
        
    stNode->vertex++;
	return;
}
/*
void initGraph(int V)
{
	for (int i = 1; i <= V; i++) {
		graph[i].weight = 0;
		graph[i].vertex = 0;
		graph[i].next = NULL;
	}
	return;
}
*/
void initResult(int V)
{
	for (int i = 1; i <= V; i++)
		result[i] = INF;
	return;
}
#if DEBUG
void printVector(vector *vec)
{
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < (int)sizeV(&vec[i]); j++) {
			printf("v:%d, w:%d   ", vec[i].mem[j].vertex, vec[i].mem[j].weight);
		}
		printf("\n");
	}
	return;
}
#endif
