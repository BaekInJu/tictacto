#include "myhead.h"


void human(int(*ip)[3]) {
	int row = 0, col = 0;
	while (1) {
		printf("�ప �Է� : ");
		scanf("%d", &row);
		printf("���� �Է� : ");
		scanf("%d", &col);
		if (ip[row][col] != 0) {
			printf("�̹� ������ �ڸ�\n");
			system("pause");
			system("cls");
			draw_board(ip);
		}
		else {
			ip[row][col] = 2;
			return;
		}
	}
	
	
}