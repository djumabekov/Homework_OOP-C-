/*
Задание N1 - Класс "Магазин"
Для создания класса "Магазин" необходимо сначала реализовать класс "Товар" (или использовать ранее созданный класс "Товар").
В классе "Товар" необходимо хранить в переменных - членах класса : название товара, цена, описание, фирма изготовитель, количество товара.
Реализуйте функции - члены класса для ввода данных, вывода данных, реализуйте аксессоры для доступа к отдельным переменным - членам.

Далее реализуйте класс "Магазин", в котором должен быть динамический массив объектов "Товар" - товары для продажи.
Для класса "Магазин" определите и реализуйте необходимые get / set - методы, конструкторы, методы ввода - вывода на консоль и другие необходимые методы.
Обязательно реализуйте в классе "Магазин" конструктор копирования, оператор копирования и деструктор.
Продемонстрируйте работу класса "Магазин".
*/
/*
#include <iostream>
#include <string>
#include <time.h>// time(), clock()
#include <algorithm>  // библиотека алгоритмов
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иници-ции параметров консоли и генератора случ. чисел
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;


class Goods
{
private:
    string Name; //имя
    string Descr;//описание
    string Manuf;//производитель
    int Count;//количество
    double Coast;//цена

public:
    //constructors
    Goods() : Name("Неизвестно"), Descr("Неизвестно"), Manuf("Неизвестно"), Count(0), Coast(0.0) {}
    Goods(string _Name, string _Descr, string _Manuf, int _Count, double _Coast)
        : Name(_Name), Descr(_Descr), Manuf(_Manuf), Count(_Count), Coast(_Coast){}
    Goods(string _Name, string _Descr, double _Coast)
        :Goods() {
        SetName(_Name);
        SetDescr(_Descr);
        SetCoast(_Coast);
    }

    //setters
    void SetName(const string& newName) { Name = newName; }
    void SetDescr(const string& newDescr) { Descr = newDescr; }
    void SetManuf(const string& newManuf) { Manuf = newManuf; }
    void SetCount(int newCount) {
        if (newCount >= 0) {
            Count = newCount;
        }
        else {
            cout << "Error! Count is incorrect!\n";
        }
    }
    void SetCoast(double newCoast) {
        if (newCoast >= 0) { Coast = newCoast; }
        else { cout << "Error! Coast is incorrect!\n"; }
    }

    //getters
    string GetName()const { return Name; }
    string GetDescr()const { return Descr; }
    string GetManuf()const { return Manuf; }
    int GetCount()const { return Count; }
    double GetCoast() const { return Coast; }

    //Input data
    void Input() {
        string tmpS;
        int tmpI;
        double tmpD;

        cout << "Enter goods name: ";
        getline(cin, tmpS);
        SetName(tmpS);

        cout << "Enter goods description: ";
        getline(cin, tmpS);
        SetDescr(tmpS);

        cout << "Enter goods manufacture: ";
        getline(cin, tmpS);
        SetManuf(tmpS);

        cout << "Enter goods count: ";
        cin >> tmpI;
        SetCount(tmpI);
        cin.ignore();

        cout << "Enter goods coast: ";
        cin >> tmpD;
        SetCoast(tmpD);
        cin.ignore();
    }

    //Print data
    void Print()const {
        cout << "Goods name: " << GetName() << endl;
        cout << "Goods description:  " << GetDescr() << endl;
        cout << "Goods manufacture: " << GetManuf() << endl;
        cout << "Goods count: " << GetCount() << endl;
        cout << "Goods coast: " << GetCoast() << endl;
    }
}; // class Goods;

// класса Библиотеки для хранения и управлением массивом товаров
class Shop {
private:
    Goods* Data; // рабочий указатель на дин. массив
    int   Size; // текущее кол-во элементов в массиве Data
public:
    Shop() : Data(), Size() { cout << "\n>>>Сработал конструктор<<<\n" << endl; }
    Shop(int _Size) : Shop() { SetSize(_Size); }
    Shop(Goods* mas, int size) : Shop() { SetGoods(mas, size); }

    // конструктор копирования
    Shop(const Shop& obj) :Shop() {
        *this = obj;
        cout << "\n>>>Сработал конструктор копирования<<<\n" << endl;
    }

    Shop& operator=(const Shop& obj) {
        SetGoods(obj.GetGoods(), obj.GetSize());
        cout << "\n>>>Сработал оператор копирования<<<\n" << endl;
        return *this;
    }

    // деструктор - здесь ОБЯЗАТЕЛЕН!!! т.к. есть дин. объект - массив Data
    ~Shop() { delete[] Data; cout << "\n>>>Сработал деструктор<<<\n" << endl;
    }
    // set
    void SetSize(int newSize)
    {
        Goods* temp = new Goods[newSize]; // создание нового рабочего массива
        // определение минимального размера для
        //  копирования старых данных
        int minSize = (newSize > Size) ? Size : newSize; // тернарный оператор
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i]; // копирование из Data в temp
        }
        delete[] Data; // удаление старых данных
        Data = temp;   // запоминаем адрес нового рабочего массива
        Size = newSize;
    }
    void SetGoods(const Goods* mas, int size)
    {
        SetSize(size);
        for (int i = 0; i < size; i++) { Data[i] = mas[i]; }
    }
    void SetAt(Goods goods, int index)
    {
        if (index >= 0 && index < Size) { Data[index] = goods; }
        else { cout << "Error! Incorrect index!\n"; }
    }
    // get
    int GetSize()const { return Size; }
    const Goods* GetGoods()const { return Data; }

    Goods GetAt(int index)const
    {
        if (index >= 0 && index < Size) { return Data[index]; }
        cout << "Error! Incorrect index!\n";
        throw "Exception! Incorrect index";
    }
    // Input
    void Input()
    {
        int tmpI;
        cout << "Enter count of goods: ";
        cin >> tmpI; SetSize(tmpI);
        cin.ignore();
        for (int i = 0; i < GetSize(); i++)
        {
            Data[i].Input();
        }
    }

    // Print
    void Print()
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << i + 1 << ":" << endl;
            Data[i].Print();
            cout << endl;
        }
    }

    // select from manufactures
    void SelectFromManuf(string _Manuf)
    {
        for (int i = 0; i < GetSize(); i++)
        {
            if (Data[i].GetManuf() == _Manuf) { Data[i].Print(); }
        }
    }

    // sort by name
    void SortByName() {
        bool CmpGoodsName(Goods g1, Goods g2); // локальный прототип ф-ции
        sort(Data, Data + Size, CmpGoodsName);
    }

   // sort by manuf
    void SortByManuf() {
        sort(Data, Data + Size,
            // лямбда-функция, безымянная функция для сравения
            [](Goods g1, Goods g2) {return (g1.GetManuf() < g2.GetManuf()); }
        );
    }

    // sort by coast
    void SortByCoast() {
        auto cmpFunc =
            [](auto a, auto b) {return a.GetCoast() < b.GetCoast(); };
        sort(Data, Data + Size, cmpFunc);
    }

}; // class Library

// if(b1.Author < b2.Author) ==> True
bool CmpGoodsName(Goods g1, Goods g2) {
    return (g1.GetName() < g2.GetName());
}

int main()
{

    Shop shop;
    shop.Input();
    shop.Print();

    cout << "\n----------выборка по производителю(Danon)-----------\n";
    shop.SelectFromManuf("Danon");

    cout << "\n----------Сортировка по названию-----------\n";
    shop.SortByName(); // сортировка по названию
    shop.Print();

    cout << "\n----------Сортировка по производителю-----------\n";
    shop.SortByManuf(); // сортировка по производителю
    shop.Print();

    cout << "\n---------Сортировка по цене------------\n";
    shop.SortByCoast(); // сортировка по цене
    shop.Print();

    cout << "\n---------Копируем объект shop в shop2------------\n";
    Shop shop2 = shop;
    shop2.Print();
}
*/

