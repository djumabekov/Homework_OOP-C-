#pragma once
#include "Print.h"
using namespace std;

/* Класс Print реализуют методы для работы с печатью на экран.
	
*/

Print::Print() {};

Print::~Print() {};

void Print::print(int canvas[SIZEX][SIZEY],int block[SIZE_BLOCK][SIZE_BLOCK], int px, int py, int score) //печать
	{
		int buff[SIZEX][SIZEY];

		for (int i = 0; i < SIZEY; i++) {
			for (int j = 0; j < SIZEX; j++) {
				buff[j][i] = canvas[j][i];
			}
		} 

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block[j][i]) { buff[j + px][i + py] = 1; }//если часть блока, то в буфере обозначить 1
			}
		}

		//вывод из буфера на экран
		SetPos(0, 0); //перейти в точку с координатами 0, 0
		for (int i = 0; i < SIZEY; i++)
		{
			for (int j = 0; j < SIZEX; j++)
			{
				putch(buff[j][i] == 0 ? CANVAS_SP : BLOCK_SP); //если элемент в буфере не часть блока, то закрасить полем
			}
			putch('\n');
		}

		SetPos(SIZEX + 1, 0); //уйти вбок
		cout << "Колличество очков: " << score;//вывести количество очков, набираемое в ходе игры
	}

void Print::nextBlock(const int init_block[BLOCK_COUNT][4][4], int nextBlock) //напечатать следующую идущий блок в поле cправа
	{
		SetPos(SIZEX + 1, 2); //перейти в точку с координатами 
		cout << "Следующая: ";

		for (int i = 0; i < 4; i++)
		{
			SetPos(SIZEX + 2, i + 3);//перейти в точку с координатами
			for (int j = 0; j < 4; j++)
			{
				putch(init_block[nextBlock][j][i] == 0 ? ' ' : BLOCK_SP); //если не часть блока, то закрасить пробелами, иначе закрасить блок
			}
		}
	}
