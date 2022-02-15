#pragma once

#include "Controller.h" 
#include "Canvas.h"
#include "Top.h"
#include "Print.h"

using namespace std;
class Tetris {
private:
	// ���� ������ �������� ��� ������ �������
	int canvas[SIZEX][SIZEY];    //������ ������
	int block[SIZE_BLOCK][SIZE_BLOCK]; //����
	int px, py; //���������� ������.
	int score, nextBlock; //����������� ����� � ��������� ����

	const char GAME_TITLE[19][72]
	{
		" ###########  #########  ###########  ######## ####    ####  ######### ",
		" ##   ##  ##  ##         ##   ##  ##  ##    ##  ##    ####   ##     ## ",
		" ##   ##  ##  ##         ##   ##  ##  ##    ##  ##   ## ##   ##        ",
		"      ##      #########       ##      ########  ##  ##  ##   ##        ",
		"      ##      ##              ##      ##        ## ##   ##   ##        ",
		"      ##      ##              ##      ##        ####    ##   ##     ## ",
		"    ######    #########     ######   ####      ####    ####  ######### ",
		"                                                                       ",
		"                      +===============================+                ",
		"                      |  1. ����� ����                |                ",
		"                      +===============================+                ",
		"                      |  2. ��������� ����            |                ",
		"                      +===============================+                ",
		"                      |  3. ����������� ����          |                ",
		"                      +===============================+                ",
		"                      |  4. ����������                |                ",
		"                      +===============================+                ",
		"                      |  5. �����                     |                ",
		"                      +===============================+                ",
	}; 
	Controller controller;// ������ ��������� ����������
	Canvas board; // ������ ��������� ����
	Print print;// ������ ��������� ������
	Top top; // ������ ��������� ��� 5 �������
public:
	Tetris();
	~Tetris();

	//������������� �������� ����� ����. ���� ������� true �� ��������� ����.����� ���.
	int blockNewPos(int x, int y);

	// ��������� ���� �� ���� ���.( ����������)
	void moveDownStep(int px, int py);

	// ��������� ������ �� ������ �����. ���� ��������� blockNewPos()
	void moveDownFast(int canvas[SIZEX][SIZEY]);

	//������� �����
	void rotateBlock();

	//����� ��������� �����
	void deleteLine(int canvas[SIZEX][SIZEY]);

	//�������� �����
	void createBlock();

	// ������ ����
	void startGame(int _score = 0);

	// ���� 
	void gameMenu();

	// ��������� 
	void gameTitle();

	// ����
	void gameInfo();
};
