#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float sum = 0, d = 12.5e-4, h, a;
	int i;
	const int n = 5;
	for (i = 1; i <= n; i++)//Выполняем n раз, для всех значений a 
	{
		cout << "Введите a" << i << endl;
		cin >> a;//вводим a
		sum = sum + pow(a, 2);//рассчитываем сумму для каждого значения a
	}
	cout << "Сумма равна " << sum << endl;//выводим значение суммы на экран
	h = d + sum;//рассчитываем h
	cout << "h = " << h << endl;//выводим значение h на экран
	
	return 0;
}
