#include <iostream>   // ���������� ���������� iostream
#include <windows.h>  // ���������� ���������� Windows.h ��� Sleep() � SetColor()
using namespace std;  // ������� ����������� std - standart

//
// ������� ��� ��������� ����� ���������� �������:
//  colBkgr - ����� ����� ����
//  colSym  - ����� ����� �������
// ����������.
//   ������ ��������� ������ ����� ���������� � ���������� ���� � �������
//   ������� COLOR /? ��� COLOR -help
//
void SetColor(int colBkgr, int colSym) {
	int wAttributes = colBkgr * 16 + colSym;
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}


int main()
{
	setlocale(LC_ALL, "Rus");
	// system("chcp 1251 > nul"); // ��������� ������� �������� 1251 � ������� ���������� ������� CHCP



	cin.get(); cin.get(); // ���������� �������
	// system("pause > nul"); // ���������� ������� � ������� ���������� ������� PAUSE
}


#include <iostream>
using namespace std;
/*
2. *������������ ������ � ���������� ���������� ��
��������� � �����, �� ������� ����� �������.
��������� ��������, � ������� ��� ����� �����.
*/
int main() {
	setlocale(LC_ALL, "Rus");
	// system("chcp 1251 > nul");
	cout << "������� ���������� �� ���������, ��: ";
	//int S; // ���������� ��� ����������
	double S;
	cin >> S; // ���� ��������� � �������
	cout << "������� ����� � �������: ";
	//int t; // ���������� ��� ��������
	double t;
	cin >> t; // ���� �������
	// ����������
	//t = t / 60; // ������� ������ � ����
	t /= 60; // ����������� ����� ������
	//int V = S / t;
	double V = S / t;
	cout << "�������� �����: " << V << " ��/�\n";

	cin.get(); cin.get(); // ���������� �������
	// system("pause > nul"); // ���������� �������
}


#include <iostream>
using namespace std;

