#pragma once
#include "Canvas.h"


Canvas::Canvas() {};

Canvas::~Canvas() {};

void Canvas::clear(int canvas[SIZEX][SIZEY]) //очистка экрана
	{
	for (int i = 0; i < SIZEY; i++) {
		for (int j = 0; j < SIZEX; j++) {
			canvas[j][i] = 0;
		}
	}
}

void Canvas::createRandom(int canvas[SIZEX][SIZEY]) //создать случайную игру
{
	clear(canvas);
	int rn = random(10);
	for (int i = SIZEY - 1; i >= (SIZEY - 1) - rn; i--) {
		for (int j = 0; j < SIZEX; j++)
		{
			canvas[j][i] = random(1);
		}
	}
}


void Canvas::saveGame(int canvas[SIZEX][SIZEY], int & score)
{
	ofstream ofile("Save.txt");
	if (!ofile.is_open())
	{
		//cout << "Error open file!" << endl;
		return;
	}
	for (int i = 0; i < SIZEY; i++) {
		for (int j = 0; j < SIZEX; j++) {
			ofile << canvas[j][i] << " ";
		}
	}
	ofile << score;
	ofile.close();
}

void Canvas::loadGame(int canvas[SIZEX][SIZEY], int & score)
{
	ifstream ifile("Save.txt");
	if (!ifile.is_open())
	{
		//cout << "Error open file!" << endl;
		return;
	}

	for (int i = 0; i < SIZEY; i++) {
		for (int j = 0; j < SIZEX; j++) {
			ifile >> canvas[j][i];
			//cout << canvas[j][i];
		}
	}
	ifile >> score;
}