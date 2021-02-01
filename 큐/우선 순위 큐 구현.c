// �켱���� ť�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];
	int count;
} priorityQueue;

// �켱���� ť�� ����
void push(priorityQueue *pq, int data) {
	if (pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data;   // �׻� ���� ���� Ʈ���� ������ ���ҷ� data�� ��
	int now = pq->count;          // ������ data�� �ε����� now�����
	int parent = (pq->count - 1) / 2;
	// �� ���Ҹ� ������ ���Ŀ� ��������� ���� ����
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {  // �ڽ��� �θ𺸴� �� ũ�ٸ�
		swap(&pq->heap[now], &pq->heap[parent]);           // ��ġ�� ���� �ٲ���
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

// �켱���� ť�� ����
int pop(priorityQueue *pq) {
	if (pq->count <= 0) return -9999;
	int res = pq->heap[0];  // ��Ʈ ����� ���� ��Ҵٰ� ����
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];  // ���� ������ ���Ҹ� ��Ʈ ��忡 �־���
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	// �� ���Ҹ� ������ ���Ŀ� ��������� ���� ����
	while (leftChild < pq->count) {   // ���Ұ� ������ �������� �ݺ�
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
		if (target == now) break;     // �� �̻� �������� �ʾƵ� �� �� ����
		else {
			swap(&pq->heap[now], &pq->heap[target]); 
			now = target;
			leftChild = now * 2 + 1;     // now�� �������� leftChild�� rightChild�� �ٽ� ��������
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

int main(void) {
	int n, data;
	scanf("%d", &n);
	priorityQueue pq;
	pq.count = 0;
	for (int i = 0;i < n;i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for (int i = 0;i < n;i++) {   // ū ���ں��� �켱������ ���� ��µ�
		int data = pop(&pq);
		printf("%d ", data);
	}
	return 0;
}