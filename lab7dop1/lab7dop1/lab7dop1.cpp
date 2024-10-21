#include <iostream>
#include <cmath>
using namespace std;

int find_square_number()//функция, которая делает следующее:
{
    for (int i = 10; i <= 31; i++) //проверяет числа от 10 до 31(так как они в квадрате дают трехзначные числа),
    {
        int square = i * i;//вычисляет квадрат каждого числа
        int digit1 = square / 100;//расписываем первую цифру числа,
        int digit2 = (square / 10) % 10;//вторую цифру числа, 
        int digit3 = square % 10;//третью цифру числа

        if (digit1 < digit2 && digit2 < digit3) //проверяем, чтобы цифры числа шли в порядке возрастания
        {
            return square;//если число найдено
        }
    }

    return -1; // Если такое число не найдено
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int result = find_square_number();//вызываем нашу функцию

    if (result != -1) //если число найдено, то
    {
        cout << "Найдено число: " << result << endl;//выводим его на экран
    }
    else //иначе
    {
        cout << "Такое число не найдено." << endl;//выводим на экран, что такое число не найдено
    }
    return 0;
}