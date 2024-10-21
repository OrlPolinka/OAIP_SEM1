﻿#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    double a = 3, b = 6, x, h, s = 0, y1, y2;                     //ввод данных
    int n = 200;                                                  //разделим криволинейную трапецию на n частей
    h = (b - a) / n;                                              //находим высоту трапеции
    x = a;
    for (int i = 0; i < n; i++) {                                 //подключаем цикл for и находим площади всех трапеций
        y1 = pow(x, 3) + 3;                                       //находим первое иснование трапеции
        x = x + h;                                                //добавляем к х высоту
        y2 = pow(x, 3) + 3;                                       //находим второе основание
        s = s + h * (y1 + y2) / 2;                                //рассчитываем площадь трапеции
    }
    cout << "Площадь криволинейной трапеции равна " << s << endl; //выводим результат на экран
    return 0;
}
