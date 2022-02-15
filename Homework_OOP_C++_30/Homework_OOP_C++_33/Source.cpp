/*
������� N1 - ����� "�������"
��� �������� ������ "�������" ���������� ������� ����������� ����� "�����" (��� ������������ ����� ��������� ����� "�����").
� ������ "�����" ���������� ������� � ���������� - ������ ������ : �������� ������, ����, ��������, ����� ������������, ���������� ������.
���������� ������� - ����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ��������� ���������� - ������.

����� ���������� ����� "�������", � ������� ������ ���� ������������ ������ �������� "�����" - ������ ��� �������.
��� ������ "�������" ���������� � ���������� ����������� get / set - ������, ������������, ������ ����� - ������ �� ������� � ������ ����������� ������.
����������� ���������� � ������ "�������" ����������� �����������, �������� ����������� � ����������.
����������������� ������ ������ "�������".
*/
/*
#include <iostream>
#include <string>
#include <time.h>// time(), clock()
#include <algorithm>  // ���������� ����������
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// ��������� ��� �����-��� ���������� ������� � ���������� ����. �����
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;


class Goods
{
private:
    string Name; //���
    string Descr;//��������
    string Manuf;//�������������
    int Count;//����������
    double Coast;//����

public:
    //constructors
    Goods() : Name("����������"), Descr("����������"), Manuf("����������"), Count(0), Coast(0.0) {}
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

// ������ ���������� ��� �������� � ����������� �������� �������
class Shop {
private:
    Goods* Data; // ������� ��������� �� ���. ������
    int   Size; // ������� ���-�� ��������� � ������� Data
public:
    Shop() : Data(), Size() { cout << "\n>>>�������� �����������<<<\n" << endl; }
    Shop(int _Size) : Shop() { SetSize(_Size); }
    Shop(Goods* mas, int size) : Shop() { SetGoods(mas, size); }

    // ����������� �����������
    Shop(const Shop& obj) :Shop() {
        *this = obj;
        cout << "\n>>>�������� ����������� �����������<<<\n" << endl;
    }

    Shop& operator=(const Shop& obj) {
        SetGoods(obj.GetGoods(), obj.GetSize());
        cout << "\n>>>�������� �������� �����������<<<\n" << endl;
        return *this;
    }

    // ���������� - ����� ����������!!! �.�. ���� ���. ������ - ������ Data
    ~Shop() { delete[] Data; cout << "\n>>>�������� ����������<<<\n" << endl;
    }
    // set
    void SetSize(int newSize)
    {
        Goods* temp = new Goods[newSize]; // �������� ������ �������� �������
        // ����������� ������������ ������� ���
        //  ����������� ������ ������
        int minSize = (newSize > Size) ? Size : newSize; // ��������� ��������
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i]; // ����������� �� Data � temp
        }
        delete[] Data; // �������� ������ ������
        Data = temp;   // ���������� ����� ������ �������� �������
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
        bool CmpGoodsName(Goods g1, Goods g2); // ��������� �������� �-���
        sort(Data, Data + Size, CmpGoodsName);
    }

   // sort by manuf
    void SortByManuf() {
        sort(Data, Data + Size,
            // ������-�������, ���������� ������� ��� ��������
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

    cout << "\n----------������� �� �������������(Danon)-----------\n";
    shop.SelectFromManuf("Danon");

    cout << "\n----------���������� �� ��������-----------\n";
    shop.SortByName(); // ���������� �� ��������
    shop.Print();

    cout << "\n----------���������� �� �������������-----------\n";
    shop.SortByManuf(); // ���������� �� �������������
    shop.Print();

    cout << "\n---------���������� �� ����------------\n";
    shop.SortByCoast(); // ���������� �� ����
    shop.Print();

    cout << "\n---------�������� ������ shop � shop2------------\n";
    Shop shop2 = shop;
    shop2.Print();
}
*/

/*�������������� �������

����������� ����� Reservoir (������).
����� ������ ����������� ����� ���� "��������".
��������� ���� (���������� ������) - �� �������������.
����� ������ ���������:
- ����������� �� ���������;
- ����������� � �����������;
- �������� - ������ get � set ��� ������� � ���������� ������;
- ��� ������������� ����������� ���������� � ����������� �����������.

� ����� ���������� ��������:
1. ����� ��� ����������� ���������������� ������ (������*�����*������������ �������);
2. ����� ��� ����������� ������� ������ �����������;
3. ����� ��� �������� ��������� �� ������� � ������ ���� (����-����; �������-����);
4. ����� ��� ��������� ������� ������ ����������� �������� ������ ����;
5. ����� ��� ����������� ��������;

�������� ��������� ��� ������ � �������.
����������� ������������ ������ �������� ������ � ������������ ����������, �������� �������� �� �������.
����������� ����������� ������ ���������� �� �������� ������� � ��������� ����, �������� ����.
����������� explicit ����������� � ����������� �������-����� (��������, ��� ����������� ������ � ������ � �.�.).
*/
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <iostream>
#include <string>
#include <time.h>// time(), clock()
#include <algorithm>  // ���������� ����������
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// ��������� ��� �����-��� ���������� ������� � ���������� ����. �����
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;


