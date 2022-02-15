/*Домашнее задание
21-22. Очередь

Задание 1
Разработать приложение, имитирующее очередь печати принтера.
Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
Каждый новый клиент попадает в очередь в зависимости от своего приоритета.
Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
Предусмотреть вывод статистики на экран.
Для решения этой задачи реализуйте очередь с приоритетами или воспользуйтесь библиотечным шаблоном класса priority_queue<> из библиотеки "queue" (#include <queue>)*/

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

//Пользователи
struct Users {
    string uName;
    int uRange;
};
//Документы
struct Docs {
    string docName;
    int pageCount;
    float docSize;
    string dateTime;
};
//Статистика
struct Stat {
    Docs docs;
};

class Print
{ //Очередь
    Docs* Doc;
    Stat* Statistic;
    Users* User;
    //Приоритет
    int* Pri;
    //Максимальный размер очереди
    int MaxQueueLength;
    //Текущий размер очереди
    int QueueLength;
    //Текущий размер статистики
    int StatLength;
public:
    //Конструктор
    Print(int m);
    //Деструктор
    ~Print();
    //Добавление элемента
    void Add(Docs d, Users u);
    //Добавление элемента в статистику
    void AddStat(Docs d);
    //Извлечение элемента
    void Extract();
    //Очистка очереди
    void Clear();
    //Проверка существования элементов в очереди
    bool IsEmpty();
    //Проверка на переполнение очереди
    bool IsFull();
    //Количество элементов в очереди
    int GetCount();
    //демонстрация очереди
    void Show();
    //демонстрация статистики
    void ShowStatistic();
};

void Print::Show() {
    cout << "\n---------------Показ очереди--------------------\n";
    //демонстрация очереди
    cout << "Назв.док-та" << " | " << "Разм.док-та" << " | " << "Кол-во стр." << " | " << "Имя польз." << " | " << "Приор. польз." << " | " << "Дата и время доб.в очередь" << "\n";
    for (int i = 0; i < QueueLength; i++)
    {
        cout << Doc[i].docName << " \t " << Doc[i].docSize << " \t\t " << Doc[i].pageCount << " \t " << User[i].uName << " \t " << User[i].uRange << " \t\t " << Doc[i].dateTime << "\n";
    }
    cout << "\n-----------------------------------\n";
}

void Print::ShowStatistic() {
    cout << "\n---------------Показ статистики распечатанных документов--------------------\n";
    //демонстрация очереди
    cout << "Назв.док-та" << " | " << "Разм.док-та" << " | " << "Кол-во стр." << " | " << "Дата и время распеч." << "\n";
    for (int i = 0; i < StatLength; i++)
    {
        cout << Statistic[i].docs.docName << " \t " << Statistic[i].docs.docSize << " \t\t " << Statistic[i].docs.pageCount << " \t " << Statistic[i].docs.dateTime << "\n";
    }
    cout << "\n-----------------------------------\n";
}

Print::~Print()
{
    //удаление очереди
    delete[]Doc;
    delete[]User;
    delete[]Statistic;
    delete[]Pri;
}
Print::Print(int m)
{
    //получаем размер
    MaxQueueLength = m;
    //создаем очередь
    Doc = new Docs[MaxQueueLength];
    User = new Users[MaxQueueLength];
    Statistic = new Stat[MaxQueueLength];
    Pri = new int[MaxQueueLength];
    //Изначально очередь пуста
    QueueLength = 0;
    //Изначально стастистика пуста
    StatLength = 0;
}
void Print::Clear()
{
    //очистка очереди и стастики
    QueueLength = 0;
    StatLength = 0;
}
bool Print::IsEmpty()
{
    //Пуст?
    return QueueLength == 0;
}bool Print::IsFull()
{
    //Полон?
    return QueueLength == MaxQueueLength;
}
int Print::GetCount()
{
    //Количество присутствующих в стеке документов
    return QueueLength;
}
void Print::Add(Docs d, Users u)
{
    //Если в очереди есть свободное место,
    //то увеличиваем количество
    //значений и вставляем новый документ
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
    // обновляем время постановки в очередь на время распечатки
    auto end = std::chrono::system_clock::now();
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    Statistic[StatLength].docs.dateTime = ctime(&end_time);
    StatLength++;
}

