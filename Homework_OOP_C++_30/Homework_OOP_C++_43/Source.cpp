/*Домашнее задание
Тема: 27-28. Бинарное дерево

Задание.
Доделать классную работу - бинарное дерево tree ("1-Работа в классе-BTree-H.txt").*/
/*
#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// структра для настройки консоли с глобальной переменой с именем "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


template<class T>
struct Node {
    T key;    // Полезные данные
              // Указатели на родителя, левого и правого потомков

    int cnt;  // счетчик повторений
    Node<T>* parent;
    Node<T>* left, * right;
    Node() : parent(), left(), right(), key(), cnt() {}
    Node(T key) :Node() { this->key = key; }
};

template<class T>
class Tree
{
    Node<T>* root;    // Корень
public:
    // Конструктор по умолчанию
    Tree() :root() {};

    // Конструктор принимающий массив элементов
    Tree(Node<T>* mas, size_t size);

    // Получить корень дерева
    Node<T>* GetRoot() { return root; }

    // Добавление элемента
    // add();
    void push(const T& val);
    // Отображение дерева с начального узла
    void Print(Node<T>* pNode);
    // Отображение всего дерева
    void Print();

    // Поиск данных в узле
    Node<T>* Search(Node<T>* node, const T& key);

    // Следующий элемент в узле
    Node<T>* Next(Node<T>* node);
    // Предыдущий элемент в узле
    Node<T>* Previous(Node<T>* node);
    // Поиск мин элемента в узле
    Node<T>* Min(Node<T>* node);
    // Поиск макс элемента в узле
    Node<T>* Max(Node<T>* node);

    // удаление всего дерева
    void Del_all();
    // Удаление узла/ветки
    void Del(Node<T>* Node);

    //деструктор
    ~Tree() { cout << "\nСработал деструктор" << endl; Del_all(); }
}; // class Tree

template<class T>
void Tree<T>::push(const T& val)
{
    Node<T>* temp = new Node<T>(val);
    if (root == nullptr) { root = temp; }
    else {
        // while (temp)
        Node<T>* temp2 = root;
        Node<T>* pref = nullptr;
        while (temp2 != nullptr) {
            pref = temp2;
            if (val < temp2->key) { temp2 = temp2->left; }
            else if (val > temp2->key) { temp2 = temp2->right; }
            // val == temp2->key
            else {
                temp2->cnt++;
                delete temp;
                return;
            }
        }
        if (val < pref->key) { pref->left = temp; }
        else { pref->right = temp; }
        temp->parent = pref;
    }
}
// Поиск данных в узле
template<class T>
Node<T>* Tree<T>::Search(Node<T>* node, const T& key)
{
    Node<T>* temp = root;
    while (temp != nullptr) {
        if (key < temp->key) { temp = temp->left; }
        else if (key > temp->key) { temp = temp->right; }
        else
        { // key == temp->key
          //return temp;
            break;
        }
    }
    //return nullptr;
    return temp;
}

// Следующий элемент в узле
template<class T>
Node<T>* Tree<T>::Next(Node<T>* node)
{
    Node<T>* y = nullptr;
    if (node != nullptr)
    {
        //если есть правый потомок
        if (node->right != nullptr) {
            return Min(node->right);
        }
        //родитель узла
        y = node->parent;
        //если Node не корень и Node справа
        while (y != nullptr && node == y->right)
        {
            //Движемся вверх
            node = y;
            y = y->parent;
        }
    }
    return y;
}
// Предыдущий элемент в узле
template<class T>
Node<T>* Tree<T>::Previous(Node<T>* node)
{
    Node<T>* y = nullptr;
    if (node != nullptr)
    {
        //если есть левый потомок
        if (node->left != nullptr)
            return Max(node->left);
        //родитель узла
        y = node->parent;
        //если Node не корень и Node слева
        while (y != nullptr && node == y->left)
        {
            //Движемся вверх
            node = y;
            y = y->parent;
        }
    }
    return y;
}
template<class T>
Node<T>* Tree<T>::Min(Node<T>* node)
{
    if (root == nullptr) { return nullptr; }
    Node<T>* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}// Поиск минимума
template<class T>
Node<T>* Tree<T>::Max(Node<T>* node) {
    if (root == nullptr) { return nullptr; }
    Node<T>* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}		// Поиск максимума




// Конструктор принимающий массив элементов
template<class T>
Tree<T>::Tree(Node<T>* mas, size_t size) {
    for (int i = 0; i < size; i++)
    {
        push(mas[i]);
    }

}

// Отображение дерева с начального узла
template<class T>
void Tree<T>::Print(Node<T>* Node) {
    if (!Node) { return; }
    cout << Node->key << endl;
    Print(Node->left);
    Print(Node->right);
}

// Отображение всего дерева
template<class T>
void Tree<T>::Print() {
    if (!root) { return; }
    Print(root);
}


// Удаление узла/ветки (nullptr удаление всего дерева)
template<class T>
void Tree<T>::Del(Node<T>* Node) {
    if (Node == nullptr) { return; }
    Del(Node->right);
    Del(Node->left);
    cout << "Удалено: " << Node->key << endl;
    if (Node->parent) {
        if (Node->key < Node->parent->key) { Node->parent->left = nullptr; }
        else { Node->parent->right = nullptr; }
    }
    delete Node;
}

// удаление всего дерева
template<class T>
void Tree<T>::Del_all() {
    if (root == nullptr) { return; }
    Del(root); root = nullptr;
};



int main()
{
    Tree<int> t1;

    for (int i = 0; i < 50; i++)
    {
        t1.push(RAND(1, 100));
    }
    t1.Print();

    cout << "Vvedite chislo dla poiska: ";
    int s;
    cin >> s;
    if (t1.Search(t1.GetRoot(), s)) {
        cout << "Найдено: " << (t1.Search(t1.GetRoot(), s))->key << endl;
    }
    else {
        cout << "Такого значения в дереве нет!" << endl;
    }
    cout << "Удаляем ветку: " << t1.Search(t1.GetRoot(), s)->key << endl;

    t1.Del(t1.Search(t1.GetRoot(), s));
    t1.Print();
    return 0;
}
*/


