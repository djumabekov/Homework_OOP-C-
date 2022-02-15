

#include <iostream>
#include <string>
#include <time.h>// time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иници-ции параметров консоли и генератора случ. чисел
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;

/*
***Создайте программу, имитирующую многоквартирный дом.
Необходимо иметь классы "Человек", "Квартира", "Дом".
Класс "Квартира" содержит динамический массив объектов класса "Человек".
Класс "Дом" содержит массив объектов класса "Квартира".
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области класса.
Обращаем ваше внимание, что память под строковые значения выделяется динамически.
Например, для ФИО в классе "Человек".
Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен), деструкторами.
В main() протестировать работу полученного набора классов.
*/

class Chelovek
{
private:
    string Sername; //Фамилия
    string Name;// Имя
    int Age;// Возраст
    char Sex;// Пол (M/F)
public:
    Chelovek() : Sername("Не задано"), Name("Не задано"), Age(0), Sex(' ') {}
    Chelovek(string _Sername, string _Name, int _Age, int _Sex)
        : Sername(_Sername), Name(_Name), Age(_Age), Sex(_Sex) {}
    Chelovek(string _Sername, string _Name, int _Age) :Chelovek() {
        SetSername(_Sername);
        SetName(_Name);
        SetAge(_Age);
    }

    void SetSername(const string& newSername) { Sername = newSername; }
    void SetName(const string& newName) { Name = newName; }
    void SetAge(int newAge) {
        if (newAge >= 0 && newAge <= 2021) {
            Age = newAge;
        }
        else {
            cout << "Error! Age incorrect!\n";
        }
    }
    void SetSex(int newSex) {
        if (newSex == 'm' || newSex == 'M') {
            Sex = 'M';
        }
        else if (newSex == 'f' || newSex == 'F') {
            Sex = 'F';
        }
        else {
            cout << "Error! Sex incorrect!\n";
        }
    }

    string GetSername()const { return Sername; }
    string GetName()const { return Name; }
    int GetAge()const { return Age; }
    int GetSex() const { return Sex; }

    void Input() {
        string tmpS;
        char tmpC;
        int tmpI;
        cout << "Enter sername: ";
        getline(cin, tmpS);
        SetSername(tmpS);

        cout << "Enter name: ";
        getline(cin, tmpS);
        SetName(tmpS);

        cout << "Enter age: ";
        cin >> tmpI;
        SetAge(tmpI);
        cin.ignore();

        cout << "Enter sex: ";
        cin >> tmpC;
        SetSex(tmpC);
        cin.ignore();
    }
    void Print()const {
        cout << "Sername: " << GetSername() << endl;
        cout << "Name: " << GetName() << endl;
        cout << "Age: " << GetAge() << endl;
        cout << "Sex: " << GetSex() << endl;
    }
}; // class Chelovek;

// класса Kvartira
class Kvartira {
private:
    Chelovek* Data; // рабочий указатель на дин. массив жильцов
    int   Size; // текущее кол-во жильцов в массиве Data
public:
    Kvartira() : Data(), Size() {}
    Kvartira(int _Size) : Kvartira() { SetSize(_Size); }
    Kvartira(Chelovek* mas, int size) : Kvartira() { SetChelovek(mas, size); }

    //Constructor copy
    Kvartira(Chelovek& obj) {
        cout << "Copy Kvartira!!!\n";
    }

    // деструктор - здесь ОБЯЗАТЕЛЕН!!! т.к. есть дин. объект - массив Data
    ~Kvartira() { delete[] Data; }
    // set
    void SetSize(int newSize)
    {
        Chelovek* temp = new Chelovek[newSize];
        int minSize = (newSize > Size) ? Size : newSize;
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i];
        }
        delete[] Data;
        Data = temp;
        Size = newSize;
    }
    void SetChelovek(Chelovek* mas, int size)
    {
        //Size = 0; // Если не хотим копировать старых жильцов
        SetSize(size);
        for (int i = 0; i < size; i++)
        {
            Data[i] = mas[i];
        }
    }
    void SetAt(Chelovek chelovek, int index)
    {
        if (index >= 0 && index < Size) { Data[index] = chelovek; }
        else { cout << "Error! Incorrect index!\n"; }
    }
    // get
    int GetSize()const { return Size; }
    const Chelovek* GetChelovek()const { return Data; }
    Chelovek GetAt(int index)const    // Chelovek chelovek = Kvartira[index];
    {
        if (index >= 0 && index < Size) { return Data[index]; }
        cout << "Error! Incorrect index!\n";
        throw "Exception! Incorrect index";
    }
    // 
    void Input()
    {
        int tmpI;
        cout << "Count of person lives in flat: ";
        cin >> tmpI; SetSize(tmpI);
        cin.ignore();

        for (int i = 0; i < GetSize(); i++)
        {
            Data[i].Input();
        }
    }
    void Print()
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << "Person № " << i + 1 << ":" << endl;
            Data[i].Print();
            cout << endl;
        }
    }
}; // class Kvartira

class Dom {
private:
    Kvartira* Data; // рабочий указатель на дин. массив жильцов
    int   Size; // текущее кол-во жильцов в массиве Data
public:
    Dom() : Data(), Size() {}
    Dom(int _Size) : Dom() { SetSize(_Size); }
    Dom(Kvartira* mas, int size) : Dom() { SetKvartira(mas, size); }

    //Constructor copy
    Dom(Kvartira& obj) {
        cout << "Copy Dom!!!\n";
    }

    // конструктор копирования
    Dom(const Dom& obj) :Dom() {
        *this = obj;
        cout << "\n>>>Сработал конструктор копирования<<<\n" << endl;
    }

    // оператор копирования, оператор присваивания
    Dom& operator=(const Dom& obj) {
        SetKvartira(obj.GetKvartira(), obj.GetSize());
        cout << "\n>>>Сработал оператор копирования<<<\n" << endl;
        return *this;
    }


    // деструктор - здесь ОБЯЗАТЕЛЕН!!! т.к. есть дин. объект - массив Data
    ~Dom() { delete[] Data; }
    // set
    void SetSize(int newSize)
    {
        Kvartira* temp = new Kvartira[newSize];
        int minSize = (newSize > Size) ? Size : newSize;
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i];
        }
        delete[] Data;
        Data = temp;
        Size = newSize;
    }
    void SetKvartira(const Kvartira* mas, int size)
    {
        //Size = 0; // Если не хотим копировать старых жильцов
        SetSize(size);
        for (int i = 0; i < size; i++)
        {
            Data[i] = mas[i];
        }
    }
    // get
    int GetSize()const { return Size; }
    const Kvartira* GetKvartira()const { return Data; }
    Kvartira GetAt(int index)const    // Kvartira kvartira = Dom[index];
    {
        if (index >= 0 && index < Size) { return Data[index]; }
        cout << "Error! Incorrect index!\n";
        throw "Exception! Incorrect index";
    }
    // 
    void Input()
    {
        int tmpI;
        cout << "Count of flat in House: ";
        cin >> tmpI; SetSize(tmpI);
        cin.ignore();

        for (int i = 0; i < GetSize(); i++)
        {
            Data[i].Input();
        }
    }
    void Print()
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << "\n--------------------------\nFlat № " << i + 1 << ":" << endl;
            Data[i].Print();
            cout << endl;
        }
    }
};


int main()
{

    Dom dom;
    dom.Input();

    cout << "\n---------Дом №1 (оригинал)---------\n";
    dom.Print();

    cout << "\n---------Дом №2 (копия первого дома)---------\n";
    Dom dom2 = dom;
    dom2.Print();
}

