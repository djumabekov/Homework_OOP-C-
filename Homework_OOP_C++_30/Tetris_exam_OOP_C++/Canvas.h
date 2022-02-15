#pragma once
#include "Controller.h"
#include "Win10.h"


class Canvas : Controller {
public:

	Canvas();
	~Canvas();
	//очистка экрана
	void clear(int canvas[SIZEX][SIZEY]);

	//создать случайный экран
	void createRandom(int canvas[SIZEX][SIZEY]);

	//метод сохранения игрового поля и статистики игры
	void saveGame(int canvas[SIZEX][SIZEY], int& score);

	//метод загрузки игрового поля и статистики игры
	void loadGame(int canvas[SIZEX][SIZEY], int& score);
};