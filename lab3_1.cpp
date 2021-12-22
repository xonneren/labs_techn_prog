/* Ввести с клавиатуры целое положительное число N. Посчитать сумму чётных целых чисел от 1 до N.*/

#include<iostream>
using namespace std;

int main() {

	setlocale(0, "");

	int N;

	cout << "Введите число N - ";
	cin >> N;

	int sum = 0;

	for (int i = 1; i <= N; i++) 
	{
		if (i % 2 == 0) 
		{
			sum += i;
		}
	}
	
	cout << "Сумма чётных целых чисел - " << sum;

	return 0;
}