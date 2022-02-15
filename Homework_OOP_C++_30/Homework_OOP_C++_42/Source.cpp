/*�������� ������
25-26. ���������� ������

������� 1.
����������� ��������� ����� "������� � ������������" �� ������ ����������� ������.
*/

/*
 ��������� ������������ ������
  class TList
*/
/*
template <class T>
struct Node {
    // ������� �������� ������
    T Data;

    // ������� ������ �� ��������� ��������
    Node<T>* pNext; // ��������� �� ��������� �������
    Node<T>* pPrev; // ��������� �� ���������� �������
    //
    Node() : Data(), pNext(nullptr), pPrev(nullptr) {}
    Node(T data) : Data(data), pNext(), pPrev() {} //��������� �� ������� ������
    Node(T data, Node<T>* next, Node<T>* prev) //������������� ����������
        : Data(data), pNext(next), pPrev(prev) {}

    Node<T>* GetNext() { return pNext; }
    void  SetNext(Node<T>* next) { pNext = next; }
    Node<T>* GetPrev() { return pPrev; }
    void  SetPrev(Node<T>* prev) { pPrev = prev; }
};

template <class T>
class TList {

    Node<T>* Head; // ������ ������
    Node<T>* Tail; // ����� ������
    int       cnt;  // ���-�� ��������� � ������

public:
    TList() : Head(nullptr), Tail(nullptr), cnt() {}
    TList(const T& Val) : TList() { AddHead(Val); } // AddTail(Val);
    TList(const TList<T>& V) : TList() { *this = V; }
    TList<T>& operator=(const TList<T>& V)
    {
        Node<T>* temp = V.Head;
        for (int i = 0; i < V.cnt; i++)
        {
            //AddTail(temp->Data);  //������ �������
            //temp = temp->pNext;   //������� ��� ������ �������
            AddTail(V.GetAt(i));    //������ �������
        }
        return *this;
    }
    ~TList() { Clear(); }

    Node<T>* GetNode(int idx)
    {
        if (idx < 0 || idx >= cnt) { return nullptr; }
        Node<T>* temp = GetHead();
        for (int i = 0; i < idx; i++)
        {
            temp = temp->pNext;
        }
        return temp;
    }

    Node<T>* GetHead() { return Head; }
    Node<T>* GetTail() { return Tail; }
    Node<T>* NewNode(const T& data) { return new Node<T>(data); }

    bool isEmpty() { return Head == nullptr; }

    void AddTail(const T& data)  // void push_back(const T& data);
    {
        Node<T>* newNode = NewNode(data); //������� ����� ����
        if (isEmpty()) { Head = Tail = newNode; }
        else
        {
            Tail->pNext = newNode;
            newNode->pPrev = Tail;
            Tail = newNode;
        }
        cnt++;
    }
    void AddHead(const T& data)  // void push_front(const T& data);
    {
        Node<T>* newNode = NewNode(data);
        if (isEmpty()) { Head = Tail = newNode; }
        else
        {
            Head->pPrev = newNode;
            newNode->pNext = Head;
            Head = newNode;
        }
        cnt++;
    }
    void Insert(const T& data, int idx)
    {
        if (idx == 0) { AddHead(data); }
        else if (idx == cnt) { AddTail(data); }
        else
        {
            Node<T>* Next = GetNode(idx);
            if (Next != nullptr)
            {
                Node<T>* newNode = NewNode(data);
                Node<T>* Prev = Next->pPrev;

                newNode->pNext = Next;
                newNode->pPrev = Prev;
                Prev->pNext = newNode;
                Next->pPrev = newNode;
                cnt++;
            }
            else { cout << "Error! Out of range!\n"; }
        }
    }
    void Delete(int idx)
    {
        Node<T>* toDelete = GetNode(idx);
        if (toDelete)
        {
            Node<T>* Prev = toDelete->pPrev;
            Node<T>* Next = toDelete->pNext;
            if (Prev) { Prev->pNext = Next; }
            else { Head = Next; }
            if (Next) { Next->pPrev = Prev; }
            else { Tail = Prev; }
            delete toDelete;
            cnt--;
        }
        else { cout << "Error! Out of range!\n"; }
    }
    T& GetAt(int idx)
    {
        Node<T>* temp = GetNode(idx);
        if (temp) { return temp->Data; }
        throw "Exception! out of range!";
    }
    //const T&   operator[](int idx) const;
    //T&   operator[](int idx);
    int  GetCnt()const { return cnt; }

    int  Search(const T& data)
    {
        Node<T>* temp = Head;
        for (int i = 0; i < cnt; i++)
        {
            if (temp->Data == data) { return i; }
            temp = temp->pNext;
        }
        return -1;
    }
    void Clear() { while (Head) { Delete(0); } }




int Dequeue()
{
    //���� � ������� ���� ��������, �� ���������� ���,
    //� �������� ��������� ��������� � �������� �������
    if (!isEmpty()) {
        //����� ������������ ������� - �������
        Node<T>* temp = Head;
        int max_pri = 0;
        //� ������������ ������ = 0
        int idx = 0;
        //���� ���������
        for (int i = 0; i < cnt; i++) {
            //���� �������� ����� ������������ �������
            if (max_pri < temp->Data) {
                max_pri = temp->Data;
                idx = i;
            }
            temp = temp->pNext;

        }
        //����������� ������������ �������
        int data = GetAt(idx);
        //�������� ��� ��������
        Delete(idx);
        //������� ������������ ��������
        return data;
    }
    else return -1;
}

int Peek()
{
    //���� � ������� ���� ��������, �� ���������� ���,
    //� �������� ��������� ��������� ��� ��������
    if (!isEmpty()) {
        //����� ������������ ������� - �������
        Node<T>* temp = Head;
        int max_pri = 0;
        //� ������������ ������ = 0
        int idx = 0;
        //���� ���������
        for (int i = 0; i < cnt; i++) {
            //���� �������� ����� ������������ �������
            if (max_pri < temp->Data) {
                max_pri = temp->Data;
                idx = i;
            }
            temp = temp->pNext;

        }
        //����������� ������������ �������
        int data = GetAt(idx);
        //������� ������������ ��������
        return data;
    }
    else return -1;
}
}; // class TList

template <class T>
ostream& operator<<(ostream& os, TList<T>& obj)
{
    cout << "List size: " << obj.GetCnt() << endl;
    for (int i = 0; i < obj.GetCnt(); i++)
    {
        os << obj.GetAt(i) << endl;
    }
    cout << endl;
    return os;
}


#include <iostream>
#include <initializer_list>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// ������
//  ������������ ������

int main()
{
    TList<int> A;

    int size = 10; // ������� �� 10 ���������
    for (int i = 0; i < size; i++)
    {
        A.Insert(RAND(1, 100), i);  // ��������� ���������� � ������� �� �������� � ��������
    }
    cout << A << endl;

    cout << "������������ ������� (��� ���������� �� �������): " << A.Peek() << endl;

    cout << A << endl;

    cout << "������������ ������� (� ����������� �� �������): " << A.Dequeue() << endl;

    cout << A << endl;
}
*/

