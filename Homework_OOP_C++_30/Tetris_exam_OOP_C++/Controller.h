#pragma once 
#include "Win10.h"

/*
Класс Controller.
Реализует методы рандома, задержки, и паузы.
*/
class Controller {
public:
	Controller();
	~Controller();

	//рандомизация
	int random(int max);

	//задержка
	void sleep(int milsec);

	//-пауза во время игры
	int getkey();
};