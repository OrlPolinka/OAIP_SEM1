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

    //Поиск строки, имеющей положительное число:
    bool foundPositive = false;
    int positiveRow = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                foundPositive = true;
                positiveRow = i;
                break;
            }
        }
        if (foundPositive) {
            break;
        }
    }

    //Если найдена строка с положительным числом, то 
    if (foundPositive) {
        cout << "Строка " << positiveRow + 1 << " содержит положительное число." << endl;
        //изменяем знаки элементов предыдущей строки на противоположные
        for (int j = 0; j < n; j++) {
            matrix[positiveRow - 1][j] *= -1;
        }
        //Выводим измененную матрицу на экран
        cout << "Измененная матрица: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    //Если такая строка не найдена, то выводим соответствующее сообщение на экран
    else {
        cout << "Ни одна строка не содержит положительное число." << endl;
    }

    // Освобождаем память, выделенную под матрицу
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}