/*Дополнительное задание

Разработать класс Reservoir (водоем).
Класс должен обязательно иметь поле "Название".
Остальные поля (переменные класса) - по необходимости.
Класс должен содержать:
- конструктор по умолчанию;
- конструктор с параметрами;
- асессоры - методы get и set для доступа к переменным класса;
- при необходимости реализовать деструктор и конструктор копирования.

В класс необходимо добавить:
1. Метод для определения приблизительного объема (ширина*длина*максимальная глубина);
2. Метод для определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
4. Метод для сравнения площади водной поверхности водоемов одного типа;
5. Метод для копирования объектов;

Написать интерфейс для работы с классом.
Реализовать динамический массив объектов класса с возможностью добавления, удаления объектов из массива.
Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функции-члены (например, для отображения данных о водоёме и т.д.).
*/
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <iostream>
#include <string>
#include <time.h>// time(), clock()
#include <algorithm>  // библиотека алгоритмов
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иници-ции параметров консоли и генератора случ. чисел
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;


class Reservoir
{
private:
    string Name; //имя
    string TypeOfReservoir; //тип водема (море, озеро и т д)
    float Width; // Ширина
    float Length; //Длина
    float Depth; //Глубина
    float Volume; //Объем
    float Square; //Площадь
    Reservoir* Data; // рабочий указатель на дин. массив 
    int Size; // текущее кол-во элементов в массиве Data
public:
    explicit Reservoir() : Name("Неизвестно"), TypeOfReservoir("Без имени"), Width(0), Length(0), Depth(0) {}
    Reservoir(string _Name, string _TypeOfReservoir, float _Width, float _Length, float _Depth)
        : Name(_Name), TypeOfReservoir(_TypeOfReservoir), Width(_Width), Length(_Length), Depth(_Depth) {}
    Reservoir(string _Name, string _TypeOfReservoir, float _Width)
        :Reservoir() {
        SetName(_Name);
        SetTypeOfReservoir(_TypeOfReservoir);
        SetWidth(_Width);
    }

