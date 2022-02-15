#pragma once
#include "Win10.h"
using namespace std;

/* Класс Print реализуют методы для работы с печатью на экран.

*/
class Print {
public:
	Print();
	~Print();
	//печать
	void print(int canvas[SIZEX][SIZEY], int block[SIZE_BLOCK][SIZE_BLOCK], int px, int py, int score);

	//напечатать следующую идущий блок в поле cправа
	void nextBlock(const int init_block[BLOCK_COUNT][4][4], int nextBlock);
};