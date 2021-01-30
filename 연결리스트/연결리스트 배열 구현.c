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

//Ư���� ��ġ�� ���Ҹ� �����ϴ� �Լ�
void removeAt(int index) {
	for (int i = index;i < count - 1;i++) {
		arr[i] = arr[i + 1];
	}
	count--;
}

int main(void) {
	//�տ������� ����
	addFirst(4);
	addFirst(6);
	addFirst(8);
	//�ڷ� ����
	addBack(9);
	removeAt(3);
	addBack(7);
	addBack(5);
	//��� ���� 8 6 4 7 5
	show();
	return 0;
}