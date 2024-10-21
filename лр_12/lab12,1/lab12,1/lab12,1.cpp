﻿#include <iostream>
using namespace std;

int findMinNotInSecondArray(int* A, int szA, int* B, int szB)//задаём функцию для нахождения нашего результата:
{
    int min = INT_MAX;//задаём минимум равным максимальному значению типа данных int
    for (int i = 0; i < szA; i++)
    {//задаём цикл for и проверяем каждый член массива А
        if (find(B, B + szB, A[i]) == B + szB)
        {//проверяем, есть ли данный(i-тый член) массива А в массиве В, если нет, то
            if (A[i] < min)
            {//если данный член массива А меньше минимального значения, то минимальное значение равно данному числу
                min = A[i];
            }
        }
    }
    return min;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int i, j, szA = 10, szB = 10;

    int A[] = { 'a', 's', 'v', 'd','u','k','g','r','w','m' };
    cout << "Массив A: ";
    for (i = 0; i < szA; i++)
    {
        cout << A[i] << " ";//выводим поочередно числа массива на экран
    }

    int B[] = { 'b', 'h', 'e', 'v','a','c','n','s','w','x' };
    cout << "\n Массив B: ";
    for (i = 0; i < szB; i++)
    {
        cout << B[i] << " ";//выводим поочередно числа массива на экран
    }
    //задаём указатели на начало массивов
    int* ptr1 = A;
    int* ptr2 = B;
    int result = findMinNotInSecondArray(ptr1, szA, ptr2, szB);//Вводим переменную результата и присваиваем ей значение данной функции
    cout << "\n Наименьшее среди чисел первого массива, которое не входит во второй массив: " << result << endl;//Выводим наш результат на экран
    return 0;
}
