#include <iostream>
#include <string>
using namespace std;

//Функция для нахождения количества положительных, отрицательных и равных нулю чисел
void findElementsCount(int& negativeCount, int& positiveCount, int& zeroCount, int** a, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] < 0) {
                negativeCount++;
            }
            else {
                if (a[i][j] > 0) {
                    positiveCount++;
                }
                else {
                    zeroCount++;
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int N, M;
    //Вводим размер матрицы
    cout << "Введите размеры матрицы: ";
    cin >> N >> M;

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

    //Вводим переменные и используем функцию
    int negativeCount = 0;
    int positiveCount = 0;
    int zeroCount = 0;
    findElementsCount(negativeCount, positiveCount, zeroCount, a, N, M);
    //Выводим результат на экран
    cout << "Отрицательные: " << negativeCount << endl;
    cout << "Положительные: " << positiveCount << endl;
    cout << "Нулевые: " << zeroCount << endl;

    //освобождаем выделенную память
    for (int i = 0; i < N; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}