#include <iostream>   // подключить библиотеку iostream
#include <windows.h>  // подключить библиотеку Windows.h для Sleep() и SetColor()
using namespace std;  // открыть простанство std - standart

//
// функция для установки цвета выводимого символа:
//  colBkgr - номер цвета фона
//  colSym  - номер цвета символа
// Примечание.
//   Номера возможных цветов можно посмотреть в консольном окне с помощью
//   команды COLOR /? или COLOR -help
//
void SetColor(int colBkgr, int colSym) {
	int wAttributes = colBkgr * 16 + colSym;
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}


int main()
{
	setlocale(LC_ALL, "Rus");
	// system("chcp 1251 > nul"); // установка кодовой страницы 1251 с помощью консольной команды CHCP



	cin.get(); cin.get(); // блокировка консоли
	// system("pause > nul"); // блокировка консоли с помощью консольной команды PAUSE
}


#include <iostream>
using namespace std;
/*
2. *Пользователь вводит с клавиатуры расстояние до
аэропорта и время, за которое нужно доехать.
Вычислить скорость, с которой ему нужно ехать.
*/
int main() {
	setlocale(LC_ALL, "Rus");
	// system("chcp 1251 > nul");
	cout << "Введите расстояние до аэропорта, км: ";
	//int S; // переменная для расстояния
	double S;
	cin >> S; // ввод расстояни с консоли
	cout << "Введите время в минутах: ";
	//int t; // переменная для времения
	double t;
	cin >> t; // ввод времени
	// вычисления
	//t = t / 60; // перевод митнут в часы
	t /= 60; // сокращенная форма записи
	//int V = S / t;
	double V = S / t;
	cout << "Скорость равна: " << V << " км/ч\n";

	cin.get(); cin.get(); // блокировка консоли
	// system("pause > nul"); // блокировка консоли
}


#include <iostream>
using namespace std;

