﻿#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int N = 100;//Определяем максимальный размер массива равным 100
    int i, sz = 10, rmn = 0, rmx = 99, maxCount = 1, currentCount = 1;//объявляем переменные
    
    int A[] = { 'a', 's', 'v', 'v','a','d','b','b','b','s' };
    cout << "Массив A: ";
    for (i = 0; i < sz; i++)
    {
        cout << A[i] << " ";//выводим поочередно числа массива на экран
    }

    for (i = 1; i < sz; i++)
    {//задаём цикл for и сравниваем рядом стоящие символы
        if (A[i] == A[i + 1])
        {//если соседние символы равны, то к переменной, обозначающей количество одинаковых рядом строящих элементов, +1
            currentCount++;
            if (currentCount > maxCount)
            {//обновляем максимальное значение
                maxCount = currentCount;
            }
        }
        else
        {//если соседние символы не равны, то количество одинаковых рядом стоящих символов остается равным 1
            currentCount = 1;
        }
    }
    cout << "\n Наибольшее число подряд идущих одинаковых элементов равно " << maxCount << endl;//Выводим наш результат на экран
    return 0;
}