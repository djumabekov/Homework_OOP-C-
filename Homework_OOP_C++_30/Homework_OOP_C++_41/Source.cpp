
/*�������� �������
23-24. ����������� ������

������� 1
�������� ������ ������ ������������ ������� "1-������ � ������-TList1.txt":
����������� ������ ������:
  List(const List& obj) - ����������� �����������;
  List& operator=(const List& obj) - �������� �����������;
����������� ��� �������������� ��������� ������ � �����
  ostream& operator<<(ostream& os, const List<T>& obj);
��������� ����������������� ������� ������ List<>.
�
������� 2
� ������������ ����� ������������ ������ ��������:
a) ����������� �������� + (�������� ������ ���������� ����� ������ ������ ������, ����������� �������� ����� ������� ��� ������� ��������� ��������);
b) ����������� �������� * (�������� ������ ���������� ����� ������ ������ ������, ����������� ������ ����� �������� ����� ������� ��� ������� ��������� ��������)
*/
/*
#include <iostream>
#include <initializer_list>
#include <time.h>
#include <Windows.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// ������
//  ������������� ������

// ������ ��������� ������ ���� ������
template <class T>
struct Element
{
    Element<T>* next;   // ��������� �� ��������� �������
    T data;             // �������� ������
    //
    Element() : next(), data() {}
    Element(T data, Element<T>* next = nullptr)
        :data(data), next(next) {}
    Element<T>* GetNext() { return next; }
    void SetNext(Element<T>* other) { next = other; }
    void SetData(T data) { this->data = data; }
    T GetData() { return data; }
};

// ������ ������ ������������ ������
template <class T>
class List
{
private:
    Element<T>* head, * tail; // ��������� �� �������� � ������� �������� ������
    int cnt; // ������� ���������� ����� � ������
public:
    List() : head(), tail(), cnt() {
        //cout << "����������� ��������" << endl;
    }
    List(const T& val) :List() {
        AddHead(val);
    } // ����-��� ����� ���������
    List(initializer_list<T> mas) {
        //cout << "�����������" << endl;
        for (auto a : mas) { AddTail(a); }
        //for (T a : mas) { AddTail(a); }


    }// ����-��� �������
    List(const T* mas, int size) : List() {
        for (int i = 0; i < size; i++)
        {
            AddTail(mas[i]);
        }
    }  // ����-��� ��������

    List(const List& obj):List() {
        //cout << "����������� ����������� ��������" << endl;
        *this = obj;
    };
    List& operator=(const List& obj) {
        //cout << "�������� ����������� ��������" << endl;
        if (this != &obj) {
            for (int i = 0; i < obj.GetCnt(); i++) {
                this->Insert(obj.Get(i), i);
            }
            this->cnt = obj.GetCnt();
        }
        return *this;
    };


    ~List() {
       // cout << "���������� ��������" << endl;
        Clear(); }
    // ������� ���� - ������� ���� ��������� ������
    void Clear() {
        while (cnt) {
            DeleteHead();
        }
    }

    // �������� ����� ������� � ������ ������
    //  ������ ������ list<T>::push_front();
    void AddHead(const T& val);

    // �������� ����� ������� � ����� ������
    //  ������ ������ list<T>::push_back();
    void AddTail(const T& val);

    // ������� �������� �������
    //  ������ ������ list<T>::pop_front();
    void DeleteHead();

    // ������� ��������� �������
    //  ������ ������ list<T>::pop_back();
    void DeleteTail();

    // �������� ������� � ������ � ��������� ������� index
    void Insert(const T& val, int index);

    // �������� ������� ���-�� ����� � ������
    int GetCnt() const { return cnt; }

    // �������� �������� ���� �� ��������� �������
    T Get(int index = 0) const {
        if (index > -1 && index < cnt) {
            Element<T>* other = head;
            for (int i = 0; i < index; i++) {
                other = other->next;
            }
            return other->data;
        }
        //throw exception("uncorrect index");
        throw 1;
    }
    // ������������� ��������� ���������� []
    T& operator[](int index) const {
        return Get(index);
    } // ��� ������
    T& operator[](int index) { return Get(index); } // ��� ������ (���������)

    // ����� ���� � �������� ���������
    // ���������� ������ ���������� ���� ��� -1 � ��������� ������
    int Search(const T& val) {
        Element<T>* temp = head;
        for (int i = 0; i < cnt; i++) {
            if (temp->data == val) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    template <class T>
    friend ostream& operator<<(ostream& os, const List<T>& obj);

    template <class T>
    List<T> operator+(const List<T>& obj) const {
        List<T> newList;
        if (this != &obj) {
            newList = *this;
            for (int i = this->GetCnt(), j = 0; i < this->GetCnt() + obj.GetCnt(); i++, j++) {
                newList.Insert(obj.Get(j), i);
                //cout << " newList.Get(" << i << ")  = " << newList.Get(i) << endl;
            }
        }
        return newList;
    };

    template <class T>
    List<T> operator*(const List<T>& obj) const {
        List<T> newList;
        if (this != &obj) {
            int minSize = (this->GetCnt() < obj.GetCnt()) ? this->GetCnt() : obj.GetCnt();
            for (int i = 0, j = 0; i < minSize; i++) {
                if (this->Get(i) == obj.Get(i)) {
                    newList.Insert(obj.Get(i), j);
                    j++;
                    //cout << " newList.Get(" << i << ")  = " << newList.Get(i) << endl;
                }
            }
        }
        return newList;
    };

};


template <class T>
ostream& operator<<(ostream& os, const List<T>& obj)
{
    os << "Size = " << obj.GetCnt() << endl;
    for (int i = 0; i < obj.GetCnt(); i++) {
        os << i + 1 << ") " << obj.Get(i) << endl;
    }
    return os;
}


// �������� ����� ������� � ������ ������
//  ������ ������ list<T>::push_front();
template <class T>
void List<T>::AddHead(const T& val)
{
    Element<T>* newel = new Element<T>(val);
    if (!cnt) {
        head = tail = newel;
    }
    else {
        newel->next = head;
        head = newel;
    }
    cnt++;
}

// �������� ����� ������� � ����� ������
//  ������ ������ list<T>::push_back();
template <class T>
void List<T>::AddTail(const T& val)
{
    Element<T>* newel = new Element<T>(val);
    if (!cnt) {
        head = tail = newel;
    }
    else {
        tail->next = newel;
        tail = newel;
    }
    cnt++;

}

// ������� �������� �������
//  ������ ������ list<T>::pop_front();
template <class T>
void List<T>::DeleteHead()
{
    if (cnt) {
        Element<T>* temp = head->next;
        delete head;
        head = temp;
        //cnt--;
        if (!--cnt) { tail = nullptr; }
    }
    else {
        cout << "\nlist's empty\n";
    }


}

// ������� ��������� �������
//  ������ ������ list<T>::pop_back();
template <class T>
void List<T>::DeleteTail()
{
    if (cnt) {
        Element<T>* temp = head;
        for (int i = 0; i < cnt - 2; i++) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        if (!--cnt) {
            head = tail = nullptr;
        }
        else {
            tail->next = nullptr;
        }
    }
    else {
        cout << "\n list's empty\n";
    }
}

// �������� ������� � ������ � ��������� ������� index
template <class T>
void List<T>::Insert(const T& val, int index)
{
    if (index == 0) { AddHead(val); }
    else if (index == cnt) { AddTail(val); }
    else if (index > 0 && index < cnt)
    {
        Element<T>* newel = new Element<T>(val);
        Element<T>* count = head;
        Element<T>* next = nullptr;
        for (int i = 0; i < index - 1; i++) {
            count = head->next;
        }
        next = count->next;
        count->next = newel;
        newel->next = next;
        //swap(newel, count->next);
        //count->next->next = newel;
        cnt++;
    }
    else {
        cout << "\nout of range\n";
        //throw out_of_range("out of range")
    }
}


int main()
{
    cout << "������ A: " << endl;
    List<string> A("First value");
    string s = "Second value";
    A.AddHead(s);
    s = "Third value";
    A.AddTail(s);
    s = "Fourth value";
    A.Insert(s, 1);
    cout << A << endl;
    cout << endl;

    cout << "������ �: " << endl;
    List<string> B;
    B = A;
    cout << B << endl;

    cout << "������ A + �: " << endl;
    cout << (A + B) << endl;

    List<string> C("First value"); //����� ��������
    s = "Sixth value";
    C.AddHead(s);
    s = "Third value"; //����� ��������
    C.AddTail(s);
    s = "Eighth value";
    C.Insert(s, 1);
    cout << "������ A * C: " << endl;
    cout << (A * C) << endl;
}
*/

