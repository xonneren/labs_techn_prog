// [Объединение двух файлов в один]

#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	ofstream fout;
	ifstream fin;
	string path = "text1.txt", path2 = "text2.txt", path3 = "text3.txt";

	string a, b, w, op;
	string mas[20], mas1[40], mas3[40];
	int i = 0, k = 0, opt = 0, opt1 = 0, mas2[20], p = 0;
	fin.open(path);

	while (!fin.eof())
	{
		getline(fin, mas[i]);
		i++;
	};
	fin.close();

	fin.open(path2);

	while (!fin.eof())
	{
		getline(fin, mas3[opt]);
		opt++;
	};
	fin.close();

	opt1 += i + opt;
	fout.open(path3);
	for (int l = 0; l < i; l++)
	{

		fout << l + 1 << ". " << mas[l] << endl;
		printf("Копирование завершено на %f %s", (l + 1) / (opt1 / 100.0), "%\n");
	}
	for (int l = 0; l < opt; l++)
	{

		fout << l + 1 << ". " << mas3[l] << endl;
		printf("Копирование завершено на %f %s", (l + 1 + i) / (opt1 / 100.0), "%\n");
	}

	fout.close();
	return 0;
}
