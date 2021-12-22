// Числа Фибоначчи

#include<iostream>
#include<cmath>
using namespace std;

int fib(int N)
{
	int f1, f2, fn;

	f1 = 0; // первые два члена условно равны 1
	f2 = 1;
	fn = 0;

	if (N == 0) // согласно условию, N должно быть больше 0
	{
		return 0;
	}
	if (N == 1)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < N; i++)	  // т.к. первые два числа равны 1, то 2 номер равен 1, поэтому, счёт продолжается от этой цифры
		{
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}

		return fn;
	}
}

int fib_rec(int N)
{
	int fn = 1;

	if (N == 0)
	{
		return 0;
	}
	else if (N == 1)
	{
		return 1;
	}
	else
	{
		fn = fib_rec(N - 1) + fib_rec(N - 2); // а формуле рекурсивного процесса функция вызывается два раза
	}

	return fn;
}

int max_N() // максимальное значение, которое может вместить int = 2 147 483 647
{
	int n = 1;
	int f1 = fib(n), fn;
	
	while (true)
	{
		fn = fib(++n);
		if (fn < f1)
		{
			return n-1;
		}
		else
		{
			f1 = fn;
		}
	}
}

int main() {

	setlocale(0, "");

	int N, n; // ввод номера необходимого числа в ряду Фибоначчи

	cout << "Введите номер числа (N) - ";
	cin >> N;

	if (N < 0)
	{
		cout << "Номер числа должен быть положительным! Попробуйте снова" << endl;
	}

	cout << "Ваше число (рекурсивный метод) - " << fib_rec(N) << endl; // вызов функции рекурсии
	cout << "Ваше число (нерекурсивный метод) - " << fib(N) << endl;
	cout << "Максимальное число N, результат которого помещается в типе int - " << max_N() << endl;
	
	return 0;
}
