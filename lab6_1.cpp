// Работа с массивом

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

const int MSIZE = 10;
const char str[] = "***************************";

int main() {

	setlocale(0, "");

	int mas[MSIZE], o, p, sum, ind, min, max, sum2, hist, length ; // массив на 10 элементов
	double average;

	// Формирование массива и его вывод

	srand(time(0));
	for (int i = 0; i < MSIZE; i++)
	{
		mas[i] = rand() % 60 - 30; // определение нужного диапазона, 30 - (-30) = 60
									//генерируем число и прибавляем нижнее значение диапазона
		cout << " " << mas[i];
	}

	cout << endl;

	// Подсчёт кол-ва положительных и отрицательных элементов

	o = p = 0;
	for (int i = 0; i < MSIZE; i++){
		if (mas[i]<0)
		{
			o++;
		}
		else
		{
			p++;
		}
	}

	// Среднее арифметическое элементов и поиск близкого по значению элемента

	sum = 0;
	average = 0;
	
	for (int i = 0; i < MSIZE; i++) { // по очереди каждый элемент массива суммируется в памяти до тех пор, пока условие цикла не будет выполнено
		sum += mas[i];
	}
	average = sum / 10.0; // СА - сумма значений массива/количество элементов

	ind = 0; // ближний элемент

	for (int i = 1; i < MSIZE; i++) {
		if (abs(average-mas[i]) < abs(average-mas[ind])) // если модуль разности среднего значения и массива i меньше чем разница текущего и среднего элемента
			ind = i; // если ближнее значение элемента больше чем текущее, то оно заменяется им 
	}

	// Cумма элементов в массиве между максимальным и минимальным
	
	min = max = 0;

	for (int i = 0; i < MSIZE; ++i) {
		if (mas[i] < mas[min]) {
			min = i; // min массива определяется как его индекс
		}
		else if (mas[i]>mas[max])
		{
			max = i; // max
		}	
	}

	sum2 = 0;
	if (min < max)
	{
		for (int i = min+1; i < max; i++) // "+1" т.к. min и max не учитываются
		{
			sum2 += mas[i]; // расчёт суммы элементов
		}
	}
	else if (min > max)
	{
		for (int i = max+1; i < min; i++)
		{
			sum2 += mas[i];
		}
	}
	
	// Гистограмма
	
	hist = 0;
	length = 60;

	for (int i = 0; i < MSIZE; i++)
	{
		if (mas[i] < 0)
		{
			hist = -mas[i];
			printf("%*.*s", length, hist, str);
			cout << "|" << endl;
		} 
		else if (mas[i]>0)
		{
			hist = mas[i];
			printf("%*.*s", length, 0, str); // %*.*s -  *, length - минимальная ширина поля
			cout << "|";					// 0 - , str - то, как будет отображаться выведенное число, т.е. в виде массива *
			printf("%*.*s", hist, hist, str);
			cout << endl;
		}
		else
		{
			printf("%*.*s", length, 0, str);
			cout << "|" << endl;
		}		
	}

	cout << "\nКоличество положительных чисел массива - " << p << endl;
	cout << "Количество отрицательных чисел массива - " << o << endl;
	cout << "Номер ближайшего к среднему арифметическому " << average << " - #" << ind << endl;
	cout << "Сумма элементов между min (" << mas[min] << ") и max (" << mas[max] << ") равна " << sum2 << endl;

	return 0;
}