
/*Домашнее задание
23-24. Односвязный список

Задание 1
Доделать шаблон класса односвязного списока "1-Работа в классе-TList1.txt":
реализовать методы класса:
  List(const List& obj) - конструктор копирования;
  List& operator=(const List& obj) - оператор копирования;
Реализовать код перегруженного оператора вывода в поток
  ostream& operator<<(ostream& os, const List<T>& obj);
Проверить работоспособность шаблона класса List<>.
и
Задание 2
В существующий класс односвязного списка добавить:
a) перегрузить оператор + (оператор должен возвращать адрес головы нового списка, содержащего элементы обоих списков для которых вызывался оператор);
b) перегрузить оператор * (оператор должен возвращать адрес головы нового списка, содержащего только общие элементы обоих списков для которых вызывался оператор)
*/
/*
#include <iostream>
#include <initializer_list>
#include <time.h>
#include <Windows.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// структра для настройки консоли с глобальной переменой с именем "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// Списки
//  Односвязанный список

// Шаблон структуры одного узла списка
template <class T>
struct Element
{
    Element<T>* next;   // указатель на следующий элемент
    T data;             // полезные данные
    //
    Element() : next(), data() {}
    Element(T data, Element<T>* next = nullptr)
        :data(data), next(next) {}
    Element<T>* GetNext() { return next; }
    void SetNext(Element<T>* other) { next = other; }
    void SetData(T data) { this->data = data; }
    T GetData() { return data; }
};

// Шаблон класса односвязного списка
template <class T>
class List
{
private:
    Element<T>* head, * tail; // указатели на головной и хвостой элементы списка
    int cnt; // текущее количество узлов в списке
public:
    List() : head(), tail(), cnt() {
        //cout << "Конструктор сработал" << endl;
    }
    List(const T& val) :List() {
        AddHead(val);
    } // иниц-ция одним элементом
    List(initializer_list<T> mas) {
        //cout << "Конструктор" << endl;
        for (auto a : mas) { AddTail(a); }
        //for (T a : mas) { AddTail(a); }


    }// иниц-ция списком
    List(const T* mas, int size) : List() {
        for (int i = 0; i < size; i++)
        {
            AddTail(mas[i]);
        }
    }  // иниц-ция массивом

    List(const List& obj):List() {
        //cout << "Конструктор копирования сработал" << endl;
        *this = obj;
    };
    List& operator=(const List& obj) {
        //cout << "Оператор копирования сработал" << endl;
        if (this != &obj) {
            for (int i = 0; i < obj.GetCnt(); i++) {
                this->Insert(obj.Get(i), i);
            }
            this->cnt = obj.GetCnt();
        }
        return *this;
    };


    ~List() {
       // cout << "Деструктор сработал" << endl;
        Clear(); }
    // Очистка узла - удалени всех элементов списка
    void Clear() {
        while (cnt) {
            DeleteHead();
        }
    }

    // Добавить новый элемент в начало списка
    //  Аналог метода list<T>::push_front();
    void AddHead(const T& val);

    // Добавить новый элемент в конец списка
    //  Аналог метода list<T>::push_back();
    void AddTail(const T& val);

    // Удалить головной элемент
    //  Аналог метода list<T>::pop_front();
    void DeleteHead();

    // Удалить хвостовой элемент
    //  Аналог метода list<T>::pop_back();
    void DeleteTail();

    // Вставить элемент в список в указанную позицию index
    void Insert(const T& val, int index);

    // Получить текущее кол-во узлов в списке
    int GetCnt() const { return cnt; }

    // Получить значение узла по указанной позиции
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
    // перегруженные операторы индексации []
    T& operator[](int index) const {
        return Get(index);
    } // для чтения
    T& operator[](int index) { return Get(index); } // для записи (изменения)

    // Поиск узла с заданным значением
    // Возвращает индекс найденного узла или -1 в противном случае
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


// Добавить новый элемент в начало списка
//  Аналог метода list<T>::push_front();
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

// Добавить новый элемент в конец списка
//  Аналог метода list<T>::push_back();
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

// Удалить головной элемент
//  Аналог метода list<T>::pop_front();
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

// Удалить хвостовой элемент
//  Аналог метода list<T>::pop_back();
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

// Вставить элемент в список в указанную позицию index
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
    cout << "Список A: " << endl;
    List<string> A("First value");
    string s = "Second value";
    A.AddHead(s);
    s = "Third value";
    A.AddTail(s);
    s = "Fourth value";
    A.Insert(s, 1);
    cout << A << endl;
    cout << endl;

    cout << "Список В: " << endl;
    List<string> B;
    B = A;
    cout << B << endl;

    cout << "Список A + В: " << endl;
    cout << (A + B) << endl;

    List<string> C("First value"); //будет добавлен
    s = "Sixth value";
    C.AddHead(s);
    s = "Third value"; //будет добавлен
    C.AddTail(s);
    s = "Eighth value";
    C.Insert(s, 1);
    cout << "Список A * C: " << endl;
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
Задание 2
Реализуйте стек в виде односвязного списка.
Требуется реализовать типичные операции по работе со стеком.
При переполнении стека нужно увеличивать его размер.
*/
template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front(); // удаляет первый элемент списка
    void push_back(T data); // добавляем элемент списка в конец
    void clear(); //очищаем список
    int GetSize() { return Size; }
    T& operator[](const int index); // возвращаем элемент списка по индексу
    void push_front(T data); // добавляем элемент списка в начало
    void insert(T data, int index); // добавляем элемент списка в указанное место
    void removeAt(int index); //удалем эдемент по указанному индексу
    void pop_back(); // удаляет последний элемент списка

