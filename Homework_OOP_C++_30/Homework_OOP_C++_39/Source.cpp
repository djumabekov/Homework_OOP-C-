
/*������� 1.
���� ������ ��������, ��������� �����, ������� �������� ������ ';'.
� ������ ����� ���� ��������, �������, ���������� ������.
������ ����� ���� ������������ � ������������.
���������� ��������� ������������ ����������� ������.
��� ���� ����������, ����� ����������� ��������� �������:
1) ������ ����������� ������ ������ ����� ������ ����� �� �����������. �������� ����� ������ ���� �����.
2) ����������� � ����������� ���� ������ ������ ����� ������ ���� ��������� ����������� �� ��������� ���� � �����.

- ������ ���������� ������: ({x-y-z}*[x+2y]-(z+4x));
- ������ ������������ ������: ([x-y-z}*[x+2y)-{z+4x)];.

���� ��� ������� ��������� �������� �������������� ��������� � ������������ ������, ����� �������� ������ �� ����� ������������� ������ ������.
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

    bool GetIsCorrect() { //��������� �� ������������
        //for (char c : s) {
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(': stack.push(')'); break;// ����� ������������� ������ � ����
            case '[': stack.push(']'); break;
            case '{': stack.push('}'); break;

            case ')': // ���� ����������� ������
            case ']':
            case '}':
                if (stack.empty() || stack.top() != s[i]) { // ���� ���� ������ ��� ��� ������� ������� �� ����� ����� �� ������ �� ���������� false
                    SetIncorrectSym(i);
                    return false; //������ �����������
                }
                else {
                    stack.pop(); // ����� ������� ������� �� �����
                }
                break;
            default:
                break;
            }
        }
        return stack.empty(); // ���� ���� ������ ������������ true (�.�. ������ ���������) ����� false - �����������
    }

    // �������� ������������ ������
    CheckSyntax& operator = (const string& s) {
        this->s = s;
        return *this;
    }

    // �������� ������ � ������������ ������������� ������ �������
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

    //��������� ������� ������������ ������
    cout << "\n������������ ������: " << endl;
    if (!A.GetIsCorrect()) { A.ShowIncorrectSym(); }
    if (!B.GetIsCorrect()) { B.ShowIncorrectSym(); } // ��������� �������
}
