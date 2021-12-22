// Создание копии файла

#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>

using namespace std;

int main() {

	setlocale(0, "");
	SetConsoleCP(1251); // подключение локали для работы с русскими символами
	SetConsoleOutputCP(1251);

	string name;
	string mas[30]; // задание массива символов строки, "30" - максимальное количество символов в строке
	char symb;
	int i = 0; // счётчик символов

	ifstream fin("test1.txt");	// класс, предназначенный для чтения из файла
	ofstream fout(name);	// класс, предназначенный для записи в файл

	if (!fin)
	{
		cout << "Ошибка! Невозможно найти файл test1.txt"; // если произойдёт какая-то ошибка, то программа выведет сообщение
		return 1;
	}
	
	cout << "Введите название нового файла: ";
	getline(cin, name);
	name = name + ".txt"; // задание имени нового файла

	while (!fin.eof())	// пока не достигнут конец файла
	{
		getline(fin, mas[i]); // считываем исходную строку, проходя по каждому элементу
		i++;
	}

	fout.open(name);

	for (symb = 0; symb != i; symb++) // пока не будет достигнут последний указатель, строка переносится в новый файл
	{
		fout << mas[symb];
		fout << endl;
	}

	fin.close(); // закрытие файлов
	fout.close();

	return 0;
}
