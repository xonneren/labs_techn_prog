﻿/*Ввести с клавиатуры номер года (положительное целое число) и напечатать, является ли год високосным. 
Високосные года делятся на 400 (например, 2000) или же делятся на 4, но не делятся на 100 (2004).*/

#include<iostream>
using namespace std;

int main() {
	setlocale(0, "");

	int year;
	
	cout << "Введите год : ";
	cin >> year;

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) // операторы равенства '==' - "равно", '!=' - "не равно"
	{													// = 0 - проверка на остаток от деления, т.е. делится ли одно число на другое
		cout << year << " год является високосным\n";
	}
	else
	{
		cout << year << " год является обычным\n";
	}
		
	return 0;
}