
/*�������� �������
����: 49-50. STL.����������.���������

��������� ���������� STL C++ (array, vector, list) � ��������� ������ ������

1. **� ���������� �������, ��������� �� N ������������ (float ��� double) ����� ���������:
a) ����� ������������� ���������.
b) ������������ ���������, ����������� ����� min � max ����������.
c) ������������ ��������� � ������� ��������.
d) �����  ���������, ����������� ����� ������ � ��������� �������������� ����������.

2. *�������� ���������, ������� ��������� ������������ ����� ���� �������� � ��������� ������� � ������  ������.

3. **�������� ���������, ������� �������������� ������ (������ ������� ����������� ���������, ������ ������������� � �.�.)*/

#include <iostream>
#include <iomanip>
#include <string>     // ��������� ��� ��������� ��������
#include <fstream>    // �������� ��������� ��� ������ � ��������� ��������
#include <array>      // array<> - ����� ��� ������ � ����������� ��������
#include <vector>     // vector<> - ����� ��� ������ � ������������ ��������
#include <list>       // list<> - ����� ����������� ������
#include <iterator>   // ������ ���������� ��� ������ � ������������
#include <algorithm>  // ���� � ���������� ��������� STL C++
#include <random>     // ������ STL ��� ������ � ����. �������
#include <time.h>
#include "../BattleCity/Win10.h"

using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
int main()
{
    const int N = 10;
    vector<float>   mas(N);

    //���������� �������
    for_each(begin(mas), end(mas), [](auto& a) {
        a = static_cast<float>(RAND(-500, 500) / 100.0);
        cout << a << " ";
        });

    //a) ����� ������������� ���������.
    cout <<endl;
    float sum = 0;
    vector<float>::iterator itBegin = begin(mas); // ��������� ��� ���������� mas
    for (; itBegin != end(mas); ++itBegin) {
        if (*itBegin < 0) { sum += *itBegin; } // ����� �����. ���������� ���������� mas
    }
    cout << "����� ������������� ��������� = " << sum << endl;

    //b) ������������ ���������, ����������� ����� min � max ����������.
    cout << endl;
    int indexMin = 0;
    int indexMax = 0;
    float Min = mas[0];
    float Max = mas[0];
   itBegin = begin(mas); // ��������� ��� ���������� mas
    for (; itBegin != end(mas); ++itBegin) {
        if (*itBegin < Min) { Min = *itBegin; indexMin = (int)distance(mas.begin(), itBegin); } // ����� �����. ���������� ���������� mas
        if (*itBegin > Max) { Max = *itBegin; indexMax = (int)distance(mas.begin(), itBegin);} // ����� �����. ���������� ���������� mas
    }
    cout << "Min = " << Min << " indexMin = " << indexMin << endl;
    cout << "Max = " << Max << " indexMax = " << indexMax << endl;

    int startIndex = (indexMin < indexMax) ? indexMin : indexMax;
    int endIndex = (indexMin > indexMax) ? indexMin : indexMax;
    sum = 1;
    for (int i = startIndex; i <= endIndex; i++) {
        sum *= mas[i];
    }
    cout << "������������ ���������, ����������� ����� min � max ���������� = " << sum << endl;

    //c) ������������ ��������� � ������� ��������.
    cout << endl;
    int curIndex = 0;
    sum = 1;
    itBegin = begin(mas); // ��������� ��� ���������� mas
    for (; itBegin != end(mas); ++itBegin) {
        curIndex = (int)distance(mas.begin(), itBegin);
        if (curIndex % 2 == 0) { sum *= *itBegin; cout << *itBegin << " "; } // ����� �����. ���������� ���������� mas
    }
    cout << "������������ ��������� � ������� �������� = " << sum << endl;

    //d) �����  ���������, ����������� ����� ������ � ��������� �������������� ����������.
    cout << endl;
    indexMin = 0;
    indexMax = 0;
    Min = mas[0];
    Max = mas[0];
    itBegin = begin(mas); // ��������� ��� ���������� mas
    for (; itBegin != end(mas); ++itBegin) {
        if (*itBegin < 0 && Min == 0) { Min = *itBegin; indexMin = (int)distance(mas.begin(), itBegin); } // ������ �������������� ����������
        if (*itBegin < 0) { Max = *itBegin; indexMax = (int)distance(mas.begin(), itBegin); } // ��������� �������������� ����������
    }
    cout << "Min = " << Min << " indexMin = " << indexMin << endl;
    cout << "Max = " << Max << " indexMax = " << indexMax << endl;

    startIndex = (indexMin < indexMax) ? indexMin : indexMax;
    endIndex = (indexMin > indexMax) ? indexMin : indexMax;
    sum = 1;
    for (int i = startIndex; i <= endIndex; i++) {
        sum += mas[i];
    }
    cout << "�����  ���������, ����������� ����� ������ � ��������� �������������� ���������� = " << sum << endl;
}
*/

/*2. *�������� ���������, ������� ��������� ������������ ����� ���� �������� � ��������� ������� � ������  ������.*/
/*
int main()
{
    const int N = 10;
    vector<float>   mas1(N);
    vector<float>   mas2(N);

    //���������� �������
    for_each(begin(mas1), end(mas1), [](auto& a) {
        a = static_cast<float>(RAND(-500, 500) / 100.0);
        cout << a << " ";
        });
    cout << endl;
    for_each(begin(mas2), end(mas2), [](auto& a) {
        a = static_cast<float>(RAND(-500, 500) / 100.0);
        cout << a << " ";
        });
    cout << endl;

    vector<float>   mas3;
    for (int i = 0; i < N; i++) {
        float k = mas1[i] + mas2[i];
        mas3.push_back(k);
    }

    for (auto a : mas3) { cout << a << " "; }

}
*/

