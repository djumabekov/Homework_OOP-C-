#include <iostream>
using namespace std;
/*
1.*Создать приложение, которое выводит
на консоль фразу:
"To be
    or not
        to be!"
            \Shakespeare\
*/
int main() {
    // "\n" == endl
    cout << "\"To be\n\a"
        << "\tor not\n\a"
        << "\t\tto be!\"\n\a"
        << "\t\t\t\\Shakespear\\\n\a\a" << endl;
}


#include <iostream>
using namespace std;
int main() {
    // \b, \r 
    //cout << "Hello World!\b\b\b\bA";
    cout << "Hello World!\rGood bye...";
    cin.get(); // ожидание нажатия ВВОДА <ENTER>
}


#include <iostream>
#include <Windows.h>  // Sleep() 
using namespace std;

// Анимация вывода текста на экран

int main() {

    cout << "Hello World!\r"; Sleep(250); // "уснуть" на 250 милисекунд
    cout << " Hello World! \r"; Sleep(250);
    cout << "  Hello World!\r"; Sleep(250);
    cout << "   Hello World!\r"; Sleep(250);
    cout << "    Hello World!\r"; Sleep(250);
    cout << "     Hello World!\r"; Sleep(250);
    cout << "      Hello World!\r"; Sleep(250);
    cout << "       Hello World!\r"; Sleep(250);
    cout << "        Hello World!\r"; Sleep(250);
    cout << "         Hello World!\r"; Sleep(250);
    cout << "          Hello World!\r"; Sleep(250);
    cout << "           Hello World!\r"; Sleep(250);
    cout << "          Hello World! \r"; Sleep(250);
    cout << "         Hello World! \r"; Sleep(250);
    cout << "        Hello World! \r"; Sleep(250);
    cout << "       Hello World! \r"; Sleep(250);
    cout << "      Hello World! \r"; Sleep(250);
    cout << "     Hello World! \r"; Sleep(250);
    cout << "    Hello World! \r"; Sleep(250);
    cout << "   Hello World! \r"; Sleep(250);
    cout << "  Hello World! \r"; Sleep(250);
    cout << " Hello World! \r"; Sleep(250);
    cout << "Hello World! \r"; Sleep(250);

    cin.get(); // ожидание нажатия ВВОДА <ENTER>
}


#include <iostream>
#include <Windows.h>  // Sleep() 
using namespace std;

// Анимация вывода текста на экран

int main() {

    // char - character - один символ
    cout << char(201)
        << (char)205 << (char)205 << (char)205 << (char)205
        << char(187) << endl;
    cout << char(186) << "    " << (char)186 << "\n";
    cout << char(186) << "    " << (char)186 << "\n";
    cout << char(186) << "    " << (char)186 << "\n";
    cout << char(186) << "    " << (char)186 << "\n";
    cout << char(186) << "    " << (char)186 << "\n";
    cout << char(200)
        << (char)205 << (char)205 << (char)205 << (char)205
        << char(188) << endl;

    cin.get(); // ожидание нажатия ВВОДА <ENTER>
}
