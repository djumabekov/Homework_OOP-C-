/*Домашнее задание
Урок: 49-50. Работа с фалами. Командная строка

Задание 1
Записать в файл текст введённый с клавиатуры. Текст вводится до тех пор пока не будет нажата клавиша ESC.
*/
/*
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <ctype.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

void SaveToFile() {
    cout << endl;
    //Сохранениe в файл
    cout << "Сохранениe в файл :" << endl;
    ofstream F1("File2.txt");

    if (!F1.is_open())
    {
        cout << "Ошибка открытия файла для записи - файл не найден!" << endl;
    }
    else
    {
        string buffer;
        int cnt = 0; // счетчик строк
        cout << "Введите строку и нажмите ESC для сохранения :" << endl;
        while (_getch() != 27) {
            getline(cin, buffer);
            if (cnt == 0) { F1 << buffer; } // певая строка
            else { F1 << endl << buffer; } // следующие строки
            cnt++; // считаем введенные строки
        }
        cout << "Ввод строк окончен" << endl << endl;
    }
}

void ReadOfFile() {
    string buffer;
    cout << endl;
    //Чтение из фала
    cout << "Чтение из файла :" << endl;
    ifstream F2("File2.txt");
    if (!F2.is_open()) {
        cout << "Ошибка открытия файла для чтения - файл не найден!" << endl;
    }
    else {
        while (!F2.eof()) // цикл пока не конец файла
        {
            getline(F2, buffer); // прочесть из файлового потока
            cout << buffer << endl;
        }
    }
}

int main() {

    SaveToFile();

    ReadOfFile();

}

*/

/*Дополнительно
Задание 2
Разработать класс хранящий:
- ID - уникальный числовой идентификатор 4 байта;
- Name - строка размером 50 символов содержащая название вещи, предмета;
- Description - строка размером 500 символов содержащая описание вещи, предмета.

Наполнить класс необходимыми методами (get/set), конструкторами и перегруженными операторами и написать программу позволяющую заполнять/редактировать/отображать/ содержимое класса на экран, а так же сохранять/загружать/искать любое количество объектов в файл.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <ctype.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

class Thing {
private:
    int ID;
    string Name;
    string Description;
public:
    Thing() :ID(), Name(), Description() {}
    Thing(int ID, string Name, string Description) :ID(ID), Name(Name), Description(Description) {}
    void SetID(int ID) { this->ID = ID; }
    void SetName(string Name) { this->Name = Name; }
    void SetDescription(string Description) { this->Description = Description; }

    int GetID() const { return this->ID; }
    string GetName() const { return this->Name; }
    string GetDescription() const { return this->Description; }

    friend ostream& operator<<(ostream& os, const Thing& obj) {
        if (&os == &cout) {
            os << "ID - " << obj.GetID() << endl;
            os << "Name  - " << obj.GetName() << endl;
            os << "Description - " << obj.GetDescription() << endl;
        }
        else {
            os << obj.GetID() << endl;
            os << obj.GetName() << endl;
            os << obj.GetDescription() << endl;
        }
        return os;
    }
    // cin >> Thing
    friend istream& operator>>(istream& is, Thing& obj) {
        if (&is == &cin) {
            int tmpID;
            string tmp;
            cout << "Enter ID - ";
            (is >> tmpID).ignore();
            obj.SetID(tmpID);

            cout << "Enter Name - ";
            getline(is, tmp);
            obj.SetName(tmp);

            cout << "Enter Description  - ";
            getline(is, tmp);
            obj.SetDescription(tmp);
        }
        else {
            int tmpID;
            string tmp;

            (is >> tmpID).ignore();
            obj.SetID(tmpID);

            getline(is, tmp);
            obj.SetName(tmp);

            getline(is, tmp);
            obj.SetDescription(tmp);
        }
        return is;
    }

    //Редактирование записи;
    void Edit() { //- Редактирование записи.
        Thing temp;
        (cin >> temp).ignore();
        this->SetID(temp.GetID());
        this->SetName(temp.GetName());
        this->SetDescription(temp.GetDescription());
        cout << "Thing is edited" << endl;
    }

    // метод для сохранения текущего объекта в файл
    bool Save(string FileName) {
        ofstream oFile; // файловый объект,поток для записи
        oFile.open(FileName); // открытие файла
        if (oFile.is_open()) { // проверка на открытие файла
            oFile << GetID() << endl;
            oFile << GetName() << endl;
            oFile << GetDescription() << endl;
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

        int tmpID;
        string tmp;

        (LFile >> tmpID).ignore();
        SetID(tmpID);

        (getline(LFile, tmp)).ignore();
        SetName(tmp);

        (getline(LFile, tmp)).ignore();
        SetDescription(tmp);
        return true;
    }

    char* Find(string LoadFile, char* word) {
        ifstream LFile(LoadFile); // файловый объект,поток для чтения
        if (!LFile.is_open()) {  // проверка на ошибку при открытии файла
            cout << "Ошибка открытия файла!!" << endl;
            return nullptr;
        }
        else {
            int count = 0;
            string buf;

            while (getline(LFile, buf)) {
                count++;
                cout << buf << endl;
            }
            string* arr = new string[count];
            LFile.clear(); //сбрасываем состояние потока, иначе seekg не работает
            LFile.seekg(0, ios::beg);
            for (int i = 0; i < count; i++) {
                char* str = new char[500];
                LFile.getline(str, 500);
                char* ptemp = str;
                char* wtemp = word;
                int lenPtemp = strlen(ptemp);
                int lenWtemp = strlen(wtemp);
                int index = 0;
                //cout << "lenPtemp = " << lenPtemp << endl;
                //cout << "lenWtemp = " << lenWtemp << endl;
                for (int i = 0; i < lenPtemp; i++) {
                    if (*(wtemp) == *(ptemp + i)) {
                        index = i;
                        for (int j = 1; j < lenWtemp; j++) {
                            if (*(wtemp + j) == *(ptemp + i + j)) {
                                if (j == lenWtemp - 1) {
                                    return ptemp;
                                }
                            }
                        }
                    }
                }

            }
        }return nullptr;
    }
};


int main()
{
    Thing A;
    cin >> A;
    cout << "Thing A : \n" << A;

    cout << endl;
    //Редактирование записи
    cout << "Редактирование записи:" << endl;
    A.Edit();

    cout << endl;
    //Сохранения в файл 
    cout << "Сохранения в файл :" << endl;
    ofstream F1("File2.txt");
    F1 << A; // сохранить в файловый поток объект A
    F1.close();

    cout << endl;
    //Чтение из фала 
    cout << "Чтение из файла :" << endl;
    ifstream F2("File2.txt");
    Thing C;
    F2 >> C; // прочесть из файлового потока в объект C
    cout << "Thing C : \n" << C;

    cout << endl;
    //Поиск из фала 
    cout << "Поиск в файле :" << endl;
    //ifstream F2("File2.txt");
    char word[] = "класс";
    cout << "Найдено слово: " << A.Find("File2.txt", word) << endl;
}