/*
3. **������������ ������ � ���������� ����� ������
� ����� ���������� ����������� ���������
(����, ������ � �������).
��������� ��������� ���������, ���� ���������
������ - 30 ������.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	int H1, M1, S1; // ���������� ��� ������� ������ ���������
	int H2, M2, S2; // ���������� ��� ������� ��������� ���������
	cout << "������� ����� ������ ��������� (� � �): ";
	cin >> H1 >> M1 >> S1; // ���� � ������� ����� ���. ������
	cout << "������� ����� ����� ��������� (� � �): ";
	cin >> H2;
	cin >> M2;
	cin >> S2;
	// ����������
	int Time1 = H1 * 3600 + M1 * 60 + S1; // ����� ������ ��������� � ��������
	int Time2 = H2 * 3600 + M2 * 60 + S2; // ����� ����� ��������� � ��������
	int DeltaTime = Time2 - Time1; // ������������ ��������� � ��������
	cout << "������������ ��������� � ��������: "
		<< DeltaTime << endl;
	cout << "������������ ��������� � �������: "
		<< DeltaTime / 60 << endl;
	cout << "��������� ���������: " << DeltaTime / 60 * 30
		<< " �����\n";
	system("pause > nul"); // ���������� �������
}


#include <iostream>
using namespace std;
/*
3. **������������ ������ � ���������� ����� ������
� ����� ���������� ����������� ���������
(����, ������ � �������).
��������� ��������� ���������, ���� ���������
������ - 30 ������.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	int H1, M1, S1; // ���������� ��� ������� ������ ���������
	int H2, M2, S2; // ���������� ��� ������� ��������� ���������
	cout << "������� ����� ������ ��������� (� � �): ";
	cin >> H1 >> M1 >> S1; // ���� � ������� ����� ���. ������
	cout << "������� ����� ����� ��������� (� � �): ";
	cin >> H2;
	cin >> M2;
	cin >> S2;
	// ����������
	int Time1 = H1 * 3600 + M1 * 60 + S1; // ����� ������ ��������� � ��������
	int Time2 = H2 * 3600 + M2 * 60 + S2; // ����� ����� ��������� � ��������
	int DeltaTime = Time2 - Time1; // ������������ ��������� � ��������
	cout << "������������ ��������� � ��������: "
		<< DeltaTime << endl;
	cout << "������������ ��������� � �������: "
		<< DeltaTime / 60 << endl;
	cout << "��������� ���������: " << DeltaTime / 60 * 30
		<< " �����\n";
	cout << "---------------------\n";
	cout << "������������ ��������� � �������: "
		<< (double)DeltaTime / 60 << endl;
	cout << "��������� ���������: "
		<< (double)DeltaTime / 60 * 30 << " �����\n";

	system("pause > nul"); // ���������� �������
}


#include <iostream>
using namespace std;
/*
4. **������������ ������ � ���������� ����� � �����
� ���� �������, ���� � �����.
���������, ������� ������������ ������ ������ ��������,
���� � ������.
�) ���������� ��������, ���� � ������ ������ ���� �����
(������ �� ������).
b) ����������� ������, ������������� ������� �� �����
����� � �����.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	float Summa, KursDollar, KursEuro, KursRub;
	cout << "������� �����, ��: ";
	cin >> Summa;
	cout << "������� ���� �������, ��: ";
	cin >> KursDollar;
	cout << "������� ���� ����, ��: ";
	cin >> KursEuro;
	cout << "������� ���� �����, ��: ";
	cin >> KursRub;
	// 1 �������
	cout << "���-�� ��������: " << Summa / KursDollar << endl;
	cout << "���-�� ����:     " << Summa / KursEuro << endl;
	cout << "���-�� ������:   " << Summa / KursRub << endl;
	// 2 ������� - � ������, ��������������� ����������������
	//              � ���� int
	cout << "���-�� ��������: " << (int)(Summa / KursDollar) << endl;
	cout << "���-�� ����:     " << int(Summa / KursEuro) << endl;
	cout << "���-�� ������:   " << (int)(Summa / KursRub) << endl;
	// 3 ������� - ������� ���������� ����� float � int
	int CountDollars = Summa / KursDollar;
	int CountEuro = Summa / KursEuro;
	int CountRub = Summa / KursRub;
	cout << "���-�� ��������: " << CountDollars << endl;
	cout << "���-�� ����:     " << CountEuro << endl;
	cout << "���-�� ������:   " << CountRub << endl;
	// ���������� �����
	cout << "C����" << endl;
	cout << "����� �� ��������: "
		<< Summa - CountDollars * KursDollar << endl;
	cout << "����� �� ����: "
		<< Summa - CountEuro * KursEuro << endl;
	cout << "����� �� ������: "
		<< Summa - CountRub * KursRub << endl;

	system("pause > nul"); // ���������� �������
}


#include <iostream>
using namespace std;
/*
14. **������������ ������ � ���������� ����� ������ ������
� ����������.
���������, ������� ������ ����������� ���� ��������
��� �������� ������ �� ����� � ���� �����.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	// ������ ������� 1.44 �� � ������
	const int DiskSize = 1.44 * 1024 * 1024;
	long long FilmSize;
	cout << "������� ������ ������, ��: ";
	cin >> FilmSize;
	// ������� ������� ����� ������ �� �������� � �����
	FilmSize = FilmSize * 1024 * 1024 * 1024;
	// ���������� ���-�� ������ ��� ������
	int CntDisks = FilmSize / DiskSize;
	cout << "���-�� ������: " << CntDisks << endl;
	cout << "������� �� ����������� ������: "
		<< FilmSize % DiskSize << " ����" << endl;
	// �������� �� ������� ���������� ����� �����������
	if (FilmSize % DiskSize != 0) {
		// ����������� �� 1 ���-�� ������
		// CntDisks = CntDisks + 1;
		CntDisks++; // ��������� ���������� CntDisks
	}
	cout << "���-�� ������: " << CntDisks << endl;

	system("pause > nul"); // ���������� �������
}