class Reservoir
{
private:
    string Name; //���
    string TypeOfReservoir; //��� ������ (����, ����� � � �)
    float Width; // ������
    float Length; //�����
    float Depth; //�������
    float Volume; //�����
    float Square; //�������
    Reservoir* Data; // ������� ��������� �� ���. ������ 
    int Size; // ������� ���-�� ��������� � ������� Data
public:
    explicit Reservoir() : Name("����������"), TypeOfReservoir("��� �����"), Width(0), Length(0), Depth(0) {}
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

    //����� ��� ����������� ���������������� ������(������ * ����� * ������������ �������);
    void SetVolume() { Volume = GetWidth() * GetLength() * GetDepth(); }

    // ����� ��� ����������� ������� ������ �����������;
    void SetSquare() { Square = GetWidth() * GetLength(); }

    //getters
    string GetName()const { return Name; }
    string GetTypeOfReservoir()const { return TypeOfReservoir; }
    float GetWidth()const { return Width; }
    float GetLength()const { return Length; }
    float GetDepth()const { return Depth; }

    //����� ��� ��������� ���������������� ������(������ * ����� * ������������ �������);
    float GetVolume() { return Volume; }

    // ����� ��� ��������� ������� ������ �����������;
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
    Reservoir* Data; // ������� ��������� �� ���. ������ 
    int Size; // ������� ���-�� ��������� � ������� Data
public:
    explicit CollectReservoir() : Data(), Size() {}
    CollectReservoir(int _Size) : CollectReservoir() { SetSize(_Size); }
    CollectReservoir(Reservoir* mas, int size) : CollectReservoir() { SetReservoir(mas, size); }

    // ����������� �����������
    CollectReservoir(const CollectReservoir& obj) :CollectReservoir() { *this = obj; } // this->operator(obj);
    //Library(const Library& obj) :Data(),Size() { *this = obj; }

    CollectReservoir& operator=(const CollectReservoir& obj) {
        SetReservoir(obj.GetReservoir(), obj.GetSize());
        return *this;
    }

    // ���������� - ����� ����������!!! �.�. ���� ���. ������ - ������ Data
    ~CollectReservoir() { delete[] Data; }
    // set
    void SetSize(int newSize, int Index = -1)
    {
        Reservoir* temp = new Reservoir[newSize]; // �������� ������ �������� �������
        // ���� ����������� ������ ������
        int j = 0;
        for (int i = 0; i < Size; i++)
        {
            if (i != Index) { //�������� �� ������ ����� ��������� �� ����������� ��� �������� �� �������
                temp[j] = Data[i]; // ����������� �� Data � temp
                j++;
            }

        }
        delete[] Data; // �������� ������ ������
        Data = temp;   // ���������� ����� ������ �������� �������
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

    //����� ��� ���������� ������� � ������;
    void SetAddReservoir()
    {
        SetSize(GetSize() + 1);
        Reservoir obj;
        obj.Input();
        Data[GetSize() - 1] = obj;
    }

    //����� ��� �������� ������� �� �������;
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
    // ����� ��� �������� ��������� �� ������� � ������ ���� (����-����; �������-����);
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
                cout << "������ " << _Name1 << " � " << _Name2 << " ��������� � ������ ����: " << Data[a].GetTypeOfReservoir() << " = " << Data[b].GetTypeOfReservoir() << endl;
            }
            else {
                cout << "������ " << _Name1 << " � " << _Name2 << " �� ��������� � ������ ����: " << Data[a].GetTypeOfReservoir() << " != " << Data[b].GetTypeOfReservoir() << endl;
            }
        }
        else {
            cout << "������� �� �������" << endl;
        }
    }
    // ����� ��� ��������� ������� ������ ����������� �������� ������ ����;
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
                cout << "������ " << _Name1 << " � �������� " << Data[a].GetSquare() << " ������ ��� ������ " << _Name2 << " � �������� " << Data[b].GetSquare() << endl;
            }
            else if (Data[a].GetSquare() < Data[b].GetSquare()) {
                cout << "������ " << _Name1 << " � �������� " << Data[a].GetSquare() << " ������ ��� ������ " << _Name2 << " � �������� " << Data[b].GetSquare() << endl;
            }
            else {
                cout << "������� " << _Name1 << " � �������� " << Data[a].GetSquare() << " � ������ " << _Name2 << " � �������� " << Data[b].GetSquare() << " ����� " << endl;
            }
        }
        else {
            cout << "������� �� �������" << endl;
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

    cout << "\n----------����� ��� �������� ��������� �� ������� � ������ ���� (����-����; �������-����)-----------\n";
    reservoir.CheckReservoirByTypes("������", "����");

    cout << "\n----------����� ��� ��������� ������� ������ ����������� �������� ������ ����-----------\n";
    reservoir.CheckReservoirBySquare("������", "����");

    cout << "\n----------����� ��� ���������� ������� � ������-----------\n";
    reservoir.SetAddReservoir();
    reservoir.Print();

    cout << "\n----------����� ��� �������� ������� �� �������-----------\n";
    cout << "Enter reservoir num for delete his from array: ";
    int Index;
    cin >> Index;
    cin.ignore();
    reservoir.SetDelReservoir(Index);
    reservoir.Print();

    cout << "\n---------�������� ������ reservoir � reservoir2------------\n";
    CollectReservoir reservoir2 = reservoir;
    reservoir2.Print();

    cout << "\n---------�������� ������ reservoir � ����------------\n";
    string FileName; // ��� �����
    cout << "������� ��� �����: ";
    getline(cin, FileName); // ������ ����� �����
    reservoir.WriteToFile(FileName);

}
