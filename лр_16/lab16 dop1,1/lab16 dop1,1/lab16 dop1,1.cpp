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

int main() {
    setlocale(LC_ALL, "RUS");
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

    return 0;
}