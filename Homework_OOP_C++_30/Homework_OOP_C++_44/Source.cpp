
/*Домашнее задание
Тема: Наследование

Задание 1.
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай».
С помощью конструктора установить имя каждого животного и его характеристики.*/
/*
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


 Наследование
*/
/*
// базовый класс
class Pet {
private:
    string type;
    string name;
    string golos;
    int age;
protected:
    string color;
public:
    // методы
    Pet() :age(0), type("unknown"), name("unknown"), golos("unknown"), color("unknown"){}

    void setAge(int age) { this->age = age; }
    void setType(string type) { this->type = type; }
    void setName(string name) { this->name = name; }
    void setGolos(string golos) { this->golos = golos; }
    void setColor(string color) { this->color = color; }

    int getAge() const { return age;}
    string getType() const { return type; }
    string getName() const { return name; }
    string getGolos() const { return golos; }
    string getColor() const { return color; }

    friend ostream& operator<<(ostream& os, const Pet& obj)
    {
        cout << "type = " << obj.getType() << endl;
        cout << "name = " << obj.getName() << endl;
        cout << "golos = " << obj.getGolos() << endl;
        cout << "age = " << obj.getAge() << endl;
        cout << "color = " << obj.getColor() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Pet& obj) {
        string tmpS;
        int tmpI;
        cout << "Enter type : "; getline(is, tmpS); obj.setType(tmpS);
        cout << "Enter name : "; getline(is, tmpS); obj.setName(tmpS);
        cout << "Enter golos : "; getline(is, tmpS); obj.setGolos(tmpS);
        cout << "Enter age : "; is >> tmpI; is.ignore();  obj.setAge(tmpI);
        cout << "Enter color : "; getline(is, tmpS); obj.setColor(tmpS);
        return is;
    }
}; //Pet

// дочерний, производный класс Dog
//  от родительского класса Pet
class Dog : public Pet
{
private:
    string breef;
public:
    Dog() :breef("unknown") {}
    string getBreef() const { return breef; }
    void setBreef(string breef) { this->breef = breef; }

    friend ostream& operator<<(ostream& os, const Dog& obj)
    {
        cout << endl;

        os << (Pet&)obj;
        cout << "breef = " << obj.getBreef() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Dog& obj) {
        string tmpS;
        cout << "** Dog **\n";
        is >> (Pet&)obj;
        cout << "Enter breef : "; getline(is, tmpS); obj.setBreef(tmpS);
        return is;
    }
};

// дочерний, производный класс Cat
//  от родительского класса Pet
class Cat : public Pet
{
private:
    int lifes;

public:
    Cat() :lifes(9) {}
    int getLifes() const { return lifes; }
    void setLifes(int lifes) { this->lifes = lifes; }

    friend ostream& operator<<(ostream& os, const Cat& obj)
    {
        cout << endl;
        cout << "** Cat **\n";
        os << (Pet&)obj;
        cout << "lifes = " << obj.getLifes() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Cat& obj) {
        int tmpI;
        cout << "** Cat **\n";
        is >> (Pet&)obj;
        cout << "Enter lifes : "; is >> tmpI; is.ignore();  obj.setLifes(tmpI);
        return is;
    }
};

// дочерний, производный класс Cat
//  от родительского класса Pet
class Parrot : public Pet
{
private:
    bool speaking;
    bool flies;
public:
    Parrot() :speaking(false), flies(false) {}
    bool getSpeaking() const { return speaking; }
    bool getFlies() const { return flies; }
    void setSpeaking(bool speaking) { this->speaking = speaking; }
    void setFlies(bool flies) { this->flies = flies; }

    friend ostream& operator<<(ostream& os, const Parrot& obj)
    {
        cout << endl;
        cout << "** Parrot **\n";
        os << (Pet&)obj;
        cout << "speaking = " << boolalpha << obj.getSpeaking() << endl;
        cout << "fliing = " << boolalpha << obj.getFlies() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Parrot& obj) {
        char tmpS;
        cout << "** Parrot **\n";
        is >> (Pet&)obj;
        cout << "Enter speaking(y/n) : "; is >> tmpS; is.ignore(); if (tmpS == 'y') { obj.setSpeaking(true); }
        else if (tmpS == 'n') { obj.setSpeaking(false); }
        else { cout << "Incorrect papametr!" << endl; }
        cout << "Enter fliing(y/n) : "; is >> tmpS; is.ignore(); if (tmpS == 'y') { obj.setFlies(true); }
        else if (tmpS == 'n') { obj.setFlies(false); }
        else { cout << "Incorrect papametr!" << endl; }
        return is;
    }
};

int main()
{
    Dog dog;
    cin >> dog;
    cout << dog;
    cout << endl;

    Cat cat;
    cin >> cat;
    cout << cat;
    cout << endl;

    Parrot parrot;
    cin >> parrot;
    cout << parrot;
}
*/

