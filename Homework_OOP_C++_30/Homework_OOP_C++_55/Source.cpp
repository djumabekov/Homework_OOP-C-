
/*�������� �������
����: 53-54. STL.����������.���������.����������

��������� STL C++ (string, vector<>, list<>, ���������, ���������) ������ ������


1) �������� ��������� "����������", � ������� �������� ������ ����� ���������, ������ ��������� � ������ ICQ (����� ����� ���� int).
����������� ���� ��� ������������:
a) ������� ������ ���������;
b) ������������� �� ������ ���������;
c) ������������� �� ������� ���������;
d) ������������� �� ������� ICQ;
e) �����.*/
/*
#include <iostream>
#include <iomanip>
#include <string>     // ��������� ��� ��������� ��������
#include <fstream>    // �������� ��������� ��� ������ � ��������� ��������
#include <array>      // array<> - ����� ��� ������ � ����������� ��������
#include <vector>     // vector<> - ����� ��� ������ � ������������ ��������
#include <list>       // list<> - ����� ����������� ������
#include <iterator>   // ������ ���������� ��� ������ � ������������
#include <algorithm>  // ���� � ���������� ��������� STL C++
#include <random>     // ������ STL ��� ������ � ����. �������
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
        cout << "-------------� � � �----------------\n";
        cout << "1) ������� ������ ���������;\n";
        cout << "2) ������������� �� ������� ICQ\n";
        cout << "3) ������������� �� ������ ���������\n";
        cout << "4) ������������� �� ������� ��������\n";
        cout << "5) �����\n";
        cout << "�������� ����� ����: ";
        (cin >> select).ignore();

        switch (select) {
        case 1:
            cout << endl << "C����� ��������� " << endl;
            cout << lstAbonents << endl;
            break;
        case 2:
            cout << endl << "���������� �� ������ ICQ " << endl;
            lstAbonents.sort(Abonent::CmpICQNum);
            cout << lstAbonents << endl;
            cout << endl << "�������������" << endl << endl;
            break;
        case 3:
            cout << endl << "���������� �� ����� " << endl;
            lstAbonents.sort();
            cout << lstAbonents << endl;
            cout << endl << "�������������" << endl << endl;
            break;
        case 4:
            cout << endl << "���������� �� ������ �������� " << endl;
            lstAbonents.sort(Abonent::CmpPhoneNum);
            cout << lstAbonents << endl;
            cout << endl << "�������������" << endl << endl;
            break;
        case 5: isWork = false; return -1;
        }
    }
}
*/


#include <iostream>
#include <iomanip>
#include <string>     // ��������� ��� ��������� ��������
#include <fstream>    // �������� ��������� ��� ������ � ��������� ��������
#include <array>      // array<> - ����� ��� ������ � ����������� ��������
#include <vector>     // vector<> - ����� ��� ������ � ������������ ��������
#include <list>       // list<> - ����� ����������� ������
#include <iterator>   // ������ ���������� ��� ������ � ������������
#include <algorithm>  // ���� � ���������� ��������� STL C++
#include <random>     // ������ STL ��� ������ � ����. �������
#include <time.h>
#include <ctype.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*2) �������� �������, ������� ���������� �������� �� ������ ����������� (�.�. �������, ������� ����� ������ � ����� �������, � ������ ������: "� ���� ����� �� ���� �����", "��������� ����� �����", "� �� ����").*/
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
        if (in <= '�' && in >= '�')
            return in - ('�' - '�');
        return in;
    }

int main() {
    string str = "� ���� ����� �� ���� �����";

    for (string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (*it == ' ') { str.erase(it); }
    }

    transform(str.begin(), str.end(), str.begin(), ToLowerCase);

    CheckPolindrom check(str);
    cout << "\"" << str << "\"" << " is polyndrom? : " << boolalpha << check.IsPolindrom() << endl;
}
*/

/*3) ������ �� ������ ��� ������� '�' � ��������� �� �� ������������ �������. ����������� ����� erase() ������ string.*/

int main() {
    string str = "������� ���������� �������� �� ������ �����������";

    for (string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (*it == '�' || *it == '�') { str.erase(it); }
    }

    cout << str << endl;
}
