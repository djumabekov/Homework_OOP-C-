#pragma once

#include "Tetris.h"
using namespace std;

Tetris::Tetris() {};

Tetris::~Tetris() {};

int Tetris::blockNewPos(int x, int y) //необходимость движения блока вниз. Если вернула true то двигаемся вниз.Иначе нет.
{
	if (x < 0) { return false; } // Двигаться некуда.
	for (int i = 0; i < 4; i++)// Перебираем варианты
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[j][i])
			{
				if ((j + x >= SIZEX) || (i + y >= SIZEY)) { return false; }//-проверка не зашел ли блок за границы нашего экрана.
				if (canvas[j + x][i + y])                 { return false; }//-если да то вернем false
				
			}
		}
	}
	return true;//-если нет возвращаем true - блок движется вниз.
}

void Tetris::moveDownStep(int px, int py)
{// двигаемся вниз на один шаг.( координату)
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if (block[j][i]) { 
					canvas[px + j][py + i] = 1; 
				}
			}
		}
}


void Tetris::moveDownFast(int canvas[SIZEX][SIZEY]){// Двигаемся быстро до самого конца. Пока разрешает blockNewPos()
		for (; blockNewPos(px, py + 1); py++);
		moveDownStep(px, py);
		
	}

void Tetris::rotateBlock() //поворот блока
{
	int _block[4][4]; // буферный( дополнительный) массив для рабботы с block  
	int sx = 4, sy = 4;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			_block[j][i] = block[j][i];//-создание копию блока,для того что бы вернуть первоначальный вид.
			if (block[j][i])//с условием ЕСЛИ блок равен нулю ,то 
			{
				if (i < sx) sx = i;//проходим по блоку запоминаем новую координату х
				if (inv(j) < sy) sy = inv(j);//новую координату у
			}
			block[j][i] = 0;//-обнуляем матрицу с блоком
		}
	}
	// переворачиваем блок
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (_block[inv(i)][j]) {
				block[j - sx][i - sy] = 1;
			}//рисуем перевертыш
		}
	}
	if (!blockNewPos(px, py)) {
		for (int i = 0; i < 4; i++) {// Если двигаться уже нельзя
			for (int j = 0; j < 4; j++) {
				block[j][i] = _block[j][i];//возвращаем обратно на изначальный блок
			}
		}
	}
}

void Tetris::deleteLine(int canvas[SIZEX][SIZEY]) //убрать собранную линию
	{
		int i, j, k, flag;
		for (i = SIZEY - 1; i >= 0; i--)
		{
			flag = 1;
			for (j = 0, flag = 1; j < SIZEX; j++)
			{
				if (!canvas[j][i]) { flag = 0; } //пробегаемся по всем строчкам и проверяем ее на заполненость.
			}
			if (flag) // Если она так и осталась равная 1 то перерисовываем нашу игру, убираем линию. И добавляем очки
			{
				SetPos(0, i);
				for (k = 0; k < SIZEX; k++) { putch('_'), controller.sleep(20); }

				score += (((i * (-1)) + SIZEY) * 10);// добавляем очки

				for (k = i; k > 0; k--)
				{
					for (j = 0; j < SIZEX; j++)
					{
						canvas[j][k] = canvas[j][k - 1];
					}
				}
				i++;
				print.print(canvas, block, px, py, score);
			}
		}
	}
void Tetris::createBlock() //создание блока
	{
		
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			block[j][i] = init_block[nextBlock][j][i];
		}
	}
		py = 0;
		px = SIZEX / 2;

		nextBlock = controller.random(BLOCK_COUNT - 1);
		print.nextBlock(init_block, nextBlock);
	}

