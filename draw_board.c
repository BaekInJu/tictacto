#include <stdio.h>
#include <stdlib.h>

void draw_board(int(*ip)[3]) {
	printf("忙式式式式成式式式式成式式式式忖 \n");
	printf("弛  %d 弛  %d 弛  %d 弛  \n", ip[0][0], ip[0][1], ip[0][2]);
	printf("弛式式式式托式式式式托式式式式弛 \n");
	printf("弛  %d 弛  %d 弛  %d 弛  \n", ip[1][0], ip[1][1], ip[1][2]);
	printf("弛式式式式托式式式式托式式式式弛 \n");
	printf("弛  %d 弛  %d 弛  %d 弛  \n", ip[2][0], ip[2][1], ip[2][2]);
	printf("戌式式式式扛式式式式扛式式式式戎  \n");
}