    void SetName(const string& newName) { Name = newName; }
    void SetTypeOfReservoir(const string& newTypeOfReservoir) { TypeOfReservoir = newTypeOfReservoir; }
    void SetWidth(const float& newWidth) { Width = newWidth; }
    void SetLength(const float& newLength) { Length = newLength; }
    void SetDepth(const float& newDepth) { Depth = newDepth; }

    //Метод для определения приблизительного объема(ширина * длина * максимальная глубина);
    void SetVolume() { Volume = GetWidth() * GetLength() * GetDepth(); }

    // Метод для определения площади водной поверхности;
    void SetSquare() { Square = GetWidth() * GetLength(); }

    //getters
    string GetName()const { return Name; }
    string GetTypeOfReservoir()const { return TypeOfReservoir; }
    float GetWidth()const { return Width; }
    float GetLength()const { return Length; }
    float GetDepth()const { return Depth; }

    //Метод для получения приблизительного объема(ширина * длина * максимальная глубина);
    float GetVolume() { return Volume; }

    // Метод для получения площади водной поверхности;
    float GetSquare() { return Square; }

    void Input() {
        string tmpS;
        float tmpD;

        cout << "Enter reservoir Name: ";
        getline(cin, tmpS);
        SetName(tmpS);

        cout << "Enter reservoir Type: ";
        getline(cin, tmpS);
        SetTypeOfReservoir(tmpS);

        cout << "Enter reservoir width: ";
        cin >> tmpD;
        SetWidth(tmpD);
        cin.ignore();

        cout << "Enter reservoir Length: ";
        cin >> tmpD;
        SetLength(tmpD);
        cin.ignore();

        cout << "Enter reservoir Depth: ";
        cin >> tmpD;
        SetDepth(tmpD);
        cin.ignore();

        SetSquare();
        SetVolume();
    }
    void Print() {
        cout << "Reservoir name: " << GetName() << endl;
        cout << "Reservoir type: " << GetTypeOfReservoir() << endl;
        cout << "Reservoir Width:  " << GetWidth() << endl;
        cout << "Reservoir Length: " << GetLength() << endl;
        cout << "Reservoir Depth: " << GetDepth() << endl;
        cout << "Reservoir Volume: " << GetVolume() << endl;
        cout << "Reservoir Square: " << GetSquare() << endl;
    }
}; // class Reservoir;

