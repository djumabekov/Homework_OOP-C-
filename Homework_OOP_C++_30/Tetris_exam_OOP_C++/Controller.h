#pragma once 
#include "Win10.h"

/*
����� Controller.
��������� ������ �������, ��������, � �����.
*/
class Controller {
public:
	Controller();
	~Controller();

	//������������
	int random(int max);

	//��������
	void sleep(int milsec);

	//-����� �� ����� ����
	int getkey();
};