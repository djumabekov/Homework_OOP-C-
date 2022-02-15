#pragma once

#include "Controller.h" 
#include "Canvas.h"
#include "Top.h"
#include "Print.h"

using namespace std;
class Tetris {
private:
	// поля класса закрытые для других классов
	int canvas[SIZEX][SIZEY];    //размер экрана
	int block[SIZE_BLOCK][SIZE_BLOCK]; //блок
	int px, py; //Координаты экрана.
	int score, nextBlock; //Количесство очков и следующий блок

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
		"                      |  1. НОВАЯ ИГРА                |                ",
		"                      +===============================+                ",
		"                      |  2. СЛУЧАЙНАЯ ИГРА            |                ",
		"                      +===============================+                ",
		"                      |  3. СОХРАНЕННАЯ ИГРА          |                ",
		"                      +===============================+                ",
		"                      |  4. ИНФОРМАЦИЯ                |                ",
		"                      +===============================+                ",
		"                      |  5. ВЫХОД                     |                ",
		"                      +===============================+                ",
	}; 
	Controller controller;// создем экземпляр Управления
	Canvas board; // создем экземпляр Поле
	Print print;// создем экземпляр Печать
	Top top; // создем экземпляр Топ 5 игроков
public:
	Tetris();
	~Tetris();

	//необходимость движения блока вниз. Если вернула true то двигаемся вниз.Иначе нет.
	int blockNewPos(int x, int y);

	// двигаемся вниз на один шаг.( координату)
	void moveDownStep(int px, int py);

	// Двигаемся быстро до самого конца. Пока разрешает blockNewPos()
	void moveDownFast(int canvas[SIZEX][SIZEY]);

	//поворот блока
	void rotateBlock();

	//убрат собранную линию
	void deleteLine(int canvas[SIZEX][SIZEY]);

	//создание блока
	void createBlock();

	// начать игру
	void startGame(int _score = 0);

	// Меню 
	void gameMenu();

	// Заголовок 
	void gameTitle();

	// Инфо
	void gameInfo();
};
