
/*�������� �������
����: ����������
����: 43-44. ��������� �������������� ��������

������� 1.
�������� � ����� ������� ���� ���� (Stack) �������� ��������� ����������.
�� ��� ����� ����������� ���������� � ������ ������.
��������, �������� ������, ������� ���������� �� ������� �����, ������������ ����� � �.�.*/
/*
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front(); // ������� ������ ������� ������
    void push_back(T data); // ��������� ������� ������ � �����
    void clear(); //������� ������
    int GetSize() { return Size; }
    int GetCurrentSize() {
        int CurrentSize = 1;
        Node<T>* current = this->head;
        while(current->pNext != nullptr) {
            current = current->pNext; // ���������� ���� �� ��������� �� ��������� ������������ �� NULL
            CurrentSize++;
        }
        return CurrentSize;
    }
    T& operator[](const int index); // ���������� ������� ������ �� �������
    void push_front(T data); // ��������� ������� ������ � ������
    void insert(T data, int index); // ��������� ������� ������ � ��������� �����
    void removeAt(int index); //������ ������� �� ���������� �������
    void pop_back(); // ������� ��������� ������� ������

private:
    template<typename T>
    class Node {
    public:
        Node* pNext; // ��������� �� ��������� ������� ������
        T data; // ������

        Node(T data = T(), Node* pNext = nullptr) { // ��� �������� ������� �� ��������� ������ ������� ������ ��������� �� NULL
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size; // ������ ������
    Node<T>* head; // ������ ������
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}
template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    if (!GetSize()) {throw exception("���� ������!");}
    Node<T>* temp = head; // �������� ���������� ��������� �� ������� head
    head = head = head->pNext; // �������� head �� ��������� �� ���� �������
    delete temp; // �������� ������ ������� head
    Size--; // ��������� ������
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) // ���� ��� ������� ������ ��������� head
    {
        head = new Node<T>(data); // �� ������� ����� ������� ���� ����� �������� data
    }
    else {
        Node<T>* current = this->head; // ����� ���������� ��������� �� head
        while (current->pNext != nullptr) {
            current = current->pNext; // ���������� ���� �� ��������� �� ��������� ������������ �� NULL
        }
        current->pNext = new Node<T>(data); // �������������� ����� ���� ������� ����� ������� ���� ����� �������� data
    }
    Size++; //����������� Size
}

template<typename T>
void List<T>::clear()
{
    while (Size) {
        pop_front();
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    if (!GetSize()) { throw exception("������ ����� = 0!"); }
    if (GetCurrentSize()==GetSize()) { throw exception("���� ����������!"); }
    head = new Node<T>(data, head); // ������� ����� �������, ���������� ��� ��� head � �������� � �����������
                                    // "data" � ���������� head �� ������� ������ ����� �������� ����� head
    Size++; // ����������� ������
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (!GetSize()) { throw exception("������ ����� = 0!"); }
    if (GetCurrentSize() == GetSize()) { throw exception("���� ����������!"); }
    if (index > GetSize()) { throw exception("����� �� ������� �����!"); }
    if (index == 0) //���� ������ ������� �� �������� ����� ������� ��������� ��������
    {
        push_front(data);
    }
    else {
        Node<T>* previous = this->head; //  ���������� ������� head
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext; // ���� ������� �������������� ������� ���� ����� ���������
        }
        Node<T>* newNode = new Node<T>(data, previous->pNext); // ������� ������� � � ����������� ��������
                                                                // data � ��������� pNext ��������������� ��������
        previous->pNext = newNode; //  ������ ��������� � �������������� �������� �� ����� �������
        Size++;
    }

}

template<typename T>
void List<T>::removeAt(int index)
{
    if (!GetSize()) { throw exception("���� ������!"); }
    if (index > GetCurrentSize()) { throw exception("����� �� ������� �����!"); }
    if (index == 0) //���� ������ ������� �� �������� ����� �������� ��������� ��������
    {
        pop_front();
    }
    else {
        Node<T>* previous = this->head; //  ���������� ������� head
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext; // ���� ������� �������������� �������
        }
        Node<T>* toDelete = previous->pNext; // ���������� ��������� �� ��������� �������
        previous->pNext = toDelete->pNext; //  ������ ��������� � �������������� ���������� �������� �� �������� �� ���� �������
        delete toDelete; // ������� �������
        Size--;
    }

}

template<typename T>
void List<T>::pop_back()
{
    if (!GetSize()) { throw exception("���� ������!"); }
    removeAt(Size - 1); // �������� ����� �������� �� ������� � �������� ��� ��������� � ������ ������
}

int main()
{
    List<int> list;

    int size;
    cout << "������� ������ ������:";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        list.push_back(RAND(100, 1000));
    }

    cout << "size = " << list.GetSize() << endl;
    cout << endl << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "list[" << i << "] = " << list[i] << endl;
    }

    cout << endl << endl;

    try
    {
        cout << "�������� �������� ������� 333. " << endl;
        list.push_front(333);
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;
    }
    catch (const std::exception&e)
    {
        cout << "�������� ����������� �� ���� std::exception ��� push_front()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

    try
    {
        cout << "��������� ������� 444 � ������ 2.\n " << endl;
        list.insert(444, 2);
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception&e)
    {
        cout << "�������� ����������� �� ���� std::exception ��� insert()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

    try
    {
        cout << "������� ������� � ������� 10.\n" << endl;
         list.removeAt(10);
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception&e)
    {
        cout << "�������� ����������� �� ���� std::exception ��� removeAt()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

    try
    {
        cout << "������� ��������� �������.\n "<< endl;
        list.pop_back();
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception&e)
    {
        cout << "�������� ����������� �� ���� std::exception ��� pop_back()" << endl;
        cout << "e = " << e.what() << endl;
    }

    cout << endl << endl;

    try
    {
        cout << "������� ������.\n " << endl;
        list.clear();
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception& e)
    {
        cout << "�������� ����������� �� ���� std::exception ��� clear()" << endl;
        cout << "e = " << e.what() << endl;
    }

    cout << endl << endl;
    try
    {
        cout << "������� ������ �������.\n " << endl;
        list.pop_front();
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "list[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const exception& e)
    {
        cout << "�������� ����������� �� ���� std::exception ��� pop_front()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

}
*/


