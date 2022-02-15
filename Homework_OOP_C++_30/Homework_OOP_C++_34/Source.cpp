
/*�������
���������� ����� "���� �����".
� ������ �������� ����������: "�������� ����� �����", "������� ������", "��������� ������" � ��.
���������� ������������, �����������, ������ ������ ��� ������� � ���������� ������.
� ������ ������� ����������� ���������� - "������ �����".
���������� ����������� ������� ��������� ��������� �������� �������.
���������� ����� ������ - "������ �� �������". ������ ����� �����������, ��� ���������� ������� �� ��������� ������������ ��������.

� ��������� �������� ������ �����, ��������: ����, ����, ����, ���.
������ �������� �������� �������.
������ ���� ����� ����� ����� ��������� ������� ����������� ������ �� ��� ���������.
� ����� ������� ����� ������ ������� ����� �����.*/


class Family {
private:
    static int FamilyBudget;
    string FamilyMember;
    int CurrentSpend;
    int TotalSpend;
public:
    Family() :CurrentSpend(0), TotalSpend(0) { //cout << "C������� �����������" << endl; 
    }
    ~Family() { //cout << "C������� ����������" << endl; 
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
            FamilyBudget -= GetCurrentSpend(); //�������� � ������ �������
            SetTotalSpend(); // ���������� � �������� ����� �����
        }
        else {
            cout << "Error! Insufficient funds!" << endl; // ������������ �������
        }
    }

};

int Family::FamilyBudget = 0;

int main() {

    int const size = 4;
    //�������� ������ �����, ��������: ����, ����, ����, ���
    string FamilyMembers[size] = { "Mother  ", "Father  ", "Daughter", "Son     " };
    Family family[size];
    cout << "Family members: " << endl;
    for (int i = 0; i < size; i++) {
        family[i].SetFamilyMember(FamilyMembers[i]);
        cout << family[i].GetFamilyMember() << endl;
    }

    //������ �������� �������� �������.
    cout << "Enter Family Budget: " << endl;
    int FamilyBudget;
    cin >> FamilyBudget;
    Family::SetFamilyBudget(FamilyBudget);

    //������ ���� ����� ����� ����� ��������� ������� ����������� ������
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

    //� ����� ������� ����� ������ ������� ����� �����.
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

