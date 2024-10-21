#include <iostream> 
using namespace std;

//Функция для поиска максимального числа в матрице
int findNegative(int** a, int n, int m, int rowNegative) {
    bool foundNegative = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < 0) {
                foundNegative = true;
                rowNegative = i + 1;
                break;
            }
        }
        if (foundNegative) {
            break;
        }
    }
    //Если был найден отрицательный элемент
    if (foundNegative) {
        //Выводим номер строки, содержащий отрицательный элемент 
        cout << "Номер строки, содержащей отрицательный элемент: " << rowNegative << endl;
        //Все элементы столбца с этим номером уменьшаем вдвое
        for (int i = 0; i < n; i++) {
            a[i][rowNegative - 1] /= 2;
        }
        //Выводим измененную матрицу на экран
        cout << "Измененная матрица: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {//Если отрицательных элементов в матрице нет, то выводим соответствующее сообщение на экран
        cout << "Ни одна строка не содержит отрицательный элемент." << endl;
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

    //Объявляем переменную и вызываем функцию
    int rowNegative = 0;
    findNegative(a, n, m, rowNegative);

    //Освобождаем память, выделенную под массив
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}