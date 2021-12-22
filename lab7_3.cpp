// Подсчёт слов

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(0, "");

	string str;
	int sl = 0;

	cout << "Введите строку: ";
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) // если символ строки не является её концом и последующий символ не оканчивается пробельным символом
	{
		if ((str[i] != ' ' && ((str[i + 1] == ' ') || (str[i + 1] == '\t') || (str[i + 1] == '\n')))) // то далее обрабатывается следующий и если он содержит пробел
		{														// они суммируются и так до конца строки
			sl++;
		}

	}

	cout << "Количество слов в строке - " << sl + 1; // пробелов всегда на 1 меньше, чем слов, поэтому к числу пробелов добавляем 1

	return 0;
}