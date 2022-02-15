
/*«адание 1
—оздайте класс Date, который будет содержать информацию о дате
(день, мес€ц, год).
— помощью механизма перегрузки операторов, определите:
 - операцию (-) разности двух дат (результат в виде количества дней между датами);
 - операцию (+=) увеличени€ даты на определенное количество дней;
 - операцию (-=) уменьшение даты на определенное количество дней.
*/

/*
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


class Date {
private:
    int  DD, MM, YYYY; // DD - день, MM - мес€ц, YYYY - год
    bool IsVysGod; // хранит параметр true/false - высокосный.невысокосный год
public:
    //Constructors
    Date() :DD(1), MM(1), YYYY(1970), IsVysGod(true){};
    Date(int  DD, int MM, int YYYY, bool IsVysGod) :DD(DD), MM(MM), YYYY(YYYY), IsVysGod(IsVysGod) {}
    //Setters
    void SetDD(int newDD) {if (newDD > 0) {DD = newDD;}
        else { cout << "ќшибка! ƒата ниже или равна нулю" << endl; }}
    void SetMM(int newMM) {if (newMM > 0) { MM = newMM; }
        else { cout << "ќшибка! ћес€ц ниже или равен нулю" << endl; }}
    void SetYYYY(int newYYYY) {
        if (newYYYY > 0) { YYYY = newYYYY; }
        else { cout << "ќшибка! √од ниже или равен нулю" << endl; }
    }
    void Set(int  DD, int MM, int YYYY) {
        SetDD(DD); SetMM(MM); SetYYYY(YYYY);}

    //Getters
    int GetDD()const { return DD; }
    int GetMM()const { return MM; }
    int GetYYYY()const { return YYYY; }
    bool GetIsVysGod() const { //вычисл€ет и возращает параметр true/false - высокосный или невысокосный год
        if (((YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400)) { return true; }
                                                           else { return false; }
     }
    int GetDaysInMonth() { // возвращает дней в мес€це
        int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (GetIsVysGod()) { DaysInMonth[1] = 29; } // если год высокосный то +1 к февралю
        return DaysInMonth[MM - 1]; //
    }
    int GetDaysInYear() { // // возвращает дней в году на основе прошедших мес€цев + дата мес€ца
        int CountDaysInYear =0; // счетчик количества дней
        for (int i = 0; i < this->MM; i++) { // в цикле вычисл€ем количества дней в году
            CountDaysInYear += GetDaysInMonth();
        }
        return CountDaysInYear + this->DD;
    }
    int GetDaysInDate() { // возращает количество дней в дате
        return YYYY * 365 + (YYYY - 1) / 4 - (YYYY - 1) / 100 + (YYYY - 1) / 400 + GetDaysInYear();
    }
    // operator -
    const int operator-( Date& obj) { // возвращает разницу между двум€ датами
        if (GetDaysInDate() > obj.GetDaysInDate()) { // в зависимости от того кака€ дата старше отнимаем от нее
            return GetDaysInDate() - obj.GetDaysInDate();
        }
        else { return obj.GetDaysInDate() - GetDaysInDate(); }
    }
    // operator +=
    Date& operator+=(int DD) { // возращает дату плюс прибавл€емое количество дней
        if (this->DD + DD > GetDaysInMonth()) { // провер€ем если прибавл€емое кол.дней выходит за рамки кол.дней в мес€це
            DD -= GetDaysInMonth() - this->DD;
            if (++this->MM > 12) {
                this->MM = 1;
                this->YYYY++;
            }
            while (DD / GetDaysInMonth()) {
                if (++this->MM > 12) {
                    this->MM = 1;
                    this->YYYY++;
                }
                DD -= GetDaysInMonth();
            }
            this->DD = DD;
        }
        else { this->DD += DD; } //если нет то просто суммируем к числу количество дней
        return *this;
    }
    // operator -=
    Date& operator-=(int DD) {// возращает дату минус отнимаемое количество дней
        if (this->DD - DD < 1) {
            DD -= this->DD;
            if (--this->MM == 0) {
                this->MM = 12;
                this->YYYY--;
            }
            while (DD / GetDaysInMonth()) {
                DD -= GetDaysInMonth();
                if (--this->MM == 0) {
                    this->MM = 12;
                    this->YYYY--;
                }
            }
            this->DD = GetDaysInMonth() - DD;
        }
        else { this->DD -= DD; }
        return *this;
    }

    // Input
    friend istream& operator >> (istream& is, Date& obj) {
        int tmpDD;
        int tmpMM;
        int tmpYYYY;
        cout << "\n¬ведите дату в формате DD MM YYYY: ";
        is >> tmpDD >> tmpMM >> tmpYYYY;
        obj.Set(tmpDD, tmpMM, tmpYYYY);
        return is;
    }

    // Output
    friend ostream& operator <<(ostream& os, const Date& obj)
    {
        os << obj.GetDD() << "-" << obj.GetMM() << "-" << obj.GetYYYY();
        return os;
    }
};

int main()
{
    Date  A, B;
    cin >> A >> B;
    cout << endl << "--------------Reusult-------------" << endl;
    cout << fixed << setprecision(2) << "Date 1 = " << A.GetDD() << "-" << A.GetMM() << "-" << A.GetYYYY() << endl;
    cout << "Date 2 = " << B.GetDD() << "-" << B.GetMM() << "-" << B.GetYYYY() << endl;
    cout << "Date 1 - Date 2 = " << (A - B) << endl;
    cout << "Date 1 += 10 дней = " << (A += 10) << endl;
    cout << "Date 2 -= 10 дней = " << (B -= 10) << endl;
}
*/


