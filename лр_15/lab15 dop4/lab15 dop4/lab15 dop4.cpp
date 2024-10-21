#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n, m;
    int** a;

    cout << "Введите размеры матрицы ";
    cin >> n >> m;//вводим размеры матрицы
    a = new int* [n];//создаем переменные

    for (int i = 0; i < n; i++) {
        a[i] = new int[m];//отделяем память
    }

    cout << "Введите элементы матрицы:" << endl;
    //Вводим матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int max = a[0][0];//объявляем переменную максимального элемента матрицы
    //ищем максимальный элемент матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }

    int str = 0;//объявляем переменную количества строк
    for (int i = 0; i < n; i++) {
        bool status = true;//выполняем проверку элементов строк матрицы
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                status = false;
                break;
            }
        }
        //выполняем подсчет количества строк матрицы
        if (status) {
            str++;
        }
    }

    //выводим результат на экран
    cout << "Количество строк: " << str << "\nМаксимальное число матрицы: " << max << endl;

    //освобождаем выделенную память
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
