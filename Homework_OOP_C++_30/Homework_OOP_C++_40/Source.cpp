/*�������� �������
21-22. �������

������� 1
����������� ����������, ����������� ������� ������ ��������.
������ ���� �������, ���������� ������� �� �������, � ������� �� ������� ���� ���� ���������.
������ ����� ������ �������� � ������� � ����������� �� ������ ����������.
���������� ��������� ���������� ������ (������������, �����) � ��������� �������.
������������� ����� ���������� �� �����.
��� ������� ���� ������ ���������� ������� � ������������ ��� �������������� ������������ �������� ������ priority_queue<> �� ���������� "queue" (#include <queue>)*/

/*
#include <iostream>
#include <iomanip>
#include <string.h>
#include <time.h>
#include <chrono>
#include <ctime>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
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
//����������
struct Stat {
    Docs docs;
};

class Print
{ //�������
    Docs* Doc;
    Stat* Statistic;
    Users* User;
    //���������
    int* Pri;
    //������������ ������ �������
    int MaxQueueLength;
    //������� ������ �������
    int QueueLength;
    //������� ������ ����������
    int StatLength;
public:
    //�����������
    Print(int m);
    //����������
    ~Print();
    //���������� ��������
    void Add(Docs d, Users u);
    //���������� �������� � ����������
    void AddStat(Docs d);
    //���������� ��������
    void Extract();
    //������� �������
    void Clear();
    //�������� ������������� ��������� � �������
    bool IsEmpty();
    //�������� �� ������������ �������
    bool IsFull();
    //���������� ��������� � �������
    int GetCount();
    //������������ �������
    void Show();
    //������������ ����������
    void ShowStatistic();
};

void Print::Show() {
    cout << "\n---------------����� �������--------------------\n";
    //������������ �������
    cout << "����.���-��" << " | " << "����.���-��" << " | " << "���-�� ���." << " | " << "��� �����." << " | " << "�����. �����." << " | " << "���� � ����� ���.� �������" << "\n";
    for (int i = 0; i < QueueLength; i++)
    {
        cout << Doc[i].docName << " \t " << Doc[i].docSize << " \t\t " << Doc[i].pageCount << " \t " << User[i].uName << " \t " << User[i].uRange << " \t\t " << Doc[i].dateTime << "\n";
    }
    cout << "\n-----------------------------------\n";
}

void Print::ShowStatistic() {
    cout << "\n---------------����� ���������� ������������� ����������--------------------\n";
    //������������ �������
    cout << "����.���-��" << " | " << "����.���-��" << " | " << "���-�� ���." << " | " << "���� � ����� ������." << "\n";
    for (int i = 0; i < StatLength; i++)
    {
        cout << Statistic[i].docs.docName << " \t " << Statistic[i].docs.docSize << " \t\t " << Statistic[i].docs.pageCount << " \t " << Statistic[i].docs.dateTime << "\n";
    }
    cout << "\n-----------------------------------\n";
}

Print::~Print()
{
    //�������� �������
    delete[]Doc;
    delete[]User;
    delete[]Statistic;
    delete[]Pri;
}
Print::Print(int m)
{
    //�������� ������
    MaxQueueLength = m;
    //������� �������
    Doc = new Docs[MaxQueueLength];
    User = new Users[MaxQueueLength];
    Statistic = new Stat[MaxQueueLength];
    Pri = new int[MaxQueueLength];
    //���������� ������� �����
    QueueLength = 0;
    //���������� ����������� �����
    StatLength = 0;
}
void Print::Clear()
{
    //������� ������� � ��������
    QueueLength = 0;
    StatLength = 0;
}
bool Print::IsEmpty()
{
    //����?
    return QueueLength == 0;
}bool Print::IsFull()
{
    //�����?
    return QueueLength == MaxQueueLength;
}
int Print::GetCount()
{
    //���������� �������������� � ����� ����������
    return QueueLength;
}
void Print::Add(Docs d, Users u)
{
    //���� � ������� ���� ��������� �����,
    //�� ����������� ����������
    //�������� � ��������� ����� ��������
    if (!IsFull()) {
        Doc[QueueLength] = d;
        User[QueueLength] = u;
        Pri[QueueLength] = u.uRange;
        QueueLength++;
    }
}

void Print::AddStat(Docs d)
{
    Statistic[StatLength].docs = d;
    // ��������� ����� ���������� � ������� �� ����� ����������
    auto end = std::chrono::system_clock::now();
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    Statistic[StatLength].docs.dateTime = ctime(&end_time);
    StatLength++;
}

void Print::Extract()
{
    //���� � ������� ���� ���������, �� �������� ���,
    //� �������� ��������� ��������� � �������� �������
    if (!IsEmpty()) {
        //������ ������� ������ ������: ������������ �������� = �������
        int max_pri = Pri[0];
        //� ������������ ������ = 0
        int pos_max_pri = 0;
        //���� ���������
        for (int i = 1; i < QueueLength; i++)
            //���� �������� ����� ������������ ��������
            if (max_pri < Pri[i]) {
                max_pri = Pri[i];
                pos_max_pri = i;
            }
        //����������� ������������ ��������
        Docs temp1 = Doc[pos_max_pri];
        int temp2 = Pri[pos_max_pri];
        cout << "���������� ��������: " << temp1.docName << ", � ����������� " << temp2 << "\n";
        //�������� ��� ���������
        for (int i = pos_max_pri; i < QueueLength - 1; i++) {
            Doc[i] = Doc[i + 1];
            User[i] = User[i + 1];
            Pri[i] = Pri[i + 1];
        }
        //��������� ���������� ����������
        QueueLength--;
        //������� ������������ ���������
        //return temp1;
        //�������� ����������� �������� � ����������
        AddStat(temp1);
    }
    else { cout << "Queue is empty!" << endl; }
}
void main()
{
    //�������� ������� ����������
    int QueueSize = 5; //���������� ����.������� ����������
    Print QUP(QueueSize);
    //���������� ����������
    for (int i = 0; i < QueueSize; i++) {
        // ��������� ������� ���������
        Docs doc;
        doc.docName = "Document_" +to_string(i);
        doc.pageCount = RAND(10, 100); //�������� ������ ��������
        doc.docSize = RAND(100, 1000);//�������� ������ ������
        auto end = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        doc.dateTime = ctime(&end_time); // ������ �����
        Sleep(1000);
        // ��������� ������� ������������
        Users user;
        user.uName = "User_" +to_string(i);
        user.uRange = RAND(0, 10); //�������� ������ ��������� ������������ �� 0 �� 10 (��� ����, ��� ������������ ������������,
                                    //������������� ��� �������� ����� ���������� ������)

        //��������� ������ �� ���������� � ������������ � �������
        QUP.Add(doc, user);
    }//����� ������� ����������
    QUP.Show();
    //���������� ����������
    for (int i = 0; i < QueueSize; i++) {
        QUP.Extract();
        //����� �������
        QUP.Show();
        Sleep(1000);
    };
    //����� ����������
    QUP.ShowStatistic();
}
*/

