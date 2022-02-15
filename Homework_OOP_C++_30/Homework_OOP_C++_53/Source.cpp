/*�������� �������
����: 49-50. ������ � ������. ��������� ������

������� 1
�������� � ���� ����� �������� � ����������. ����� �������� �� ��� ��� ���� �� ����� ������ ������� ESC.
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
    //���������e � ����
    cout << "���������e � ���� :" << endl;
    ofstream F1("File2.txt");

    if (!F1.is_open())
    {
        cout << "������ �������� ����� ��� ������ - ���� �� ������!" << endl;
    }
    else
    {
        string buffer;
        int cnt = 0; // ������� �����
        cout << "������� ������ � ������� ESC ��� ���������� :" << endl;
        while (_getch() != 27) {
            getline(cin, buffer);
            if (cnt == 0) { F1 << buffer; } // ����� ������
            else { F1 << endl << buffer; } // ��������� ������
            cnt++; // ������� ��������� ������
        }
        cout << "���� ����� �������" << endl << endl;
    }
}

void ReadOfFile() {
    string buffer;
    cout << endl;
    //������ �� ����
    cout << "������ �� ����� :" << endl;
    ifstream F2("File2.txt");
    if (!F2.is_open()) {
        cout << "������ �������� ����� ��� ������ - ���� �� ������!" << endl;
    }
    else {
        while (!F2.eof()) // ���� ���� �� ����� �����
        {
            getline(F2, buffer); // �������� �� ��������� ������
            cout << buffer << endl;
        }
    }
}

int main() {

    SaveToFile();

    ReadOfFile();

}

*/

/*�������������
������� 2
����������� ����� ��������:
- ID - ���������� �������� ������������� 4 �����;
- Name - ������ �������� 50 �������� ���������� �������� ����, ��������;
- Description - ������ �������� 500 �������� ���������� �������� ����, ��������.

��������� ����� ������������ �������� (get/set), �������������� � �������������� ����������� � �������� ��������� ����������� ���������/�������������/����������/ ���������� ������ �� �����, � ��� �� ���������/���������/������ ����� ���������� �������� � ����.
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

    //�������������� ������;
    void Edit() { //- �������������� ������.
        Thing temp;
        (cin >> temp).ignore();
        this->SetID(temp.GetID());
        this->SetName(temp.GetName());
        this->SetDescription(temp.GetDescription());
        cout << "Thing is edited" << endl;
    }

    // ����� ��� ���������� �������� ������� � ����
    bool Save(string FileName) {
        ofstream oFile; // �������� ������,����� ��� ������
        oFile.open(FileName); // �������� �����
        if (oFile.is_open()) { // �������� �� �������� �����
            oFile << GetID() << endl;
            oFile << GetName() << endl;
            oFile << GetDescription() << endl;
            return true;
        }
        else { cout << "������ �������� �����!!!" << endl; return false; }
    }

    // ����� ��� ������ �������� ������� �� �����
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // �������� ������,����� ��� ������
        if (!LFile.is_open()) {  // �������� �� ������ ��� �������� �����
            cout << "������ �������� �����!!" << endl;
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
        ifstream LFile(LoadFile); // �������� ������,����� ��� ������
        if (!LFile.is_open()) {  // �������� �� ������ ��� �������� �����
            cout << "������ �������� �����!!" << endl;
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
            LFile.clear(); //���������� ��������� ������, ����� seekg �� ��������
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
    //�������������� ������
    cout << "�������������� ������:" << endl;
    A.Edit();

    cout << endl;
    //���������� � ���� 
    cout << "���������� � ���� :" << endl;
    ofstream F1("File2.txt");
    F1 << A; // ��������� � �������� ����� ������ A
    F1.close();

    cout << endl;
    //������ �� ���� 
    cout << "������ �� ����� :" << endl;
    ifstream F2("File2.txt");
    Thing C;
    F2 >> C; // �������� �� ��������� ������ � ������ C
    cout << "Thing C : \n" << C;

    cout << endl;
    //����� �� ���� 
    cout << "����� � ����� :" << endl;
    //ifstream F2("File2.txt");
    char word[] = "�����";
    cout << "������� �����: " << A.Find("File2.txt", word) << endl;
}
