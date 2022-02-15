#pragma once
#include <iomanip>
#include <fstream> 
#include<string>
#include <iostream>
#include "Win10.h"
using namespace std;

//��������� ��� �������� ����� � ����� ������
struct dataScoreName {
	string name;
	int score;
	void show();
};

class Top
{
private:
	dataScoreName playersTop[TOPSIZE + 1]{}; //������ ��� �������� ����������� ��� �������
public:
	Top();
	~Top();

	//����������� ��������� ������ � ����
	int getMinTop();

	//�������� ��������� ������ � ��� �������
	void addTop(string name, int const score);

	//����������� ������ ����������� ��� �������
	void sortTop();

	//�������� ������ ����������� ��� ������� �� �����
	void showTop(int x, int y);

	//���������� ���������� ��� ������� �� �����
	void loadTop(string fName);

	//��������� ���������� ��� ������� � ����
	void saveTop(string fName);

};

