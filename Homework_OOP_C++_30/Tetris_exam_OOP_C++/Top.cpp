
#pragma once
#include "Top.h"

void dataScoreName::show()
{
	if (score > 0) {
		cout << setw(6) << name << "\t" << score << endl;
	}
}

Top::Top() { loadTop("Top.txt"); }

Top::~Top() {}

//����������� ��������� ������ � ����
int Top::getMinTop() {
	return playersTop[TOPSIZE-1].score;
}

//�������� ��������� ������ � ��� �������
void Top::addTop(string name, int const score) {
	playersTop[TOPSIZE].name = name;
	playersTop[TOPSIZE].score = score;
	sortTop();
}

//����������� ������ ����������� ��� �������
void Top::sortTop()
{
	for (int i = 0; i < TOPSIZE + 1; i++)
	{
		for (int j = TOPSIZE; j > 0; j--)
		{
			if (playersTop[j].score > playersTop[j - 1].score)
			{
				swap(playersTop[j], playersTop[j - 1]);
			}
		}
	}
}

//�������� ������ ����������� ��� ������� �� �����
void Top::showTop(int x, int y)
{
	SetPos(x, y);
	cout << "��� 5 ������ �������: \n";
	SetPos(x, ++y+1);
	cout << "���:\t\t���� ����:" << endl;
	for (int i = 0; i < TOPSIZE; i++) {
		SetPos(x, ++y+1);
		playersTop[i].show();
	}
};

//���������� ���������� ��� ������� �� �����
void Top::loadTop(string fName)
{
	ifstream ifile(fName);
	if (!ifile.is_open())
	{
		//cout << "Error open file!" << endl;
		return;
	}
	for (int i = 0; i < TOPSIZE; i++)
	{
		ifile >> playersTop[i].name >> playersTop[i].score;
	}
}

//��������� ���������� ��� ������� � ����
void Top::saveTop(string fName)
{
	ofstream ofile(fName);
	if (!ofile.is_open())
	{
		//cout << "Error open file!" << endl;
		return;
	}
	for (int i = 0; i < TOPSIZE; i++)
	{
		ofile << playersTop[i].name << "\t" << playersTop[i].score << endl;
	}
}