/*Использовать этот класс tree для следующей задачи:
Реализовать базу данных ГАИ по штрафным квитанциям с помощью бинарного дерева.
Ключом будет служить номер автомашины, значением узла - список правонарушений.
Если квитанция добавляется в первый раз, то в дереве появляется новый узел, а в списке данные по правонарушению; если нет, то данные заносятся в существующий список.
Необходимо также реализовать следующие операции:
- Полная распечатка базы данных (по номерам машин и списку правонарушений, числящихся за ними);
- Распечатка данных по заданному номеру;
- Распечатка данных по диапазону номеров.*/

#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
#include <vector> 
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// структра для настройки консоли с глобальной переменой с именем "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


template<class T, class T2>
struct Node {
    T key;    // Полезные данные
              // Указатели на родителя, левого и правого потомков
    T2 data;
    vector <T2> offense;
    int cnt;  // счетчик повторений
    Node<T, T2>* parent;
    Node<T, T2>* left, * right;
    Node() : parent(), left(), right(), key(), data(), offense(), cnt() {}
    Node(T key, T2 data) :Node() { this->key = key; this->offense.push_back(data); }
};

template<class T, class T2>
class Tree
{
    Node<T, T2>* root;    // Корень
public:
    // Конструктор по умолчанию
    Tree() :root() {};

    // Конструктор принимающий массив элементов
    Tree(Node<T, T2>* mas, size_t size);

    // Получить корень дерева
    Node<T, T2>* GetRoot() { return root; }

    // Добавление элемента
    // add();
    void push(const T& va1, const T2& val2);
    // Отображение одного элемента дерева
    void PrintOne(Node<T, T2>* node);
    // Отображение дерева с начального узла
    void Print(Node<T, T2>* pNode);
    // Отображение всего дерева
    void Print();
    // Поиск данных в узле по номеру
    Node<T, T2>* SearchCarNum(Node<T, T2>* node, const T& key);