/*
ƒополнительное задание

«адача є2 из файла "Lab_C++_week_3.pdf"
–еализовать класс var - "”ниверсальна€ переменна€"
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

const string operator * (const string& leftStr, const string& rightStr);
const string operator / (const string& leftStr, const string& rightStr);
const string operator - (const string& leftStr, const string& rightStr);

class Var
{
private:
    int* pInt;
    double* pDouble;
    string* pStr;
    int TypeVar; //0 - int, 1 - double, 2- string
public:
    //constructors
    Var() :pInt(NULL), pDouble(NULL), pStr(NULL), TypeVar(-1) { };

    Var(const int& number) {
        pInt = new int(number);
        TypeVar = 0;
    };
    Var(const double& number) {
        pDouble = new double(number);
        TypeVar = 1;
    };
    Var(const string& str) {
        pStr = new string(str);
        TypeVar = 2;
    };

    void Print() {
        switch (TypeVar)
        {
        case 0: cout << *pInt; break;
        case 1: cout << *pDouble; break;
        case 2: cout << *pStr; break;
        default:cout << "NULL"; break;
        }
    };
    int ConvertToInt()const {
        switch (TypeVar)
        {
        case 0: return *pInt;
        case 1: return (int)*pDouble;
        case 2: return atoi((*pStr).c_str());
        }
        return 0;
    };
    double ConvertToDouble()const {
        switch (TypeVar)
        {
        case 0: return (double)*pInt;
        case 1: return *pDouble;
        case 2: return (double)atof((*pStr).c_str());
        }
        return 0;
    };
    char* ConvertToChar()const {
        char* tmpStr = new char[80];
        switch (TypeVar)
        {
        case 0:
            return _itoa(*pInt, tmpStr, 10);
        case 1:
            sprintf(tmpStr, "%d", *pDouble);
            return tmpStr;
        case 2:
            strcpy(tmpStr, (*pStr).c_str());
            return tmpStr;
        }
        return NULL;
    };
    const string ConvertToString()const {
        if (TypeVar == 2)
        {
            return string(*pStr);

        }
        return string(ConvertToChar());
    };

    const Var operator + (const Var& obj) {
        switch (TypeVar)
        {
        case 0:
            return Var(*pInt + obj.ConvertToInt());

        case 1:
            return Var(*pDouble + obj.ConvertToDouble());

        case 2:
            return Var(*pStr + obj.ConvertToString());

        }
        return *this;

    };

    const Var operator - (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            return Var(*pInt - obj.ConvertToInt());
        case 1:
            return Var(*pDouble - obj.ConvertToDouble());

        case 2:
            return Var(*pStr - obj.ConvertToString());

        }
        return *this;
    }

    const Var operator * (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            return Var(*pInt * obj.ConvertToInt());

        case 1:
            return Var(*pDouble * obj.ConvertToDouble());

        case 2:
            return Var(*pStr * obj.ConvertToString());

        }
        return *this;
    }
    const Var operator / (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            return Var(*pInt / obj.ConvertToInt());

        case 1:
            return Var(*pDouble / obj.ConvertToDouble());

        case 2:
            return Var(*pStr / obj.ConvertToString());

        }
        return *this;
    }
    Var& operator += (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            *pInt = *pInt + obj.ConvertToInt();
            return *this;
        case 1:
            *pDouble = *pDouble + obj.ConvertToDouble();
            return *this;
        case 2:
            *pStr = *pStr + obj.ConvertToString();
            return *this;
        }
        return *this;
    }
    Var& operator -= (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            *pInt = *pInt - obj.ConvertToInt();
            return *this;
        case 1:
            *pDouble = *pDouble - obj.ConvertToDouble();
            return *this;
        case 2:
            *pStr = *pStr - obj.ConvertToString();
            return *this;
        }
        return *this;
    }
    Var& operator *= (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            *pInt = *pInt * obj.ConvertToInt();
            break;
        case 1:
            *pDouble = *pDouble * obj.ConvertToDouble();
            break;
        case 2:
            *pStr = *pStr * obj.ConvertToString();
            break;
        }
        return *this;
    }
    Var& operator /= (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            *pInt = *pInt / obj.ConvertToInt();
            break;
        case 1:
            *pDouble = *pDouble / obj.ConvertToDouble();
            break;
        case 2:
            *pStr = *pStr / obj.ConvertToString();
            break;
        }
        return *this;
    }
    bool operator > (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            return *pInt > obj.ConvertToInt();
        case 1:
            return *pDouble > obj.ConvertToDouble();
        case 2:
            return *pStr > obj.ConvertToString();
        }
        return false;
    }
    bool operator < (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            return *pInt < obj.ConvertToInt();
        case 1:
            return *pDouble < obj.ConvertToDouble();
        case 2:
            return *pStr < obj.ConvertToString();
        }
        return false;
    }
    bool operator == (const Var& obj)
    {
        switch (TypeVar)
        {
        case 0:
            return *pInt == obj.ConvertToInt();
        case 1:
            return *pDouble == obj.ConvertToDouble();
        case 2:
            return *pStr == obj.ConvertToString();
        }
        return false;
    }

    bool operator <= (const Var& obj)
    {
        return(!(*this > obj));
    }
    bool operator >= (const Var& obj)
    {
        return(!(*this < obj));
    }
    bool operator != (const Var& obj)
    {
        return(!(*this == obj));
    }

    Var& operator =(const Var& obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        switch (TypeVar)
        {
        case 0:
            delete pInt;
            break;
        case 1:
            delete pDouble;
            break;
        case 2:
            delete pStr;
            break;
        }
        TypeVar = -1;
        switch (obj.TypeVar)
        {
        case 0:
            pInt = new int(*(obj.pInt));
            break;
        case 1:
            pDouble = new double(*(obj.pDouble));
            break;
        case 2:
            pStr = new string(*(obj.pStr));
            break;
        }
        TypeVar = obj.TypeVar;
        return *this;
    }

    Var& operator = (const int& number) {
        switch (TypeVar)
        {
        case 0:
            delete pInt;
            break;
        case 1:
            delete pDouble;
            break;
        case 2:
            delete pStr;
            break;
        }
        TypeVar = 0;
        pInt = new int(number);
        return *this;
    };

    Var& operator = (const double& number) {
        switch (TypeVar)
        {
        case 0:
            delete pInt;
            break;
        case 1:
            delete pDouble;
            break;
        case 2:
            delete pStr;
            break;
        }
        TypeVar = 1;
        pDouble = new double(number);
        return *this;
    };

    Var& operator = (const string& str) {
        switch (TypeVar)
        {
        case 0:
            delete pInt;
            break;
        case 1:
            delete pDouble;
            break;
        case 2:
            delete pStr;
            break;
        }
        TypeVar = 2;
        pStr = new string(str);
        return *this;
    };
    friend const string operator * (const string& leftStr, const string& rightStr)
    {
        string tmp;
        string::const_iterator i;
        string::const_iterator j;
        for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
            for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
                if (*i == *j)
                {
                    tmp.push_back(*i);
                    break;
                }
        return tmp;
    }

    friend const string operator / (const string& leftStr, const string& rightStr)
    {
        bool flag = true;
        string tmp;
        string::const_iterator i;
        string::const_iterator j;
        for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
        {
            for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
            {
                if (*i == *j)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                flag = true;
                continue;
            }
            tmp.push_back(*i);
        }
        return tmp;

    }

    friend const string operator - (const string& leftStr, const string& rightStr)
    {
        return leftStr;
    };
};

int main()
{
    Var a = 15;
    Var b = string("Hello");
    Var c = 7.8;
    Var d = string("50");
    b = a + d;
    b.Print();// ¬ыведет 65
    if (a == b) cout << "\nEqual\n";
    else cout << "\nNot Equal\n";
    cout << endl;

    Var a1 = 10, b1 = string("120"), c1;
    c1 = a1 + b1;
    c1.Print();// ¬ыведет 130
    cout << endl;
    c1 = b1 + a1;
    c1.Print(); // ¬ыведет У12010Ф
    cout << endl;

    Var a2 = string("Microsoft"), b2 = string("Windows"), c2;
    c2 = a2 * b2;
    c2.Print();// ¬ыведет УiosoФ
    cout << endl;

    Var a3 = string("Microsoft"), b3 = string("Windows"), c3;
    c3 = a3 / b3;
    c3.Print();// ¬ыведет УMcrftФ
}