/*�������������� �������

������� 2
�������� ����� ������� � ������������ QueuePrior ��� ������ � ������ ����������.
��������� ������� ���������� ��� �������� �������� ��� ���������� �������:
* IsEmpty - �������� ������� �� �������
* IsFull - �������� ������� �� ����������
* Enqueue - ���������� �������� c ����������� � �������
* Dequeue  - �������� �������� � ����� ������� ����������� �� �������
* Peek - ������� ������ �������� �� ���������� ��������.
    �������� ���� ��������, ��� ������� �� ��������� �� �������.
* ������������� �������� ������ - ����������� ���� ��������� ������� �� �����.
    ��� ������ �������� ����� ���������� ���������� ���������.*/
    /*
    #include <iostream>
    #include <iomanip>
    #include <string.h>
    #include <time.h>
    #include <chrono>
    #include <ctime>
    using namespace std;
    #define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
    struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

    class QueuePriority
    {//�������
        int* Wait;
        //���������
        int* Pri;
        //������������ ������ �������
        int MaxQueueLength;
        //������� ������ �������
        int QueueLength;
    public:
        //�����������
        QueuePriority(int m);
        //����������
        ~QueuePriority();
        //�������� ������������� ��������� � �������
        bool IsEmpty();
        //�������� �� ������������ �������
        bool IsFull();
        //���������� ��������
        void Enqueue(int c, int p); //Add
        //���������� ��������
        int Dequeue (); //Extract
        //������� �������� ��� �������� � �������
        int Peek(); //Extract
        //������� �������
        void Clear();

        //���������� ��������� � �������
        int GetCount();
        //������������ �������
        friend ostream& operator<<(ostream& os, const QueuePriority& B);
    };

    ostream& operator<<(ostream& os, const QueuePriority& Q) {
        cout << "\n-----------------------------------\n";
        cout << "����� - ���������" << "\n";
        //������������ �������
        for (int i = 0; i < Q.QueueLength; i++)
        {
            cout << Q.Wait[i] << " \t " << Q.Pri[i] << "\n\n";
        }
        cout << "\n-----------------------------------\n";
        return os;
    };

    QueuePriority::~QueuePriority()
    {
        //�������� �������
        delete[]Wait;
        delete[]Pri;
    }
    QueuePriority::QueuePriority(int m)
    {
        //�������� ������
        MaxQueueLength = m;
        //������� �������
        Wait = new int[MaxQueueLength];
        Pri = new int[MaxQueueLength];
        //���������� ������� �����
        QueueLength = 0;
    }
    void QueuePriority::Clear()
    {
        //����������� "�������" �������
        QueueLength = 0;
    }
    bool QueuePriority::IsEmpty()
    {
        //����?
        return QueueLength == 0;
    }bool QueuePriority::IsFull()
    {
        //�����?
        return QueueLength == MaxQueueLength;
    }
    int QueuePriority::GetCount()
    {
        //���������� �������������� � ����� ���������
        return QueueLength;
    }
    void QueuePriority::Enqueue(int c, int p)
    {
        //���� � ������� ���� ��������� �����,
        //�� ����������� ����������
        //�������� � ��������� ����� �������
        if (!IsFull()) {
            Wait[QueueLength] = c;
            Pri[QueueLength] = p;
            QueueLength++;
        }
    }
    int QueuePriority::Dequeue()
    {
        //���� � ������� ���� ��������, �� ���������� ���,
        //� �������� ��������� ��������� � �������� �������
        if (!IsEmpty()) {
            //����� ������������ ������� - �������
            int max_pri = Pri[0];
            //� ������������ ������ = 0
            int pos_max_pri = 0;
            //���� ���������
            for (int i = 1; i < QueueLength; i++)
                //���� �������� ����� ������������ �������
                if (max_pri < Pri[i]) {
                    max_pri = Pri[i];
                    pos_max_pri = i;
                }
            //����������� ������������ �������
            int temp1 = Wait[pos_max_pri];
            int temp2 = Pri[pos_max_pri];
            //�������� ��� ��������
            for (int i = pos_max_pri; i < QueueLength - 1; i++) {
                Wait[i] = Wait[i + 1];
                Pri[i] = Pri[i + 1];
            }
            //��������� ����������
            QueueLength--;
            //������� ������������ ��������
            return temp1;
        }
        else return -1;
    }

    int QueuePriority::Peek()
    {
        //���� � ������� ���� ��������, �� ���������� ���,
        //� �������� ��������� ��������� ��� ��������
        if (!IsEmpty()) {
            //����� ������������ ������� - �������
            int max_pri = Pri[0];
            //� ������������ ������ = 0
            int pos_max_pri = 0;
            //���� ���������
            for (int i = 1; i < QueueLength; i++)
                //���� �������� ����� ������������ �������
                if (max_pri < Pri[i]) {
                    max_pri = Pri[i];
                    pos_max_pri = i;
                }
            //����������� ������������ �������
            int temp1 = Wait[pos_max_pri];
            int temp2 = Pri[pos_max_pri];
            //������� ������������ ��������
            return temp1;
        }
        else return -1;
    }


    void main()
    {
        //�������� �������
        QueuePriority QUP(25);
        //���������� ����� ���������
        for (int i = 0; i < 5; i++) {
            //�������� �� 0 �� 99 (������������)
            //� ��������� �� 0 �� 11 (������������)
            QUP.Enqueue(RAND(0, 99), RAND(0, 12));
        }//����� �������
        cout << QUP;
        //������� ������������� ��������
        cout << "������� ������������� ��������: " << QUP.Peek() << endl;
        //����� �������
        cout << QUP;
        //���������� ������������� ��������
        cout << "���������� ������������� ��������: " << QUP.Dequeue() << endl;
        //����� �������
        cout << QUP;
    }
    */

    /*������� 3
    ������������ ����� ������� � ������������ QueuePrior � ��������� �����
    */
#include <iostream>
#include <iomanip>
#include <string.h>
#include <time.h>
#include <chrono>
#include <ctime> 
#include <queue> 
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

void main()
{
    int qSize = 5;
    priority_queue<int> q;

    for (int i = 0; i < qSize; i++) {
        q.push(RAND(0, 100));
    }
    cout << "���������� ���������: " << q.size() << endl;

    cout << "������� ������������� ��������: ";
    cout << q.top() << endl;

    cout << "���������� ���������: " << q.size() << endl;
    cout << endl;
    cout << "���������� ������������� ��������: ";
    cout << "������������ �������: " << q.top() << endl;
    q.pop();
    cout << endl;
    cout << "���������� ���������: " << q.size() << endl;
    cout << endl;

    cout << "���������� ��������� ������������ ���������: " << endl;
    while (!q.empty()) {
        cout << "������������ �������: " << q.top() << " - ";
        q.pop();
        cout << "���������� ���������: " << q.size() << endl;
    }
}
