#pragma once
#include "Controller.h"
#include "Win10.h"


class Canvas : Controller {
public:

	Canvas();
	~Canvas();
	//������� ������
	void clear(int canvas[SIZEX][SIZEY]);

	//������� ��������� �����
	void createRandom(int canvas[SIZEX][SIZEY]);

	//����� ���������� �������� ���� � ���������� ����
	void saveGame(int canvas[SIZEX][SIZEY], int& score);

	//����� �������� �������� ���� � ���������� ����
	void loadGame(int canvas[SIZEX][SIZEY], int& score);
};