/*������� 2.
����������� ����������, ����������� ������� ������ ��������.
������� ������ ���� ����������� � ������� ����������� ������.
������ ���� �������, ���������� ������� �� �������, � ������� �� ������� ���� ���� ���������.
������ ����� ������ �������� � ������� � ����������� �� ������ ����������.
���������� ��������� ���������� ������ (������������, �����) � ��������� �������.
������������� ����� ���������� �� �����.*/


#include <iostream>
#include <initializer_list>
#include <time.h>
#include <chrono>
#include <ctime> 
#include <vector> 
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

//������������
struct Users {
    string uName;
    int uRange;
};
//���������
struct Docs {
    string docName;
    int pageCount;
    float docSize;
    string dateTime;
};

struct _Data {

    Users user;
    Docs doc;
};
//����������
struct Stats {
    _Data Data;
};

struct Node {
    // ������� �������� ������
    _Data Data;
    // ������� ������ �� ��������� ��������
    Node* pNext; // ��������� �� ��������� �������
    Node* pPrev; // ��������� �� ���������� �������
    //
    Node() : Data(), pNext(nullptr), pPrev(nullptr) {}
    Node(_Data data) : Data(data), pNext(), pPrev() {} //��������� �� ������� ������
    Node(_Data data, Node* next, Node* prev) //������������� ����������
        : Data(data), pNext(next), pPrev(prev) {}

