#pragma once

#include "Tetris.h"
using namespace std;

Tetris::Tetris() {};

Tetris::~Tetris() {};

int Tetris::blockNewPos(int x, int y) //������������� �������� ����� ����. ���� ������� true �� ��������� ����.����� ���.
{
	if (x < 0) { return false; } // ��������� ������.
	for (int i = 0; i < 4; i++)// ���������� ��������
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[j][i])
			{
				if ((j + x >= SIZEX) || (i + y >= SIZEY)) { return false; }//-�������� �� ����� �� ���� �� ������� ������ ������.
				if (canvas[j + x][i + y])                 { return false; }//-���� �� �� ������ false
				
			}
		}
	}
	return true;//-���� ��� ���������� true - ���� �������� ����.
}

void Tetris::moveDownStep(int px, int py)
{// ��������� ���� �� ���� ���.( ����������)
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if (block[j][i]) { 
					canvas[px + j][py + i] = 1; 
				}
			}
		}
}


void Tetris::moveDownFast(int canvas[SIZEX][SIZEY]){// ��������� ������ �� ������ �����. ���� ��������� blockNewPos()
		for (; blockNewPos(px, py + 1); py++);
		moveDownStep(px, py);
		
	}

void Tetris::rotateBlock() //������� �����
{
	int _block[4][4]; // ��������( ��������������) ������ ��� ������� � block  
	int sx = 4, sy = 4;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			_block[j][i] = block[j][i];//-�������� ����� �����,��� ���� ��� �� ������� �������������� ���.
			if (block[j][i])//� �������� ���� ���� ����� ���� ,�� 
			{
				if (i < sx) sx = i;//�������� �� ����� ���������� ����� ���������� �
				if (inv(j) < sy) sy = inv(j);//����� ���������� �
			}
			block[j][i] = 0;//-�������� ������� � ������
		}
	}
	// �������������� ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (_block[inv(i)][j]) {
				block[j - sx][i - sy] = 1;
			}//������ ����������
		}
	}
	if (!blockNewPos(px, py)) {
		for (int i = 0; i < 4; i++) {// ���� ��������� ��� ������
			for (int j = 0; j < 4; j++) {
				block[j][i] = _block[j][i];//���������� ������� �� ����������� ����
			}
		}
	}
}

