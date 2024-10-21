#include <iostream>
#include <string>
using namespace std;

//Функция для нахождения столбца, в котором находится элемент d
int find(int** a, int x) {
    for (int i = 0; i < sizeof(a[0]); i++) {
        for (int j = 0; j < sizeof(a[0][0]); j++) {
            if (a[i][j] == x) {
                return i + 1;
            }
        }
    }
}

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
    setlocale(LC_ALL, "RUS");
    int choice;
    cout << "Выберите номер задания" << endl;
    cout << "1 - Задание 1" << endl;
    cout << "2 - Задание 2" << endl;
    cout << "3 - Выход" << endl;
    while (true) {
        cout << "Выберите пункт: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int N, M, d;
            //Вводим размер матрицы
            cout << "Введите размеры матрицы: ";
            cin >> N >> M;
            //Вводим число k
            cout << "Введите число d = ";
            cin >> d;

            //Создаем массив и выделяем для него память 
            int** a;
            a = new int* [N];
            for (int i = 0; i < N; i++) {
                a[i] = new int[M];
            }

            //Выводим нашу матрицу на экран
            cout << "Введите элементы матрицы: " << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cin >> a[i][j];
                }
            }

            //Выводим результат на экран, используя функцию
            cout << "Строка, в которой содержится элемент d: " << find(a, d) << endl;

            //освобождаем выделенную память
            for (int i = 0; i < N; i++) {
                delete[] a[i];
            }
            delete[] a;
            break;
        }

        case 2: {
            //создаем строку
            string s;
            //вводим строку с клавиатуры
            cout << "Введите строку: ";
            cin >> s;
            //выводим результат на экран, используя функцию для нахождения суммы кодов
            cout << "Сумма кодов символов строки: " << finds(s) << endl;
            break;
        }

        case 3: {
            exit(0);
        }
        }
    }

    return 0;
}