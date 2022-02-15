/*������� N1
���������� ����� "�����".
���������� ������� � ����������-������ ������:
�������� ������, ����, ��������, ����� ������������, ���������� ������.
���������� �������-����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ��������� ����������-������.*/
/*
class Goods {
private:
    string GoodsName;
    string DescrGoods;
    string ManufCompany;
    int CountGood;
    float CoastGood;

public:
    // ������������ ����������� ����������� �����
    Goods() {
        GoodsName = "�� ������";
        DescrGoods = "�� ������";
        ManufCompany = "�� ������";
        CountGood = 0;
        CoastGood = 0.0;
    }
    // ������ ��������
    //  ������������, setter, �������
    void  SetGoodsName(string newGoodsName) {
        if(newGoodsName.size() >=3){
        GoodsName = newGoodsName;
        }
        else { cout << "��� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetDescrGoods(string newDescrGoods) {
        if (newDescrGoods.size() >= 3) {
            DescrGoods = newDescrGoods;
        }
        else {
            cout << "�������� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetManufCompany(string newManufCompany) {
        if (newManufCompany.size() >= 3) {
            ManufCompany = newManufCompany;
        }
        else {
            cout << "�������� ������������� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetCountGood(int newCountGood) {
        if (newCountGood >= 0) {
            CountGood = newCountGood;
        }
        else {
            cout << "���������� ������ �� ����� ���� ������ ����" << endl;
        }
    };

    void  SetCoastGood(float newCoastGood) {
        if (newCoastGood > 0.0) {
            CoastGood = newCoastGood;
        }
        else {
            cout << "���� ������ �� ����� ���� ������ ��� ����� ����" << endl;
        }
    };

    //  ������ ����������, getter, �������
    string GetGoodsName() { return GoodsName; };
    string GetDescrGoods() { return DescrGoods; };
    string GetManufCompany() { return ManufCompany; };
    int GetCountGood() { return CountGood; };
    float GetCoastGood() { return CoastGood; };

    // ������ ����� ������
    void Input()
    {
        string tmpS;
        int tmpI;
        float tmpF;

        cout << "\nEnter Goods Name: ";
        getline(cin, tmpS);
        SetGoodsName(tmpS);

        cout << "\nEnter Description for Goods: ";
        getline(cin, tmpS);
        SetDescrGoods(tmpS);

        cout << "\nEnter Manufactury Company: ";
        getline(cin, tmpS);
        SetManufCompany(tmpS);

        cout << "\nEnter Count of Goods: ";
        cin >> tmpI;
        SetCountGood(tmpI);

        cout << "\nEnter Coast of Goods: ";
        cin >> tmpF;
        SetCoastGood(tmpF);

        cin.ignore();
    }
    void Print()
    {
        cout << "----------------" << endl;
        cout << "\Goods Name: " << GetGoodsName();
        cout << "\nDescription for Goods: " << GetDescrGoods();
        cout << "\nManufactury Company: " << GetManufCompany();
        cout << "\nCount of Goods: " << GetCountGood();
        cout << "\nCoast for one: $" << GetCoastGood();
        cout << endl;
    }
};

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    Goods Good1;
    Good1.Input();
    Good1.Print();

    cin.get(); cin.get();
}
*/

/*
������� N2
���������� ����� "�������".
���������� ������� � ����������-������ ������: ���, ���� ��������, ���������� �������, �����, ������, �������� �������� ���������, ����� � ������ (��� ��������� ������� ���������), ����� ������.
���������� �������-����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ��������� ����������-������. */
struct Date {
    int DD;
    int MM;
    int YYYY;
};