#include <iostream>
#include <initializer_list> // STL C++ ==> class initializer_list<>
#include <string>  // STL C++ ==> class string
#include <fstream>
#include <stack>   // STL C++ ==> class stack<>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
������� 2
���������� ���� � ���� ������������ ������.
��������� ����������� �������� �������� �� ������ �� ������.
��� ������������ ����� ����� ����������� ��� ������.
*/
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
    head = new Node<T>(data, head); // ������� ����� �������, ���������� ��� ��� head � �������� � �����������  
                                    // "data" � ���������� head �� ������� ������ ����� �������� ����� head
    Size++; // ����������� ������
}

template<typename T>
void List<T>::insert(T data, int index)
{
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
    removeAt(Size - 1); // �������� ����� �������� �� ������� � �������� ��� ��������� � ������ ������
}

int main()
{
    List<int> list;

    int Size;
    cout << "������� ������ ������:";
    cin >> Size;

    for (int i = 0; i < Size; i++)
    {
        list.push_back(RAND(100, 1000));
    }

    cout << "Size = " << list.GetSize() << endl;

    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.pop_front();
    cout << "������� ������ �������.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.push_front(333);
    cout << "�������� �������� ������� 333.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.insert(444, 2);
    cout << "��������� ������� 444 � ������ 2.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.removeAt(2);
    cout << "������� ������� 444 � ������� 2.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.pop_back();
    cout << "������� ��������� �������.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.clear();
    cout << "������� ������.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }
}