/*
3. **Пользователь вводит с клавиатуры время начала
и время завершения телефонного разговора
(часы, минуты и секунды).
Посчитать стоимость разговора, если стоимость
минуты - 30 копеек.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	int H1, M1, S1; // переменные для времени начала разговора
	int H2, M2, S2; // переменные для времени окончания разговора
	cout << "Введите время начала разговора (Ч М С): ";
	cin >> H1 >> M1 >> S1; // ввод с консоли Часов Мин. Секунд
	cout << "Введите время конца разговора (Ч М С): ";
	cin >> H2;
	cin >> M2;
	cin >> S2;
	// вычисления
	int Time1 = H1 * 3600 + M1 * 60 + S1; // время начала разговора в секундах
	int Time2 = H2 * 3600 + M2 * 60 + S2; // время конца разговора в секундах
	int DeltaTime = Time2 - Time1; // длительность разговора в секундах
	cout << "Длительность разговора в секундах: "
		<< DeltaTime << endl;
	cout << "Длительность разговора в минутах: "
		<< DeltaTime / 60 << endl;
	cout << "Стоимость разговора: " << DeltaTime / 60 * 30
		<< " тенге\n";
	system("pause > nul"); // блокировка консоли
}


#include <iostream>
using namespace std;
/*
3. **Пользователь вводит с клавиатуры время начала
и время завершения телефонного разговора
(часы, минуты и секунды).
Посчитать стоимость разговора, если стоимость
минуты - 30 копеек.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	int H1, M1, S1; // переменные для времени начала разговора
	int H2, M2, S2; // переменные для времени окончания разговора
	cout << "Введите время начала разговора (Ч М С): ";
	cin >> H1 >> M1 >> S1; // ввод с консоли Часов Мин. Секунд
	cout << "Введите время конца разговора (Ч М С): ";
	cin >> H2;
	cin >> M2;
	cin >> S2;
	// вычисления
	int Time1 = H1 * 3600 + M1 * 60 + S1; // время начала разговора в секундах
	int Time2 = H2 * 3600 + M2 * 60 + S2; // время конца разговора в секундах
	int DeltaTime = Time2 - Time1; // длительность разговора в секундах
	cout << "Длительность разговора в секундах: "
		<< DeltaTime << endl;
	cout << "Длительность разговора в минутах: "
		<< DeltaTime / 60 << endl;
	cout << "Стоимость разговора: " << DeltaTime / 60 * 30
		<< " тенге\n";
	cout << "---------------------\n";
	cout << "Длительность разговора в минутах: "
		<< (double)DeltaTime / 60 << endl;
	cout << "Стоимость разговора: "
		<< (double)DeltaTime / 60 * 30 << " тенге\n";

	system("pause > nul"); // блокировка консоли
}


#include <iostream>
using namespace std;
/*
4. **Пользователь вводит с клавиатуры сумму в тенге
и курс доллара, евро и рубля.
Посчитать, сколько пользователь сможет купить долларов,
евро и рублей.
а) Количество долларов, евро и рублей должно быть целым
(мелочь не выдают).
b) Пересчитать задачу, дополнительно вывести на экран
сдачу в тенге.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	float Summa, KursDollar, KursEuro, KursRub;
	cout << "Введите сумму, тг: ";
	cin >> Summa;
	cout << "Введите курс доллара, тг: ";
	cin >> KursDollar;
	cout << "Введите курс евро, тг: ";
	cin >> KursEuro;
	cout << "Введите курс рубля, тг: ";
	cin >> KursRub;
	// 1 вариант
	cout << "Кол-во долларов: " << Summa / KursDollar << endl;
	cout << "Кол-во евро:     " << Summa / KursEuro << endl;
	cout << "Кол-во рублей:   " << Summa / KursRub << endl;
	// 2 вариант - с явными, принудительными преобразованиями
	//              к типу int
	cout << "Кол-во долларов: " << (int)(Summa / KursDollar) << endl;
	cout << "Кол-во евро:     " << int(Summa / KursEuro) << endl;
	cout << "Кол-во рублей:   " << (int)(Summa / KursRub) << endl;
	// 3 вариант - неявное приведение типов float к int
	int CountDollars = Summa / KursDollar;
	int CountEuro = Summa / KursEuro;
	int CountRub = Summa / KursRub;
	cout << "Кол-во долларов: " << CountDollars << endl;
	cout << "Кол-во евро:     " << CountEuro << endl;
	cout << "Кол-во рублей:   " << CountRub << endl;
	// вычисление сдачи
	cout << "Cдачи" << endl;
	cout << "Сдача по долларам: "
		<< Summa - CountDollars * KursDollar << endl;
	cout << "Сдача по евро: "
		<< Summa - CountEuro * KursEuro << endl;
	cout << "Сдача по рублям: "
		<< Summa - CountRub * KursRub << endl;

	system("pause > nul"); // блокировка консоли
}


#include <iostream>
using namespace std;
/*
14. **Пользователь вводит с клавиатуры объем одного фильма
в гигабайтах.
Посчитать, сколько дискет понадобится Васе Ламерову
для переноса фильма от друга к себе домой.
*/
int main() {
	system("chcp 1251 > nul"); // setlocale(LC_ALL, "Rus");
	// размер дискеты 1.44 Мб в байтах
	const int DiskSize = 1.44 * 1024 * 1024;
	long long FilmSize;
	cout << "Введите размер фильма, Гб: ";
	cin >> FilmSize;
	// перевод размера файла фильма из Гигабайт в байты
	FilmSize = FilmSize * 1024 * 1024 * 1024;
	// вычисление кол-ва дискет для фильма
	int CntDisks = FilmSize / DiskSize;
	cout << "Кол-во дискет: " << CntDisks << endl;
	cout << "Остаток от копирования фильма: "
		<< FilmSize % DiskSize << " байт" << endl;
	// проверка на остаток информации после копирования
	if (FilmSize % DiskSize != 0) {
		// увеличиваем на 1 кол-во дискет
		// CntDisks = CntDisks + 1;
		CntDisks++; // инкремент переменной CntDisks
	}
	cout << "Кол-во дискет: " << CntDisks << endl;

	system("pause > nul"); // блокировка консоли
}
