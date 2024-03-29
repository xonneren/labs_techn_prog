﻿// Преобразование « Дата => День недели »

#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");

    int d, m, p, y, dn;

    cout << "Введите дату в формате 'dd mm' " << endl;
    cin >> d >> m;

    if (d > 31 || m > 12 && d < 1 || m < 1)
    {
        cout << "Введена неверная дата! ";
    }
    
	if (m == 1 || m == 2) // январь и февраль 
    {
        y = 2007 - 1; // нюанс формулы Зеллера, январь и февраль считаются 13 и 14 месяцем предыдущего года
        p = m + 10; // оставшиеся 10 месяцев
    } 
    else
    {
        y = 2007;
        p = m - 2;
    }

    dn = (d + ((31 * p) / 12) + y + (y / 4) - (y / 100) + (y / 400)) % 7;

    cout << "[ " << d << "." << m << ".2007] - ";

    if (dn == 0)
    {
        cout << "Воскресенье"; // т.к. при делении на 7, дастся остаток 0, т.е. деление нацело
    }
    else if (dn == 1)
    {
        cout << "Понедельник";
    }
    else if (dn == 2)
    {
        cout << "Вторник";
    }
    else if (dn == 3)
    {
        cout << "Среда";
    }
    else if (dn == 4)
    {
        cout << "Четверг";
    }
    else if (dn == 5)
    {
        cout << "Пятница";
    }
    else if (dn == 6)
    {
        cout << "Суббота";
    }
    
    return 0;
}