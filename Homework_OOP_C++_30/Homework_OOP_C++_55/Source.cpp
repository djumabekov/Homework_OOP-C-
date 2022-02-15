
/*Домашнее задание
Урок: 53-54. STL.Контейнеры.Итераторы.Сортировка

Используя STL C++ (string, vector<>, list<>, итераторы, предикаты) решить задачи


1) Написать программу "справочник", в котором хранятся номера имена абонентов, номера телефонов и номера ICQ (целое число типа int).
Реализовать меню для пользователя:
a) вывести список абонентов;
b) отсортировать по именам абонентов;
c) отсортировать по номерам телефонов;
d) отсортировать по номерам ICQ;
e) выход.*/
/*
#include <iostream>
#include <iomanip>
#include <string>     // контейнер для строковых значений
#include <fstream>    // поточный контейнер для работы с файловыми потоками
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <iterator>   // классы итераторов для работы с контейнерами
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


class Abonent {
private:
    string Name;
    int PhoneNum;
    int ICQNum;
public:
    Abonent() {
        Name.resize(RAND(4, 8));
        generate(begin(Name), end(Name), []() {return RAND('A', 'Z'); });
        PhoneNum = RAND(111111, 999999);
        ICQNum = RAND(111111, 999999);
    }

    string GetName() { return Name; }
    int GetPhoneNum() { return PhoneNum; }
    int GetICQNum() { return ICQNum; }

    friend ostream& operator<<(ostream& os, const Abonent& obj) {
        os << setw(10) << obj.Name << " - ";
        os << setw(10) << obj.PhoneNum << " - ";
        os << setw(10) << obj.ICQNum << " - ";
        return os;
    }
    //
    bool operator<(const Abonent& right) const {
        if (this->Name < right.Name) { return true; }
        return false;
    }

    static bool CmpPhoneNum(const Abonent& e1, const Abonent& e2) {
        if (e1.PhoneNum < e2.PhoneNum) { return true; }
        return false;
    }

    static bool CmpICQNum(const Abonent& e1, const Abonent& e2) {
        if (e1.ICQNum < e2.ICQNum) { return true; }
        return false;
    }

};

using MyData = typename list<Abonent>;
using MyDataIter = typename MyData::iterator;

ostream& operator << (ostream& os, const MyData& obj) {
    os << "N       Name       PhoneNum     ICQNum\n";
    int i = 0;
    for (auto& a : obj) {
        os << ++i << ")" << a << endl;
    }
    return os;
}


int main() {
    MyData lstAbonents;
    int size;
    cout << "Enter num of abonents: ";
    (cin >> size).ignore();
    lstAbonents.resize(size);


    bool isWork = true;
    int select;
    while (isWork == true)
    {
        cout << "-------------М Е Н Ю----------------\n";
        cout << "1) вывести список абонентов;\n";
        cout << "2) отсортировать по номерам ICQ\n";
        cout << "3) отсортировать по именам абонентов\n";
        cout << "4) отсортировать по номерам телефона\n";
        cout << "5) выход\n";
        cout << "Выберите номер меню: ";
        (cin >> select).ignore();

        switch (select) {
        case 1:
            cout << endl << "Cписок абонентов " << endl;
            cout << lstAbonents << endl;
            break;
        case 2:
            cout << endl << "Сортировка по номеру ICQ " << endl;
            lstAbonents.sort(Abonent::CmpICQNum);
            cout << lstAbonents << endl;
            cout << endl << "Отсортировано" << endl << endl;
            break;
        case 3:
            cout << endl << "Сортировка по имени " << endl;
            lstAbonents.sort();
            cout << lstAbonents << endl;
            cout << endl << "Отсортировано" << endl << endl;
            break;
        case 4:
            cout << endl << "Сортировка по номеру телефона " << endl;
            lstAbonents.sort(Abonent::CmpPhoneNum);
            cout << lstAbonents << endl;
            cout << endl << "Отсортировано" << endl << endl;
            break;
        case 5: isWork = false; return -1;
        }
    }
}
*/


#include <iostream>
#include <iomanip>
#include <string>     // контейнер для строковых значений
#include <fstream>    // поточный контейнер для работы с файловыми потоками
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <iterator>   // классы итераторов для работы с контейнерами
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами
#include <time.h>
#include <ctype.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*2) Написать функцию, которая определяет является ли строка палиндромом (т.е. строкой, которую можно читать и слева направо, и справа налево: "А роза упала на лапу Азора", "Аргентина манит негра", "Я ем змея").*/
/*
class CheckPolindrom {
private:
    string str;
public:
    CheckPolindrom(string str) { this->str = str; }
    string GetStr() const { return str; }

    bool IsPolindrom() {
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        if (str == tmp)
        {
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const CheckPolindrom& obj) {
        os << obj.str << endl;
        return os;
    }
};

 char ToLowerCase(char in) {
        if (in <= 'Я' && in >= 'А')
            return in - ('Я' - 'я');
        return in;
    }

int main() {
    string str = "А роза упала на лапу Азора";

    for (string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (*it == ' ') { str.erase(it); }
    }

    transform(str.begin(), str.end(), str.begin(), ToLowerCase);

    CheckPolindrom check(str);
    cout << "\"" << str << "\"" << " is polyndrom? : " << boolalpha << check.IsPolindrom() << endl;
}
*/

/*3) Убрать из строки все символы 'о' и уменьшить ее до необходимого размера. Используйте метод erase() класса string.*/

int main() {
    string str = "Которая определяет является ли строка палиндромом";

    for (string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (*it == 'о' || *it == 'О') { str.erase(it); }
    }

    cout << str << endl;
}
