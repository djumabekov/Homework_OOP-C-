/*������� 1.
������� ����� Overcoat (������� ������).
����������� ������������� ���������:
1. �������� �� ��������� ����� ������ (�������� == ).
2. �������� ������������ ������ ������� � ������ (�������� = ).
3. ��������� �� ���� ���� ������ ������ ���� (�������� >, >=, <, <= ).*/
/*

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


class Overcoat {
private:
    string  Type;
    double Coast;
public:
    Overcoat() :Type("�� ������"), Coast(0.0) {};
    Overcoat(string T, double C) :Type(T), Coast(C) {}
    //Setters
    void SetType(string newType) { Type = newType; }
    void SetCoast(double newCoast) {
        if (newCoast > 0) {
            Coast = newCoast;
        }
        else { cout << "������! ���� ���� ��� ����� ����" << endl; }
    }
    void Set(string T, double C) {
        SetType(T);
        SetCoast(C);
    }
    //Getters
    string GetType()const { return Type; }
    double GetCoast()const { return Coast; }

    // Input
    friend istream& operator >> (istream& is, Overcoat& obj) {
        string tmpType;
        double tmpCoast;
        cout << "\n������� ��� ������� ������:";
        is >> tmpType;
        cout << "������� ����:";
        is >> tmpCoast;
        obj.Set(tmpType, tmpCoast);
        return is;
    }

    // Output
    friend ostream& operator <<(ostream& os, const Overcoat& obj)
    {
        os << obj.GetType() << " | " << obj.GetCoast();
        return os;
    }
    // ���������� ���������
    bool operator==(const Overcoat& obj) const {
        return (this->GetType() == obj.GetType());
    }
    bool operator > (const Overcoat& obj) const {
        return (this->GetCoast() > obj.GetCoast());
    }
    bool operator >= (const Overcoat& obj) const {
        return (this->GetCoast() >= obj.GetCoast());
    }
    bool operator < (const Overcoat& obj) const {
        return (this->GetCoast() < obj.GetCoast());
    }
    bool operator <= (const Overcoat& obj) const {
        return (this->GetCoast() <= obj.GetCoast());
    }
    // �������� ������������
    Overcoat& operator = (const Overcoat& obj) {
        this->Set(obj.GetType(), obj.GetCoast());
        return *this;
    }
};

int main()
{
    Overcoat A, B;
    cin >> A >> B;
    cout << "������ 1. ��� = " << A.GetType() << endl;
    cout << "������ 1. ���� = " << fixed << setprecision(2) << A.GetCoast() << endl;

    cout << "������ 2. ��� = " << B.GetType() << endl;
    cout << "������ 2. ���� = " << fixed << setprecision(2) << B.GetCoast() << endl;

   //1. �������� �� ��������� ����� ������(�������� == ).

    cout << "������ 1 � 2 ������ ����? " << boolalpha << (A == B) << endl;

    //2. �������� ������������ ������ ������� � ������ (�������� = ).
    Overcoat C = A;
    cout << "C = A = " << C << endl;

    //3. ��������� �� ���� ���� ������ ������ ���� (�������� >, >=, <, <= ).
    cout << "������ 1 ������ ������ 2? " << boolalpha << (A > B) << endl;
    cout << "������ 1 ������ ��� ����� ������ 2? " << (A >= B) << endl;
    cout << "������ 1 ������� ������ 2? " << (A < B) << endl;
    cout << "������ 1 ������� ��� ����� ������ 2? " << (A <= B) << endl;
}
*/

/*������� 2.
������� ����� Flat (��������).
����������� ������������� ���������:
1. �������� �� ��������� �������� ������� (�������� == ).
2. �������� ������������ ������ ������� � ������ (�������� = ).
3. ��������� ���� ������� �� ���� (�������� >, >=, <, <= ).*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


class Flat {
private:
    double  Square;
    double Coast;
public:
    Flat() :Square(0.0), Coast(0.0) {};
    Flat(double S, double C) :Square(S), Coast(C) {}
    //Setters
    void SetSquare(double newSquare) { Square = newSquare; }
    void SetCoast(double newCoast) {
        if (newCoast > 0) {
            Coast = newCoast;
        }
        else { cout << "������! ���� ���� ��� ����� ����" << endl; }
    }
    void Set(double S, double C) {
        SetSquare(S);
        SetCoast(C);
    }
    //Getters
    double GetSquare()const { return Square; }
    double GetCoast()const { return Coast; }

    // Input
    friend istream& operator >> (istream& is, Flat& obj) {
        double tmpSquare;
        double tmpCoast;
        cout << "\n������� ������� ��������:";
        is >> tmpSquare;
        cout << "������� ����:";
        is >> tmpCoast;
        obj.Set(tmpSquare, tmpCoast);
        return is;
    }

    // Output
    friend ostream& operator <<(ostream& os, const Flat& obj)
    {
        os << obj.GetSquare() << " | " << obj.GetCoast();
        return os;
    }
    // ���������� ���������
    bool operator==(const Flat& obj) const {
        return (this->GetSquare() == obj.GetSquare());
    }
    bool operator > (const Flat& obj) const {
        return (this->GetCoast() > obj.GetCoast());
    }
    bool operator >= (const Flat& obj) const {
        return (this->GetCoast() >= obj.GetCoast());
    }
    bool operator < (const Flat& obj) const {
        return (this->GetCoast() < obj.GetCoast());
    }
    bool operator <= (const Flat& obj) const {
        return (this->GetCoast() <= obj.GetCoast());
    }
    // �������� ������������
    Flat& operator = (const Flat& obj) {
        this->Set(obj.GetSquare(), obj.GetCoast());
        return *this;
    }
};

int main()
{
    Flat  A, B;
    cin >> A >> B;
    cout << "�������� 1. ������� = " << A.GetSquare() << endl;
    cout << "�������� 1. ���� = " << fixed << setprecision(2) << A.GetCoast() << endl;

    cout << "�������� 2. ������� = " << B.GetSquare() << endl;
    cout << "�������� 2. ���� = " << fixed << setprecision(2) << B.GetCoast() << endl;

    //1. �������� �� ��������� �������� ������� (�������� == ).

    cout << "�������� 1 � 2 ����� �������? " << boolalpha << (A == B) << endl;

    //2. �������� ������������ ������ ������� � ������ (�������� = ).
    Flat  C = A;
    cout << "C = A = " << C << endl;

    //3. ��������� ���� ������� �� ���� (�������� >, >=, <, <= ).
    cout << "�������� 1 ������ �������� 2? " << boolalpha << (A > B) << endl;
    cout << "�������� 1 ������ ��� ����� �������� 2? " << (A >= B) << endl;
    cout << "�������� 1 ������� �������� 2? " << (A < B) << endl;
    cout << "�������� 1 ������� ��� ����� �������� 2? " << (A <= B) << endl;
}
