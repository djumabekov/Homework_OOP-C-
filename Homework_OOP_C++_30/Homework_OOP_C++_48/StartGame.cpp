//
// StartGame.cpp
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Win10.h"
#include "Menu.h"
#include "Game.cpp"
using namespace std;   // std::string, std::cout

// массив пунктов главного меню в виде вектора строк
vector<string> menuItems({
  "    Задача 1    ",
  "    Задача 2    ",
  "    Задача 3    ",
  "   Об авторе    ",
  "     Выход      ",
    });

// экранные коордитаны главного меню игры
int menuRow = 3;
int menuCol = 8;

void StartGame()
{
    Game game;
    CMenu menu; // Menu menu(menuRow, menuCol);
    menu.Set(menuItems);
    int choose = menu.Show(menuRow, menuCol);
    switch (choose) {
    case 0: // " Start new game "
        system("cls"); // очистить экран
        game.StartRootsEquation();
        break;
    case 1: // "Continue"
        system("cls"); // очистить экран
        game.StartCircleInSquare();
        break;
    case 2: // Settings
        system("cls"); // очистить экран
        game.StartStackAndQueue();
        break;
    case 3:
        system("cls"); // очистить экран
        game.StartAbout();
    case 4: case -1:
        system("cls"); // очистить экран
        cout << "Exit" << endl;  return;
        break;
    }
}
