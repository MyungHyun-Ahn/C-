#include <stdio.h>
#include <stdlib.h>

//���Ḯ��Ʈ ����ü ����
typedef struct {
	int data;
	struct Node *next;
}Node;

//�׻� �����κ��� �����ϹǷ� ��� ���� ����
//���� �׻� ������ ������ ���� �Ҵ��� �̿��Ͽ� ������ �����ϴ°� �Ϲ�����
Node *head;

//���Ḯ��Ʈ ���� �Լ�
void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

//���Ḯ��Ʈ ���� �Լ�
void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}

//���Ḯ��Ʈ �޸� ���� �Լ�
void freeAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL) {
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}

//���Ḯ��Ʈ ��ü ����Լ�
void showAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addFront(head, 6);
	addFront(head, 3);
	addFront(head, 5);
	addFront(head, 1);
	addFront(head, 7);
	removeFront(head);
	//��� ���� 1 5 3 6
	showAll(head);
	freeAll(head);
	return 0;
}