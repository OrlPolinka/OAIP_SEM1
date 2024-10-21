#include <iostream>
#include <ctime>
#include <map>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 100;//Определяем максимальный размер массива равным 100
	int k, A[N], rmn = 0, rmx = 99;//объявляем переменные
	cout << "Количество чисел в массиве ";
	cin >> k;//вводим количество чисел в массиве(размер массива)
	cout << "\n Массив: ";
	srand((unsigned)time(NULL));//инициализируем генератор случайных чисел на основе текущего времени
	for (int i = 0; i < k; i++) 
	{//используем цикл for для заполнения массива
		A[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);//генерирует случайное число между rmn и rmx
		cout << A[i] << " "; //поочередно выводим числа массива
	}

	map<int, int> countMap;// Создаем map для подсчета количества вхождений каждого числа
	for (int num : A) 
	{// Проходим по массиву и увеличиваем счетчик для каждого числа
		countMap[num]++;
	}
	// Проходим по map и выводим числа, встречающиеся только один раз
	cout << "\n Числа, входящие в массив только один раз: ";
	for (const auto& pair : countMap) 
	{
		if (pair.second == 1) 
		{
			cout << pair.first << " ";
		}
	}

	return 0;
}