class CollectReservoir {
private:
    Reservoir* Data; // рабочий указатель на дин. массив 
    int Size; // текущее кол-во элементов в массиве Data
public:
    explicit CollectReservoir() : Data(), Size() {}
    CollectReservoir(int _Size) : CollectReservoir() { SetSize(_Size); }
    CollectReservoir(Reservoir* mas, int size) : CollectReservoir() { SetReservoir(mas, size); }

    // конструктор копирования
    CollectReservoir(const CollectReservoir& obj) :CollectReservoir() { *this = obj; } // this->operator(obj);
    //Library(const Library& obj) :Data(),Size() { *this = obj; }

    CollectReservoir& operator=(const CollectReservoir& obj) {
        SetReservoir(obj.GetReservoir(), obj.GetSize());
        return *this;
    }

    // деструктор - здесь ОБЯЗАТЕЛЕН!!! т.к. есть дин. объект - массив Data
    ~CollectReservoir() { delete[] Data; }
    // set
    void SetSize(int newSize, int Index = -1)
    {
        Reservoir* temp = new Reservoir[newSize]; // создание нового рабочего массива
        // цикл копирования старых данных
        int j = 0;
        for (int i = 0; i < Size; i++)
        {
            if (i != Index) { //проверка на Индекс чтобы исключить из копирования при удалении из массива
                temp[j] = Data[i]; // копирование из Data в temp
                j++;
            }

        }
        delete[] Data; // удаление старых данных
        Data = temp;   // запоминаем адрес нового рабочего массива
        Size = newSize;
    }
    void SetReservoir(const Reservoir* mas, int size)
    {
        SetSize(size);
        for (int i = 0; i < size; i++) { Data[i] = mas[i]; }
    }
    void SetAt(Reservoir book, int index) // 
    {
        if (index >= 0 && index < Size) { Data[index] = book; }
        else { cout << "Error! Incorrect index!\n"; }
    }
    // get
    int GetSize()const { return Size; }
    const Reservoir* GetReservoir()const { return Data; }

    Reservoir GetAt(int index)const    // 
    {
        if (index >= 0 && index < Size) { return Data[index]; }
        cout << "Error! Incorrect index!\n";
        //return ?????;
        throw "Exception! Incorrect index";
    }

    //Метод для добавления объекта в массив;
    void SetAddReservoir()
    {
        SetSize(GetSize() + 1);
        Reservoir obj;
        obj.Input();
        Data[GetSize() - 1] = obj;
    }

