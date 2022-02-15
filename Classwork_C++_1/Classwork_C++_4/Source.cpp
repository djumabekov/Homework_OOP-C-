#include <iostream>   // ���������� ���������� iostream
#include <windows.h>  // ���������� ���������� Windows.h ��� Sleep() � SetColor()
using namespace std;  // ������� ����������� std - standart

//
// ������� ��� ��������� ����� ���������� �������:
//  colBkgr - ����� ����� ����
//  colSym  - ����� ����� �������
// ����������.
//   ������ ��������� ������ ����� ���������� � ���������� ���� � �������
//   ������� COLOR /? ��� COLOR -help
//
void SetColor(int colBkgr, int colSym) {
    int wAttributes = colBkgr * 16 + colSym;
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// ������� ��� ��������� ������� ������� ������
void SetPos(int Row, int Col) {
    COORD cd;
    cd.X = Col;
    cd.Y = Row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // system("chcp 1251 > nul"); // ��������� ������� �������� 1251 � ������� ���������� ������� CHCP

    SetColor(1, 14); // 1-����� ���, 14-����-������ �����
    cout << "Hello World!" << endl;
    cout << "��� ������ ��� ������";

    SetColor(2, 0); // 2-������� ���, 0-������ �����
    SetPos(5, 12); // ���������� ������ ��� ������
                   // � ������� 5 ������, 12 �������
    cout << "���� �����.....";

    SetColor(0, 7); // ���� ������� �� ���������:
                    // ������ ��� ����� �����
    cout << "Good bye!";


    cin.get(); cin.get(); // ���������� �������
    // system("pause > nul"); // ���������� ������� � ������� ���������� ������� PAUSE
}


#include <iostream>
using namespace std;

/*
18. ***������������ ������ � ���������� ����� ������
� ����������.
���������, ������� �� ��� ���������� ������� �������� 760��,
����������� ������ ������� 95��, ����������� ����������
������� 7�� ��� ��������� ���������� ������� 350��.
�) ����������� ���������, ��������, ��� �������
������������ ���������� ������,
���� ��� ��� ���� �����, ����� ����, ��� ������ ���
�� ������, �� �������� ��� ����� ���������� �����,
����� ����, ��� �� ���� ���� ��� �� ���������� �� ������,
�� ���������� ����� ���������� ������, � ��������� �����
��������� ���������� �����������.
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    int fleshka;
    const int filmsize = 760 * 1024;
    const int clipsize = 95 * 1024;
    const int musicsize = 7 * 1024;
    const int textsize = 350;
    cout << "������� ����� ������ Gb :" << endl;
    cin >> fleshka;
    fleshka *= 1024 * 1024;
    //fleshka = fleshka * 1024 * 1024;
    cout << "���-�� ������� :" << fleshka / filmsize << endl;
    cout << "���-�� ������ :" << fleshka / clipsize << endl;
    cout << "���-�� ������ :" << fleshka / musicsize << endl;
    cout << "���-�� ��������� ������ :"
        << fleshka / textsize << endl;
    int colfilm = fleshka / filmsize;
    fleshka = fleshka % filmsize;
    //int ostatokfilm = fleshka % filmsize;
    //ostatokfilm = fleshka - (colfilm * filmsize);
    int colclip = fleshka / clipsize;
    fleshka %= clipsize;
    int colmusic = fleshka / musicsize;
    fleshka %= musicsize;
    int coltext = fleshka / textsize;
    fleshka %= textsize;
    cout << "���-�� ������� :" << colfilm << endl;
    cout << "���-�� ������ :" << colclip << endl;
    cout << "���-�� ������ :" << colmusic << endl;
    cout << "���-�� ��������� ������ :" << coltext << endl;
    cout << "���-�� ���������� ����� :" << fleshka << endl;

    cin.get(); cin.get(); // ���������� �������
    // system("pause > nul"); // ���������� �������
}


#include <iostream>
using namespace std;

/*
22. ***������������ ������ � ���������� ����������� �����.
������� ����� �� �����, ������� �� �� �����,
��������� �� �����, ������������ � ������� ��������������.
123 = 1*100 + 2*10 + 3 ==>  1, 2, 3
*/
int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "������� ����������� �����:";
    int number;
    cin >> number;

    int a = number / 100;
    int b = number % 100 / 10;
    int c = number % 10;
    int sum = a + b + c;
    cout << a << "+" << b << "+" << c << "=" << sum << endl;
    int product = a * b * c;
    cout << a << "*" << b << "*" << c << "=" << product << endl;
    float average = (float)sum / 3;
    cout << "C����. ����� =" << average << endl;

    cin.get(); cin.get(); // ���������� �������
}


#include <iostream>
using namespace std;

/*
22. ***������������ ������ � ���������� ����������� �����.
������� ����� �� �����, ������� �� �� �����,
��������� �� �����, ������������ � ������� ��������������.
123 = 1*100 + 2*10 + 3 ==>  1, 2, 3
*/
int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "������� ����������� �����:";
    int number;
    cin >> number;

    //int a = number / 100; // �����
    //int b = number % 100 / 10; // �������
    //int c = number % 10; // �������
    int c = number % 10;
    int b = number / 10 % 10;
    int a = number / 10 / 10 % 10;
    int d = number / 10 / 10 / 10 % 10;

    int sum = a + b + c;
    cout << a << "+" << b << "+" << c << "=" << sum << endl;
    int product = a * b * c;
    cout << a << "*" << b << "*" << c << "=" << product << endl;
    float average = (float)sum / 3;
    cout << "C����. ����� =" << average << endl;

    cin.get(); cin.get(); // ���������� �������
}


#include <iostream>
using namespace std;

/*
  ������ ������������� ����� ������������� � ���������
*/
int main() {
    cout << char(201)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(187) << endl;
    // 2 ������ �������
    cout << char(186); // ����� �������
    setlocale(LC_ALL, "Rus"); // ���������� ������� ��������� 1251
    cout << "  ������� ����  ";
    setlocale(LC_ALL, "C"); // ������� ������ ������� �� ��������� 866
    cout << char(186) << endl; // ������ �������
    // 3 ������ �������
    cout << char(186); // ����� �������
    setlocale(LC_ALL, "Rus");
    cout << "  ���� - �����  ";
    setlocale(LC_ALL, "C");
    cout << char(186) << endl; // ������ �������
    // 4 ������ ������ �������
    cout << char(200)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205);
    cout << char(188) << endl;

    //cin.get(); cin.get(); // ���������� �������
    system("pause > nul"); // ���������� �������
    //system("ping 192.168.1.2 -t -w 5000");
}


#include <iostream>
using namespace std;

/*
25. **������������ ������ � ���������� ������� �����.
������� �� ����� ��� ����� � ������� �����.
��������: 13.45
����� �����: 13
������� �����: 45
*/
int main() {
    setlocale(LC_ALL, "Rus");
    double var_num1;
    cout << "������� ������� �����:";
    cin >> var_num1;
    int celvar = var_num1;
    double drob_var_num1 = (var_num1 - celvar) * 100;
    int cel_var_num1 = drob_var_num1;
    cout << "����� ����� : " << celvar << endl;
    cout << "������� ����� : " << drob_var_num1 << endl;
    cout << "������� ����� : " << cel_var_num1 << endl;

    system("pause > nul"); // ���������� �������
}
