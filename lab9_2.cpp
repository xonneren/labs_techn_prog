// Поиск строк с заданным словом

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>

using namespace std;

int main() {

	setlocale(0, "");
	SetConsoleCP(1251); // подключение локали для работы с русскими символами
	SetConsoleOutputCP(1251);

	char word[80], line[80];

	ifstream fin("test1.txt");
	ofstream fout("test2.txt");

	if (!fin)
	{
		cout << "Ошибка! Невозможно найти файл test1.txt"; // если произойдёт какая-то ошибка, то программа выведет сообщение
		return 1;
	}
	cout << "Введите слово: ";
	cin >> word;

	while (fin.getline(line, 80))
	{
		if (strstr(line, word))
		{
			fout << line << endl;
		}
	}

	fin.close();
	fout.close();

	return 0;
}