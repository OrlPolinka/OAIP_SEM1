﻿#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float s = 0;//вводим переменную s(сумму)
	for (int i = 1; i < 150; i++)//вводим цикл for и для каждого значения i, которое меньше 150, начиная с 1 делаем следующее:
	{//Если i кратно 5, то к s(сумме) добавляем данное значение i
		if (i % 5 == 0)
		{
			s += i;
		}
	}
	cout << "Сумма целых положительных чисел, кратных 5 и меньших 150: " << s << endl;//Выводим наше значение на экран
	return 0;
}
