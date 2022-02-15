/*
������� 1
**�������� �������, ��� ���������� � ������������ ����������.
�������� ������� ������������, ����� �� ������������� �������� ��������� ������������� ��������� (��������, k ��������� �������� � ��������� �� 0 �� 100).
� �������� ������� ������ �������� ����� �������� �������� ����, ������� �����������. ������� ����� ������ ��������.
���������� ����������� ������������ ������������� � ������������ ��������, ���������� �������� �� 1, ����������� �������� ��������.*/
/*
class Counter {
private:
    int Min;
    int Max;
    int Count;
public:
    Counter() {
        Min = 1;
        Max = 100;
        Count = Min;
    }
    // setters
    void SetMaxMinRange(int newMin, int newMax) {
        if (newMin < newMax) {
            Min = newMin;
            Max = newMax;
        }
        else {cout << "Error! Min >=Max" << endl;
        Input();
        }
    }
    //getters
    int GetMin() {
        return Min;
    }
    int GetMax() {
        return Max;
    }
    int GetCount() {
        return Count;
    }

    //counter
    void IncrementCount() {
        Count = GetMin();
        while (Count <= Max) {
            if (_kbhit()) { return; }
            Sleep(200);
            system("cls");
            Print();
            Count++;
        };
        IncrementCount();
    }

    void Input() {
        int tmpMin, tmpMax;

        cout << "\nEnter Min and Max: ";
        cin >> tmpMin >> tmpMax;
        SetMaxMinRange(tmpMin, tmpMax);
    };
    void Print() {
        cout << "For break press any key" << endl;
        cout << "Current count: " << GetCount() << endl;
    };
};

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    Counter Counter1;
    Counter1.Input();
    Counter1.IncrementCount();

    cin.get(); cin.get();
}
*/

