/* Написать программу вычисления x^n, где x – вещественное число, а n – целое неотрицательное. 
Значения x и n ввести с клавиатуры. */

#include<iostream>
using namespace std;

int main() {

	setlocale(0, "");

	double x, c, p;
	int n;

	cout << "Введите число x - ";
	cin >> x;

	cout << "Введите степень числа x - ";
	cin >> n;

	p = x;

	if (n > 1)
	{
		for (int i = 1; i < n; i++)
		{
			x *= p;
		}
		cout << "Ответ - " << x;
	}

	if (n < 0)
	{
		for (int i = 1; i < abs(n); i++)
		{
			x *= p;
		}

		c = 1 / x;
		cout << "Ответ - " << c;
	}

	if (n==0)
	{
		c = 1;
		cout << "Ответ - " << c;
	}

	if (n==1)
	{
		c = x;
		cout << "Ответ - " << c;
	}

	return 0;
}