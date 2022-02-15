/*�������� �������
����: ������������ ����

������� 1
�������� ���������, ������������ ������������ ����, ���������� ������������ ���� X, � � Z, ���, ����� ������� main(), ����������� ����, �������� ���������.
������ ������������ ���� ������ ��������� ����������� ���������� var � ������� print(), ��������� ��������������� ���������� var � ����� cout.*/
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
    X::print();		// ����� var �� ������������ ���� � //����� 7

    using namespace Y;
    var = 9;
    print();		// ����� var �� ������������ ���� Y // ����� 9

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();	// ����� var �� ������������ ���� Z  // ����� 11
    }
    print();		// ����� var �� ������������ ���� Y // ����� 9
    X::print();		// ����� var �� ������������ ���� X //����� 7

    system("pause");
}
*/

/*������� 2
� ������ ���������� ��������������� � �������� �� ����� �� ������� ����� ������� �� ������ � ���������� ������������ ��������������� ���������� (�����, ����� � ��������� ������������, ����� � ���������� ������������ � �.�.).
���������� ��� ��������� ������ � ������������� ����. ���������� ���������� ��������� ��������� �����������. ��������� �������� ����������� �������� ��� �� ������������ ����������� �������*/

#include <iostream>
#include <time.h>
//using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { std::cin.get(); std::cin.get(); } }_;

//�������� ������ Point
namespace P1 {
    class Point {
        int x, y;
        //���������� �����, �� ��������� �����
        //������� ������� private
    public:
        //����������� ����������� ���������� ������ x � y
        //��������� �������� �������������� x0 � y0
        Point(int x0, int y0)
        {
            x = x0;
            y = y0;
        }
        //������� ������ ��������� ����� �� �����
        void ShowPoint()
        {
            std::cout << "\nx = " << x;
            std::cout << "\ny = " << y;
        }
    };
}

class line_;

//����� "����� �� ���������":
namespace P2 {
    class point_
    {
        //���������� ����� �� ���������.
        float x, y;
    public:
        float getX() { return x; }
        float getY() { return y; }

        //�����������.
        point_(float xn = 0, float yn = 0)
        {
            x = xn;
            y = yn;
        }
        friend float uclon(point_, line_);
    };
}

//����� "������ �� ���������":
namespace L1 {
    class line_
    {
        //��������� ������.
        float A, B, C;
    public:
        float getA() { return A; }
        float getB() { return B; }
        float getC() { return C; }
        //�����������.
        line_(float a, float b, float c)
        {
            A = a;
            B = b;
            C = c;
        }
        friend float uclon(P2::point_, line_);
    };
}
//������� ����������� ������������� �������.
namespace F1 {
    float uclon(P2::point_ p, L1::line_ l)
    {
        //���������� ���������� ������
        return l.getA() * p.getX() + l.getB() * p.getY() + l.getC();
    }
}


int main()
{    //����������� ����� P.
    P2::point_ P(16.0, 12.3);
    //����������� ������ L.
    L1::line_ L(10.0, -42.3, 24.0);
    std::cout << "\n Result" << F1::uclon(P, L) << "\n\n";

    P1::Point A(1, 3); //������� ����� �
    //(������ ���� Point) � ������������
    //x = 1, y = 3 (���������� ����������� Point(1, 3) 
    A.ShowPoint(); //������� ���������� ����� �
    //�� �����
}


