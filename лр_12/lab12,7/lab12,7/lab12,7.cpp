﻿#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n, m;
    //задаем размеры массива
    cout << "Введите размер массива А: ";
    cin >> n;
    cout << "\nВведите размер массива B: ";
    cin >> m;

    int* A = new int[n]; // Выделяем память под массив А
    int* ptrA = A; // Указатель на начало массива
    cout << "\nМассив А: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *ptrA; // Вводим число в массив
        ptrA++; // Переходим к следующему элементу массива
    }

    int* B = new int[m]; // Выделяем память под массив В
    int* ptrB = B; // Указатель на начало массива
    cout << "\nМассив В: ";
    for (int i = 0; i < m; i++)
    {
        cin >> *ptrB; // Вводим число в массив
        ptrB++; // Переходим к следующему элементу массива
    }

    int maxA = *A; // Возьмем за максимальное число массива А первый элемент данного массива
    ptrA = A + 1; // Указатель на следующий элемент после первого

    while (ptrA < A + n)
    {
        if (*ptrA > maxA) // Если элемент массива А больше максимума, то максимуму присваивается значение данного элемента
        { 
            maxA = *ptrA;
        }
        ptrA++; // Переходим к следующему элементу массива А
    }

    bool foundMaxInB = false; // Добавляем переменную, для нахождения максимального элемента из массива А в массиве В
    ptrB = B; // Указатель на начало массива В

    while (ptrB < B + m)
    {
        if (*ptrB == maxA) // Если элемент массива В равен максимальному элементу массива А, то 
        {
            foundMaxInB = true; // присваиваем нашей переменной значение true
            break; 
        }
        *ptrB++; // Переходим к следующему элементу массива В
    }
    // Исходя из полученного результата, выводим соответствующее утверждение на экран:
    if (foundMaxInB)
    {
        cout << "Максимальный элемент массива А содержится в массиве В." << endl;
    }
    else
    {
        cout << "Максимальный элемент массива А не содержится в массиве В." << endl;
    }

    return 0;
}