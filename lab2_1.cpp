﻿/*Даны длины трех отрезков a, b, c. Определить, можно ли из этих трех отрезков построить треугольник. 
Исходные данные ввести с клавиатуры. Все числа считать вещественными (double)
прим.: чтобы из трех отрезков можно было составить треугольник, необходимо и достаточно, 
чтобы сумма длин любых двух отрезков была строго больше третьего */

#include<iostream>
using namespace std;

int main() {

	double a, b, c;

	setlocale(0, "");
	cout << "Введите число 'a': ";
	cin >> a;

	cout << "Введите число 'b': ";
	cin >> b;

	cout << "Введите число 'c': ";
	cin >> c;

	if ((a < (b + c)) && (b < (a + c)) && (c < (a + b)))
	{
		cout << "Построение треугольника при заданных значениях ВОЗМОЖНО\n";
	}
	else
	{
		cout << "Построение треугольника при заданных значениях НЕВОЗМОЖНО\n";
	}
	
	return 0;
}
