// Поиск самого длинного слова в файле

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>

using namespace std;

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251); // подключение локали для работы с русскими символами
	SetConsoleOutputCP(1251);

	ifstream fin("test1.txt");

	int max = 0, count = 0;
	string maxdl;

	if (!fin)
	{
		cout << "Ошибка! Невозможно найти файл test1.txt"; // если произойдёт какая-то ошибка, то программа выведет сообщение
		return 1;
	}

	for (string str; fin >> str;) {
		if (str.length() > max) {
			max = str.length();
			maxdl = str;
			count = 1;
		}
		else if (str == maxdl) ++count;
	}
	cout << "Слово максимальной длины: " << maxdl << endl;
	cout << "Длина: " << max << endl;
	cout << "Встретилось в файле: " << count;

	fin.close();

	return 0;
}