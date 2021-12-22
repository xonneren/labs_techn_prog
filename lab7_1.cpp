// Подсчёт английских букв 

#include <iostream>
#include<cctype>
#include<string>
using namespace std;


int main()
{
	setlocale(0, "");
	
	string str;
	int gl, sogl, st, pr;

	cout << "Введите строку : ";
	getline(cin, str);

	gl = sogl = st = pr = 0;

	for (int i = 0; i < (int) str.size(); i++)
	{
		if (str[i] != ' ') // "пробел" не учитывается
		{
			if (isalpha(str[i]))
			{
				if (isupper(str[i])) // проверяет символ, является ли он прописным
				{
					pr++;
				}
				else
				{
					st++;
				}

				if (str[i]=='a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
				{
					gl++;
				}
				else
				{
					sogl++;
				}
			}
		}
	}

	cout << "Кол-во строчных - " << st << endl;
	cout << "Кол-во прописных - " << pr << endl;
	cout << "Кол-во гласных - " << gl << endl;
	cout << "Кол-во согласных - " << sogl << endl;

	return 0;
}
