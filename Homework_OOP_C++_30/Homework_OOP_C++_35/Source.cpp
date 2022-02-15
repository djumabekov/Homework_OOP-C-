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

    //������
    void setData(int Data) { this->Data = Data; }

    // ������
    int getData() const { return Data; }

    // �������� ������������
    Time& operator = (int val) {
        this->Data = val;
        return *this;
    }
    // �������� ��������
    Time operator + (const int right) const
    {
        Time result;
        result = this->Data + right;
        return result;
    }
    // �������� ���������
    Time operator - (const int right) const
    {
        Time result;
        result = this->Data - right;
        return result;
    }
    // �������� �������� ���� �������� ���� Time
    Time operator + (const Time& right) const
    {
        Time result;
        result = this->Data + right.Data;
        return result;
    }
    // �������� ��������� ���� �������� ���� Time
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
    return os; // ���������� ������ �� ������� ����� ������
}

int main()
{
    Time a = 10, d = 30, c, e = 0;
    int b = 20;

    cout << "a) �������� \" + \" ��� ������ ����� ������: � ������� Time ��������� ����� ����� ������ (Time + int)." << endl;
    c = a + b;
    cout << a << "(Time) + " << b  << "(int) = " << c << endl;
    cout << endl;
    cout << "b) �������� \" - \" ��� ������ ����� ������: �� ������� Time ������ ����� ����� ������ (Time + int). ��������� ���� Time." << endl;
    c = a - b;
    cout << a << "(Time) - " << b << "(int) = " << c << endl;
    cout << endl;
    cout << "c) �������� \" - \" ��� ����������� ������� ����� ����� ���������� (Time + Time). ��������� ���� Time." << endl;
    c = d - a;
    cout << d << "(Time) - " << a << "(Time) = " << c << endl;
    cout << endl;
    int i = 1;
    cout << "�������� � ����� ����� ��� ���������� ������� (������� �������� � ������ Time) �� 1 �������." << endl;
    while (i < 10) {
        e = e.Counter();
        cout << "e.Counter() = " << e << endl;
        i++;
    }
}
*/

/*�������������
2. �������� ����� ����� (��� ����������� ��� ����� ��������� ����).
��������� ���������� ���������� ���������� ��� ���� �������������� �������� ��� ������ � �������: �������� +, -, *, /.
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
    // �������� ������������
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

