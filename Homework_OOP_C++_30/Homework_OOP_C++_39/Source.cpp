
/*Задание 1.
Есть строка символов, признаком конца, которой является символ ';'.
В строке могут быть фигурные, круглые, квадратные скобки.
Скобки могут быть открывающими и закрывающими.
Необходимо проверить корректность расстановки скобок.
При этом необходимо, чтобы выполнились следующие правила:
1) Каждая открывающая скобка должна иметь справа такую же закрывающую. Обратное также должно быть верно.
2) Открывающие и закрывающие пары скобок разных типов должны быть правильно расположены по отношению друг к другу.

- Пример правильной строки: ({x-y-z}*[x+2y]-(z+4x));
- Пример неправильной строки: ([x-y-z}*[x+2y)-{z+4x)];.

Если все правила соблюдены выведите информационное сообщение о корректности строки, иначе покажите строку до места возникновения первой ошибки.
*/

#include <stack>
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <windows.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

void SetColor(int colBkgr, int colSym) {
    int wAttributes = colBkgr * 16 + colSym;
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

class CheckSyntax {
private:
    stack<char> stack;
    string s;
    int indexIncorSym;
public:
    CheckSyntax() :stack(), s(), indexIncorSym(-1) {};

    //setters
    void SetIncorrectSym(int i) {
        indexIncorSym = i;
    }

    //getters
    int GetIncorrectSym() {
        return indexIncorSym;
    }
    string GetString() {
        return s;
    }

    bool GetIsCorrect() { //проверяем на корректность
        //for (char c : s) {
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(': stack.push(')'); break;// пушим открывающуюся скобку в стек
            case '[': stack.push(']'); break;
            case '{': stack.push('}'); break;

            case ')': // ищем закрывающюю скобку
            case ']':
            case '}':
                if (stack.empty() || stack.top() != s[i]) { // если стек пустой или его верхний элемент не равен одной из скобок то возвращаем false
                    SetIncorrectSym(i);
                    return false; //строка некорректна
                }
                else {
                    stack.pop(); // иначе удаляем элемент из стека
                }
                break;
            default:
                break;
            }
        }
        return stack.empty(); // если стек пустой возвращается true (т.е. строка корректна) иначе false - некорректна
    }

    // оператор присваивания строки
    CheckSyntax& operator = (const string& s) {
        this->s = s;
        return *this;
    }

    // печатает строку и подсвечивает некорреектный символ красным
    void ShowIncorrectSym() {
        for (int i = 0; i < this->GetString().size(); i++) {
            if (i == this->GetIncorrectSym()) {
                SetColor(0, 4);
            }
            cout << this->GetString()[i];
            SetColor(0, 7);
        }
        cout << endl;
    }
};



int main() {
    CheckSyntax A;
    CheckSyntax B;
    A = "({ x - y - z }*[x + 2y] - (z + 4x));"; //correct
    B = "([x-y-z}*[x+2y)-{z+4x)];"; //incorrect

    cout << "({x-y-z}*[x+2y]-(z)+4x)); : " << boolalpha << A.GetIsCorrect() << endl; // true
    cout << "([x-y-z}*[x+2y)-{z+4x)]; : " << boolalpha << B.GetIsCorrect() << endl; // false

    //подсветим красным некорректную скобку
    cout << "\nНекорректная строка: " << endl;
    if (!A.GetIsCorrect()) { A.ShowIncorrectSym(); }
    if (!B.GetIsCorrect()) { B.ShowIncorrectSym(); } // подсветит красным
}
