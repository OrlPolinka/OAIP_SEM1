#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float a = 1.055, x = 0.6, n = 6, y, z;
	y = pow(cos(pow(x, 2)), 2) / abs(x);//Рассчитываем y
	cout << "y = " << y << endl;//Выводим y
	while (n < 16)//Пока n < 16, делаем следующее:
	{
		if (y < a * x * n)//Если y < a * x * n, то делаем следующее: 
			z = abs(y);
		else//Иначе, следующее:
			z = sqrt(1 + exp(-y));
		cout << "z = " << z << endl;//Выводим значение z

		n = n + 2;//Добавляем к n 2
	}
	return 0;
}
