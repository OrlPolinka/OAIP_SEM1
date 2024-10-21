#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, n, sum = 0, x;
	cout << "n = ";
	cin >> n;//вводим n
	for (i = 1; i <= n; i++)//Выполняем n раз, для всех значений x 
	{
		cout << "Введите x" << i << endl;
		cin >> x;//вводим x

		if (x % 2 == 0)//если х кратно 2(четное), то
		{
			sum = sum + x;//к сумме добавляем данное значение х
		}
		
	}
	cout << "Сумма равна " << sum << endl;//выводим значение суммы на экран
	return 0;
}
