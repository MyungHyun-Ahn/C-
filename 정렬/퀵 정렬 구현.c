//�迭 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a[SIZE];

//���� �Լ�
int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//�� ���� �Լ�
void quickSort(int start, int end) {                 // �κ� �迭�� ���۰� ��
	if (start >= end) return;
	int key = start, i = start + 1, j = end, temp;   // i�� ���ʿ��� ����ϴ� ��ġ, j�� �����ʿ��� ����ϴ� ��ġ,
	                                                 // key�� �׻� �ǹ����� �κй迭�� ���۰��� �ǵ��� ����.
	while (i <= j) { //������ ������ �ݺ�
		while (i <= end && a[i] <= a[key]) i++;  // a[key]���� ū ���� a[i]�� ���
		while (i > start && a[j] >= a[key]) j--; // a[key]���� ���� ���� a[j]�� ���
		if (i > j) swap(&a[key], &a[j]);         // ������ ���¶�� a[key]�� ���� ���� a[j]�� �ٲ���
		else swap(&a[i], &a[j]);                 // �׷��� �ʴٸ� a[i]�� a[j]�� �ٲ���
	}
	quickSort(start, j - 1);     //�κ� �迭�� ��������� 2�� ȣ���ϰ� ����
	quickSort(j + 1, end);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", &a[i]);
	quickSort(0, n - 1);
	for (int i = 0;i < n;i++) printf("%d ", a[i]);
	return 0;
}