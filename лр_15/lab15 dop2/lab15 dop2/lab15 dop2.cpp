#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n;

    cout << "Введите размер массива n = ";
    cin >> n;//вводим размер массива

    //Выделяем память под матрицу
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    cout << "Введите элементы матрицы:" << endl;
    //Вводим матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    //Ищем необходимую нам строку и столбец и выводим результат на экран:
    for (int k = 0; k < n; k++) {
        if (matrix[k][k] == matrix[k][0]) {
            cout << k << "-ая строка совпадает с " << k << "-ым столбцом." << endl;
        }
    }

    // Освобождаем память, выделенную под матрицу
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}