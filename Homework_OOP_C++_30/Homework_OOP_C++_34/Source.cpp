
/*Задание
Реализуйте класс "Член Семьи".
В классе заведите переменные: "Название члена семьи", "Текущий расход", "Суммарный расход" и пр.
Реализуйте конструкторы, деструкторы, методы класса для доступа к переменным класса.
В классе описать статическую переменную - "Бюджет семьи".
Реализуйте статическую функцию установки исходного значения бюджета.
Реализуйте метод класса - "расход из бюджета". Расход можно представить, как уменьшение бюджета на случайную ограниченную величину.

В программе объявить членов семьи, например: Мама, Папа, Дочь, Сын.
Задать исходное значение бюджета.
Каждый член такой семьи будет случайным образом расходовать бюджет до его обнуления.
В итоге вывести общий расход каждого члена семьи.*/


class Family {
private:
    static int FamilyBudget;
    string FamilyMember;
    int CurrentSpend;
    int TotalSpend;
public:
    Family() :CurrentSpend(0), TotalSpend(0) { //cout << "Cработал конструктор" << endl; 
    }
    ~Family() { //cout << "Cработал деструктор" << endl; 
    }

    //setters
    static void SetFamilyBudget(int newFamilyBudget) {
        if (newFamilyBudget > 0) {
            FamilyBudget = newFamilyBudget;
        }
        else {
            cout << "Error! FamilyBudget <= 0" << endl;
        }
    }
    void SetFamilyMember(string newFamilyMember) {
        if (newFamilyMember.size() >= 3) {
            FamilyMember = newFamilyMember;
        }
        else {
            cout << "Error! FamilyMember < 3 simbols" << endl;
        }
    }
    void SetCurrentSpend(int newCurrentSpend) {
        if (newCurrentSpend > 0) {
            CurrentSpend = newCurrentSpend;
        }
        else {
            cout << "Error! CurrentSpend <= 0" << endl;
        }
    }
    void SetTotalSpend() {
        TotalSpend += GetCurrentSpend();
    }

    //getters
    static int GetFamilyBudget() {
        return FamilyBudget;
    }
    string GetFamilyMember() const {
        return FamilyMember;
    }
    int GetCurrentSpend() const {
        return CurrentSpend;
    }
    int GetTotalSpend() const {
        return TotalSpend;
    }

    //some metods
    void SpendFromBudget() {
        if (FamilyBudget >= GetCurrentSpend()) {
            FamilyBudget -= GetCurrentSpend(); //отнимаем с общего бюджета
            SetTotalSpend(); // прибавляем к расходам члена семьи
        }
        else {
            cout << "Error! Insufficient funds!" << endl; // недостаточно средств
        }
    }

};

int Family::FamilyBudget = 0;

int main() {

    int const size = 4;
    //объявить членов семьи, например: Мама, Папа, Дочь, Сын
    string FamilyMembers[size] = { "Mother  ", "Father  ", "Daughter", "Son     " };
    Family family[size];
    cout << "Family members: " << endl;
    for (int i = 0; i < size; i++) {
        family[i].SetFamilyMember(FamilyMembers[i]);
        cout << family[i].GetFamilyMember() << endl;
    }

    //Задать исходное значение бюджета.
    cout << "Enter Family Budget: " << endl;
    int FamilyBudget;
    cin >> FamilyBudget;
    Family::SetFamilyBudget(FamilyBudget);

    //Каждый член такой семьи будет случайным образом расходовать бюджет
    while (Family::GetFamilyBudget() > 0) {
        int FamMemb = RAND(0, 3);
        int Spend = RAND(100, 1000);
        if (Family::GetFamilyBudget() >= Spend) {
            family[FamMemb].SetCurrentSpend(Spend);
            family[FamMemb].SpendFromBudget();
            cout << family[FamMemb].GetFamilyMember() << " = " << family[FamMemb].GetCurrentSpend() << endl;
        }
        else { break; }
    }

    //В итоге вывести общий расход каждого члена семьи.
    cout << "\n\nTotal Family Budget = " << FamilyBudget << endl;
    cout << "-------------------------Spends of Budget---------------------------------------" << endl;
    cout << "Family member's name" << "\t" << "Total Spend from Family Budget" << endl;
    for (int i = 0; i < size; i++) {
        cout << "----------------------------------------------------------------" << endl;
        cout << family[i].GetFamilyMember() << "\t\t\t" << family[i].GetTotalSpend() << endl;
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << "Current balans of Budget = " << Family::GetFamilyBudget() << endl;

}

