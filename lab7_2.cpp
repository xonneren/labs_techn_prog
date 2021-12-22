// Подсчёт русских букв

#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;

int main() {

	setlocale(0, "");
	SetConsoleCP(1251);			//
	SetConsoleOutputCP(1251);
	
	string str;
	int gl, sogl, st, pr;

	string ABCstr = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"; // формируем строки для дальнейшего поиска букв
	string ABCzagl = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";	// в данном случае прописных и строчных

	string ABCgl = "АЕЁИОУЫЭЮЯаеёиоуыэюя";		// гласные и согласные буквы любого регистра
	string ABCsogl = "БВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфхцчшщ";

	cout << "Введите строку : ";
	getline(cin, str);

	gl = sogl = st = pr = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (ABCstr.find_first_of(str[i]) != string::npos) // функция find_first_of проходит по всей введённой строке 
		{												// и ищет первый символ, равный символу из другой строки 
			st++;						// в случае его отсутствия, функция возвращает npos, т.е. поиск идёт до тех пор пока нужный шаблон не будет найден
		}
		else if (ABCzagl.find_first_of(str[i]) != string::npos)
		{
			pr++;
		}

		if (ABCgl.find_first_of(str[i]) != string::npos)
		{
			gl++;
		}
		else if (ABCsogl.find_first_of(str[i]) != string::npos)
		{
			sogl++;
		}
	}

	cout << "Кол-во строчных - " << st << endl;
	cout << "Кол-во прописных - " << pr << endl;
	cout << "Кол-во гласных - " << gl << endl;
	cout << "Кол-во согласных - " << sogl << endl;

	return 0;
}