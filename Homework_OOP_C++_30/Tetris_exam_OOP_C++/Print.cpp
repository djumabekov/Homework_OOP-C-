#pragma once
#include "Print.h"
using namespace std;

/* ����� Print ��������� ������ ��� ������ � ������� �� �����.
	
*/

Print::Print() {};

Print::~Print() {};

void Print::print(int canvas[SIZEX][SIZEY],int block[SIZE_BLOCK][SIZE_BLOCK], int px, int py, int score) //������
	{
		int buff[SIZEX][SIZEY];

		for (int i = 0; i < SIZEY; i++) {
			for (int j = 0; j < SIZEX; j++) {
				buff[j][i] = canvas[j][i];
			}
		} 

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block[j][i]) { buff[j + px][i + py] = 1; }//���� ����� �����, �� � ������ ���������� 1
			}
		}

		//����� �� ������ �� �����
		SetPos(0, 0); //������� � ����� � ������������ 0, 0
		for (int i = 0; i < SIZEY; i++)
		{
			for (int j = 0; j < SIZEX; j++)
			{
				putch(buff[j][i] == 0 ? CANVAS_SP : BLOCK_SP); //���� ������� � ������ �� ����� �����, �� ��������� �����
			}
			putch('\n');
		}

		SetPos(SIZEX + 1, 0); //���� ����
		cout << "����������� �����: " << score;//������� ���������� �����, ���������� � ���� ����
	}

void Print::nextBlock(const int init_block[BLOCK_COUNT][4][4], int nextBlock) //���������� ��������� ������ ���� � ���� c�����
	{
		SetPos(SIZEX + 1, 2); //������� � ����� � ������������ 
		cout << "���������: ";

		for (int i = 0; i < 4; i++)
		{
			SetPos(SIZEX + 2, i + 3);//������� � ����� � ������������
			for (int j = 0; j < 4; j++)
			{
				putch(init_block[nextBlock][j][i] == 0 ? ' ' : BLOCK_SP); //���� �� ����� �����, �� ��������� ���������, ����� ��������� ����
			}
		}
	}
