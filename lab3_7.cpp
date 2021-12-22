/* Подсчитать число «счастливых» шестизначных билетиков в диапазоне от 100000 до 999999. 
Билет считается «счастливым», если сумма его первых трёх цифр совпадает с суммой последних трёх.
(Ответ: 50412)
*/

#include<iostream>
using namespace std;

int main() {

	setlocale(0, "");

	int first, last, sum1, sum2, result = 0;

	for (int i = 100000; i <= 999999; i++)
	{
		/*a = i / 100000;
		b = i / 10000 - a * 10;
		c = i / 1000 - a * 100 - b * 10;
		d = i / 100 - a * 1000 - b * 100 - c * 10;
		e = i / 10 - a * 10000 - b * 1000 - c * 100 - d * 10;
		f = i - a * 100000 - b * 10000 - c * 1000 - d * 100 - e * 10;

		sum1 = a + b + c;
		sum2 = d + e + f;*/

		first = i / 1000;
		last = i % 1000;

		sum1 = first / 100 + (first / 10)%10 + first % 10;
		sum2 = last / 100 + (last / 10)%10 + last % 10;

		if (sum1==sum2)
		{
			result++;
		}
	}
	cout << "Число счастливых билетов - " << result;

	return 0;
}