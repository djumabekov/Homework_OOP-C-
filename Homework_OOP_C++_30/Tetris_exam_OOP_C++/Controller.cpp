#pragma once 
#include "Controller.h"
/*
����� Controller. 
��������� ������ �������, ��������, � �����.
*/

Controller::Controller() {};

Controller::~Controller() {};

int Controller::random(int max) //������
	{
	return (int)(rand() * (max + 1) / RAND_MAX);
	}

void Controller::sleep(int milsec) //��������
	{
		clock_t t = clock();
		while (clock() - t < milsec);
	}

int Controller::getkey()//-����� �� ����� ����
	{
		int c;
		if (_kbhit()) //���� ������ �������
		{

			if ((c = _getch()) == _KEY::SPACE) {
				SetPos(0, SIZEY);
				cout << "�����.." << endl;
				c = _getch();
			}
			//���� ������ ������� (�����), �� ������ ����� ������� ��� ����������� ����
		SetPos(0, SIZEY);
		cout << "       " << endl;
		return c;
		}

		return 0;
	}