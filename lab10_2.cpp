// [Работа со структурой «Товары»]

#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include <windows.h>

using namespace std;

struct PRICE
{
	string name;
	string shop;
	int price;
};

bool cmp_by_cnt(const PRICE& lh, const PRICE& rh)
{
	return lh.name[0] < rh.name[0];
}

vector <PRICE> p;

void PRINT()
{
	for (int i = 0; i < p.size(); i++)
	{
		cout << "Товар: " << p[i].name << endl;
		cout << "Магазин: " << p[i].shop << endl;
		cout << "Цена: " << p[i].price << endl;
		cout << endl;
	}
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251); // подключение локали для работы с русскими символами
	SetConsoleOutputCP(1251);

	int st, y = 0;
	ifstream fin("file.txt");

	if (!fin) {
		cout << "Ошибка открытия файла!\n";
		return 1;
	}

	for (int k = 0; k < 10; k++)
	{
		PRICE str;
		fin >> str.name;
		fin >> str.shop;
		fin >> str.price;
		p.push_back(str);
	}
	fin.close();

	sort(p.begin(), p.end(), cmp_by_cnt);
	PRINT();
	cout << "Введите минимальную стоимость : ";
	cin >> st;
	cout << endl;

	for (int k = 0; k < p.size(); k++)
	{
		if (p[k].price > st)
		{
			cout << "Товар: " << p[k].name << endl;
			cout << "Магазин: " << p[k].shop << endl;
			cout << "Цена: " << p[k].price << endl;
			cout << endl;
			y++;
		}

	}
	if (y == 0)
	{
		cout << "Товары отсутствуют!" << endl;
	}
	return 0;
}