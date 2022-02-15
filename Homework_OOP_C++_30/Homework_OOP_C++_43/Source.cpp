/*�������� �������
����: 27-28. �������� ������

�������.
�������� �������� ������ - �������� ������ tree ("1-������ � ������-BTree-H.txt").*/
/*
#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


template<class T>
struct Node {
    T key;    // �������� ������
              // ��������� �� ��������, ������ � ������� ��������

    int cnt;  // ������� ����������
    Node<T>* parent;
    Node<T>* left, * right;
    Node() : parent(), left(), right(), key(), cnt() {}
    Node(T key) :Node() { this->key = key; }
};

template<class T>
class Tree
{
    Node<T>* root;    // ������
public:
    // ����������� �� ���������
    Tree() :root() {};

    // ����������� ����������� ������ ���������
    Tree(Node<T>* mas, size_t size);

    // �������� ������ ������
    Node<T>* GetRoot() { return root; }

    // ���������� ��������
    // add();
    void push(const T& val);
    // ����������� ������ � ���������� ����
    void Print(Node<T>* pNode);
    // ����������� ����� ������
    void Print();

    // ����� ������ � ����
    Node<T>* Search(Node<T>* node, const T& key);

    // ��������� ������� � ����
    Node<T>* Next(Node<T>* node);
    // ���������� ������� � ����
    Node<T>* Previous(Node<T>* node);
    // ����� ��� �������� � ����
    Node<T>* Min(Node<T>* node);
    // ����� ���� �������� � ����
    Node<T>* Max(Node<T>* node);

    // �������� ����� ������
    void Del_all();
    // �������� ����/�����
    void Del(Node<T>* Node);

    //����������
    ~Tree() { cout << "\n�������� ����������" << endl; Del_all(); }
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
// ����� ������ � ����
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

// ��������� ������� � ����
template<class T>
Node<T>* Tree<T>::Next(Node<T>* node)
{
    Node<T>* y = nullptr;
    if (node != nullptr)
    {
        //���� ���� ������ �������
        if (node->right != nullptr) {
            return Min(node->right);
        }
        //�������� ����
        y = node->parent;
        //���� Node �� ������ � Node ������
        while (y != nullptr && node == y->right)
        {
            //�������� �����
            node = y;
            y = y->parent;
        }
    }
    return y;
}
// ���������� ������� � ����
template<class T>
Node<T>* Tree<T>::Previous(Node<T>* node)
{
    Node<T>* y = nullptr;
    if (node != nullptr)
    {
        //���� ���� ����� �������
        if (node->left != nullptr)
            return Max(node->left);
        //�������� ����
        y = node->parent;
        //���� Node �� ������ � Node �����
        while (y != nullptr && node == y->left)
        {
            //�������� �����
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
}// ����� ��������
template<class T>
Node<T>* Tree<T>::Max(Node<T>* node) {
    if (root == nullptr) { return nullptr; }
    Node<T>* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}		// ����� ���������




// ����������� ����������� ������ ���������
template<class T>
Tree<T>::Tree(Node<T>* mas, size_t size) {
    for (int i = 0; i < size; i++)
    {
        push(mas[i]);
    }

}

// ����������� ������ � ���������� ����
template<class T>
void Tree<T>::Print(Node<T>* Node) {
    if (!Node) { return; }
    cout << Node->key << endl;
    Print(Node->left);
    Print(Node->right);
}

// ����������� ����� ������
template<class T>
void Tree<T>::Print() {
    if (!root) { return; }
    Print(root);
}


// �������� ����/����� (nullptr �������� ����� ������)
template<class T>
void Tree<T>::Del(Node<T>* Node) {
    if (Node == nullptr) { return; }
    Del(Node->right);
    Del(Node->left);
    cout << "�������: " << Node->key << endl;
    if (Node->parent) {
        if (Node->key < Node->parent->key) { Node->parent->left = nullptr; }
        else { Node->parent->right = nullptr; }
    }
    delete Node;
}

// �������� ����� ������
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
        cout << "�������: " << (t1.Search(t1.GetRoot(), s))->key << endl;
    }
    else {
        cout << "������ �������� � ������ ���!" << endl;
    }
    cout << "������� �����: " << t1.Search(t1.GetRoot(), s)->key << endl;

    t1.Del(t1.Search(t1.GetRoot(), s));
    t1.Print();
    return 0;
}
*/


