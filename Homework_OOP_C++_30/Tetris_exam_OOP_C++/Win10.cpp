//
// Win10.cpp
//
#include <iostream>
#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include "Win10.h"
using namespace std;

// Функция для скрытия/отображения каретки,
//  установки размера курсора
void CursorHide(BOOL bVisible, DWORD dwSize) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = dwSize;
	cursorInfo.bVisible = bVisible;
	SetConsoleCursorInfo(hOUTPUT, &cursorInfo); // Hide/Show console cursor
}


// функция для смена цвета
void SetColor(WORD wAttributes) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

void SetColor(int colBkgr, int colSym) {
	SetColor(colBkgr * 16 + colSym);
}


// Функция для выбора позиции курсора на экране

void SetPos(int row, int col) //стандартная функция перехода курсором в точку с координатами xpos, ypos
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);//создание "ручки" для вывода на экран консоли текста и прочего 
	scrn.X = row; scrn.Y = col;//-присваем значения
	SetConsoleCursorPosition(hOuput, scrn);//-ставим курсор,на нужную позицию.
}


void ConsoleSetSize(int row, int col)
{
	// установка размера шрифта
	CONSOLE_FONT_INFOEX cfon{};
	cfon.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfon);
	cfon.nFont = 10;
	cfon.dwFontSize.X = 5;
	cfon.dwFontSize.Y = 20;
	cfon.FontFamily = 54;
	cfon.FontWeight = 50;
	wcscpy(cfon.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfon);

	// установка размера окна консоли
	char str[100];
	sprintf_s(str, "mode con cols=%d lines=%d", col, row);
	system(str);
	clearCanvas();
}

void clearCanvas()
{
	system("cls");
}
