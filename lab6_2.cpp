// Упорядочивание массивов

#include <iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int MSIZE = 15;

int main()
{
	setlocale(0, "");

	int mas[MSIZE], p, o; // массив на 15 элементов

	// Формирование массива и его вывод

	srand(time(0));

	cout << "Исходный массив" << endl;

	for (int i = 0; i < MSIZE; i++)
	{
		mas[i] = rand() % 180 - 90;
		cout << " " << mas[i];
	}

	cout << endl;

	// Упорядочивание массива. Сначала все отрицательные элементы, затем нули и положительные

	cout << "Упорядоченные массивы " << endl;

	for (int i = 0; i < MSIZE; i++)
	{
		sort(mas, mas + 15);

		cout << mas[i] << " ";
	}

	cout << endl;

	// Упорядочить массив по возрастанию модулей элементов

	for (int i = 0; i < MSIZE; i++)
	{
		for (int j = i+1; j < MSIZE; j++)
		{
			if (abs(mas[i]) > abs(mas[j])) // если модуль i-го элемента больше модуля следующего
			{
				swap(mas[i], mas[j]);	// то они меняются местами
			}
		}
		cout << mas[i] << " ";
	}
	cout << endl;
	
	// Упорядочить массив так, чтобы вначале шли чётные элементы, а потом все нечётные
	
	for (int i = 0; i < MSIZE; i++)
	{
		if (mas[i] % 2 != 0) // если элемент массива при делении на 2 не даёт остатка ноль, то он нечётный
		{
			for (int j = i+1; j < MSIZE; j++) // вводим дополнительную переменную, которая условно будет следующим числом после нечётного элемента
											//проходим по массиву
			{
				if (mas[j] % 2 == 0) // если следующий элемент после нечётного чётный
				{
					swap(mas[i], mas[j]); // то они меняются местами
				}
			}

			cout << mas[i] << " ";
		}
	}
	
	return 0;
}