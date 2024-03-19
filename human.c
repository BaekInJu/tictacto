#include "myhead.h"


void human(int(*ip)[3]) {
	int row = 0, col = 0;
	while (1) {
		printf("행값 입력 : ");
		scanf("%d", &row);
		printf("열값 입력 : ");
		scanf("%d", &col);
		if (ip[row][col] != 0) {
			printf("이미 착수된 자리\n");
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