    // Поиск данных в узле по данным
    Node<T, T2>* SearchData(Node<T, T2>* node, const T2& data);
    // Следующий элемент в узле 
    Node<T, T2>* Next(Node<T, T2>* node);
    // Предыдущий элемент в узле 
    Node<T, T2>* Previous(Node<T, T2>* node);
    // Поиск мин элемента в узле 
    Node<T, T2>* Min(Node<T, T2>* node);
    // Поиск макс элемента в узле 
    Node<T, T2>* Max(Node<T, T2>* node);
    // удаление всего дерева
    void Del_all();
    // Удаление узла/ветки
    void Del(Node<T, T2>* Node);

    //деструктор
    ~Tree() { cout << "\nСработал деструктор" << endl; Del_all(); }
}; // class Tree

template<class T, class T2>
void Tree<T, T2>::push(const T& val1, const T2& val2)
{
    Node<T, T2>* temp = new Node<T, T2>(val1, val2);
    if (root == nullptr) { root = temp; }
    else {
        // while (temp)
        Node<T, T2>* temp2 = root;
        Node<T, T2>* pref = nullptr;
        while (temp2 != nullptr) {
            pref = temp2;
            if (val1 < temp2->key) { temp2 = temp2->left; }
            else if (val1 > temp2->key) { temp2 = temp2->right; }
            // val1 == temp2->key
            else {
                temp2->cnt++;
                temp2->offense.push_back(val2);
                delete temp;
                return;
            }
        }
        if (val1 < pref->key) { pref->left = temp; }
        else { pref->right = temp; }
        temp->parent = pref;
    }
}
// Поиск данных в узле по номеру
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::SearchCarNum(Node<T, T2>* node, const T& key)
{
    Node<T, T2>* temp = root;
    while (temp != nullptr) {
        if (key < temp->key) { temp = temp->left; }
        else if (key > temp->key) { temp = temp->right; }
        else
        { // key == temp->key
          //return temp;
            break;
        }
    }
    //return nullptr;
    return temp;
}

// Поиск данных в узле по данным 
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::SearchData(Node<T, T2>* node, const T2& data)
{
    Node<T, T2>* temp = node;
    if (temp != nullptr)
    {
        //vector<int>::iterator ptr;
        //for (ptr = temp->offense.begin(); ptr < temp->offense.end(); ptr++)
        for (int i = 0; i < temp->offense.size(); i++)
        {
            if (temp->offense[i] == data) {
                return temp;
            }
        }
        if (temp->left != nullptr)
        {
            return SearchData(temp->left, data);
        }
        else if (temp->right != nullptr) {
            return SearchData(temp->right, data);
        }
        else {
            return nullptr;
        }
    }
    return temp;
}

// Следующий элемент в узле 
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Next(Node<T, T2>* node)
{
    Node<T, T2>* y = nullptr;
    if (node != nullptr)
    {
        //если есть правый потомок
        if (node->right != nullptr) {
            return Min(node->right);
        }
        //родитель узла
        y = node->parent;
        //если Node не корень и Node справа
        while (y != nullptr && node == y->right)
        {
            //Движемся вверх
            node = y;
            y = y->parent;
        }
    }
    return y;
}
// Предыдущий элемент в узле 
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Previous(Node<T, T2>* node)
{
    Node<T, T2>* y = nullptr;
    if (node != nullptr)
    {
        //если есть левый потомок
        if (node->left != nullptr)
            return Max(node->left);
        //родитель узла
        y = node->parent;
        //если Node не корень и Node слева
        while (y != nullptr && node == y->left)
        {
            //Движемся вверх
            node = y;
            y = y->parent;
        }
    }
    return y;
}
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Min(Node<T, T2>* node)
{
    if (root == nullptr) { return nullptr; }
    Node<T>* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}// Поиск минимума
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Max(Node<T, T2>* node) {
    if (root == nullptr) { return nullptr; }
    Node<T, T2>* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}		// Поиск максимума




