﻿/* Напечатать таблицу значений функции у = sin(x), где x изменяется от 0 до 180° с шагом 15. 
Нарисовать разделительные линии и шапку таблицы. 
Замечание: библиотечная функция sin(x) принимает значение угла в радианах, а не градусах (π радиан = 180°).
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

	cout << setprecision(3);
	double y;
	const double pi = 3.14;

	cout << " -----------------------------------------" << endl;
	cout << " |\t x \t |\t y=sin(x) \t | " << endl;
	cout << " -----------------------------------------" << endl;

	for (int x = 0; x <= 180; x+=15)
	{	
		y = sin((x/180.)*pi);
		
		cout << " | \t" << x << " \t | \t" << y << "\t  \t | \t" << endl;
	}

	cout << " -----------------------------------------" << endl;

	return 0;
}