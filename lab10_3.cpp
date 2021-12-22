// [Работа со структурой «Студент»]

#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <algorithm>
#include <vector>	
using namespace std;


struct STUDENT
{
	string name;
	string group;
	int grade[5];
};


bool cmp_by_cnt(const STUDENT& lh, const STUDENT& rh)
{
	double a, b;
	a = (lh.grade[0] + lh.grade[1] + lh.grade[2] + lh.grade[3] + lh.grade[4]) / 5.0;
	b = (rh.grade[0] + rh.grade[1] + rh.grade[2] + rh.grade[3] + rh.grade[4]) / 5.0;
	
	return a < b;
}

vector <STUDENT> p;

void Print()
{
	for (int k = 0; k < p.size(); k++)
	{
		cout << "Студент : " << p[k].name << endl;
		cout << "Группа : " << p[k].group << endl;
		cout << "Оценки : " << p[k].grade[0] << ", " << p[k].grade[1] << ", " << p[k].grade[2] << ", " << p[k].grade[3] << ", " << p[k].grade[4] << endl;
		cout << endl;
	}
}
int main()
{
	setlocale(0, "");

	string b;
	int a, y = 0;
	ifstream fin("journal.txt");
	

	for (int i = 0; i < 10; i++)
	{
		STUDENT fts;
		fin >> fts.name;
		fin >> b;
		fts.name = fts.name + " " + b;
		fin >> fts.group;
		
		for (int k = 0; k < 5; k++)
		{
			fin >> fts.grade[k];
		}
		p.push_back(fts);
	}
	fin.close();

	sort(p.begin(), p.end(), cmp_by_cnt);
	Print();
	cout << "Введите минимальный балл : ";
	cin >> a;
	cout << endl;


	for (int k = 0; k < p.size(); k++)
	{
		if ((p[k].grade[0] > a) || (p[k].grade[1] > a) || (p[k].grade[2] > a) || (p[k].grade[3] > a) || (p[k].grade[4] > a))
		{
			cout << "Студент : " << p[k].name << endl;
			cout << "Группа : " << p[k].group << endl;
			cout << "Оценки : " << p[k].grade[0] << ", " << p[k].grade[1] << ", " << p[k].grade[2] << ", " << p[k].grade[3] << ", " << p[k].grade[4] << endl;
			cout << endl;
			y++;
		}
	}
	if (y == 0)
	{
		cout << "Студенты отсутствуют";
	}

	return 0;
}