/*������������ ���� ����� tree ��� ��������� ������:
����������� ���� ������ ��� �� �������� ���������� � ������� ��������� ������.
������ ����� ������� ����� ����������, ��������� ���� - ������ ��������������.
���� ��������� ����������� � ������ ���, �� � ������ ���������� ����� ����, � � ������ ������ �� ��������������; ���� ���, �� ������ ��������� � ������������ ������.
���������� ����� ����������� ��������� ��������:
- ������ ���������� ���� ������ (�� ������� ����� � ������ ��������������, ���������� �� ����);
- ���������� ������ �� ��������� ������;
- ���������� ������ �� ��������� �������.*/

#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
#include <vector> 
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


template<class T, class T2>
struct Node {
    T key;    // �������� ������
              // ��������� �� ��������, ������ � ������� ��������
    T2 data;
    vector <T2> offense;
    int cnt;  // ������� ����������
    Node<T, T2>* parent;
    Node<T, T2>* left, * right;
    Node() : parent(), left(), right(), key(), data(), offense(), cnt() {}
    Node(T key, T2 data) :Node() { this->key = key; this->offense.push_back(data); }
};

template<class T, class T2>
class Tree
{
    Node<T, T2>* root;    // ������
public:
    // ����������� �� ���������
    Tree() :root() {};

    // ����������� ����������� ������ ���������
    Tree(Node<T, T2>* mas, size_t size);

    // �������� ������ ������
    Node<T, T2>* GetRoot() { return root; }

    // ���������� ��������
    // add();
    void push(const T& va1, const T2& val2);
    // ����������� ������ �������� ������
    void PrintOne(Node<T, T2>* node);
    // ����������� ������ � ���������� ����
    void Print(Node<T, T2>* pNode);
    // ����������� ����� ������
    void Print();
    // ����� ������ � ���� �� ������
    Node<T, T2>* SearchCarNum(Node<T, T2>* node, const T& key);

    // ����� ������ � ���� �� ������
    Node<T, T2>* SearchData(Node<T, T2>* node, const T2& data);
    // ��������� ������� � ���� 
    Node<T, T2>* Next(Node<T, T2>* node);
    // ���������� ������� � ���� 
    Node<T, T2>* Previous(Node<T, T2>* node);
    // ����� ��� �������� � ���� 
    Node<T, T2>* Min(Node<T, T2>* node);
    // ����� ���� �������� � ���� 
    Node<T, T2>* Max(Node<T, T2>* node);
    // �������� ����� ������
    void Del_all();
    // �������� ����/�����
    void Del(Node<T, T2>* Node);

