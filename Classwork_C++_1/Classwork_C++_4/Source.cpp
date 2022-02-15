#include <iostream>   // подключить библиотеку iostream
#include <windows.h>  // подключить библиотеку Windows.h для Sleep() и SetColor()
using namespace std;  // открыть простанство std - standart

//
// функция для установки цвета выводимого символа:
//  colBkgr - номер цвета фона
//  colSym  - номер цвета символа
// Примечание.
//   Номера возможных цветов можно посмотреть в консольном окне с помощью
//   команды COLOR /? или COLOR -help
//
void SetColor(int colBkgr, int colSym) {
    int wAttributes = colBkgr * 16 + colSym;
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// Функция для установки позиции курсора вывода
void SetPos(int Row, int Col) {
    COORD cd;
    cd.X = Col;
    cd.Y = Row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // system("chcp 1251 > nul"); // установка кодовой страницы 1251 с помощью консольной команды CHCP

    SetColor(1, 14); // 1-синий фон, 14-ярко-желтые буквы
    cout << "Hello World!" << endl;
    cout << "Моя строка для вывода";

    SetColor(2, 0); // 2-Зеленый фон, 0-черные буквы
    SetPos(5, 12); // установить курсор для вывода
                   // в позицию 5 строка, 12 столбец
    cout << "Меня зовут.....";

    SetColor(0, 7); // цвет консоли по умолчанию:
                    // черный фон белые буквы
    cout << "Good bye!";


    cin.get(); cin.get(); // блокировка консоли
    // system("pause > nul"); // блокировка консоли с помощью консольной команды PAUSE
}


#include <iostream>
using namespace std;

/*
18. ***Пользователь вводит с клавиатуры объем флешки
в гигабайтах.
Посчитать, сколько на нее поместится фильмов размером 760мб,
музыкальных клипов объемом 95мб, музыкальных композиций
объемом 7мб или текстовых документов объемом 350кб.
а) пересчитать результат, учитывая, что сначала
пользователь записывает фильмы,
пока для них есть место, после того, как фильмы уже
не влазят, но осталось еще место записывает клипы,
после того, как ни один клип уже не помещается на флешку,
на оставшееся место записывает музыку, и свободное место
заполняет текстовыми документами.
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    int fleshka;
    const int filmsize = 760 * 1024;
    const int clipsize = 95 * 1024;
    const int musicsize = 7 * 1024;
    const int textsize = 350;
    cout << "Введите обьем флешки Gb :" << endl;
    cin >> fleshka;
    fleshka *= 1024 * 1024;
    //fleshka = fleshka * 1024 * 1024;
    cout << "Кол-во фильмов :" << fleshka / filmsize << endl;
    cout << "Кол-во клипов :" << fleshka / clipsize << endl;
    cout << "Кол-во музыки :" << fleshka / musicsize << endl;
    cout << "Кол-во текстовых файлов :"
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
    cout << "Кол-во фильмов :" << colfilm << endl;
    cout << "Кол-во клипов :" << colclip << endl;
    cout << "Кол-во музыки :" << colmusic << endl;
    cout << "Кол-во текстовых файлов :" << coltext << endl;
    cout << "Кол-во свободного места :" << fleshka << endl;

    cin.get(); cin.get(); // блокировка консоли
    // system("pause > nul"); // блокировка консоли
}


#include <iostream>
using namespace std;

/*
22. ***Пользователь вводит с клавиатуры трехзначное число.
Разбить число на цифры, вывести их на экран,
посчитать их сумму, произведение и среднее арифметическое.
123 = 1*100 + 2*10 + 3 ==>  1, 2, 3
*/
int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Введите трехзначное число:";
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
    cout << "Cредн. арифм =" << average << endl;

    cin.get(); cin.get(); // блокировка консоли
}


#include <iostream>
using namespace std;

/*
22. ***Пользователь вводит с клавиатуры трехзначное число.
Разбить число на цифры, вывести их на экран,
посчитать их сумму, произведение и среднее арифметическое.
123 = 1*100 + 2*10 + 3 ==>  1, 2, 3
*/
int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Введите трехзначное число:";
    int number;
    cin >> number;

    //int a = number / 100; // сотни
    //int b = number % 100 / 10; // десятки
    //int c = number % 10; // единицы
    int c = number % 10;
    int b = number / 10 % 10;
    int a = number / 10 / 10 % 10;
    int d = number / 10 / 10 / 10 % 10;

    int sum = a + b + c;
    cout << a << "+" << b << "+" << c << "=" << sum << endl;
    int product = a * b * c;
    cout << a << "*" << b << "*" << c << "=" << product << endl;
    float average = (float)sum / 3;
    cout << "Cредн. арифм =" << average << endl;

    cin.get(); cin.get(); // блокировка консоли
}


#include <iostream>
using namespace std;

/*
  Пример одновременный вывод псевдографики и кириллицы
*/
int main() {
    cout << char(201)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(187) << endl;
    // 2 строка таблицы
    cout << char(186); // левая граница
    setlocale(LC_ALL, "Rus"); // установить русскую раскладку 1251
    cout << "  Времена года  ";
    setlocale(LC_ALL, "C"); // вернуть локаль консоли по умолчанию 866
    cout << char(186) << endl; // правая граница
    // 3 строка таблицы
    cout << char(186); // левая граница
    setlocale(LC_ALL, "Rus");
    cout << "  Зима - Весна  ";
    setlocale(LC_ALL, "C");
    cout << char(186) << endl; // правая граница
    // 4 нижняя строка таблицы
    cout << char(200)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205);
    cout << char(188) << endl;

    //cin.get(); cin.get(); // блокировка консоли
    system("pause > nul"); // блокировка консоли
    //system("ping 192.168.1.2 -t -w 5000");
}


#include <iostream>
using namespace std;

/*
25. **Пользователь вводит с клавиатуры дробное число.
Вывести на экран его целую и дробную части.
Например: 13.45
целая часть: 13
дробная часть: 45
*/
int main() {
    setlocale(LC_ALL, "Rus");
    double var_num1;
    cout << "Введите дробное число:";
    cin >> var_num1;
    int celvar = var_num1;
    double drob_var_num1 = (var_num1 - celvar) * 100;
    int cel_var_num1 = drob_var_num1;
    cout << "Целую часть : " << celvar << endl;
    cout << "Дробная часть : " << drob_var_num1 << endl;
    cout << "Дробная часть : " << cel_var_num1 << endl;

    system("pause > nul"); // блокировка консоли
}
