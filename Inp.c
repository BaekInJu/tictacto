#include <stdio.h>
#include <stdlib.h>

int Inp() {
	int inp;
	while (1) {
		printf("����1, �İ�2\n");
		printf("�Է� : ");
		scanf("%d", &inp);
		if (inp == 1 || inp == 2) {
			//1�� 2�� �ƴ� �ٸ����� ������ �޼��� ����� ���� �ݺ�
			system("cls");
			return inp;
		}  
		printf("1�� 2�߿� �Է����ּ���. \n");
		system("pause");
		system("cls");
	}
}