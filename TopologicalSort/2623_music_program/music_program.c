#include "music_program.h"

void check(int pos)
{
    bool before = false;
    
    for (int i = 1; i <= N; i++) {
		//pos 이전에 해야하는 가수가 있는지 검사
        if (graph[i][pos]) {
            before = true;
            break;
        }
    }
	//pos 이전에 해야하는 가수가 없으면 queue에 push (제거 가능)
    if (!before) {
        push(qu, pos);
    }
    return;
}

bool topologicalSorting(void)
{
    while (!empty(qu)) {
        int cur = front(qu);
        pop(qu);
        
		//queue의 front에 들어 있는 가수의 모든 연결 제거
        for (int i = 1; i <= N; i++) {
            if (graph[cur][i]) {
                graph[cur][i] = false;
                check(i);
            }
        }
		//결과에 최종적으로 순서 결정
        arrResult[resultIdx++] = cur;
    }
    if (arrResult[N])
        return true;
    else
        return false;
}

void initQueue(queue *qu)
{
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
        qu->mem[i] = 0;
    qu->front = -1;
    qu->back = -1;
    return;
}
bool empty(queue *qu)
{
    if (qu->front == qu->back) { return true; }
    else { return false; }
}
void pop(queue *qu)
{
    if (!empty(qu))
        qu->mem[++qu->front] = 0;
    return;
}
void push(queue *qu, int data)
{
    qu->mem[++qu->back] = data;
    return;
}
size_t size(queue *qu) { return (size_t)(qu->back - qu->front); }
int front(queue *qu) { return qu->mem[qu->front + 1]; }
int back(queue *qu) { return qu->mem[qu->back]; }

