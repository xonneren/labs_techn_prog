// Игра "Угадайка-2"

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


int main()
{
	setlocale(0, "");

	int n, nmin, nmax, symb;

	nmin = 0;
	nmax = 100;

	cout << "| Инструкция к игре |" << endl;
	cout << "1. Загадайте число от 0 до 100" << endl;
	cout << "2. В зависимости от близости числа, предложенного компьютером, введите один из 3-х символов:" << endl;
	cout << "1 - моё число больше;" << endl << "2 - моё число меньше;" << endl << "3 - компьютер угадал." << endl;

	do
	{
		srand(time(0));
		n = nmin + rand() % (nmax - nmin + 1); // генерация случайного числа от 0 до 100 включительно

		cout << "Ваше число - " << n << "?" << endl;;
		cin >> symb;

		if (symb==1)
		{
			nmin = n++; // минимальное значение увеличивается и генерируется новое число, с учётом нового промежутка
		}
		else if(symb==2)
		{
			nmax = n--;
		}
	} while (symb!=3);

	cout << "Спасибо за игру!";

	return 0;
}