/*������� 2
*�������� ����� Worker.
���������� ������� ������: ���, ���������, ��� ����������� �� ������, ��������.
����������� ������������, ������������� �������������, ����������� �������-����� (������� ��� ���������� ������).

***������� ������ �������� Worker.
��� ������� �������� Worker ����������� ����������� �������:
- ������ ����������, ���� ������ ������� �� ������ ����������� ����������� �������� ����� ���;
- ������ ����������, �������� ������� ����������� ��������;
- ������ ����������, ���������� �������� ���������.*/
/*
struct Date {
    int DD;
    int MM;
    int YYYY;
};

class Worker {
private:
    string FIO;
    string Position;
    Date DateStartWork;
    float Salary;

public:
    // ������������ ����������� ����������� �����
    Worker() : FIO("�� ������"), Position("�� ������"), Salary(42500.0){
        DateStartWork.DD = 1;
        DateStartWork.MM = 1;
        DateStartWork.YYYY = 1980;
    };

    Worker(Date _DateStartWork): Worker() {
        SetDateStartWork(_DateStartWork);
    }

    // ������ ��������
    //  ������������, setter, �������
    void  SetFIO(string newFIO) {
        if (newFIO.size() >= 3) {
            FIO = newFIO;
        }
        else {
            cout << "��� ��������� �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetPosition(string newPosition) {
        if (newPosition.size() >= 3) {
            Position = newPosition;
        }
        else {
            cout << "��������� ��������� �� ����� ���� ������ 3-� ��������" << endl;
        }
    };

    void  SetDateStartWork(Date newDateStartWork) {
        if (newDateStartWork.DD > 0 && newDateStartWork.MM > 0 && newDateStartWork.YYYY > 1980) {
            DateStartWork.DD = newDateStartWork.DD;
            DateStartWork.MM = newDateStartWork.MM;
            DateStartWork.YYYY = newDateStartWork.YYYY;
        }
        else {
            cout << "���� �� ���������" << endl;
        }
    };

    void  SetSalary(float newSalary) {
        if (newSalary >= 42500) {
            Salary = newSalary;
        }
        else {
            cout << "�� �� ����� ���� ������ 42500" << endl;
        }
    };

    //  ������ ����������, getter, �������
    string GetFIO() { return FIO; };
    string GetPosition() { return Position; };
    Date GetDateStartWork() { return DateStartWork; };
    float GetSalary() { return Salary; };

    // ������ ����� ������
    void Input()
    {
        string tmpS;
        float tmpF;
        Date tmpD;

        cout << "\nEnter Worker's FIO: ";
        getline(cin, tmpS);
        SetFIO(tmpS);

        cout << "\nEnter Worker's Position: ";
        getline(cin, tmpS);
        SetPosition(tmpS);

        cout << "\nEnter Date Of Birth (DD MM YYYY): ";
        cin >> tmpD.DD >> tmpD.MM >> tmpD.YYYY;
        cin.ignore();
        SetDateStartWork(tmpD);

        cout << "\nEnter Salary: ";
        cin >> tmpF;
        cin.ignore();
        SetSalary(tmpF);
    }

    Worker AddWorker() {
        // ��������� ������ �� ������ ���������
        Worker newWorker;
        newWorker.Input();
        return newWorker;
    }

    void CreateArrWorkers(Worker * & ArrWorkers, int & Size) {
       //��������� ������� ��������������� ��������� � ������ ����������
        int i = 0;
        while (i < Size) {
            ArrWorkers[i++] = AddWorker();
        }
    }

    void Print(Worker* ArrWorkers, int Index) {
        // �������� ������ ���������� � �������
            cout << "----------------" << endl;
            cout << "\nWorker's FIO: " << ArrWorkers[Index].GetFIO();
            cout << "\nWorker's Position: " << ArrWorkers[Index].GetPosition();
            cout << "\nDate Of Start Work: " << ArrWorkers[Index].GetDateStartWork().DD << "/" << ArrWorkers[Index].GetDateStartWork().MM << "/" << ArrWorkers[Index].GetDateStartWork().YYYY;
            cout << "\nSalary: " << ArrWorkers[Index].GetSalary();
            cout << endl;
    }

    void SelectByMoreWorkExp(Worker* ArrWorkers, int Size, int Param) {
        // ������� ���������� �� �����
        int i = 0;
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int CurrentYYYY = (1970 + ltm->tm_year) - 70;
        while (i < Size) {
            if (Param < CurrentYYYY - ArrWorkers[i].GetDateStartWork().YYYY) {
                Print(ArrWorkers, i);
            }
            i++;
        }
    }

    void SelectByMoreSalary(Worker* ArrWorkers, int Size, float Param) {
        // ������� ���������� �� ��������
        int i = 0;
        while (i < Size) {
            if (Param < ArrWorkers[i].GetSalary()) {
                Print(ArrWorkers, i);
            }
            i++;
        }
    }

    void SelectByPosition(Worker* ArrWorkers, int Size, string Param) {
        // ������� ���������� �� ���������
        int i = 0;
        while (i < Size) {
            if (Param == ArrWorkers[i].GetPosition()) {
                Print(ArrWorkers, i);
            }
            i++;
        }
    }
};



int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    int Size;
    cout << "\nEnter Count of Workers: ";
    cin >> Size;
    cin.ignore();
    Worker* ArrWorkers = new Worker[Size];

    Worker newWorkers;
    newWorkers.CreateArrWorkers(ArrWorkers, Size);

    int ParamI;
    cout << "\nEnter Work Experience in Years For Select From Workers: ";
    cin >> ParamI;
    newWorkers.SelectByMoreWorkExp(ArrWorkers, Size, ParamI);
    cin.ignore();

    float ParamF;
    cout << "\nEnter Salary For Select From Workers:";
    cin >> ParamF;
    newWorkers.SelectByMoreSalary(ArrWorkers, Size, ParamF);
    cin.ignore();

    string ParamS;
    cout << "\nEnter Position For Select From Workers:";
    getline(cin, ParamS);
    newWorkers.SelectByPosition(ArrWorkers, Size, ParamS);

    cin.get(); cin.get();
}
*/

/*
�������������� �������
������� 3
***�������� ���������, ����������� ��������������� ���.
���������� ����� ������ "�������", "��������", "���".
����� "��������" �������� ������������ ������ �������� ������ "�������".
����� "���" �������� ������ �������� ������ "��������".
������ �� ������� �������� ����������-����� � �������-�����, ������� ���������� ��� ���������� ������� ������.
�������� ���� ��������, ��� ������ ��� ��������� �������� ���������� �����������.
��������, ��� ��� � ������ "�������".
�� ��������� ���������� ������ ���������� �������������� (����������� ����������� ����������), �������������.
� main() �������������� ������ ����������� ������ �������.*/


class Chelovek {
private:
    string FIO;
public:
    //constructor
    Chelovek() {
        FIO = "�� ������";
    }
    //destructor
    ~Chelovek() {
    }

    // setters
    void SetFIO(string newFIO) {
        if (newFIO.size() > 3) {
            FIO = newFIO;
        }
        else {
            cout << "��� �� ����� ���� ������ 3-� ��������" << endl;
        }
    }
    //getters
    string GetFIO() {
        return FIO;
    }