    //����������
    ~Tree() { cout << "\n�������� ����������" << endl; Del_all(); }
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
// ����� ������ � ���� �� ������
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

// ����� ������ � ���� �� ������ 
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

// ��������� ������� � ���� 
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Next(Node<T, T2>* node)
{
    Node<T, T2>* y = nullptr;
    if (node != nullptr)
    {
        //���� ���� ������ �������
        if (node->right != nullptr) {
            return Min(node->right);
        }
        //�������� ����
        y = node->parent;
        //���� Node �� ������ � Node ������
        while (y != nullptr && node == y->right)
        {
            //�������� �����
            node = y;
            y = y->parent;
        }
    }
    return y;
}
// ���������� ������� � ���� 
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Previous(Node<T, T2>* node)
{
    Node<T, T2>* y = nullptr;
    if (node != nullptr)
    {
        //���� ���� ����� �������
        if (node->left != nullptr)
            return Max(node->left);
        //�������� ����
        y = node->parent;
        //���� Node �� ������ � Node �����
        while (y != nullptr && node == y->left)
        {
            //�������� �����
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
}// ����� ��������
template<class T, class T2>
Node<T, T2>* Tree<T, T2>::Max(Node<T, T2>* node) {
    if (root == nullptr) { return nullptr; }
    Node<T, T2>* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}		// ����� ���������




// ����������� ����������� ������ ���������
template<class T, class T2>
Tree<T, T2>::Tree(Node<T, T2>* mas, size_t size) {
    for (int i = 0; i < size; i++)
    {
        push(mas[i]);
    }

}
// ���������� ������ �� ��������� �������� ������
template<class T, class T2>
void Tree<T, T2>::PrintOne(Node<T, T2>* Node) {
    if (!Node) { return; }
    cout << "\n\n***����� ������: " << Node->key << endl;
    for (int i = 0; i < Node->offense.size(); i++)
    {
        cout << i + 1 << ") ��������������: " << Node->offense[i] << endl;
    }
}

// ����������� ������ � ���������� ����
template<class T, class T2>
void Tree<T, T2>::Print(Node<T, T2>* Node) {
    if (!Node) { return; }
    cout << "\n***������ ���� � ���� ��������������***" << endl;
    cout << "\n***����� ������: " << Node->key << endl;
    for (int i = 0; i < Node->offense.size(); i++)
    {
        cout << i + 1 << ") ��������������: " << Node->offense[i] << endl;
    }
    Print(Node->left);
    Print(Node->right);
}

// ����������� ����� ������
template<class T, class T2>
void Tree<T, T2>::Print() {
    if (!root) { return; }
    Print(root);
}


// �������� ����/����� (nullptr �������� ����� ������)
template<class T, class T2>
void Tree<T, T2>::Del(Node<T, T2>* Node) {
    if (Node == nullptr) { return; }
    Del(Node->right);
    Del(Node->left);
    cout << "�������: " << Node->key << endl;
    if (Node->parent) {
        if (Node->key < Node->parent->key) { Node->parent->left = nullptr; }
        else { Node->parent->right = nullptr; }
    }
    delete Node;
}

// �������� ����� ������
template<class T, class T2>
void Tree<T, T2>::Del_all() {
    if (root == nullptr) { return; }
    Del(root); root = nullptr;
};


int main()
{
    Tree<int, string> t1;
    t1.push(10, "����������� �������� �����");
    t1.push(10, "������ �� �������");
    t1.push(10, "��������� ������������� �����");
    t1.push(11, "����������� ����������");
    t1.push(7, "�������� ������������� �����");
    t1.push(2, "�������� ��������� �������� �� ������");
    t1.push(12, "�������� ������ ��������");
    t1.push(6, "���������� ���� ��� ����������");
    t1.push(2, "��������� ����-�����");
    t1.push(16, "���������� ���� � ��������� ���������");
    t1.push(7, "���������� ���� � ������������ ������");


    //-������ ���������� ���� ������(�� ������� ����� � ������ ��������������, ���������� �� ����);
    t1.Print();

    //- ���������� ������ �� ��������� ������;
    cout << "\n\n������� ����� ���� ��� ������ � ����: ";
    int n;
    cin >> n;
    cin.ignore();
    if (t1.SearchCarNum(t1.GetRoot(), n)) {
        t1.PrintOne(t1.SearchCarNum(t1.GetRoot(), n));
        cout << endl;
    }
    else {
        cout << "������ �������� � ������ ���!" << endl;
    }

    //- ���������� ������ �� ��������� �������.
    cout << endl;
    cout << "������� �������� ������� ���� ��� ������ � ����: ";
    int n1, n2;
    cin >> n1 >> n2;
    cin.ignore();
    if (n1 == n2) {
        cout << "��������� ������� ���������!" << endl;
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

    //����� ��������������
    cout << endl;
    cout << "������� ������ �� ��������� ��� ������ � ����, ����, \"������ �� �������\": ";
    string d;
    getline(cin, d);
    if (t1.SearchData(t1.GetRoot(), d)) {
        t1.PrintOne(t1.SearchData(t1.GetRoot(), d));
    }
    else {
        cout << "������ �������� � ������ ���!" << endl;
    }
    return 0;
}