void Tetris::deleteLine(int canvas[SIZEX][SIZEY]) //������ ��������� �����
	{
		int i, j, k, flag;
		for (i = SIZEY - 1; i >= 0; i--)
		{
			flag = 1;
			for (j = 0, flag = 1; j < SIZEX; j++)
			{
				if (!canvas[j][i]) { flag = 0; } //����������� �� ���� �������� � ��������� �� �� ������������.
			}
			if (flag) // ���� ��� ��� � �������� ������ 1 �� �������������� ���� ����, ������� �����. � ��������� ����
			{
				SetPos(0, i);
				for (k = 0; k < SIZEX; k++) { putch('_'), controller.sleep(20); }

				score += (((i * (-1)) + SIZEY) * 10);// ��������� ����

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
void Tetris::createBlock() //�������� �����
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

		clearCanvas(); // ������� ��� ������� 

		px = SIZEX / 2;//�������� ��� ������� ����� �� �,����� �� ������
		py = 0;
		score = _score;
		tm = clock();// �������� �����. ����� ��� ������� �����

		nextBlock = controller.random(BLOCK_COUNT - 1);//��������� ���� ���������� �� 6 
		createBlock();//�������� �����
		
		while (true)
		{
			c = controller.getkey(); // ���������� ����� ������ Controller getKey()

			switch (c)
			{
			case _KEY::UP:
				rotateBlock();//�������
				break;
			case _KEY::DOWN://�������� ����
				moveDownFast(canvas); //�������� ����, ��� ������� ������� ����
				print.print(canvas, block, px, py, score);
				deleteLine(canvas);//������ �� ������� �������� ����������� �� ����� � � ��������
				createBlock();//����� ����
				break;
			case _KEY::LEFT:
				if (blockNewPos(px - 1, py)) px--;//�������� ����� ,��������� �������� �� �
				break;
			case _KEY::RIGHT:
				if (blockNewPos(px + 1, py)) px++;//�������� ������ ,����������� �������� �� �
				break;
			case _KEY::SPACE://�����
				break;
			case 's'://���������� ����
				board.saveGame(canvas, score);
				break;
			case 'l'://�������� ����������� ����
				board.clear(canvas); // ������� ������
				board.loadGame(canvas, score); // �������� ����
				//board.createRandom(canvas); // �������� ���������� ���������� ������
				startGame(score); // ������ ����
				SetPos(0, SIZEY);
				cout << "������� ESC ��� ������ � ������� ����..." << endl; while (_getch() != _KEY::ESC);
				break;
			case _KEY::ESC://�����
				return;
			}


			if ((clock() - tm) > 720)//-����� ������� ����� 
			{
				tm = clock();

				if (!(blockNewPos(px, py + 1)))
				{
					moveDownStep(px, py); // ���� ���� ���� ������, �� ��������� ����. 
					createBlock();
					deleteLine(canvas);//  � �������� �������� �� ������������ �������.
				}
				else { py++; }//������� ����
			}
			top.showTop(18, 8);
			print.print(canvas, block, px, py, score); //������ ������

			for (int i = 0; i < SIZEX; i++)
			{
				if (canvas[i][0])//���� ������� � � � ����� ������� � ����� 0,�� ����� ���� ,���� ����������� �� �����
				{
					clearCanvas();
					SetPos(2, 8);
					cout << "����� ����!" << endl;
					if (score > top.getMinTop()) {
						SetPos(2, 10);
						cout << "�����������! ��� ��������� ����� � ���-5 ������!" << endl;
						string playerName;
						SetPos(2, 12);
						cout << "������� ���� ��� � ������� Enter:  ";
						getline(cin, playerName);
						top.addTop(playerName, score);
						top.saveTop("Top.txt");
					}
					return;
				}
			}
		}
	}


void Tetris::gameMenu() //������� ����
	{
		int p = 1, c = 0;
		clearCanvas();
		gameTitle();
			while (true) { //��������� �� ����
			c = _getch();

			switch (c){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
				p = c - '0'; //���������� ����. ����� ������� �� ������� �������. ������� ����� ������� ������
			case _KEY::ENTER:
				switch (p)
				{
				case 1: // ������� = 1
					board.clear(canvas);  
					startGame();

					SetPos(0, SIZEY); 
					cout << "������� ESC ��� ������ � ������� ����..." << endl; while (_getch() != _KEY::ESC);
					break;
				case 2:
					board.clear(canvas); // ������� ������
					board.createRandom(canvas); // �������� ���������� ���������� ������
					startGame(); // ������ ����
					SetPos(0, SIZEY);
					cout << "������� ESC ��� ������ � ������� ����..." << endl; while (_getch() != _KEY::ESC);
					break;
				case 3:
					board.clear(canvas); // ������� ������
					board.loadGame(canvas, score); // �������� ����
					startGame(score); // ������ ����
					SetPos(0, SIZEY);						
					cout << "������� ESC ��� ������ � ������� ����..." << endl; while (_getch() != _KEY::ESC);
					break;
				case 4:
					clearCanvas();
					gameInfo();// ���� ����
					break;
				case 5: clearCanvas();	return;
				}
				clearCanvas();
				gameTitle();
				p = 1;
				break;
			case _KEY::UP: // ��� ������� �����
				if (p > 1) p--; // ��������� ��������
				break;
			case _KEY::DOWN: // ��� ������� ����
				if (p < 5) p++;
				break;
			case _KEY::ESC:
				clearCanvas();
				return;
			}

		}
	}

 
void Tetris::gameTitle() { // ��������� � ���� 
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 72; j++) {

			cout << GAME_TITLE[i][j];
		}
		cout << endl;
	}
}

void Tetris::gameInfo() { // ����

		cout << "���� ���� \"������\":\n��������� ��� ����� ������ ��������������\n";
		cout << "����� �� ������� ����, �������� ������������ ����� �\n";
		cout << "�� �������� ������ ����������� ����� ����.\n";
		cout << "����������� ����� ������������� ���������, ������������\n";
		cout << "������������ ��� ����������� ����.\n\n";

		cout << "������� ���������� �����:\n";
		cout << "+========+============+\n";
		cout << "|   <    | �����      |\n";
		cout << "|   >    | ������     |\n";
		cout << "|   v    | ����       |\n";
		cout << "|   ^    | �������    |\n";
		cout << "|  space | �����      |\n";
		cout << "|   s    | ���������� |\n";
		cout << "|   l    | ��������   |\n";
		cout << "|   ESC  | �����      |\n";
		cout << "+========+============+\n\n";
		cout << "�����: ���������� ������\n������: SEP-211-1\n\n\n";
		cout << "����� ����� ������� ��� �������� � ����...\n";
		_getch();
		if (_kbhit()) _getch(); // ���� ������� �������
	}
