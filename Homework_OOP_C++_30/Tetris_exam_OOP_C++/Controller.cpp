#pragma once 
#include "Controller.h"
/*
Класс Controller. 
Реализует методы рандома, задержки, и паузы.
*/

Controller::Controller() {};

Controller::~Controller() {};

int Controller::random(int max) //рандом
	{
	return (int)(rand() * (max + 1) / RAND_MAX);
	}

void Controller::sleep(int milsec) //задержка
	{
		clock_t t = clock();
		while (clock() - t < milsec);
	}

int Controller::getkey()//-пауза во время игры
	{
		int c;
		if (_kbhit()) //если нажата клавиша
		{

			if ((c = _getch()) == _KEY::SPACE) {
				SetPos(0, SIZEY);
				cout << "Пауза.." << endl;
				c = _getch();
			}
			//если нажата клавиша (пауза), то нажать любую клавишу для продолжения игры
		SetPos(0, SIZEY);
		cout << "       " << endl;
		return c;
		}

		return 0;
	}