/*3. **�������� ���������, ������� �������������� ������ (������ ������� ����������� ���������, ������ ������������� � �.�.)*/
/*
int main()
{
    const int N = 10;
    vector<float>   mas(N);
    //���������� �������
    for_each(begin(mas), end(mas), [](auto& a) {
        a = static_cast<float>(RAND(-500, 500) / 100.0);
        cout << a << " ";
        });
    cout << endl;

    reverse(mas.begin(), mas.end());
    for (auto a : mas) { cout << a << " "; }
}
*/

/*5. **��������, ���������, ������� ��������� ������� ����� �� 5 ���.
������������ ������ ������� ����� �� ������ �����. ��������� ����� ������� � ������� �� ������ ���.
�) **������� ������ � ������������� �������������� ������� �� ������ ���:
1  ++++++++++++++
2  ++++++++++++++++
3  ++++
4  +++++++++++++++
5  +++++++
�) ***������� ������������ ������*/

/*
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int const row = 5;
    int const col = 12;
    vector<vector<int>> arr(row, vector<int>(col,0));
    //int arr[row][col];
    int pribylAll = 0;
    int pribylYear[5];
    for (int i = 0; i < row; i++) {
        int count = 0;
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 1000 + 1;
          //  cout << setw(2) << "[" << i << "][" << j << "] -> " << arr[i][j] << "\n";
            count += arr[i][j];
        }
        pribylYear[i] = count;
        pribylAll += count;
    }

    for (int i = 0; i < row; i++) {
        cout << "������� �� " << i + 1 << " ��� -> " << pribylYear[i] << "\n";
    }
        cout << "������� �� 5 ��� -> " << pribylAll << "\n";

    cout << "C������������ �������������� ������� �� ������ ��� (��������������): \n";
    for(int i = 0; i < row; i++){
        int len = (float(pribylYear[i]) / pribylAll) * 100;
        cout << i + 1 << " -> ";
        for (int j = 0; j < len; j++) {
            cout << "+";
        }
        cout << endl;
    }
    cout << endl;
    cout << "C������������ �������������� ������� �� ������ ��� (������������): \n";
    for (int i = 0; i < row; i++) {
        int len = (float(pribylYear[i]) / pribylAll) * 100;
        SetPos(40, 1+i);
        cout << i + 1;
        for (int j = 0; j < len; j++) {
            SetPos(39-j, 1+i);
            cout << "+\n";
        }
        cout << endl;
    }


    cin.get(); cin.get();
}
*/

/*12. ***�������� ��������� <����������>. ������� ��� ���������� �������. ����
������ ������ ������ ICQ, ������ - ���������� ������. ����������� ���� ���
������������:
a) ������������� �� ������� ICQ
b) ������������� �� ������� ��������
c) ������� ������ �������������
d) �����*/

int main()
{
    setlocale(LC_ALL, "Rus");
    bool isWork = true;
    int const Size = 6;
    vector<long long> arr1(Size);// = { 523456, 423450, 323451, 223452, 123453, 623454 };
    generate(begin(arr1), end(arr1), []() {return RAND(111111, 999999); });

    vector<long long> arr2(Size);// = { 617119, 556699, 424488, 338877, 269977, 173366 };
    generate(begin(arr2), end(arr2), []() {return RAND(111111, 999999); });

    vector <string> arr3(Size);// = { "����", "����", "�����", "����", "�����", "����" };
    generate(begin(arr3), end(arr3), []() {return RAND('A', 'Z'); });

    int select;
    while (isWork == true)
    {
        cout << "1) ������������� �� ������� ICQ\n";
        cout << "2) ������������� �� ������� ��������\n";
        cout << "3) ������� ������ �������������\n";
        cout << "4) �����\n";
        cout << "�������� ����� ����: ";
        (cin >> select).ignore();

        switch (select) {
        case 1:
            for (int i = 1; i < Size; ++i)
            {
                int j = i;
                while (j > 0 && arr1[j - 1] > arr1[j])
                {
                    long long num = arr1[j - 1];
                    arr1[j - 1] = arr1[j];
                    arr1[j] = num;

                    num = arr2[j - 1];
                    arr2[j - 1] = arr2[j];
                    arr2[j] = num;

                    string num2 = arr3[j - 1];
                    num2 = arr3[j - 1];
                    arr3[j - 1] = arr3[j];
                    arr3[j] = num2;
                    j--;
                }
            }
            cout << endl << "�������������" << endl << endl;
            break;
        case 2:
            for (int i = 1; i < Size; ++i)
            {
                int j = i;
                while (j > 0 && arr2[j - 1] > arr2[j])
                {
                    long long num = arr2[j - 1];
                    arr2[j - 1] = arr2[j];
                    arr2[j] = num;

                    num = arr1[j - 1];
                    arr1[j - 1] = arr1[j];
                    arr1[j] = num;

                    string num2 = arr3[j - 1];
                    num2 = arr3[j - 1];
                    arr3[j - 1] = arr3[j];
                    arr3[j] = num2;

                    j--;
                }
            }
            cout << endl << "�������������" << endl << endl;
            break;
        case 3:
            for (int i = 0; i < Size; i++) {
                cout << "ICQ: " << arr1[i] << "\tTEL: " << arr2[i] << "\tUSER: " << arr3[i] << "\n";
            }
            break;
        case 4: isWork = false; return 0;
        }
    }
    cin.get(); cin.get();
}
