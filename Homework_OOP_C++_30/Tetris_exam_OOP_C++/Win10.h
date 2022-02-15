//
// Win10.h
//
#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <locale.h>
#include <ctime>
#include <random>
#include <conio.h>
using namespace std;
#pragma warning(disable:4996)

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))

#define TOPSIZE 5//���������� ���������� ��� �������� ���������� ��� �������

#define SIZEX 16//-������ ����
#define SIZEY 20//-����� ����
#define BLOCK_COUNT 7 //���������� ������ �������

#define CANVAS_SP  '*' //������������ ����
#define BLOCK_SP  '@' //������������ �����
#define SIZE_BLOCK 4
#define inv(x) ((x * (-1)) + 3)



// �������� ������
enum COLOR {
	_BLACK,
	_BLUE,
	_GREEN,
	_AQUA,
	_RED,
	_PURPLE,
	_YELLOW,
	_WHITE,
	_GRAY,
	_LIGHT_BLUE,
	_LIGHT_GREEN,
	_LIGHT_AQUA,
	_LIGHT_RED,
	_LIGHT_PURPLE,
	_LIGHT_YELLOW,
	_BRIGHT_WHITE,
};

// ������������ ����� ������ ����������
// ������������ ������������ � ������ KEY
enum _KEY {
	ESC = 27,
	ENTER = 13,
	SPACE = 32,     // ������
	TAB = 9,
	BACKSPACE = 8,
	PLUS = 43, MINUS = 45,

	CURSOR1 = 0, CURSOR2 = 224,

	UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77,

	INS = 82, DEL = 83,
	HOME = 71, END = 79,
	PG_UP = 73, PG_DOWN = 81,

	F1 = 59, F2, F3, F4, F5, F6, F7, F8, F9, F10, // CURSOR1, 59-68
	F11 = 133, F12 = 134, // CURSOR2, 133-134
};


const int init_block[BLOCK_COUNT][4][4] = //������������� ������ �������
{
	{
		{ 1, 1, 0, 0 }, //O
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 }, //I
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 }, //L
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 }, //J
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 }, //S
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 }, //Z
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 }, //T
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};

// ��������� �-��� Win10.cpp
void CursorHide(BOOL bVisible = 0, DWORD dwSize = 20);
void SetColor(WORD wAttributes);
void SetColor(int colBkgr, int colSym);
void SetPos(int row, int col);
void ConsoleSetSize(int row = 25, int col = 80);
void clearCanvas(); //�������� ������� �������

