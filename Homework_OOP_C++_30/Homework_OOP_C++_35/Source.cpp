/*
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


class Time {
private:
    int Data;
public:
    Time() : Data() {} // Data = 0;
    Time(int val) :Data(val) {} // Data = val;

    //сеттер
    void setData(int Data) { this->Data = Data; }

    // геттер
    int getData() const { return Data; }

    // оператор присавивания
    Time& operator = (int val) {
        this->Data = val;
        return *this;
    }
    // оператор сложения
    Time operator + (const int right) const
    {
        Time result;
        result = this->Data + right;
        return result;
    }
    // оператор вычитания
    Time operator - (const int right) const
    {
        Time result;
        result = this->Data - right;
        return result;
    }
    // оператор сложения двух объектов типа Time
    Time operator + (const Time& right) const
    {
        Time result;
        result = this->Data + right.Data;
        return result;
    }
    // оператор вычитания двух объектов типа Time
    Time operator - (const Time& right) const
    {
        Time result;
        result = this->Data - right.Data;
        return result;
    }

    Time Counter ()
    {
        return this->Data + 1;
    }
};

ostream& operator<<(ostream& os, const Time& right)
{
    //os << "Data: " << right.getData();
    os << right.getData();
    return os; // возвращаем ссылку на текущий поток вывода
}

int main()
{
    Time a = 10, d = 30, c, e = 0;
    int b = 20;

    cout << "a) операция \" + \" для целого числа секунд: к времени Time прибавить целое число секунд (Time + int)." << endl;
    c = a + b;
    cout << a << "(Time) + " << b  << "(int) = " << c << endl;
    cout << endl;
    cout << "b) операция \" - \" для целого числа секунд: от времени Time отнять целое число секунд (Time + int). Результат типа Time." << endl;
    c = a - b;
    cout << a << "(Time) - " << b << "(int) = " << c << endl;
    cout << endl;
    cout << "c) операция \" - \" для определения разницы между двумя веременами (Time + Time). Результат типа Time." << endl;
    c = d - a;
    cout << d << "(Time) - " << a << "(Time) = " << c << endl;
    cout << endl;
    int i = 1;
    cout << "Добавьте в класс метод для приращения времени (которое хранится в объкте Time) на 1 секунду." << endl;
    while (i < 10) {
        e = e.Counter();
        cout << "e.Counter() = " << e << endl;
        i++;
    }
}
*/

/*Дополнительно
2. Создайте класс Дробь (или используйте уже ранее созданный вами).
Используя перегрузку операторов реализуйте для него арифметические операции для работы с дробями: операции +, -, *, /.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

class CDouble {
private:
    double Data;

public:
    CDouble() : Data() {} // Data = 0;
    CDouble(double val) :Data(val) {} // Data = val;
    // оператор присавивания
    CDouble& operator = (double val) {
        this->Data = val;
        return *this;
    }
    CDouble operator + (const CDouble& right) const
    {
        CDouble result;
        result = this->Data + right.Data;
        return result;
    }

    CDouble operator - (const CDouble& right) const
    {
        CDouble result;
        result = this->Data - right.Data;
        return result;
    }
    CDouble operator * (const CDouble& right) const
    {
        CDouble result;
        result = this->Data * right.Data;
        return result;
    }

    CDouble operator / (const CDouble& right) const
    {
        CDouble result;
        if (right.Data != 0) {
            result = this->Data / right.Data;
            return result;
        }
        else { cout << "Error! Devide by zero!"; }
    }

    double getData() const { return Data; }
    void setData(double Data) { this->Data = Data; }
};

ostream& operator<<(ostream& os, const CDouble& right)
{
    os << right.getData();
    return os;
}

int main()
{
    CDouble a = 10.2, b = 30.4, c = 0.0;

    c = a + b;
    cout << a << "(CDouble) + " << b << "(CDouble) = " << c << endl;
    cout << endl;

    c = a - b;
    cout << a << "(CDouble) - " << b << "(CDouble) = " << c << endl;
    cout << endl;

    c = a * b;
    cout << a << "(CDouble) * " << b << "(CDouble) = " << c << endl;
    cout << endl;

    c = a / b;
    cout << a << "(CDouble) / " << b << "(CDouble) = " << c << endl;
    cout << endl;

}

