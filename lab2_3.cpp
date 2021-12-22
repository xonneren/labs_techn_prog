/* Даны координаты точки A (x, y) и координаты левого верхнего (xl, yt) и правого нижнего (xr, yb) углов прямоугольника. 
Определить, принадлежит ли точка A прямоугольнику. Исходные данные ввести с клавиатуры. Все числа считать целыми.
*/

#include<iostream>
using namespace std;

int main() {
	setlocale(0, "");

	int x, y, xl, yt, xr, yb;

	cout << "x: ";
	cin >> x;

	cout << "y: ";
	cin >> y;

	cout << "xl: ";
	cin >> xl;

	cout << "yt: ";
	cin >> yt;

	cout << "xr: ";
	cin >> xr;

	cout << "yb: ";
	cin >> yb;

	if (((x>=xl && x<=xr) || (x<=xl && x>=xr)) && ((y>=yt && y<=yt) || (y<=yt && y>=yb)))
	{
		cout << "Точка принадлежит прямоугольнику";
	}
	else
	{
		cout << "Точка не принадлежит прямоугольнику";
	}
	return 0;
}