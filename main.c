#include "myhead.h"

int main(void) {
	int board[ROW][COL] = { 0 };
	//draw_board(board);  //void draw_board(int(*)[3]);

	int userInp = Inp();  //int Inp();    *추가
	//선공, 후공을 사용자 입력을 통해 1과 2로 반환한다.
	while (1) {
		gameStarter(userInp, board);  //void gameStarter(int(*), int(*)[3]);   *추가
		//반환받은 선공, 후공을 통해 gameStarter함수에서 human함수와 computer함수를 호출한다.
		//조건문을 통해 컴퓨터와 유저의 순서를 정해준다.
		//여기에 선언한 board의 포인터 변수도 같이 넘겨 주고 gameStater에서 다시 포인터 변수로 넘겨준다.     
		draw_board(board);  
		system("pause");
		system("cls");
	}
	return 0;
}

//업그레이드
//1. 선공 후공 선택  Inp()
//2. 컴퓨터가 무조건 가운데에 착수하지 않음 computer()