    Node* GetNext() { return pNext; }
    void  SetNext(Node* next) { pNext = next; }
    Node* GetPrev() { return pPrev; }
    void  SetPrev(Node* prev) { pPrev = prev; }
};

class TList {

    Node* Head; // ������ ������
    Node* Tail; // ����� ������
    int       cnt;  // ���-�� ��������� � ������
    vector <Stats> stat;
public:
    TList() : Head(nullptr), Tail(nullptr), cnt(), stat() {}
    TList(const _Data& Val) : TList() { AddHead(Val); }
    ~TList() { Clear(); }

    Node* GetNode(int idx)
    {
        if (idx < 0 || idx >= cnt) { return nullptr; }
        Node* temp = GetHead();
        for (int i = 0; i < idx; i++)
        {
            temp = temp->pNext;
        }
        return temp;
    }

    Node* GetHead() { return Head; }
    Node* GetTail() { return Tail; }
    Node* NewNode(const _Data& data) { return new Node(data); }

    bool isEmpty() { return Head == nullptr; }

    void AddTail(const _Data& data)  // void push_back(const T& data);
    {
        Node* newNode = NewNode(data); //������� ����� ����
        if (isEmpty()) { Head = Tail = newNode; }
        else
        {
            Tail->pNext = newNode;
            newNode->pPrev = Tail;
            Tail = newNode;
        }
        cnt++;
    }
    void AddHead(const _Data& data)  // void push_front(const T& data);
    {
        Node* newNode = NewNode(data);
        if (isEmpty()) { Head = Tail = newNode; }
        else
        {
            Head->pPrev = newNode;
            newNode->pNext = Head;
            Head = newNode;
        }
        cnt++;
    }
    void Insert(const _Data& data, int idx)
    {
        if (idx == 0) { AddHead(data); }
        else if (idx == cnt) { AddTail(data); }
        else
        {
            Node* Next = GetNode(idx);
            if (Next != nullptr)
            {
                Node* newNode = NewNode(data);
                Node* Prev = Next->pPrev;

                newNode->pNext = Next;
                newNode->pPrev = Prev;
                Prev->pNext = newNode;
                Next->pPrev = newNode;
                cnt++;
            }
            else { cout << "Error! Out of range!\n"; }
        }
    }
    void Delete(int idx)
    {
        Node* toDelete = GetNode(idx);
        if (toDelete)
        {
            Node* Prev = toDelete->pPrev;
            Node* Next = toDelete->pNext;
            if (Prev) { Prev->pNext = Next; }
            else { Head = Next; }
            if (Next) { Next->pPrev = Prev; }
            else { Tail = Prev; }
            delete toDelete;
            cnt--;
        }
        else { cout << "Error! Out of range!\n"; }
    }
    _Data& GetAt(int idx)
    {
        Node* temp = GetNode(idx);
        if (temp) { return temp->Data; }
        throw "Exception! out of range!";
    }
    int  GetCnt()const { return cnt; }

    int  Search(const _Data& data)
    {
        Node* temp = Head;
        for (int i = 0; i < cnt; i++)
        {
            if (temp->Data.doc.docName == data.doc.docName) { return i; }
            temp = temp->pNext;
        }
        return -1;
    }
    void Clear() { while (Head) { Delete(0); } }

    void AddStat(const _Data& data)
    {
        Stats tmp;
        tmp.Data = data;
        // ��������� ����� ���������� � ������� �� ����� ����������
        auto end = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        tmp.Data.doc.dateTime = ctime(&end_time);
        stat.push_back(tmp);
    }

    void  ShowStat() {
        cout << "\n---------------����� ���������� ������������� ����������--------------------\n";
        //������������ �������
        cout << "����.���-��" << " | " << "����.���-��" << " | " << "���-�� ���." << " | " << "�����." << " | " << "���� � ����� ������." << "\n";
        for (int i = 0; i < stat.size(); i++)
        {
            cout << stat[i].Data.doc.docName << " \t " << stat[i].Data.doc.docSize << " \t\t " << stat[i].Data.doc.pageCount << "\t" << stat[i].Data.user.uName << " \t " << stat[i].Data.doc.dateTime << "\n";
        }
        cout << "\n-----------------------------------\n";
    }

