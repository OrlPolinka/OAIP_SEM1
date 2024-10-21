﻿#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    //вводим массив А:
    int A[] = { 'a', 'b', 'c', 'd', 'e' };
    cout << "Массив A: ";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    //вводим массив В:
    int B[] = { 'e', 'd', 'c', 'b', 'a' };
    cout << "\n Массив B: ";
    for (int i = 0; i < 5; i++)
    {
        cout << B[i] << " ";
    }
    
    int C[5];//задаём массив С

    int* ptrA = A;//указатель на начало массива А
    int* ptrB = B;//указатель на начало массива В
    int* ptrC = C;//указатель на начало массива С

    for (int i = 0; i < 5; i++)//задаём цикл for и проходим по каждому элементу массивов
    {
        *ptrC = *ptrA + *ptrB;//вычисляем сумму элементов массивов А и В и присаиваем это значение массиву С 
        *ptrA++;//переход к следующему элементу массива А
        *ptrB++;//переход к следующему элементу массива В
        *ptrC++;//переход к следующему элементу массива С
    }
    //выводим массив С на экран:
    cout << "\n Массив С: ";
    for (int i = 0; i < 5; i++)
    {
        cout << C[i] << " ";
    }

    return 0;
}