﻿#include <iostream>
#include <string>
using namespace std;

//вводим и расписываем функцию для нахождения суммы кодов
int finds(string s) {
    int sum = 0;// Создаем переменную sum для хранения суммы ASCII кодов.
    for (int i = 0; i < s.length(); i++) {// Используем цикл for для перебора всех символов в строке s.
        if (s[i] != ' ') {// Если текущий символ - пробел, то 
            sum += int(s[i]);//прибавляем его ASCII код к переменной sum.
        }
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "rus"); 
    //создаем строку
    string s;
    //вводим строку с клавиатуры
    cout << "Введите строку: "; 
    cin >> s;
    //выводим результат на экран, используя функцию для нахождения суммы кодов
    cout << "Сумма кодов символов строки: " << finds(s);

    return 0;
}