    //Метод для удаления объекта из массива;
    void SetDelReservoir(int Index)
    {

        if (Index - 1 >= 0 && Index - 1 < GetSize()) {
            SetSize(GetSize() - 1, Index - 1);
        }
        else {
            cout << "Error! Incorrect index!\n";
        }
    }
    // 
    void Input()
    {
        int tmpI;
        cout << "Enter count of Reservoir: ";
        cin >> tmpI;
        SetSize(tmpI);
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
            cout << i + 1 << ":" << endl;
            Data[i].Print();
            cout << endl;
        }
    }
    // Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
    void CheckReservoirByTypes(string _Name1, string _Name2)
    {
        int a = -1, b = -1;
        for (int i = 0; i < GetSize(); i++)
        {
            if (Data[i].GetName() == _Name1) {
                a = i;
            }
        }
        for (int j = 0; j < GetSize(); j++)
        {
            if (Data[j].GetName() == _Name2) {
                b = j;
            }
        }
        if (a != -1 && b != -1) {
            if (Data[a].GetTypeOfReservoir() == Data[b].GetTypeOfReservoir()) {
                cout << "Водоем " << _Name1 << " и " << _Name2 << " относятся к одному типу: " << Data[a].GetTypeOfReservoir() << " = " << Data[b].GetTypeOfReservoir() << endl;
            }
            else {
                cout << "Водоем " << _Name1 << " и " << _Name2 << " не относятся к одному типу: " << Data[a].GetTypeOfReservoir() << " != " << Data[b].GetTypeOfReservoir() << endl;
            }
        }
        else {
            cout << "Водоемы не найдены" << endl;
        }
    }
    // Метод для сравнения площади водной поверхности водоемов одного типа;
    void CheckReservoirBySquare(string _Name1, string _Name2) {
        int a = -1, b = -1;
        for (int i = 0; i < GetSize(); i++)
        {
            if (Data[i].GetName() == _Name1) {
                a = i;
            }
        }
        for (int j = 0; j < GetSize(); j++) {
            if (Data[j].GetName() == _Name2) {
                b = j;
            }
        }
        if (a != -1 && b != -1) {
            if (Data[a].GetSquare() > Data[b].GetSquare()) {
                cout << "Водоем " << _Name1 << " с площадью " << Data[a].GetSquare() << " больше чем водоем " << _Name2 << " с площадью " << Data[b].GetSquare() << endl;
            }
            else if (Data[a].GetSquare() < Data[b].GetSquare()) {
                cout << "Водоем " << _Name1 << " с площадью " << Data[a].GetSquare() << " меньше чем водоем " << _Name2 << " с площадью " << Data[b].GetSquare() << endl;
            }
            else {
                cout << "Водоемы " << _Name1 << " с площадью " << Data[a].GetSquare() << " и водоем " << _Name2 << " с площадью " << Data[b].GetSquare() << " равны " << endl;
            }
        }
        else {
            cout << "Водоемы не найдены" << endl;
            return;
        }
    }

    void WriteToFile(string fName)
    {
        ofstream file;
        file.open(fName);
        if (!file.is_open()) {
            cout << "Error , cant create file " << endl;
        }
        for (int i = 0; i < GetSize(); i++) {
            file << Data[i].GetName() << ", "
                << Data[i].GetTypeOfReservoir() << ", "
                << Data[i].GetWidth() << ", "
                << Data[i].GetLength() << ", "
                << Data[i].GetDepth() << ", "
                << Data[i].GetVolume() << ", "
                << Data[i].GetSquare() << "\n";
        }
        cout << "File writting" << endl;
    }
}; // class CollectReservoir


int main()
{

    CollectReservoir reservoir;
    reservoir.Input();
    reservoir.Print();

    cout << "\n----------Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд)-----------\n";
    reservoir.CheckReservoirByTypes("Балхаш", "Арал");

    cout << "\n----------Метод для сравнения площади водной поверхности водоемов одного типа-----------\n";
    reservoir.CheckReservoirBySquare("Балхаш", "Арал");

    cout << "\n----------Метод для добавления объекта в массив-----------\n";
    reservoir.SetAddReservoir();
    reservoir.Print();

    cout << "\n----------Метод для удаления объекта из массива-----------\n";
    cout << "Enter reservoir num for delete his from array: ";
    int Index;
    cin >> Index;
    cin.ignore();
    reservoir.SetDelReservoir(Index);
    reservoir.Print();

    cout << "\n---------Копируем объект reservoir в reservoir2------------\n";
    CollectReservoir reservoir2 = reservoir;
    reservoir2.Print();

    cout << "\n---------Печатаем объект reservoir в файл------------\n";
    string FileName; // имя файла
    cout << "Введите имя файла: ";
    getline(cin, FileName); // чтение имени файла
    reservoir.WriteToFile(FileName);

}
