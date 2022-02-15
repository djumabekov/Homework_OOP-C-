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

// ������ ������� �������� ���� � ���� ������� �����
vector<string> menuItems({
  "    ������ 1    ",
  "    ������ 2    ",
  "    ������ 3    ",
  "   �� ������    ",
  "     �����      ",
    });

// �������� ���������� �������� ���� ����
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
        system("cls"); // �������� �����
        game.StartRootsEquation();
        break;
    case 1: // "Continue"
        system("cls"); // �������� �����
        game.StartCircleInSquare();
        break;
    case 2: // Settings
        system("cls"); // �������� �����
        game.StartStackAndQueue();
        break;
    case 3:
        system("cls"); // �������� �����
        game.StartAbout();
    case 4: case -1:
        system("cls"); // �������� �����
        cout << "Exit" << endl;  return;
        break;
    }
}
