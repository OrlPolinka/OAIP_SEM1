#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, n, x, LastIndex;
	cout << "n = ";
	cin >> n;//вводим n
	for (i = 1; i <= n; i++)//Выполняем n раз, для всех значений x 
	{
		cout << "Введите x" << i << endl;
		cin >> x;//вводим x

		if (x < 0)//если х < 0, то
		{
			LastIndex = i;//присваиваем переменной(которая обозначает порядковый номер последнего отрицательного элемента) значение данного порядкового номера
		}

	}
	cout << "Порядковый номер последнего отрицательного элемента " << LastIndex << endl;//выводим наш порядковый номер на экран
	return 0;
}
