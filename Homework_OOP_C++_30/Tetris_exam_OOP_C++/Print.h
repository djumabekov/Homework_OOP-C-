#pragma once
#include "Win10.h"
using namespace std;

/* ����� Print ��������� ������ ��� ������ � ������� �� �����.

*/
class Print {
public:
	Print();
	~Print();
	//������
	void print(int canvas[SIZEX][SIZEY], int block[SIZE_BLOCK][SIZE_BLOCK], int px, int py, int score);

	//���������� ��������� ������ ���� � ���� c�����
	void nextBlock(const int init_block[BLOCK_COUNT][4][4], int nextBlock);
};