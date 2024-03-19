#include "myhead.h"
void gameStarter(int inp, int(*bd)[3]) {
	if (inp == 1) {
		draw_board(bd);
		human(bd); //void user(int(*)[3]);
		check(bd);
		computer(bd, inp);  //void computer(int(*)[3]);
		check(bd);
		return;
	}
	else {
		computer(bd, inp);
		check(bd);
		draw_board(bd);
		human(bd); 
		check(bd);
		return;
	}	
}