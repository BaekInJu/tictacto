#pragma once
#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 3

void draw_board(int(*)[3]);
void computer(int(*)[3], int);
void human(int(*)[3]);
void check(int(*)[3]);
int Inp();
void gameStarter(int, int(*)[3]);

