#include <iostream>
using namespace std;
    
    int countWays(int amount)//функция, которая вычисляет количество способов набрать заданную сумму(amount), расписываем эту функцию:
    {
        if (amount == 0) {
            return 1; // базовый случай: сумма равна 0, есть один способ - ничего не брать
        }

        int ways = 0;//ways это количество способов набрать заданную сумму, изначально равно 0
        //вызываем функцию для оставшейся суммы, для каждой монеты(50коп, 20коп, 5коп и 2коп):
        if (amount >= 50) {
            ways += countWays(amount - 50); 
        }

        if (amount >= 20) {
            ways += countWays(amount - 20);
        }

        if (amount >= 5) {
            ways += countWays(amount - 5);
        }

        if (amount >= 2) {
            ways += countWays(amount - 2);
        }

        return ways;
     }

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int ways = countWays(100);//присваиваем количеству способов расписанную выше функцию для получения в сумме 100коп(1р)
	cout << "Количество способов набрать один рубль: " << ways << endl;//выводим наш результат на экран
	return 0;
}