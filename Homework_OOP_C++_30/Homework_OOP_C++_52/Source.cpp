/*Домашнее задание
Урок: 47-48. Повторение

Задание
Описать класс Man с полями: Фамилия, Имя, Возраст, Дата рождения.
Реализовать для этого класса:
- необходимые конструкторы;
- set/get-методы;
- перегруженные операторы ввода/вывода в поток;
- метод для сохранения в файл,
- метод для чтения из файла.

Создать массив типа vector<Man> (или класса для хранения массива объектов типа Man).
Предусмотреть для такого массива (класса):
- Вывод информации с сортировкой по фамилии или имени;
- Вывод списка именинников месяца с указанием даты рождения.
- Изменение размеров массива при добавлении и удалении записей;
- Поиск по фамилии и имени;
- Редактирование записи;
- Сохранения в файл и чтения из фала массива объектов Man.

Продемонстрировать работу с реализованным классом Man и работу с массивом объектов типа Man.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

struct Date {
    int DD;
    int MM;
    int YYYY;
};

class Man {
private:
    string Name;
    string Surname;
    Date DateOfBirth;
    int Age;
public:
    Man() :Name("no name"), Surname("no surname"), Age(), DateOfBirth() {}
    // set/get
    void SetName(string var) { Name = var; }
    void SetSurname(string var) { Surname = var; }
    void SetDateOfBirth(Date var) {
        DateOfBirth.DD = var.DD;
        DateOfBirth.MM = var.MM;
        DateOfBirth.YYYY = var.YYYY;
    }
    void SetAge(int var) { Age = var; }

    string GetName()const { return Name; }
    string GetSurname()const { return Surname; }
    Date GetDateOfBirth()const { return DateOfBirth; }
    int GetAge()const { return Age; }

    // cout << Man
    friend ostream& operator<<(ostream& os, const Man& obj) {
        if (&os == &cout) {
            os << "Name - " << obj.GetName() << endl;
            os << "Surname - " << obj.GetSurname() << endl;
            os << "DateOfBirth(DD MM YYYY) - " << obj.GetDateOfBirth().DD << obj.GetDateOfBirth().MM << obj.GetDateOfBirth().YYYY << endl;
            os << "Age - " << obj.GetAge() << endl;
        }
        else {
            os << obj.GetName() << endl;
            os << obj.GetSurname() << endl;
            os << obj.GetDateOfBirth().DD << endl;
            os << obj.GetDateOfBirth().MM << endl;
            os << obj.GetDateOfBirth().YYYY << endl;
            os << obj.GetAge() << endl;
        }
        return os;
    }
    // cin >> Man
    friend istream& operator>>(istream& is, Man& obj) {
        if (&is == &cin) {
            string temp;
            Date tempDate;
            cout << "Enter Name - ";
            getline(is, temp);
            obj.SetName(temp);
            cout << "Enter Surname - ";
            getline(is, temp);
            obj.SetSurname(temp);
            cout << "Enter Date Of Birth(DD MM YYYY) - ";
            (is >> tempDate.DD >> tempDate.MM >> tempDate.YYYY).ignore();
            obj.SetDateOfBirth(tempDate);
            int tmp;
            cout << "Enter Age - ";
            is >> tmp;
            obj.SetAge(tmp);
            is.ignore();
        }
        else {
            string temp;
            Date tempDate;
            getline(is, temp);
            obj.SetName(temp);
            getline(is, temp);
            obj.SetSurname(temp);
            is >> tempDate.DD;
            is >> tempDate.MM;
            is >> tempDate.YYYY;
            obj.SetDateOfBirth(tempDate);
            int tmp;
            is >> tmp;
            obj.SetAge(tmp);
            is.ignore();
        }
        return is;
    }

    // метод для сохранения текущего объекта в файл
    bool Save(string FileName) {
        ofstream oFile; // файловый объект,поток для записи
        oFile.open(FileName); // открытие файла
        if (oFile.is_open()) { // проверка на открытие файла
            oFile << GetName() << endl;
            oFile << GetSurname() << endl;
            oFile << GetDateOfBirth().DD << endl;
            oFile << GetDateOfBirth().MM << endl;
            oFile << GetDateOfBirth().YYYY << endl;
            oFile << GetAge() << endl;
            return true;
        }
        else { cout << "Ошибка создания файла!!!" << endl; return false; }
    }

    // метод для чтения текущего объекта из файла
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // файловый объект,поток для чтения
        if (!LFile.is_open()) {  // проверка на ошибку при открытии файла
            cout << "Ошибка открытия файла!!" << endl;
            return false;
        }
        string temp;
        Date tempDate;
        getline(LFile, temp);
        SetName(temp);
        getline(LFile, temp);
        SetSurname(temp);
        getline(LFile, temp);
        (LFile >> tempDate.DD).ignore();
        (LFile >> tempDate.MM).ignore();
        (LFile >> tempDate.YYYY).ignore();
        SetDateOfBirth(tempDate);
        int tmp;
        LFile >> tmp;
        LFile.ignore();
        SetAge(tmp);
        return true;
    }
};

class ArrMan {
private:
    vector <Man> mas;
public:
    ArrMan() : mas() {}   //without mas()
    ArrMan(Man* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            mas.push_back(arr[i]);
        }
    }
    void SetMas(Man* arr, int size)
    {
        mas.clear();
        for (int i = 0; i < size; i++)
        {
            mas.push_back(arr[i]);
        }
    }

    vector<Man> GetMas() const { return mas; }

    Man operator[] (int index) const
    {
        return mas[index];
    }

    friend ostream& operator<< (ostream& os, const ArrMan& obj)
    {
        if (&os == &cout) {
            cout << "Size = " << obj.GetMas().size() << endl;
        }
        else {
            os << obj.GetMas().size() << endl;
        }
        for (int i = 0; i < obj.GetMas().size(); i++)
        {
            os << obj[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, ArrMan& obj) {
        if (&is == &cin) { cout << "Enter number of Mans : "; }
        int tmp;
        (is >> tmp).ignore();
        obj.mas.resize(tmp);
        for (int i = 0; i < tmp; i++)
        {
            is >> obj.mas[i];
        }
        return is;
    }

    //Добавление записи
    void AddMan(Man& obj) {
        mas.push_back(obj);
        cout << "Man of index " << mas.size() << " is added" << endl;
    }

    //Удаление записи;
    void DeleteMan(int index) {

        if (index > mas.size() || index < 0) {
            cout << "Index out of range!" << endl;
        }
        else {
            mas.erase(mas.begin() + index);
            cout << "Man of index " << index << " is deleted" << endl;
        }
    }

    //Редактирование записи;
    void EditMan(int index) { //- Редактирование записи.

        if (index > mas.size() || index < 0) {
            cout << "Index out of range!" << endl;
        }
        else {
            Man temp;
            cin >> temp;
            mas[index].SetName(temp.GetName());
            mas[index].SetSurname(temp.GetSurname());
            mas[index].SetDateOfBirth(temp.GetDateOfBirth());
            mas[index].SetAge(temp.GetAge());
            cout << "Man of index " << index << " is edited" << endl;
        }
    }

    //Поиск по фамилии;
    Man FindManOfSureName(string& str) const { //Поиск по фамилии;
        for (auto man : mas)
        {
            if (man.GetSurname() == str) {
                return man;
            }
            else {
                throw exception("Surname don't find!");
            }
        }
    }

    //Поиск по имени;
    Man FindManOfName(string& str) const { //Поиск по имени;
        for (auto man : mas)
        {
            if (man.GetName() == str) {
                return man;
            }
            else {
                throw exception("Name don't find!");
            }
        }
    }

    //- Вывод информации с сортировкой по фамилии;
    vector<Man> SortBySureName() {
        vector<Man> tempArr;
        for (int i = 0; i < mas.size(); i++) {
            tempArr.push_back(mas[i]);
        }
        for (int i = 0; i < mas.size(); i++) {
            for (int j = mas.size() - 1; j > 0; j--) {
                Man Mn = tempArr[j];
                Man Mn2 = tempArr[j - 1];
                if (Mn.GetSurname()[0] < Mn2.GetSurname()[0]) {
                    swap(tempArr[j], tempArr[j - 1]);
                }
            }
        }
        return tempArr;

    }

    //- Вывод информации с сортировкой по имени;
    vector<Man> SortByName() {
        vector<Man> tempArr;
        for (int i = 0; i < mas.size(); i++) {
            tempArr.push_back(mas[i]);
        }
        for (int i = 0; i < mas.size(); i++) {
            for (int j = mas.size() - 1; j > 0; j--) {
                Man Mn = tempArr[j];
                Man Mn2 = tempArr[j - 1];
                if (Mn.GetName()[0] < Mn2.GetName()[0]) {
                    swap(tempArr[j], tempArr[j - 1]);
                }
            }
        }
        return tempArr;
    }

    //- Вывод списка именинников месяца с указанием даты рождения.
    vector<Man> ListOfBirthdayMan(int MM) {
        vector<Man> tempArr;
        int k = 0;
        for (int i = 0; i < mas.size(); i++) {
            if (mas[i].GetDateOfBirth().MM == MM) {
                tempArr.push_back(mas[i]);
                k++;
            }
        }
        if (tempArr.size() > 0) {
            return tempArr;
        }
        else {
            throw exception("Birthday Man don't find!");
        }
    }


};

int main()
{
    ArrMan A;
    cin >> A;
    cout << "Mans A : \n" << A;

    cout << endl;
    //Добавление записи
    cout << "Добавление записи:" << endl;
    Man man;
    cin >> man;
    cout << "man : \n" << man;
    A.AddMan(man);

    cout << endl;
    //Вывод информации с сортировкой по имени;
    cout << "Вывод информации с сортировкой по имени:" << endl;
    vector<Man> tempArr;
    tempArr = A.SortByName();
    for (auto man : tempArr) { cout << man; }

    cout << endl;
    //Вывод информации с сортировкой по фамилии ;
    cout << "Вывод информации с сортировкой по фамилии:" << endl;
    tempArr = A.SortBySureName();
    for (auto man : tempArr) { cout << man; }

    cout << endl;
    //Вывод списка именинников месяца с указанием даты рождения ;
    cout << "Вывод списка именинников месяца с указанием даты рождения:" << endl;
    tempArr = A.ListOfBirthdayMan(01);
    for (auto man : tempArr) { cout << man; }

    cout << endl;
    //Поиск по фамилии ;
    cout << "Поиск по фамилии:" << endl;
    string tempStr = "Ivanov";
    Man temp;
    temp = A.FindManOfSureName(tempStr);
    cout << temp;

    cout << endl;
    //Поиск по имени ;
    cout << "Поиск по имени:" << endl;
    tempStr = "Ivan";
    temp = A.FindManOfName(tempStr);
    cout << temp;

    cout << endl;
    //Редактирование записи
    cout << "Редактирование записи 1:" << endl;
    A.EditMan(1);

    cout << endl;
    //Удаление записи
    cout << "Удаление записи 1:" << endl;
    A.DeleteMan(1);

    cout << endl;
    //Сохранения в файл 
    cout << "Сохранения в файл :" << endl;
    ofstream F1("File2.txt");
    F1 << A; // сохранить в файловый поток объект A
    F1.close();

    cout << endl;
    //Чтение из фала 
    cout << "Чтение в файл :" << endl;
    ifstream F2("File2.txt");
    ArrMan C;
    F2 >> C; // прочесть из файлового потока в объект C
    cout << "Mans C : \n" << C;
}
