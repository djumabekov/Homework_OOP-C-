/*Домашнее задание
Тема: Пространства имен

Задание 1
Напишите программу, использующую единственный файл, содержащий пространства имен X, У и Z, так, чтобы функция main(), приведенная ниже, работала правильно.
Каждое пространство имен должно содержать определение переменной var и функции print(), выводящей соответствующую переменную var в поток cout.*/
/*
#include <iostream>
#include <time.h>
//using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { std::cin.get(); std::cin.get(); } }_;


namespace X {
    int var;
    void print() {
        std::cout << "X::var = " << var << std::endl;
    }
}

namespace Y {
    int var;
    void print() {
        std::cout << "Y::var = " << var << std::endl;
    }
}

namespace Z {
    int var;
    void print() {
        std::cout << "Z::var = " << var << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");


    X::var = 7;
    X::print();		// Вывод var из пространства имен Х //вывод 7

    using namespace Y;
    var = 9;
    print();		// Вывод var из пространства имен Y // вывод 9

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();	// Вывод var из пространства имен Z  // вывод 11
    }
    print();		// Вывод var из пространства имен Y // вывод 9
    X::print();		// Вывод var из пространства имен X //вывод 7

    system("pause");
}
*/

/*Задание 2
В рамках предыдущих самостоятельных и домашних за даний вы создали набор классов по работе с различными примитивными математическими операциями (дробь, точка в двумерном пространстве, точка в трехмерном пространстве и т.д.).
Разместите уже созданные классы в пространствах имен. Продумайте правильную структуру созданных пространств. Используя механизм пространств напишите код по тестированию полученного решения*/

#include <iostream>
#include <time.h>
//using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { std::cin.get(); std::cin.get(); } }_;

//описание класса Point
namespace P1 {
    class Point {
        int x, y;
        //координаты точки, по умолчанию имеют
        //уровень доступа private
    public:
        //конструктор присваивает переменным класса x и y
        //начальные значения соответственно x0 и y0
        Point(int x0, int y0)
        {
            x = x0;
            y = y0;
        }
        //функция вывода координат точки на экран
        void ShowPoint()
        {
            std::cout << "\nx = " << x;
            std::cout << "\ny = " << y;
        }
    };
}

class line_;

//Класс "точка на плоскости":
namespace P2 {
    class point_
    {
        //Координаты точки на плоскости.
        float x, y;
    public:
        float getX() { return x; }
        float getY() { return y; }

        //Конструктор.
        point_(float xn = 0, float yn = 0)
        {
            x = xn;
            y = yn;
        }
        friend float uclon(point_, line_);
    };
}

//Класс "прямая на плоскости":
namespace L1 {
    class line_
    {
        //Параметры прямой.
        float A, B, C;
    public:
        float getA() { return A; }
        float getB() { return B; }
        float getC() { return C; }
        //Конструктор.
        line_(float a, float b, float c)
        {
            A = a;
            B = b;
            C = c;
        }
        friend float uclon(P2::point_, line_);
    };
}
//Внешнее определение дружественной функции.
namespace F1 {
    float uclon(P2::point_ p, L1::line_ l)
    {
        //вычисление отклонения прямой
        return l.getA() * p.getX() + l.getB() * p.getY() + l.getC();
    }
}


int main()
{    //Определение точки P.
    P2::point_ P(16.0, 12.3);
    //Определение прямой L.
    L1::line_ L(10.0, -42.3, 24.0);
    std::cout << "\n Result" << F1::uclon(P, L) << "\n\n";

    P1::Point A(1, 3); //создаем точку А
    //(объект типа Point) с координатами
    //x = 1, y = 3 (вызывается конструктор Point(1, 3) 
    A.ShowPoint(); //выводим координаты точки А
    //на экран
}