/*������� 2
�������� ������� ���������� �������� �� �������� ������ ��������, ���������� ������� ����� ����� � ���������� ������� ����������.
������������� ������ ������ �� ������� ��������� ������������� ����� int.
����������� �������� ����������.*/
/*
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

int StrToInt(const char* str)
{
    int oper; //���� ����� "- ��� +"
    long long res = 0; // ��������� �������� ������ � int
    int len = strlen(str);
    int start = 0;
    oper = 1;
    if (str[start] == '-') { oper = -1; } // ���������� ���� �����: "- ��� +"

    for (int i = len-1; i >= 0; i--)
    {
        if (i == 0 && str[i] == '-') { break; } // ��������� ������ ������: ���� ���� "-" �� ��������� ����
        res += (str[i] - '0') * oper;
        oper *= 10;
        cout << "res [" << i << "] = " << res << endl;
    }

    if (res < INT32_MIN || res > INT32_MAX) { throw "����� �� ������� ���������"; }

    return res;
}

void main()
{
    try {
        //cout << "res = "<< StrToInt("2147483647") << endl; //��� ����������: ����� � �������� ���������
        cout <<  "res = " <<StrToInt("2147483648") << endl; //����������: ����� �� ������� ���������
        //cout <<  "res = " <<StrToInt("-2147483649") << endl; //����������: ����� �� ������� ���������
    }
    catch (const char* e)
    {
        cout << "�������� ����������� �� ���� const char*" << endl;
        cout << "e = " << e << endl;
    }
}
*/
