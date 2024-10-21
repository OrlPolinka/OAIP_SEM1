#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float sum = 0, x, y, z = 0;
	int i;
	for (i = 1; i <= 5; i++)//Выполняем 5 раз, для всех значений x 
	{
		cout << "Введите x" << i << endl;
		cin >> x;//вводим x
		
		if (x > z)//Если x > z, то 
		{
			z = x;//присваиваем z значение x
		}

		sum = sum + pow(x, 2);//рассчитываем сумму для каждого значения х
	}
	cout << "z = " << z << endl;//выводим значение z на экран
	cout << "Сумма равна " << sum << endl;//выводим значение суммы на экран
	y = z * sum;//рассчитываем у
	cout << "y = " << y << endl;//выводим значение у на экран
	return 0;
}
