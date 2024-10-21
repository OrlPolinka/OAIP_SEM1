#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float q = 0, x, y;
	int i;
	const int n = 6;
	for (i = 1; i <= n; i++)//Выполняем 6 раз, для всех значений x и y
	{
		cout << "Введите x" << i << endl;
		cin >> x;//вводим x
		cout << "Введите y" << i << endl;
		cin >> y;//вводим y
		q = q + (x * y);//Рассчитываем нашу сумму для всех каждого значения x и y
	}
	cout << "Ответ: " << q << endl;//выводим ответ на экран
	return 0;
}
