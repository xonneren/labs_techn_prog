// Работа с массивом через функции

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

const char str[] = "***************************";

// Заполнение и вывод массива

void Massiv(int *mas, int MSIZE)	// здесь тип void указывает, что функция не возвращает значение, т.е. функция без типа
{													// * - является указателем на переменную типа int
	cout << "Исходный массив" << endl;
	for (int i = 0; i < MSIZE; i++)
	{
		mas[i] = rand() % 60 - 30; // определение нужного диапазона, 30 - (-30) = 60
									//генерируем число и прибавляем нижнее значение диапазона
		cout << " " << mas[i];
	}
	cout << endl;
}

// Подсчёт кол-ва положительных и отрицательных элементов

void PosNeg(int* mas, int MSIZE)
{
	int o, p;
	o = p = 0;

	for (int i = 0; i < MSIZE; i++) {
		if (mas[i] < 0)
		{
			o++;
		}
		else
		{
			p++;
		}
	}
	cout << "\nКоличество положительных чисел массива - " << p << endl;
	cout << "Количество отрицательных чисел массива - " << o << endl;
}

// Среднее арифметическое элементов и поиск близкого к нему по значению элемента

void Average(int* mas, int MSIZE)
{
	int sum, average, ind;
	sum = average = ind = 0;

	for (int i = 0; i < MSIZE; i++) { // по очереди каждый элемент массива суммируется в памяти до тех пор, пока условие цикла не будет выполнено
		sum += mas[i];
	}
	average = sum / 10.0; // СА - сумма значений массива/количество элементов

	for (int i = 1; i < MSIZE; i++) {
		if (abs(average - mas[i]) < abs(average - mas[ind])) // если модуль разности среднего значения и массива i меньше чем разница текущего и среднего элемента
			ind = i; // если ближнее значение элемента больше чем текущее, то оно заменяется им 
	}
	cout << "\nНомер ближайшего к среднему арифметическому " << average << " - #" << ind << endl;
}

// Cумма элементов в массиве между максимальным и минимальным

void Summa(int* mas, int MSIZE)
{
	int min, max, sum2;
	min = max = 0;

	for (int i = 0; i < MSIZE; ++i) {
		if (mas[i] < mas[min]) {
			min = i; // min массива определяется как его индекс
		}
		else if (mas[i] > mas[max])
		{
			max = i; // max
		}
	}

	sum2 = 0;

	if (min < max)
	{
		for (int i = min + 1; i < max; i++) // "+1" т.к. min и max не учитываются
		{
			sum2 += mas[i]; // расчёт суммы элементов
		}
	}
	else if (min > max)
	{
		for (int i = max + 1; i < min; i++)
		{
			sum2 += mas[i];
		}
	}
	cout << "\nСумма элементов между min (" << mas[min] << ") и max (" << mas[max] << ") равна " << sum2 << endl;
}

void Hist(int* mas, int MSIZE)
{
	int hist, length;
	
	length = 60;
	hist = 0;
	
	cout << endl;
	
	for (int i = 0; i < MSIZE; i++)
	{
		if (mas[i] < 0)
		{
			hist = -mas[i];
			printf("%*.*s", length, hist, str);
			cout << "|" << endl;
		}
		else if (mas[i] > 0)
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
}

int main() 
{
	setlocale(0, "");
	srand(time(0));

	const int MSIZE = 10;

	int mas[MSIZE];

	Massiv(mas, MSIZE);
	PosNeg(mas, MSIZE);
	Average(mas, MSIZE);
	Summa(mas, MSIZE);
	Hist(mas, MSIZE);

	return 0;
}