#include <iostream> 
using namespace std;

//Функция для поиска столбца, все элементы которого положительны
int findPositiveCol(int** a, int n, int m) {
    bool positiveCol = -1;
    //Поиск столбца, все элементы которого положительные
    for (int j = 0; j < m; j++) {
        bool allPositive = true;
        for (int i = 0; i < n; i++) {
            if (a[i][j] <= 0) {
                allPositive = false;
                break;
            }
        }
        if (allPositive) {
            positiveCol = j;
            break;
        }
    }

    // Если найден столбец с положительными элементами, то
    if (positiveCol != -1) {
        // Измененяем знаки предыдущего столбца
        if (positiveCol > 0) {
            cout << "Столбец, в котором все элементы положительные: " << positiveCol + 1 << endl;
            for (int i = 0; i < n; i++) {
                a[i][positiveCol - 1] *= -1;
            }
        }

        // Выводим измененную матрицу на экран
        cout << "Измененная матрица: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {//Если такой столбец не найден, то выводим соответствующее сообщение на экран
        cout << "Ни один столбец не содержит только положительные элементы." << endl;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    //Вводим размер матрицы
    cout << "Введите размеры матрицы: ";
    cin >> n >> m;

    //Создаем массив и выделяем для него память 
    int** a;
    a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    //Выводим нашу матрицу на экран
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    //вызываем функцию
    findPositiveCol(a, n, m);

    //Освобождаем память, выделенную под массив
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}