#include "myhead.h"

int main(void) {
	int board[ROW][COL] = { 0 };
	//draw_board(board);  //void draw_board(int(*)[3]);

	int userInp = Inp();  //int Inp();    *�߰�
	//����, �İ��� ����� �Է��� ���� 1�� 2�� ��ȯ�Ѵ�.
	while (1) {
		gameStarter(userInp, board);  //void gameStarter(int(*), int(*)[3]);   *�߰�
		//��ȯ���� ����, �İ��� ���� gameStarter�Լ����� human�Լ��� computer�Լ��� ȣ���Ѵ�.
		//���ǹ��� ���� ��ǻ�Ϳ� ������ ������ �����ش�.
		//���⿡ ������ board�� ������ ������ ���� �Ѱ� �ְ� gameStater���� �ٽ� ������ ������ �Ѱ��ش�.     
		draw_board(board);  
		system("pause");
		system("cls");
	}
	return 0;
}

//���׷��̵�
//1. ���� �İ� ����  Inp()
//2. ��ǻ�Ͱ� ������ ����� �������� ���� computer()