private:
    template<typename T>
    class Node {
    public:
        Node* pNext; // указатель на следующий элемент списка 
        T data; // данные

        Node(T data = T(), Node* pNext = nullptr) { // при создании объекта по умолчанию первый элемент списка указывает на NULL
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size; // размер списка
    Node<T>* head; // голова списка
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
    Node<T>* temp = head; // временно запоминаем указатель на текущий head
    head = head = head->pNext; // сдвигаем head на следующий от него элемент
    delete temp; // отчищаем память первого head 
    Size--; // уменьшаем размер 
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) // если это нулевой только созданный head
    {
        head = new Node<T>(data); // то создаем новый элемент куда ложим значение data
    }
    else {
        Node<T>* current = this->head; // иначе запоминаем указатель на head 
        while (current->pNext != nullptr) {
            current = current->pNext; // перебираем пока не наткнемся на указатель указываеющий на NULL 
        }
        current->pNext = new Node<T>(data); // соотвестсвенно после него создаем новый элемент куда ложим значение data 
    }
    Size++; //увеличиваем Size
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
    head = new Node<T>(data, head); // создаем новый элемент, обозначаем его как head и передаем в конструктор  
                                    // "data" и предыдущий head на который теперь будет указвать новый head
    Size++; // увеличиваем размер
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0) //если индекс нулевой то вызываем метод вставки головного элемента
    {
        push_front(data);
    }
    else {
        Node<T>* previous = this->head; //  запоминаем текущий head
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext; // ищем элемент предшествующий индексу куда будем вставлять
        }
        Node<T>* newNode = new Node<T>(data, previous->pNext); // создаем элемент и в конструктор передаем
                                                                // data и указатель pNext предшествующего элемента
        previous->pNext = newNode; //  меняем указатель в предшествующем элементе на новый элемент 
        Size++;
    }

}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0) //если индекс нулевой то вызываем метод удаления головного элемента
    {
        pop_front();
    }
    else {
        Node<T>* previous = this->head; //  запоминаем текущий head
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext; // ищем элемент предшествующий индексу
        }
        Node<T>* toDelete = previous->pNext; // запоминаем указатель на удаляемый элемент
        previous->pNext = toDelete->pNext; //  меняем указатель в предшествующем удаляемому элементу на следущий от него элемент 
        delete toDelete; // удаляем элемент
        Size--;
    }

}

template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1); // вызываем метод удаления по индексу и передаем ему последний в списке индекс
}

int main()
{
    List<int> list;

    int Size;
    cout << "Введите размер списка:";
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
    cout << "Удаляем первый элемент.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.push_front(333);
    cout << "Добавлем головной элемент 333.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.insert(444, 2);
    cout << "Вставляем элемент 444 в индекс 2.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.removeAt(2);
    cout << "Удаляем элемент 444 в индексе 2.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.pop_back();
    cout << "Удаляем последний элемент.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }

    list.clear();
    cout << "Очищаем список.\n Size = " << list.GetSize() << endl;
    for (int i = 0; i < list.GetSize(); i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }
}