/*Задание 2
Создать базовый класс <Транспортное средство> и производные классы <Автомобиль>, <Велосипед>, <Повозка>.
Подсчитать время и стоимость перевозки пассажиров и грузов каждым транспортным средством.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// базовый класс
class Transport {
private:
    int time;
    int km;
    int coast;
    int kg;
protected:
    int cntPass;
public:
    // методы
    Transport() :time(), km(), coast(), kg(), cntPass() {}

    void setTime(int time) { this->time = time; }
    void setKm(int km) { this->km = km; }
    void setCoast(int coast) { this->coast = coast; }
    void setKg(int kg) { this->kg = kg; }
    void setCntPass(int cntPass) { this->cntPass = cntPass; }

    int getTime() const { return time; }
    int getKm() const { return km; }
    int getCoast() const { return coast; }
    int getKg() const { return kg; }
    int getCntPass() const { return cntPass; }


    friend ostream& operator<<(ostream& os, const Transport& obj)
    {
        cout << "time = " << obj.getTime() << endl;
        cout << "km = " << obj.getKm() << endl;
        cout << "coast = " << obj.getCoast() << endl;
        cout << "kg = " << obj.getKg() << endl;
        cout << "cntPass = " << obj.getCntPass() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Transport& obj) {
        int tmpI;
        cout << "Enter time : "; is >> tmpI; is.ignore(); obj.setTime(tmpI);
        cout << "Enter km : "; is >> tmpI; is.ignore(); obj.setKm(tmpI);
        cout << "Enter coast : "; is >> tmpI; is.ignore(); obj.setCoast(tmpI);
        cout << "Enter kg : "; is >> tmpI; is.ignore();  obj.setKg(tmpI);
        cout << "Enter cntPass : "; is >> tmpI; is.ignore(); obj.setCntPass(tmpI);
        return is;
    }

    int Calculator() {
        return (this->getTime() + this->getKm() + this->getKg() + this->getCntPass()) * this->getCoast();
    }
}; //Transport

// дочерний, производный класс Dog
//  от родительского класса Transport
class Automobile : public Transport
{
private:
    int cntGasoline;
    string type;
public:
    Automobile() :cntGasoline(), type("unknown") {}
    int getCntGasoline() const { return cntGasoline; }
    string getType() const { return type; }
    void setCntGasoline(int cntGasoline) { this->cntGasoline = cntGasoline; }
    void setType(string type) { this->type = type; }

    friend ostream& operator<<(ostream& os, const Automobile& obj)
    {
        cout << endl;
        cout << "** Automobile **\n";
        os << (Transport&)obj;
        cout << "type = " << obj.getType() << endl;
        cout << "cntGasoline = " << obj.getCntGasoline() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Automobile& obj) {
        string tmpS;
        int tmpI;
        cout << "** Automobile **\n";
        is >> (Transport&)obj;
        cout << "Enter type : "; getline(is, tmpS); obj.setType(tmpS);
        cout << "Enter cntGasoline : "; is >> tmpI; is.ignore(); obj.setCntGasoline(tmpI);
        return is;
    }
    int Calculator() {
        return Transport::Calculator() + (this->getCntGasoline() * this->getCoast());
    }
};

// дочерний, производный класс Bike
//  от родительского класса Transport
class  Bike : public Transport
{
private:
    bool basket;
    int cntSeats;
public:
    Bike() :basket(false), cntSeats() {}
    bool getBasket() const { return basket; }
    int getCntSeats() const { return cntSeats; }
    void setBasket(bool basket) { this->basket = basket; }
    void setCntSeats(int cntSeat) { this->cntSeats = cntSeat; }

    friend ostream& operator<<(ostream& os, const Bike& obj)
    {
        cout << endl;
        cout << "** Bike **\n";
        os << (Transport&)obj;
        cout << "basket = " << boolalpha << obj.getBasket() << endl;
        cout << "cntSeats = " << obj.getCntSeats() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Bike& obj) {
        int tmpI;
        char tmpS;
        cout << "** Bike **\n";
        is >> (Transport&)obj;
        cout << "Enter basket(y/n) : "; is >> tmpS; is.ignore(); if (tmpS == 'y') { obj.setBasket(true); }
        else if (tmpS == 'n') { obj.setBasket(false); }
        else { cout << "Incorrect papametr!" << endl; }
        cout << "Enter cntSeats : "; is >> tmpI; is.ignore();  obj.setCntSeats(tmpI);
        return is;
    }

    int Calculator() {
        return Transport::Calculator() + ((this->getCntSeats() + int(this->getBasket())) * this->getCoast());
    }
};

// дочерний, производный класс Carriage
//  от родительского класса Transport
class Carriage : public Transport
{
private:
    int cntHorses;
    int cntSeats;
public:
    Carriage() :cntHorses(), cntSeats() {}
    int getCntHorses() const { return cntHorses; }
    int getCntSeats() const { return cntSeats; }
    void setCntHorses(int cntHorses) { this->cntHorses = cntHorses; }
    void setCntSeats(int cntSeats) { this->cntSeats = cntSeats; }

    friend ostream& operator<<(ostream& os, const Carriage& obj)
    {
        cout << endl;
        cout << "** Carriage **\n";
        os << (Transport&)obj;
        cout << "cntHorses = " << obj.getCntHorses() << endl;
        cout << "cntSeats = " << obj.getCntSeats() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Carriage& obj) {
        int tmpI;
        cout << "** Carriage **\n";
        is >> (Transport&)obj;
        cout << "Enter cntSeats : "; is >> tmpI; is.ignore();  obj.setCntSeats(tmpI);
        cout << "Enter cntHorses : "; is >> tmpI; is.ignore();  obj.setCntHorses(tmpI);
        return is;
    }

    int Calculator() {
        return Transport::Calculator() + ((this->getCntHorses() + getCntSeats()) * this->getCoast());
    }
};

int main()
{
    Automobile automobile;
    cin >> automobile;
    cout << automobile;
    cout << "Итоговая стоимость: $" << automobile.Calculator();
    cout << endl << endl;

    Bike bike;
    cin >> bike;
    cout << bike;
    cout << "Итоговая стоимость: $" << bike.Calculator();

    cout << endl << endl;

    Carriage carriage;
    cin >> carriage;
    cout << carriage;
    cout << "Итоговая стоимость: $" << carriage.Calculator();

}