void Print::Extract()
{
    //Если в очереди есть документы, то печатаем тот,
    //у которого наивысший приоритет и сдвигаем очередь
    if (!IsEmpty()) {
        //задаем позицию начала поиска: приоритетный документ = нулевой
        int max_pri = Pri[0];
        //а приоритетный индекс = 0
        int pos_max_pri = 0;
        //ищем приоритет
        for (int i = 1; i < QueueLength; i++)
            //если встречен более приоритетный документ
            if (max_pri < Pri[i]) {
                max_pri = Pri[i];
                pos_max_pri = i;
            }
        //вытаскиваем приоритетный документ
        Docs temp1 = Doc[pos_max_pri];
        int temp2 = Pri[pos_max_pri];
        cout << "Распечатан документ: " << temp1.docName << ", с приоритетом " << temp2 << "\n";
        //сдвинуть все документы
        for (int i = pos_max_pri; i < QueueLength - 1; i++) {
            Doc[i] = Doc[i + 1];
            User[i] = User[i + 1];
            Pri[i] = Pri[i + 1];
        }
        //уменьшаем количество документов
        QueueLength--;
        //возврат извлеченного документа
        //return temp1;
        //передаем извлеченный документ в статистику
        AddStat(temp1);
    }
    else { cout << "Queue is empty!" << endl; }
}
void main()
{
    //создание очереди документов
    int QueueSize = 5; //количество макс.очереди документов
    Print QUP(QueueSize);
    //заполнение документов
    for (int i = 0; i < QueueSize; i++) {
        // заполняем объекты документы
        Docs doc;
        doc.docName = "Document_" +to_string(i);
        doc.pageCount = RAND(10, 100); //рандомно задаем страницы
        doc.docSize = RAND(100, 1000);//рандомно задаем размер
        auto end = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        doc.dateTime = ctime(&end_time); // задаем время
        Sleep(1000);
        // заполняем объекты пользователи
        Users user;
        user.uName = "User_" +to_string(i);
        user.uRange = RAND(0, 10); //рандомно задаем приоритет пользователя от 0 до 10 (чем выше, тем приоритетнее пользователь,
                                    //соотвественно его документ будет распечатан первым)

        //добавляем данные по документам и пользвателям в очередь
        QUP.Add(doc, user);
    }//показ очереди документов
    QUP.Show();
    //извлечение документов
    for (int i = 0; i < QueueSize; i++) {
        QUP.Extract();
        //показ очереди
        QUP.Show();
        Sleep(1000);
    };
    //показ статистики
    QUP.ShowStatistic();
}
*/

