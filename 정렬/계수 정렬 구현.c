//��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10001   // ���� ū ��  10000���� �� ū ���� ������ �ȵ�
                          // �ٸ� ���ĺ��� �� ���� �޸𸮸� �䱸������ ������ ������ �� �ִ�.     
int n, m;               
int a[MAX_VALUE];

int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &m);
		a[m]++;      // ���� �Էµ� ������ �ش� ���� �迭�� 1�� ������
	}
	for (int i = 0;i < MAX_VALUE;i++) {
		while (a[i] != 0) {       // Ư�� ���Ұ� 0�� �ƴ϶�� �� ������ ũ�⸸ŭ �ش� �迭�� �����
			printf("%d ", i);
			a[i]--;
		}
	}
	return 0;
}