    _Data Dequeue()
    {
        //���� � ������� ���� ��������, �� ���������� ���,
        //� �������� ��������� ��������� � �������� �������
        if (!isEmpty()) {
            //����� ������������ ������� - �������
            Node* temp = Head;
            int max_pri = 0;
            //� ������������ ������ = 0
            int idx = 0;
            //���� ���������
            for (int i = 0; i < cnt; i++) {
                //���� �������� ����� ������������ �������
                if (max_pri < temp->Data.user.uRange) {
                    max_pri = temp->Data.user.uRange;
                    idx = i;
                }
                temp = temp->pNext;

            }
            //����������� ������������ �������
            _Data data = GetAt(idx);
            //�������� ������������� �������� � ����������
            AddStat(data);
            //��������� �������
            Delete(idx);
            //������� ������������ ��������
            return data;
        }
        else { cout << "Error! List is empty!\n"; }
    }

    _Data Peek()
    {
        //���� � ������� ���� ��������, �� ���������� ���,
        //� �������� ��������� ��������� ��� ��������
        if (!isEmpty()) {
            //����� ������������ ������� - �������
            Node* temp = Head;
            int max_pri = 0;
            //� ������������ ������ = 0
            int idx = 0;
            //���� ���������
            for (int i = 0; i < cnt; i++) {
                //���� �������� ����� ������������ �������
                if (max_pri < temp->Data.user.uRange) {
                    max_pri = temp->Data.user.uRange;
                    idx = i;
                }
                temp = temp->pNext;

            }
            //����������� ������������ �������
            _Data data = GetAt(idx);
            //������� ������������ ��������
            return data;
        }
        else { cout << "Error! List is empty!\n"; }
    }
}; // class TList

ostream& operator<<(ostream& os, TList& obj)
{
    cout << "List size: " << obj.GetCnt() << endl;
    //������������ �������
    cout << "����.���-��" << " | " << "����.���-��" << " | " << "���-�� ���." << " | " << "��� �����." << " | " << "�����. �����." << " | " << "���� � ����� ���.� �������" << "\n";
    for (int i = 0; i < obj.GetCnt(); i++) {
        os << obj.GetAt(i).doc.docName << " \t " << obj.GetAt(i).doc.docSize << " \t\t " << obj.GetAt(i).doc.pageCount << " \t " << obj.GetAt(i).user.uName << " \t " << obj.GetAt(i).user.uRange << " \t\t " << obj.GetAt(i).doc.dateTime << "\n";
    }
    cout << "\n-----------------------------------\n";
    return os;
}


int main()
{
    TList A;

    int size = 10; // ������� �� 10 ���������
    cout << "��������� ������� �� ������..." << endl;
    for (int i = 0; i < size; i++)
    {
        _Data d;
        d.doc.docName = "Document_" + to_string(i);
        d.doc.pageCount = RAND(10, 100); //�������� ������ ��������
        d.doc.docSize = RAND(100, 1000);//�������� ������ ������
        auto end = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        d.doc.dateTime = ctime(&end_time); // ������ �����
        Sleep(1000);
        // ��������� ������� ������������
        d.user.uName = "User_" + to_string(i);
        d.user.uRange = RAND(0, 10); //�������� ������ ��������� ������������ �� 0 �� 10 (��� ����, ��� ������������ ������������,
                                    //������������� ��� �������� ����� ���������� ������)

        //��������� ������ �� ���������� � ������������ � �������
        A.Insert(d, i);  // ��������� �������
    }
    cout << endl << A << endl;

    _Data tmp;
    tmp = A.Peek();
    cout << "������������ ������� (��� ���������� �� �������): " << tmp.doc.docName << ", � ����������� ������������: " << tmp.user.uRange << endl;
    cout << endl << A << endl;

    //����������� 3 ������������ ���-�� �� �������
    for (int i = 0; i < 3; i++)
    {
        tmp = A.Dequeue();
        cout << "������������ ������� (� �����������-����������� �� �������): " << tmp.doc.docName << ", � ����������� ������������: " << tmp.user.uRange << endl;
    }
    cout << endl << A << endl;

    //������� ����������
    A.ShowStat();
}