void Tetris::startGame(int _score){
		int c;
		time_t tm;

		clearCanvas(); // функция для очистки 

		px = SIZEX / 2;//значение для падения блока по х,выход из центра
		py = 0;
		score = _score;
		tm = clock();// получаем время. Нужно для падание блока

		nextBlock = controller.random(BLOCK_COUNT - 1);//следующий блок выбирается из 6 
		createBlock();//создание блока
		
		while (true)
		{
			c = controller.getkey(); // вызывается метод класса Controller getKey()

			switch (c)
			{
			case _KEY::UP:
				rotateBlock();//поворот
				break;
			case _KEY::DOWN://движение вниз
				moveDownFast(canvas); //двиаемся вниз, при нажатии клавиши вниз
				print.print(canvas, block, px, py, score);
				deleteLine(canvas);//проход по функции проверки заполнилась ли линия и её удаление
				createBlock();//новый блок
				break;
			case _KEY::LEFT:
				if (blockNewPos(px - 1, py)) px--;//движение влево ,уменьшаем значение по х
				break;
			case _KEY::RIGHT:
				if (blockNewPos(px + 1, py)) px++;//движение вправо ,увеличиваем значение по х
				break;
			case _KEY::SPACE://пауза
				break;
			case 's'://сохранение игры
				board.saveGame(canvas, score);
				break;
			case 'l'://загрузка сохраненной игры
				board.clear(canvas); // Очистка экрана
				board.loadGame(canvas, score); // Загрузка игры
				//board.createRandom(canvas); // Создание рандомного заполнения экрана
				startGame(score); // Начало игры
				SetPos(0, SIZEY);
				cout << "Нажмите ESC для выхода в главное меню..." << endl; while (_getch() != _KEY::ESC);
				break;
			case _KEY::ESC://выход
				return;
			}


			if ((clock() - tm) > 720)//-время падения блока 
			{
				tm = clock();

				if (!(blockNewPos(px, py + 1)))
				{
					moveDownStep(px, py); // Если есть куда падать, то двигается вниз. 
					createBlock();
					deleteLine(canvas);//  И делается проверка на заполненость строчки.
				}
				else { py++; }//падение вниз
			}
			top.showTop(18, 8);
			print.print(canvas, block, px, py, score); //печать экрана

			for (int i = 0; i < SIZEX; i++)
			{
				if (canvas[i][0])//если экраный у и у блока совпали и равны 0,то конец игры ,поле заполнилось до верха
				{
					clearCanvas();
					SetPos(2, 8);
					cout << "КОНЕЦ ИГРЫ!" << endl;
					if (score > top.getMinTop()) {
						SetPos(2, 10);
						cout << "Поздравляем! Ваш результат вошел в ТОП-5 лучших!" << endl;
						string playerName;
						SetPos(2, 12);
						cout << "Введите свое имя и нажмите Enter:  ";
						getline(cin, playerName);
						top.addTop(playerName, score);
						top.saveTop("Top.txt");
					}
					return;
				}
			}
		}
	}


void Tetris::gameMenu() //игровое меню
	{
		int p = 1, c = 0;
		clearCanvas();
		gameTitle();
			while (true) { //Навигация по меню
			c = _getch();

			switch (c){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
				p = c - '0'; //Реализация меню. ВЫбор зависит от нажатой клавиши. Смотрим какую клавишу нажали
			case _KEY::ENTER:
				switch (p)
				{
				case 1: // клавишу = 1
					board.clear(canvas);  
					startGame();

					SetPos(0, SIZEY); 
					cout << "Нажмите ESC для выхода в главное меню..." << endl; while (_getch() != _KEY::ESC);
					break;
				case 2:
					board.clear(canvas); // Очистка экрана
					board.createRandom(canvas); // Создание рандомного заполнения экрана
					startGame(); // Начало игры
					SetPos(0, SIZEY);
					cout << "Нажмите ESC для выхода в главное меню..." << endl; while (_getch() != _KEY::ESC);
					break;
				case 3:
					board.clear(canvas); // Очистка экрана
					board.loadGame(canvas, score); // Загрузка игры
					startGame(score); // Начало игры
					SetPos(0, SIZEY);						
					cout << "Нажмите ESC для выхода в главное меню..." << endl; while (_getch() != _KEY::ESC);
					break;
				case 4:
					clearCanvas();
					gameInfo();// Инфо игры
					break;
				case 5: clearCanvas();	return;
				}
				clearCanvas();
				gameTitle();
				p = 1;
				break;
			case _KEY::UP: // При нажатии вверх
				if (p > 1) p--; // уменьшаем значение
				break;
			case _KEY::DOWN: // При нажатие вниз
				if (p < 5) p++;
				break;
			case _KEY::ESC:
				clearCanvas();
				return;
			}

		}
	}

 
void Tetris::gameTitle() { // Заголовок и Меню 
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 72; j++) {

			cout << GAME_TITLE[i][j];
		}
		cout << endl;
	}
}

void Tetris::gameInfo() { // Инфо

		cout << "Цель игры \"Тетрис\":\nзаполнить как можно больше горизонтальных\n";
		cout << "линий на игровом поле, размещая опускающиеся блоки и\n";
		cout << "не оставляя пустых пространств между ними.\n";
		cout << "Заполненные линии автоматически удаляются, предоставляя\n";
		cout << "пространство для продолжения игры.\n\n";

		cout << "Клавиши управления игрой:\n";
		cout << "+========+============+\n";
		cout << "|   <    | Влево      |\n";
		cout << "|   >    | Вправо     |\n";
		cout << "|   v    | Вниз       |\n";
		cout << "|   ^    | Поворот    |\n";
		cout << "|  space | Пауза      |\n";
		cout << "|   s    | Сохранение |\n";
		cout << "|   l    | Загрузка   |\n";
		cout << "|   ESC  | Выход      |\n";
		cout << "+========+============+\n\n";
		cout << "Автор: Джумабеков Дархан\nГруппа: SEP-211-1\n\n\n";
		cout << "Нажми любую клавишу для возврата в меню...\n";
		_getch();
		if (_kbhit()) _getch(); // Ждет нажатие клавиши
	}
