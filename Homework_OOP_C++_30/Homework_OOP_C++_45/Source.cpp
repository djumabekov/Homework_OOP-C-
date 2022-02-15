/*
Домашнее задание
Тема: 31-32. Наследование. Множественное наследование, виртуальный базовый класс

Задание 1
Используя механизм множественного наследования разработайте класс "Автомобиль".
Должны быть классы "Колеса", "Двигатель", "Двери" и т.д.
*/
/*
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// класс "Колеса"
class Wheels{
private:
    float radius;
    string disk; //стальной, литой или кованный
public:
    Wheels() :radius(), disk("unknown") {}
    Wheels(float radius, string disk) :radius(radius), disk(disk){}

    void SetRadius(float radius) { this->radius = radius; }
    float GetRadius()const { return radius; }
    void SetDisk(string disk) { this->disk = disk; }
    string GetDisk()const { return disk; }

    friend ostream& operator<<(ostream& os, const Wheels& obj) {
        os << "TypeID :" << typeid(obj).name() << endl;
        cout << "radius = " << obj.GetRadius() << endl;
        cout << "disk = " << obj.GetDisk() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Wheels& obj) {
        float tmpF; string tmpS;
        cout << "TypeID :" << typeid(obj).name() << endl;
        cout << "Enter radius : "; is >> tmpF; is.ignore();  obj.SetRadius(tmpF);
        cout << "Enter disk : "; getline(is, tmpS); obj.SetDisk(tmpS);
        return is;
    }
};

// класс ""Двигатель", "
class Engine {
private:
    float volume;
    string fuel; //бензин, дизель и т.д.
public:
    Engine() :volume(), fuel("unknown") {}
    Engine(float volume, string fuel) :volume(volume), fuel(fuel) {}

    void SetVolume(float volume) { this->volume = volume; }
    float GetVolume()const { return volume; }
    void SetFuel(string fuel) { this->fuel = fuel; }
    string GetFuel()const { return fuel; }

    friend ostream& operator<<(ostream& os, const Engine& obj) {
        os << "TypeID :" << typeid(obj).name() << endl;
        cout << "volume = " << obj.GetVolume() << endl;
        cout << "fuel = " << obj.GetFuel() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Engine& obj) {
        float tmpF; string tmpS;
        cout << "TypeID :" << typeid(obj).name() << endl;
        cout << "Enter volume : "; is >> tmpF; is.ignore();  obj.SetVolume(tmpF);
        cout << "Enter fuel : "; getline(is, tmpS); obj.SetFuel(tmpS);
        return is;
    }
};

// класс "Двери"
class Doors {
private:
    int cnt;
    string position; //вертикальные, горизонтальные
public:
    Doors() :cnt(), position("unknown") {}
    Doors(int cnt, string position) :cnt(cnt), position(position) {}

    void SetСnt(int cnt) { this->cnt = cnt; }
    int GetСnt()const { return cnt; }
    void SetPosition(string position) { this->position = position; }
    string GetPosition()const { return position; }

    friend ostream& operator<<(ostream& os, const Doors& obj) {
        os << "TypeID :" << typeid(obj).name() << endl;
        cout << "cnt = " << obj.GetСnt() << endl;
        cout << "position = " << obj.GetPosition() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Doors& obj) {
        int tmpI; string tmpS;
        cout << "TypeID :" << typeid(obj).name() << endl;
        cout << "Enter cnt : "; is >> tmpI; is.ignore();  obj.SetСnt(tmpI);
        cout << "Enter position : "; getline(is, tmpS); obj.SetPosition(tmpS);
        return is;
    }
};


// класс "Коробка передач"
class Transmission {
private:
    int cntSpeeds;
    string types; //автоматич, механич, робвиды коробки предачот
public:
    Transmission() :cntSpeeds(), types("unknown") {}
    Transmission(int cntSpeeds, string types) :cntSpeeds(cntSpeeds), types(types) {}

    void SetСntSpeeds(int cntSpeeds) { this->cntSpeeds = cntSpeeds; }
    int GetСntSpeeds()const { return cntSpeeds; }
    void SetTypes(string types) { this->types = types; }
    string GetTypes()const { return types; }

    friend ostream& operator<<(ostream& os, const Transmission& obj) {
        os << "TypeID :" << typeid(obj).name() << endl;
        cout << "cntSpeeds = " << obj.GetСntSpeeds() << endl;
        cout << "types = " << obj.GetTypes() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Transmission& obj) {
        int tmpI; string tmpS;
        cout << "TypeID :" << typeid(obj).name() << endl;
        cout << "Enter cntSpeeds : "; is >> tmpI; is.ignore();  obj.SetСntSpeeds(tmpI);
        cout << "Enter types : "; getline(is, tmpS); obj.SetTypes(tmpS);
        return is;
    }
};

// Производный класс "Автомобиль".
class Automobile : virtual public Wheels, virtual public Engine,
               virtual public Doors, virtual public Transmission
{
public:
    Automobile() : Wheels(), Engine(), Doors(), Transmission(){}
    Automobile(Wheels wheels, Engine engine, Doors doors, Transmission transmission)
              :Wheels(wheels), Engine(engine), Doors(doors), Transmission(transmission)
    {
        SetRadius(wheels.GetRadius()); SetDisk(wheels.GetDisk());
        SetVolume(engine.GetVolume()); SetFuel(engine.GetFuel());
        SetСnt(doors.GetСnt()); SetPosition(doors.GetPosition());
        SetСntSpeeds(transmission.GetСntSpeeds()); SetTypes(transmission.GetTypes());
    }

    friend ostream& operator<<(ostream& os, const Automobile& obj) {
        os << "TypeID :" << typeid(obj).name() << endl;
        os << (Wheels&)obj << endl;
        os << (Engine&)obj << endl;
        os << (Doors&)obj << endl;
        os << (Transmission&)obj << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Automobile& obj) {
        cout << "TypeID :" << typeid(obj).name() << endl;
        return is >> (Wheels&)obj >> (Engine&)obj >> (Doors&)obj >> (Transmission&)obj;
    }
};

int main()
{
    Automobile automobile;
    cin >> automobile;
    cout << endl << endl << automobile << endl;
}
*/

