#pragma once

#include "Tetris.h" 

struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

int main() //������ ��������� ������
{
	ConsoleSetSize(25, 73);
	CursorHide();
	Tetris tetris;      // ������ ������ Tetris ����������
	tetris.gameMenu();  // ����� ������ ��� ����
	SetPos(5, 5);
	cout << "�� ��������!" << endl;
}
