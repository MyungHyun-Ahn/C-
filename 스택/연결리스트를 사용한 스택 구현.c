//������ ����
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;  // ������ �ֻ�� ���
} Stack;

//���� ���� �Լ�
void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

//���� ���� �Լ�
void pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node *node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

//���� ��ü ��� �Լ�
void show(Stack *stack) {
	Node *cur = stack->top;
	printf("--- ������ �ֻ�� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ������ ���ϴ� ---\n");
}

int main(void) {
	Stack s;
	s.top = NULL;
	push(&s, 7);
	push(&s, 4);
	push(&s, 2);
	pop(&s);
	push(&s, 3);
	pop(&s);
	show(&s);   //���� ��°� 4 7
	return 0;
}