/*Дополнительные задания

Задание 2
Создайте класс очереди с приоритетами QueuePrior для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами очереди:
* IsEmpty - проверка очереди на пустоту
* IsFull - проверка очереди на заполнение
* Enqueue - добавление элемента c приоритетом в очередь
* Dequeue  - удаление элемента с самым высоким приоритетом из очереди
* Peek - возврат самого большого по приоритету элемента.
    Обращаем ваше внимание, что элемент не удаляется из очереди.
* перегруженный оператор вывода - отображение всех элементов очереди на экран.
    При показе элемента также необходимо отображать приоритет.*/
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
    {//Очередь
        int* Wait;
        //Приоритет
        int* Pri;
        //Максимальный размер очереди
        int MaxQueueLength;
        //Текущий размер очереди
        int QueueLength;
    public:
        //Конструктор
        QueuePriority(int m);
        //Деструктор
        ~QueuePriority();
        //Проверка существования элементов в очереди
        bool IsEmpty();
        //Проверка на переполнение очереди
        bool IsFull();
        //Добавление элемента
        void Enqueue(int c, int p); //Add
        //Извлечение элемента
        int Dequeue (); //Extract
        //Возврат элемента без удаления с очереди
        int Peek(); //Extract
        //Очистка очереди
        void Clear();

        //Количество элементов в очереди
        int GetCount();
        //демонстрация очереди
        friend ostream& operator<<(ostream& os, const QueuePriority& B);
    };

    ostream& operator<<(ostream& os, const QueuePriority& Q) {
        cout << "\n-----------------------------------\n";
        cout << "Номер - Приоритет" << "\n";
        //демонстрация очереди
        for (int i = 0; i < Q.QueueLength; i++)
        {
            cout << Q.Wait[i] << " \t " << Q.Pri[i] << "\n\n";
        }
        cout << "\n-----------------------------------\n";
        return os;
    };

    QueuePriority::~QueuePriority()
    {
        //удаление очереди
        delete[]Wait;
        delete[]Pri;
    }
    QueuePriority::QueuePriority(int m)
    {
        //получаем размер
        MaxQueueLength = m;
        //создаем очередь
        Wait = new int[MaxQueueLength];
        Pri = new int[MaxQueueLength];
        //Изначально очередь пуста
        QueueLength = 0;
    }
    void QueuePriority::Clear()
    {
        //Эффективная "очистка" очереди
        QueueLength = 0;
    }
    bool QueuePriority::IsEmpty()
    {
        //Пуст?
        return QueueLength == 0;
    }bool QueuePriority::IsFull()
    {
        //Полон?
        return QueueLength == MaxQueueLength;
    }
    int QueuePriority::GetCount()
    {
        //Количество присутствующих в стеке элементов
        return QueueLength;
    }
    void QueuePriority::Enqueue(int c, int p)
    {
        //Если в очереди есть свободное место,
        //то увеличиваем количество
        //значений и вставляем новый элемент
        if (!IsFull()) {
            Wait[QueueLength] = c;
            Pri[QueueLength] = p;
            QueueLength++;
        }
    }
    int QueuePriority::Dequeue()
    {
        //Если в очереди есть элементы, то возвращаем тот,
        //у которого наивысший приоритет и сдвигаем очередь
        if (!IsEmpty()) {
            //пусть приоритетный элемент - нулевой
            int max_pri = Pri[0];
            //а приоритетный индекс = 0
            int pos_max_pri = 0;
            //ищем приоритет
            for (int i = 1; i < QueueLength; i++)
                //если встречен более приоритетный элемент
                if (max_pri < Pri[i]) {
                    max_pri = Pri[i];
                    pos_max_pri = i;
                }
            //вытаскиваем приоритетный элемент
            int temp1 = Wait[pos_max_pri];
            int temp2 = Pri[pos_max_pri];
            //сдвинуть все элементы
            for (int i = pos_max_pri; i < QueueLength - 1; i++) {
                Wait[i] = Wait[i + 1];
                Pri[i] = Pri[i + 1];
            }
            //уменьшаем количество
            QueueLength--;
            //возврат извлеченного элемента
            return temp1;
        }
        else return -1;
    }

    int QueuePriority::Peek()
    {
        //Если в очереди есть элементы, то возвращаем тот,
        //у которого наивысший приоритет без удаления
        if (!IsEmpty()) {
            //пусть приоритетный элемент - нулевой
            int max_pri = Pri[0];
            //а приоритетный индекс = 0
            int pos_max_pri = 0;
            //ищем приоритет
            for (int i = 1; i < QueueLength; i++)
                //если встречен более приоритетный элемент
                if (max_pri < Pri[i]) {
                    max_pri = Pri[i];
                    pos_max_pri = i;
                }
            //вытаскиваем приоритетный элемент
            int temp1 = Wait[pos_max_pri];
            int temp2 = Pri[pos_max_pri];
            //возврат извлеченного элемента
            return temp1;
        }
        else return -1;
    }


    void main()
    {
        //создание очереди
        QueuePriority QUP(25);
        //заполнение части элементов
        for (int i = 0; i < 5; i++) {
            //значения от 0 до 99 (включительно)
            //и приоритет от 0 до 11 (включительно)
            QUP.Enqueue(RAND(0, 99), RAND(0, 12));
        }//показ очереди
        cout << QUP;
        //возврат приоритетного элемента
        cout << "Возврат приоритетного элемента: " << QUP.Peek() << endl;
        //показ очереди
        cout << QUP;
        //извлечение приоритетного элемента
        cout << "Извлечение приоритетного элемента: " << QUP.Dequeue() << endl;
        //показ очереди
        cout << QUP;
    }
    */

    /*Задание 3
    Преобразуйте класс очереди с приоритетами QueuePrior в шаблонный класс
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
    cout << "Количество элементов: " << q.size() << endl;

    cout << "Возврат приоритетного элемента: ";
    cout << q.top() << endl;

    cout << "Количество элементов: " << q.size() << endl;
    cout << endl;
    cout << "Извлечение приоритетного элемента: ";
    cout << "Приоритетный элемент: " << q.top() << endl;
    q.pop();
    cout << endl;
    cout << "Количество элементов: " << q.size() << endl;
    cout << endl;

    cout << "Извлечение остальных приоритетных элементов: " << endl;
    while (!q.empty()) {
        cout << "Приоритетный элемент: " << q.top() << " - ";
        q.pop();
        cout << "Количество элементов: " << q.size() << endl;
    }
}
