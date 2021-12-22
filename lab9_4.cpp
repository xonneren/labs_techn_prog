// Перестановка слов в файле

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string file_1 = "test1.txt";

	ifstream fin(file_1.c_str());

	string file_2 = "test2.txt";

	ofstream fout(file_2.c_str());

	string s1;
	int pos = 0;
	char sn = 0;
	string s11, s12;
	int count = 0;
	while (getline(fin, s1, sn))
	{
		if (s11 != "")
		{
			s12 = s1.substr(pos, s1.find(" ")); // возвращает подстроку данной строки начиная с символа с индексом pos и до конца строки.
			s1.erase(pos, s12.size()); // удаляет из строки S  с символа с индексом pos и до конца строки.
			s1.erase(0, 1);
			fout << s12 << endl << s11 << " ";
			cout << s12 << endl << s11 << " ";
		}
		else if (s12 != "")
		{
			fout << endl;
			cout << endl;
		}
		while (1)
		{
			s11 = s1.substr(pos, s1.find(" "));
			s1.erase(pos, s11.size());
			if (s1[0] == ' ')
			{
				s1.erase(0, 1);
			}
			else if (s1 == "" && s12 == "" || s11 == "")
			{

				break;
			}
			s12 = s1.substr(pos, s1.find(" "));
			s1.erase(pos, s12.size());
			if (s1[0] == ' ')
			{
				s1.erase(0, 1);
			}
			else if (s1 == "" && s11 == "" || s12 == "")
			{
				break;
			}
			fout << s12 << " " << s11 << " "; // запись итоговой строки во второй файл

		}
	}
	fout << s11;

	fin.close();
	fout.close();
}