class Student {
private:
    string StudentFIO;
    Date DateOfBirth;
    long long PhoneNum;
    string CityOfStudentBirth;
    string CountryOfStudentBirth;
    string UniversityName;
    string CityOfUniversity;
    string CountryOfUniversity;
    int GroupNum;

public:
    // ������������ ����������� ����������� �����
    Student() {
        StudentFIO = "�� ������";
        DateOfBirth.DD = 1;
        DateOfBirth.MM = 1;
        DateOfBirth.YYYY = 1980;
        CityOfStudentBirth = "�� ������";
        CountryOfStudentBirth = "�� ������";
        UniversityName = "�� ������";
        CityOfUniversity = "�� ������";
        CountryOfUniversity = "�� ������";
        GroupNum = 1;
    }
    // ������ ��������
    //  ������������, setter, �������
    void  SetStudentFIO(string newStudentFIO) {
        if (newStudentFIO.size() >= 3) {
            StudentFIO = newStudentFIO;
        }
        else {
            cout << "��� �������� �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetDateOfBirth(Date newDateOfBirth) {
        if (newDateOfBirth.DD > 0 && newDateOfBirth.MM > 0 && newDateOfBirth.YYYY > 1980) {
            DateOfBirth.DD = newDateOfBirth.DD;
            DateOfBirth.MM = newDateOfBirth.MM;
            DateOfBirth.YYYY = newDateOfBirth.YYYY;
        }
        else {
            cout << "���� �� ���������" << endl;
        }
    };

    void  SetPhoneNum(long long newPhoneNum) {
        if (newPhoneNum >= 11) {
            PhoneNum = newPhoneNum;
        }
        else {
            cout << "����� �� ����� ���� ������ 11 ��������" << endl;
        }
    };

    void  SetCityOfStudentBirth(string newCityOfStudentBirth) {
        if (newCityOfStudentBirth.size() >= 3) {
            CityOfStudentBirth = newCityOfStudentBirth;
        }
        else {
            cout << "�������� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetCountryOfStudentBirth(string newCountryOfStudentBirth) {
        if (newCountryOfStudentBirth.size() >= 3) {
            CountryOfStudentBirth = newCountryOfStudentBirth;
        }
        else {
            cout << "�������� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetUniversityName(string newUniversityName) {
        if (newUniversityName.size() >= 3) {
            UniversityName = newUniversityName;
        }
        else {
            cout << "�������� ������������� �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetCityOfUniversity(string newCityOfUniversity) {
        if (newCityOfUniversity.size() >= 3) {
            CityOfUniversity = newCityOfUniversity;
        }
        else {
            cout << "�������� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetCountryOfUniversity(string newCountryOfUniversity) {
        if (newCountryOfUniversity.size() >= 3) {
            CountryOfUniversity = newCountryOfUniversity;
        }
        else {
            cout << "�������� ������ �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetGroupNum(int newGroupNum) {
        if (newGroupNum > 0) {
            GroupNum = newGroupNum;
        }
        else {
            cout << "����� ������ �� ����� ���� ������ ��� ����� ����" << endl;
        }
    };

    //  ������ ����������, getter, �������
    string GetStudentFIO() { return StudentFIO; };
    Date GetDateOfBirth() { return DateOfBirth; };
    long long GetPhoneNum() { return PhoneNum; };
    string GetCityOfStudentBirth() { return CityOfStudentBirth; };
    string  GetCountryOfStudentBirth() { return CountryOfStudentBirth; };
    string  GetUniversityName() { return UniversityName; };
    string  GetCityOfUniversity() { return CityOfUniversity; };
    string  GetCountryOfUniversity() { return CountryOfUniversity; };
    int GetGroupNum() { return GroupNum; };

    // ������ ����� ������
    void Input()
    {
        string tmpS;
        int tmpI;
        Date tmpD;
        long long tmpL;

        cout << "\nEnter Student FIO: ";
        getline(cin, tmpS);
        SetStudentFIO(tmpS);

        cout << "\nEnter Date Of Birth (DD MM YYYY): ";
        cin >> tmpD.DD >> tmpD.MM >> tmpD.YYYY;
        cin.ignore();
        SetDateOfBirth(tmpD);

        cout << "\nEnter Phone Num: ";
        cin >> tmpL;
        cin.ignore();
        SetPhoneNum(tmpL);

        cout << "\nEnter City Of Student Birth: ";
        getline(cin, tmpS);
        SetCityOfStudentBirth(tmpS);

        cout << "\nEnter Country Of Student Birth: ";
        getline(cin, tmpS);
        SetCountryOfStudentBirth(tmpS);

        cout << "\nEnter University Name: ";
        getline(cin, tmpS);
        SetUniversityName(tmpS);

        cout << "\nEnter City Of University: ";
        cin >> tmpS;
        cin.ignore();
        SetCityOfUniversity(tmpS);

        cout << "\nEnter Country Of University: ";
        cin >> tmpS;
        cin.ignore();
        SetCountryOfUniversity(tmpS);

        cout << "\nEnter Group Num: ";
        cin >> tmpI;
        cin.ignore();
        SetGroupNum(tmpI);
    }
    void Print()
    {
        cout << "----------------" << endl;
        cout << "\nStudent FIO: " << GetStudentFIO();
        cout << "\nDate Of Birth: " << GetDateOfBirth().DD << "/" << GetDateOfBirth().MM << "/" << GetDateOfBirth().YYYY;
        cout << "\nPhone Num: " << GetPhoneNum();
        cout << "\nCountry Of Student Birth: " << GetCountryOfStudentBirth();
        cout << "\nUniversity Name: " << GetUniversityName();
        cout << "\nCity Of University: " << GetCityOfUniversity();
        cout << "\nCountry Of University: " << GetCountryOfUniversity();
        cout << "\nGroup Num: " << GetGroupNum();
        cout << endl;
    }
};

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    Student Student1;
    Student1.Input();
    Student1.Print();

    cin.get(); cin.get();
}
