#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float sum = 0, x, a, y, k = 0;
	int i;
	for (i = 1; i <= 5; i++)//Выполняем 5 раз, для всех значений x 
	{
		cout << "Введите x" << i << endl;
		cin >> x;//вводим x
		sum = sum + x;//рассчитываем сумму для каждого значения х
	}
	cout << "Сумма равна " << sum << endl;//выводим значение суммы на экран

	for (i = 1; i <= 3; i++)//выполняем 3 раза для всех значений а и у
	{
		cout << "Введите a" << i << endl;
		cin >> a;//вводим a
		y = a + sum;
		cout << "y" << i << "=" << y << endl;//Выводим занчение каждого у на экран

		if (y > k)//Если y>k, то 
		{
			k = y;//присваиваем k значение у
		}
	}
	cout << "k = " << k << endl;//выводим значение k на экран
	return 0;
}
