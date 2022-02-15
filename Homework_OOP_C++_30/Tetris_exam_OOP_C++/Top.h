#pragma once
#include <iomanip>
#include <fstream> 
#include<string>
#include <iostream>
#include "Win10.h"
using namespace std;

//структура для хранения имени и счета игрока
struct dataScoreName {
	string name;
	int score;
	void show();
};

class Top
{
private:
	dataScoreName playersTop[TOPSIZE + 1]{}; //массив для хранения результатов ТОП игроков
public:
	Top();
	~Top();

	//минимальный результат игрока в ТОПе
	int getMinTop();

	//добавить результат игрока в ТОП игроков
	void addTop(string name, int const score);

	//сортировать массив результатов ТОП игроков
	void sortTop();

	//выводить массив результатов ТОП игроков на экран
	void showTop(int x, int y);

	//подгружать результаты ТОП игроков из файла
	void loadTop(string fName);

	//загружать результаты ТОП игроков в файл
	void saveTop(string fName);

};

