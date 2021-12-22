// Игра «Угадайка»

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {

	setlocale(0, "");

	int n, ch;

	srand(time(0));
	ch = rand() % 100 + 1;

	cout << "Введите число от 0 до 100 " << endl;

	do
	{
		cin >> n;

		if (n>ch)
		{
			cout << "Ваше число больше. Попробуйте снова" << endl;
		}

		if (n<ch)
		{
			cout << "Ваше число меньше. Попробуйте снова" << endl;
		}

	} while (n != ch);
		
		cout << "Вы угадали! Загаданное число - " << ch;
	
	return 0;
}

