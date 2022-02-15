
/*Домашнее задание
Тема: Исключения
Урок: 43-44. Обработка исключительных ситуаций

Задание 1.
Добавьте в класс очереди типа стек (Stack) механизм обработки исключений.
На ваш выбор генерируйте исключения в случае ошибок.
Например, нехватка памяти, попытка извлечения из пустого стека, переполнение стека и т.д.*/
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

    void pop_front(); // удаляет первый элемент списка
    void push_back(T data); // добавляем элемент списка в конец
    void clear(); //очищаем список
    int GetSize() { return Size; }
    int GetCurrentSize() {
        int CurrentSize = 1;
        Node<T>* current = this->head;
        while(current->pNext != nullptr) {
            current = current->pNext; // перебираем пока не наткнемся на указатель указываеющий на NULL
            CurrentSize++;
        }
        return CurrentSize;
    }
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
    if (!GetSize()) {throw exception("Стек пустой!");}
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
    if (!GetSize()) { throw exception("Размер стека = 0!"); }
    if (GetCurrentSize()==GetSize()) { throw exception("Стек переполнен!"); }
    head = new Node<T>(data, head); // создаем новый элемент, обозначаем его как head и передаем в конструктор
                                    // "data" и предыдущий head на который теперь будет указвать новый head
    Size++; // увеличиваем размер
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (!GetSize()) { throw exception("Размер стека = 0!"); }
    if (GetCurrentSize() == GetSize()) { throw exception("Стек переполнен!"); }
    if (index > GetSize()) { throw exception("Выход за границы стека!"); }
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
    if (!GetSize()) { throw exception("Стек пустой!"); }
    if (index > GetCurrentSize()) { throw exception("Выход за границы стека!"); }
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
    if (!GetSize()) { throw exception("Стек пустой!"); }
    removeAt(Size - 1); // вызываем метод удаления по индексу и передаем ему последний в списке индекс
}

int main()
{
    List<int> list;

    int size;
    cout << "введите размер списка:";
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
        cout << "Добавлем головной элемент 333. " << endl;
        list.push_front(333);
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;
    }
    catch (const std::exception&e)
    {
        cout << "Сработал перехватчик по типу std::exception для push_front()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

    try
    {
        cout << "Вставляем элемент 444 в индекс 2.\n " << endl;
        list.insert(444, 2);
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception&e)
    {
        cout << "Сработал перехватчик по типу std::exception для insert()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

    try
    {
        cout << "Удаляем элемент в индексе 10.\n" << endl;
         list.removeAt(10);
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception&e)
    {
        cout << "Сработал перехватчик по типу std::exception для removeAt()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

    try
    {
        cout << "Удаляем последний элемент.\n "<< endl;
        list.pop_back();
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "List[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception&e)
    {
        cout << "Сработал перехватчик по типу std::exception для pop_back()" << endl;
        cout << "e = " << e.what() << endl;
    }

    cout << endl << endl;

    try
    {
        cout << "Очищаем список.\n " << endl;
        list.clear();
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const std::exception& e)
    {
        cout << "Сработал перехватчик по типу std::exception для clear()" << endl;
        cout << "e = " << e.what() << endl;
    }

    cout << endl << endl;
    try
    {
        cout << "удаляем первый элемент.\n " << endl;
        list.pop_front();
        for (int i = 0; i < list.GetSize(); i++)
        {
            cout << "list[" << i << "] = " << list[i] << endl;
        }
        cout << "Size = " << list.GetSize() << endl;

    }
    catch (const exception& e)
    {
        cout << "сработал перехватчик по типу std::exception для pop_front()" << endl;
        cout << "e = " << e.what() << endl;
    }
    cout << endl << endl;

}
*/


/*Задание 2
Написать функцию вычисления значения по заданной строке символов, являющихся записью этого числа в десятичной системе исчисления.
Предусмотреть случай выхода за границы диапазона определяемого типом int.
Используйте механизм исключений.*/
/*
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

int StrToInt(const char* str)
{
    int oper; //знак числа "- или +"
    long long res = 0; // результат перевода строки в int
    int len = strlen(str);
    int start = 0;
    oper = 1;
    if (str[start] == '-') { oper = -1; } // запоминаем знак числа: "- или +"

    for (int i = len-1; i >= 0; i--)
    {
        if (i == 0 && str[i] == '-') { break; } // проверяем первый символ: если знак "-" то прерываем цикл
        res += (str[i] - '0') * oper;
        oper *= 10;
        cout << "res [" << i << "] = " << res << endl;
    }

    if (res < INT32_MIN || res > INT32_MAX) { throw "Выход за границы диапазона"; }

    return res;
}

void main()
{
    try {
        //cout << "res = "<< StrToInt("2147483647") << endl; //без исключения: число в пределах диапазона
        cout <<  "res = " <<StrToInt("2147483648") << endl; //исключение: Выход за границы диапазона
        //cout <<  "res = " <<StrToInt("-2147483649") << endl; //исключение: Выход за границы диапазона
    }
    catch (const char* e)
    {
        cout << "Сработал перехватчик по типу const char*" << endl;
        cout << "e = " << e << endl;
    }
}
*/