    //input
    void Input() {
        string tmpS;
        cout << "������� ��� ������: ";
        getline(cin, tmpS);
        SetFIO(tmpS);
    }
};


class Kvartira {
private:
    int Size;
    Chelovek* ArrChelovek;
public:
    //constructor
    Kvartira() {
        Size = 3;
        ArrChelovek = new Chelovek[Size];
    }
    //destructor
    ~Kvartira() {
    }
    // setters
    void SetSize(int newSize) {
        if (newSize > 0) {
            Size = newSize;
            ArrChelovek = new Chelovek[Size];
        }
        else { cout << "���������� ������� �� ����� ���� ������ ��� ����� ����" << endl; }
    }

    //getters
    int GetSize() {
        return Size;
    }

    Chelovek GetArrChelovek(int Index) {
        return ArrChelovek[Index];
    }

    Chelovek GetChelovek() {
        Chelovek newChelovek;
        newChelovek.Input();
        return newChelovek;
    }

    //input
    void Input() {
        int i = 0;
        while (i < GetSize()) {
            cout << i + 1 << ") ";
            ArrChelovek[i] = GetChelovek();
            i++;
        }
    }
};

class Dom {
private:
    int SizeKv, SizeChel;
    Kvartira* ArrKvartira;
    string Address;
    int DomNum;

public:
    //constructor
    Dom() {
        SizeKv = SizeChel = 1;
        ArrKvartira = new Kvartira[SizeKv];
        Address = "�� ������";
        DomNum = 1;
    }
    //destructor
    ~Dom() {
    }
    // setters
    void SetSize(int newSizeKv, int newSizeChel) {
        if (newSizeKv > 0 && newSizeChel > 0) {
            SizeKv = newSizeKv;
            SizeChel = newSizeChel;
            ArrKvartira = new Kvartira[SizeKv];
        }
        else { cout << "���������� ������� �� ����� ���� ������ ��� ����� ����" << endl; }

    }

    void SetAddress(string newAddress) {
        if (newAddress.size() > 3) {
            Address = newAddress;
        }
    }
    void SetDomNum(int newDomNum) {
        if (newDomNum > 0) {
            DomNum = newDomNum;
        }
    }

    //getters
    int GetSizeKv() {
        return SizeKv;
    }
    int GetSizeChel() {
        return SizeChel;
    }
    string GetAddress() {
        return Address;
    }

    int GetDomNum() {
        return DomNum;
    }

    Kvartira GetKvartira() {
        Kvartira newKvartira;
        newKvartira.SetSize(SizeChel);
        newKvartira.Input();
        return newKvartira;

    }

    Kvartira GetArrKvartira(int Index) {
        return ArrKvartira[Index];
    }

    //input
    void Input() {
        int i = 0;
        while (i < GetSizeKv()) {
            //cout << "Dom GetSize = " << GetSize() << endl;
            cout << "------------------------------------ " << endl;
            cout << "�������� �: " << i + 1 << endl;
            ArrKvartira[i] = GetKvartira();
            i++;
        }
    }

    void Print() {
        // �������� ������ � �������
        int i = 0;
        cout << "\n\n---------� ���� � " << GetDomNum() << " �� ������� " << GetAddress() << " ���������----------- " << endl;
        while (i < SizeKv) {
            int j = 0;
            cout << "------------------------------------ " << endl;
            cout << "�������� #: " << i + 1 << endl;
            while (j < SizeChel) {
                cout << j + 1 << ") ���: " << GetArrKvartira(i).GetArrChelovek(j).GetFIO();
                cout << endl;
                j++;
            }
            i++;
        }
    }


};

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    int SizeKv, SizeChel, DomNum;
    string Address;

    cout << "\n������� ������������ ������ ����: ";
    getline(cin, Address);

    cout << "\n������� ����� ����: ";
    cin >> DomNum;
    cin.ignore();

    cout << "\n������� ���������� ������� � ����: ";
    cin >> SizeKv;
    cin.ignore();

    cout << "\n������� ���������� ����������� � ������ ��������: ";
    cin >> SizeChel;
    cin.ignore();

    Dom newDom;
    newDom.SetAddress(Address);
    newDom.SetDomNum(DomNum);
    newDom.SetSize(SizeKv, SizeChel);

    newDom.Input();
    newDom.Print();
    cin.get(); cin.get();
}