/*Задание 2
Создать базовый класс <Домашнее животное> и производные
классы <Собака>, <Кошка>, <Попугай>, <Хомяк>.
С помощью конструктора установить имя каждого животного и его характеристики.
Реализуйте для каждого из классов функции:
 Sound() - издает звук животного (пишем текстом в консоль);
 Show() - отображает имя животного;
 Type() - отображает название его подвида.*/
 /*
 #include <iostream>
 #include <string>
 #include <time.h>
 using namespace std;

 #define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
 struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

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
     Pet() :age(0), type("unknown"), name("unknown"), golos("unknown"), color("unknown") {}

     void setAge(int age) { this->age = age; }
     void setType(string type) { this->type = type; }
     void setName(string name) { this->name = name; }
     void setGolos(string golos) { this->golos = golos; }
     void setColor(string color) { this->color = color; }

     int getAge() const { return age; }
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
     string Sound() {
         return getGolos();
     }
     string Show() {
         return getName();
     }
     string Type() {
         return getType();
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

 // дочерний, производный класс Hamster
 //  от родительского класса Pet
 class Hamster : public Pet
 {
 private:
     bool swim;
     float tailLen;
 public:
     Hamster() :swim(false), tailLen() {}
     bool getSwim() const { return swim; }
     bool getTailLen() const { return tailLen; }
     void setSwim(bool swim) { this->swim = swim; }
     void setTailLen(float tailLen) { this->tailLen = tailLen; }

     friend ostream& operator<<(ostream& os, const Hamster& obj)
     {
         cout << endl;
         cout << "** Hamster **\n";
         os << (Pet&)obj;
         cout << "swim = " << boolalpha << obj.getSwim() << endl;
         cout << "tailLen = " << obj.getTailLen() << endl;
         return os;
     }

     friend istream& operator>> (istream& is, Hamster& obj) {
         char tmpS;
         float tmpF;
         cout << "** Hamster **\n";
         is >> (Pet&)obj;
         cout << "Enter swim(y/n) : "; is >> tmpS; is.ignore(); if (tmpS == 'y') { obj.setSwim(true); }
         else if (tmpS == 'n') { obj.setSwim(false); }
         else { cout << "Incorrect papametr!" << endl; }
         cout << "Enter tailLen : "; is >> tmpF; is.ignore(); obj.setTailLen(tmpF);
         return is;
     }
 };

 int main()
 {
     Dog dog;
     cin >> dog;
     cout << dog;
     cout << endl << "Sound() : " << dog.Sound();
     cout << endl << "Show() : " << dog.Show();
     cout << endl << "Type() : " << dog.Type();
     cout << endl << endl;

     Cat cat;
     cin >> cat;
     cout << cat;
     cout << endl << "Sound() : " << cat.Sound();
     cout << endl << "Show() : " << cat.Show();
     cout << endl << "Type() : " << cat.Type();
     cout << endl << endl;

     Parrot parrot;
     cin >> parrot;
     cout << parrot;
     cout << endl << "Sound() : " << parrot.Sound();
     cout << endl << "Show() : " << parrot.Show();
     cout << endl << "Type() : " << parrot.Type();
     cout << endl << endl;

     Hamster hamster;
     cin >> hamster;
     cout << hamster;
     cout << endl << "Sound() : " << hamster.Sound();
     cout << endl << "Show() : " << hamster.Show();
     cout << endl << "Type() : " << hamster.Type();
 }
 */

 /*Дополнительные задания

 Задание 3
 Используя понятие множественного наследования, разработайте класс <Окружность, вписанная в квадрат>.*/
 /*
 #include <iostream>
 #include <string>
 #include <time.h>
 using namespace std;

 #define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
 struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

 class Cilcle {
 private:
     float radius;
 public:
     // методы
     Cilcle(float radius) :radius(radius) {}
     void setRadius(float radius) { this->radius = radius; }
     int getRadius() const { return radius; }
 }; //Cilcle

 class Square {
 private:
     float side;
 public:
     // методы
     Square(float side) :side(side) {}
     void setSide(float side) { this->side = side; }
     int getSide() const { return side; }
 }; //Square

 class CircleInSquare : public Cilcle, public Square
 {
 public:
     CircleInSquare(float side, float radius) : Square(side), Cilcle(radius) { }
 };

 int main(void)
 {
     float side = 20;
     float radius = side/2;

     Square mySquare = Square(side);

     CircleInSquare circleInSquare = CircleInSquare(side, radius);
     cout << "circleInSquare: " << endl;
     cout << "Radius: " << circleInSquare.getRadius() << endl;
     cout << "Side: " << circleInSquare.getSide() << endl;
 }
 */

 /*Задание 4
 Задание 5
 Создать абстрактный базовый класс с виртуальной функцией - площадь.
 Создать производные классы: прямоугольник, круг, прямоугольный треугольник, трапеция со своими функциями площади.
 Для проверки определить массив ссылок на абстрактный класс, которым присваиваются адреса различных объектов.*/
 /*
 #include <iostream>
 #include <string>
 #include <time.h>
 using namespace std;

 #define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
 struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

 class Base
 {
 public:
     float arg1;
     float arg2;
     float arg3;
     Base(float arg1, float arg2, float arg3)
     {
         this->arg1 = arg1;
         this->arg2 = arg2;
         this->arg3 = arg3;
     }
     virtual void Calculate() {};
 };

 //прямоугольник
 class Rectangle : public Base
 {
 public:
     Rectangle(float arg1, float arg2) : Base(arg1, arg2, arg3) {};
     virtual void Calculate()
     {
         float result;
         result = arg1 * arg2;
         cout << endl;
         cout << "Площадь прямоугольника: (" << arg1 << ", " << arg2 << ") = " << result << endl;
         cout << endl;
     }
 };

 //круг
 class Circle : public Base
 {
 public:
     Circle(float arg3) : Base(arg1, arg2, arg3){};
     virtual void Calculate() {
         float result;
         result = 3.14 * arg3 * arg3;
         cout << endl;
         cout << "Площадь круга (" << arg3 << ") = " << result << "\n";
         cout << endl;
     }
 };

 //прямоугольный трегольник
 class Right_triangle : public Base
 {
 public:
     Right_triangle(float arg1, float arg2) : Base(arg1, arg2, arg3){};
     virtual void Calculate()
     {
         float result;
         cout << endl;
         result = arg1 * arg2 / 2;
         cout << "Площадь прямоугольного трегольника (" << arg1 << ", " << arg2 << ") = " << result << "\n";
         cout << endl;
     }
 };

 //трапеция
 class Trapeze : public Base
 {
 public:
     Trapeze(float arg1, float arg2, float arg3) : Base(arg1, arg2, arg3){};
     virtual void Calculate()
     {
         float result;
         cout << endl;
         result = (arg1 + arg2) / 2 * arg2;
         cout << "Площадь трапеции (" << arg1 << ", " << arg2 << ") = " << result << "\n";
         cout << endl;
     }
 };

 void main()
 {
     float arg1, arg2, arg3;

     cout << "Введите аргументы (arg1, arg2, arg3): ";
     cin >> arg1 >> arg2 >> arg3;

     Base* arr[4] = {
         new Rectangle(arg1,arg2),
         new Circle(arg3),
         new Right_triangle(arg1,arg2),
         new Trapeze(arg1,arg2,arg3)
     };

     for (int i = 0; i < 4; i++) {
         arr[i]->Calculate();
     }
 }
 */
