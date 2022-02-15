/*Домашнее задание

Задание 1
Выбрать объект реального мира (например Телефон, Кошка, Дом и пр.)
Реализовать класс для этого объекта - описать для него свойства и методы:
 * переменные класса;
 * методы сеттеры/геттеры;
 * перегруженные операторы ввода-вывода информации с/на консоль;
 * конструкторы.
*/


#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

class Cat {
private:
    string breed;
    string name;
    string golos;
    int age;
protected:
    string color;
public:
    // Конструктор
    Cat() :age(0), breed("unknown"), name("unknown"), golos("unknown"), color("unknown") {}

    // Деструктор
    ~Cat() {};

    // Методы сеттеры
    void setAge(int age) { this->age = age; }
    void setBreed(string breed) { this->breed = breed; }
    void setName(string name) { this->name = name; }
    void setGolos(string golos) { this->golos = golos; }
    void setColor(string color) { this->color = color; }
    // Методы геттеры
    int getAge() const { return age; }
    string getBreed() const { return breed; }
    string getName() const { return name; }
    string getGolos() const { return golos; }
    string getColor() const { return color; }

    // Методы ввода и вывода
    friend ostream& operator<<(ostream& os, const Cat& obj)
    {
        cout << "breed = " << obj.getBreed() << endl;
        cout << "name = " << obj.getName() << endl;
        cout << "golos = " << obj.getGolos() << endl;
        cout << "age = " << obj.getAge() << endl;
        cout << "color = " << obj.getColor() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Cat& obj) {
        string tmpS;
        int tmpI;
        cout << "Enter breed : "; getline(is, tmpS); obj.setBreed(tmpS);
        cout << "Enter name : "; getline(is, tmpS); obj.setName(tmpS);
        cout << "Enter golos : "; getline(is, tmpS); obj.setGolos(tmpS);
        cout << "Enter age : "; is >> tmpI; is.ignore();  obj.setAge(tmpI);
        cout << "Enter color : "; getline(is, tmpS); obj.setColor(tmpS);
        return is;
    }
}; //Cat


int main()
{
    Cat cat;
    cin >> cat;
    cout << endl << endl << cat;
}

