﻿#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n, count = 0;
    //задаем размеры массива
    cout << "Введите размер массива Z: ";
    cin >> n;

    int* Z = new int[n]; // Выделяем память под массив А
    int* ptr = Z; // Указатель на начало массива
    cout << "\nМассив Z: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *ptr; // Вводим число в массив
        ptr++; // Переходим к следующему элементу массива
    }

    for (int i = 0; i < n; i++)
    {//используем цикл for для проверки каждого символа массива
        bool isUnique = true;//вначале каждой итерации цикла присваиваем значение переменной isUnique значение true, что означает что символ уникальный(используется в первый раз)
        for (int j = 0; j < i; j++)
        {//используем второй цикл for и срвниваем элементы массива
            if (*(ptr + i) == *(ptr + j))
            {//если такой элемент массива уже есть, то
                isUnique = false;//значение переменной становится false, это значит, что данный элемент уже использовался
                break;
            }
            *ptr++;//переходим к следующему элементу массива
        }
        if (isUnique)
        {//если после нашей проверки isUnique остается true, тотекущий элемент считается уникальным и увеличивается счетчик count
            count++;
        }
    }
    cout << "\nКоличество различных элементов равно " << count << endl;//выводим наш результат на экран
    return 0;
}