// Конструктор принимающий массив элементов
template<class T, class T2>
Tree<T, T2>::Tree(Node<T, T2>* mas, size_t size) {
    for (int i = 0; i < size; i++)
    {
        push(mas[i]);
    }

}
// Распечатка данных по заданному элементу дерева
template<class T, class T2>
void Tree<T, T2>::PrintOne(Node<T, T2>* Node) {
    if (!Node) { return; }
    cout << "\n\n***Номер машины: " << Node->key << endl;
    for (int i = 0; i < Node->offense.size(); i++)
    {
        cout << i + 1 << ") Правонарушение: " << Node->offense[i] << endl;
    }
}

// Отображение дерева с начального узла
template<class T, class T2>
void Tree<T, T2>::Print(Node<T, T2>* Node) {
    if (!Node) { return; }
    cout << "\n***Список авто в базе правонарушений***" << endl;
    cout << "\n***Номер машины: " << Node->key << endl;
    for (int i = 0; i < Node->offense.size(); i++)
    {
        cout << i + 1 << ") Правонарушение: " << Node->offense[i] << endl;
    }
    Print(Node->left);
    Print(Node->right);
}

// Отображение всего дерева
template<class T, class T2>
void Tree<T, T2>::Print() {
    if (!root) { return; }
    Print(root);
}


// Удаление узла/ветки (nullptr удаление всего дерева)
template<class T, class T2>
void Tree<T, T2>::Del(Node<T, T2>* Node) {
    if (Node == nullptr) { return; }
    Del(Node->right);
    Del(Node->left);
    cout << "Удалено: " << Node->key << endl;
    if (Node->parent) {
        if (Node->key < Node->parent->key) { Node->parent->left = nullptr; }
        else { Node->parent->right = nullptr; }
    }
    delete Node;
}

// удаление всего дерева
template<class T, class T2>
void Tree<T, T2>::Del_all() {
    if (root == nullptr) { return; }
    Del(root); root = nullptr;
};


int main()
{
    Tree<int, string> t1;
    t1.push(10, "Пересечение сплошной линии");
    t1.push(10, "Проезд на красный");
    t1.push(10, "Остановка внеположенном месте");
    t1.push(11, "Отстутствие техосмотра");
    t1.push(7, "Разворот внеположенном месте");
    t1.push(2, "Создание аварийной ситуации на дороге");
    t1.push(12, "Создание помехи пешеходу");
    t1.push(6, "Управление авто без документов");
    t1.push(2, "Пересение стоп-линии");
    t1.push(16, "Управление авто в состоянии опьянения");
    t1.push(7, "Управление авто с выключенными фарами");


    //-Полная распечатка базы данных(по номерам машин и списку правонарушений, числящихся за ними);
    t1.Print();

    //- Распечатка данных по заданному номеру;
    cout << "\n\nВведите номер авто для поиска в базе: ";
    int n;
    cin >> n;
    cin.ignore();
    if (t1.SearchCarNum(t1.GetRoot(), n)) {
        t1.PrintOne(t1.SearchCarNum(t1.GetRoot(), n));
        cout << endl;
    }
    else {
        cout << "Такого значения в дереве нет!" << endl;
    }

    //- Распечатка данных по диапазону номеров.
    cout << endl;
    cout << "Введите диапазон номеров авто для поиска в базе: ";
    int n1, n2;
    cin >> n1 >> n2;
    cin.ignore();
    if (n1 == n2) {
        cout << "Диапазоны номеров совпадают!" << endl;
    }
    else if (n1 > n2) {
        int tmp = n2;
        n2 = n1;
        n1 = tmp;
    }

    while (n1 <= n2) {
        if (t1.SearchCarNum(t1.GetRoot(), n1)) {
            t1.PrintOne(t1.SearchCarNum(t1.GetRoot(), n1));
            cout << endl;
        }
        n1++;
    }

    //Поиск правонарушения
    cout << endl;
    cout << "Введите данные по нарушению для поиска в базе, напр, \"Проезд на красный\": ";
    string d;
    getline(cin, d);
    if (t1.SearchData(t1.GetRoot(), d)) {
        t1.PrintOne(t1.SearchData(t1.GetRoot(), d));
    }
    else {
        cout << "Такого значения в дереве нет!" << endl;
    }
    return 0;
}
