#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

//�����͸� �迭�� �޺κп� ��� �Լ�
void addBack(int data) {
	arr[count] = data;
	count++;
}

//�����͸� �迭�� �պκп� ��� �Լ�
void addFirst(int data) {
	for (int i = count;i > 0;i--) {
		arr[i] = arr[i - 1];         //�迭�� ���Ҹ� ��ĭ�� �����
	}
	arr[0] = data;
	count++;
}

void show() {
	for (int i = 0;i < count;i++) {
		printf("%d ", arr[i]);
	}
}

int main(void) {
	//�տ������� ����
	addFirst(4);
	addFirst(6);
	addFirst(8);
	//�ڷ� ����
	addBack(9);
	addBack(7);
	addBack(5);
	//��� ���� 8 6 4 9 7 5
	show();
	return 0;
}