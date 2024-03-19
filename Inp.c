#include <stdio.h>
#include <stdlib.h>

int Inp() {
	int inp;
	while (1) {
		printf("선공1, 후공2\n");
		printf("입력 : ");
		scanf("%d", &inp);
		if (inp == 1 || inp == 2) {
			//1과 2가 아닌 다른값이 들어오면 메세지 출력후 무한 반복
			system("cls");
			return inp;
		}  
		printf("1과 2중에 입력해주세요. \n");
		system("pause");
		system("cls");
	}
}