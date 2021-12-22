/* Вычислить и напечатать в виде таблицы значения функции, 
заданной с помощью ряда Тейлора, на интервале от x нач до x кон с шагом dx и точностью ε.
Каждая строка таблицы должна содержать значение аргумента, значение функции и библиотечное значение */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const double pi = 3.1415, e = 2.7182;

int main() {

	setlocale(0, "");
	cout.precision(6);

	double xn, xk, dx, eps, f1, f2, f3, f4, f5, f6, gr;
	int n, fact;

	cout << "Введите xn : " << endl;
	cin >> xn;

	cout << "Введите xk : " << endl;
	cin >> xk;

	cout << "Введите шаг dx : " << endl;
	cin >> dx;

	cout << "Введите точность eps: " << endl;
	cin >> eps;

	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "     xn      |     e^-x      |    sin(x)/x   |    arctg(x)    |       ln(x)       |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	while (xn < xk + dx) // формируем цикл, который будет расчитывать в функцию в интервале [xn; xk], включая последний элемент
	{
		f1 = 0;  //e^-x, |x| < inf
		n = 0;
		gr = 10000; // задаём произвольную границу ряда
		while (abs(gr - f1) > eps)
		{
			fact = 1;
			for (int i = 1; i <= n; i++)
			{
				fact *= i;
			}
			gr = f1;
			f1 += (pow(-1, n) * pow(xn, n)) / fact;
			n++;
		}

		f2 = 0;		// sin(x)/x, |x| < inf
		n = 0;
		gr = 1000;
		while (abs(abs(gr)-abs(f2)) > eps)
		{
			double f = 1;
			for (double i = 2; i <= double(n); i+=1.0)
			{
				f *= i;
			}
			gr = f2;
			f2 += ((pow(xn, n * 2)) / fact);
			f2 = (n + 1) % 2 == 0 ? -f2 : f2;
			n++;
		}
			
		if (abs(xn) <= 1) // arctgx, |x| <= 1
		{
			f3 = 0;
			n = 0;
			gr = 1000;
			while (abs(abs(gr) - abs(f3)) > eps)
			{
				gr = f3;
				f3 += (pow(-1, n) * pow(xn, 2 * n + 1)) / (2.0 * n + 1);
				n++;
			}
		}
		else if (xn > 1) // альтернативная ветка при x > 1
		{
			f3 = 0;
			n = 0;
			gr = 1000;
			while (abs(abs(gr) - abs(f3)) > eps)
			{
				gr = f3;
				f3 += pow(-1, n + 1) / ((2 * n + 1) * pow(xn, 2 * n + 1));
				n++;
			}
			f3 += (pi / 2);
		}

		if (xn > 0) // lnx, x > 0
		{
			f4 = 0;
			n = 0;
			gr = 1000;
			while (abs(abs(gr) - abs(f4)) > eps)
			{
				gr = f4;
				f4 += pow(xn - 1, 2 * n + 1) / ((2 * n + 1) * pow(xn + 1, 2 * n + 1));
				n++;
			}
			f4 *= 2;
		}
		else
		{
			f4 = 0;
		}
		cout << "   " << setw(7) << xn << "   |   " << setw(9) << f1 << "   |   " << setw(9) << f2 << "   |   " << setw(10) << f3 << "   |   " << setw(13) << f4 << "   |   " << endl;
		cout << "  " << setw(7) << "lib.func" << "   |   " << setw(9) << pow(e, -xn) << "   |   " << setw(9) << sin(xn) / xn << "   |   " << setw(10) << atan(xn) << "   |   " << setw(13) << log(xn) << "   |   " << endl;
		cout << "_____________|_______________|_______________|________________|___________________|" << endl;
		
		xn += dx;
	}
	return 0;
}