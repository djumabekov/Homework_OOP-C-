//
// Game.cpp
//

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Win10.h"
#include "Tasks.cpp"
using namespace std;   // std::string, std::cout

class Game {
public:
    RootsEquation* CreatRootsEquation() {
        cout << "1 - Liner" << endl;
        cout << "2 - SquareEqu" << endl;
        cout << "3 - Back to menu" << endl;
        int choose;
        (cin >> choose).ignore();
        switch (choose)
        {
        case 1: return new Liner;
        case 2: return new SquareEqu;
        case 3:
            system("cls");
            StartGame(); break;
        default:
            cout << "�� ������ �����!" << endl;
            break;
        }
        return nullptr;
    }

    void StartRootsEquation()
    {
        RootsEquation* RE = nullptr;
        while (true)
        {
            RE = CreatRootsEquation();
            if (!RE) { break; }
            RE->Input();
            RE->Calc();
            RE->Show();
            delete RE;
        }
    } // StartRootsEquation()

    void  StartCircleInSquare()
    {
        float side;// = 20;
        float radius;// = side / 2;
        cout << "Enter side: ";
        (cin >> side).ignore();
        cout << "Enter radius: ";
        (cin >> radius).ignore();
        Square mySquare = Square(side);

        CircleInSquare circleInSquare = CircleInSquare(side, radius);
        cout << "circleInSquare: " << endl;
        cout << "Radius: " << circleInSquare.getRadius() << endl;
        cout << "Side: " << circleInSquare.getSide() << endl;

        cout << "Enter ESC for back to menu " << endl;
        int key = _getch();
        if (key == KEY::ESC) {
            system("cls");
            StartGame();
        }
    }

    void StartStackAndQueue()
    {
        // ����:
        cout << "����: " << endl;
        Stack<int> stack;
        for (int i = 0; i < 10; i++)
        {
            stack.Add(i);
            cout << "������� [" << i << "] = " << i << endl;
        }
        cout << "\n��������� ��������� ������� �� �����  = " << stack.Get() << endl;
        stack.DeleteTail();

        // �������:
        cout << "\n�������: " << endl;
        Queue<int> queue;
        for (int i = 0; i < 10; i++)
        {
            queue.Add(i + 10);
            cout << "������� [" << i << "] = " << i + 10 << endl;
        }
        cout << "\n��������� ������ ������� c �������  = " << queue.Get() << endl;
        queue.DeleteHead();
        cout << "Enter ESC for back to menu " << endl;
        int key = _getch();
        if (key == KEY::ESC) {
            system("cls");
            StartGame();
        }
    }

    void StartAbout()
    {
        cout << "�����: ���������� ������, ������: SEP211.1 " << endl;
        cout << "Enter ESC for back to menu " << endl;
        int key = _getch();
        if (key == KEY::ESC) {
            system("cls");
            StartGame();
        }
    }

};