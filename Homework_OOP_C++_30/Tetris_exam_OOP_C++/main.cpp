#pragma once

#include "Tetris.h" 

struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

int main() //Начало программы Тетрис
{
	ConsoleSetSize(25, 73);
	CursorHide();
	Tetris tetris;      // Обьект класса Tetris обьявление
	tetris.gameMenu();  // Вызов метода для меню
	SetPos(5, 5);
	cout << "До свидания!" << endl;
}
