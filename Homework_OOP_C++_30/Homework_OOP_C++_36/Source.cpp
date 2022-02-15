/*Задание 1.
Создать класс Overcoat (верхняя одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция == ).
2. Операцию присваивания одного объекта в другой (операция = ).
3. Сравнение по цене двух пальто одного типа (операции >, >=, <, <= ).*/
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
    Overcoat() :Type("Не задано"), Coast(0.0) {};
    Overcoat(string T, double C) :Type(T), Coast(C) {}
    //Setters
    void SetType(string newType) { Type = newType; }
    void SetCoast(double newCoast) {
        if (newCoast > 0) {
            Coast = newCoast;
        }
        else { cout << "Ошибка! Цена ниже или равна нулю" << endl; }
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
        cout << "\nВведите тип верхней одежды:";
        is >> tmpType;
        cout << "Введите цену:";
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
    // логические операторы
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
    // оператор присавивания
    Overcoat& operator = (const Overcoat& obj) {
        this->Set(obj.GetType(), obj.GetCoast());
        return *this;
    }
};

int main()
{
    Overcoat A, B;
    cin >> A >> B;
    cout << "Одежда 1. Тип = " << A.GetType() << endl;
    cout << "Одежда 1. Цена = " << fixed << setprecision(2) << A.GetCoast() << endl;

    cout << "Одежда 2. Тип = " << B.GetType() << endl;
    cout << "Одежда 2. Цена = " << fixed << setprecision(2) << B.GetCoast() << endl;

   //1. Проверка на равенство типов одежды(операция == ).

    cout << "Одежда 1 и 2 одного типа? " << boolalpha << (A == B) << endl;

    //2. Операцию присваивания одного объекта в другой (операция = ).
    Overcoat C = A;
    cout << "C = A = " << C << endl;

    //3. Сравнение по цене двух пальто одного типа (операции >, >=, <, <= ).
    cout << "Одежда 1 дороже Одежды 2? " << boolalpha << (A > B) << endl;
    cout << "Одежда 1 дороже или равна Одежде 2? " << (A >= B) << endl;
    cout << "Одежда 1 дешевле Одежды 2? " << (A < B) << endl;
    cout << "Одежда 1 дешевле или равна Одежде 2? " << (A <= B) << endl;
}
*/

/*Задание 2.
Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция == ).
2. Операцию присваивания одного объекта в другой (операция = ).
3. Сравнение двух квартир по цене (операции >, >=, <, <= ).*/


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
        else { cout << "Ошибка! Цена ниже или равна нулю" << endl; }
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
        cout << "\nВведите площадь квартиры:";
        is >> tmpSquare;
        cout << "Введите цену:";
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
    // логические операторы
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
    // оператор присавивания
    Flat& operator = (const Flat& obj) {
        this->Set(obj.GetSquare(), obj.GetCoast());
        return *this;
    }
};

int main()
{
    Flat  A, B;
    cin >> A >> B;
    cout << "Квартира 1. Площадь = " << A.GetSquare() << endl;
    cout << "Квартира 1. Цена = " << fixed << setprecision(2) << A.GetCoast() << endl;

    cout << "Квартира 2. Площадь = " << B.GetSquare() << endl;
    cout << "Квартира 2. Цена = " << fixed << setprecision(2) << B.GetCoast() << endl;

    //1. Проверка на равенство площадей квартир (операция == ).

    cout << "Квартиры 1 и 2 одной площади? " << boolalpha << (A == B) << endl;

    //2. Операцию присваивания одного объекта в другой (операция = ).
    Flat  C = A;
    cout << "C = A = " << C << endl;

    //3. Сравнение двух квартир по цене (операции >, >=, <, <= ).
    cout << "Квартира 1 дороже Квартиры 2? " << boolalpha << (A > B) << endl;
    cout << "Квартира 1 дороже или равна Квартире 2? " << (A >= B) << endl;
    cout << "Квартира 1 дешевле Квартиры 2? " << (A < B) << endl;
    cout << "Квартира 1 дешевле или равна Квартире 2? " << (A <= B) << endl;
}
