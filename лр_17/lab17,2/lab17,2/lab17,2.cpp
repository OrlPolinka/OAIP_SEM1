#include <iostream> 
using namespace std;

//Функция для поиска максимального числа в матрице
int findMax(int** a, int n, int m, int& max, int& maxN, int& maxM, int& count) {
    max = a[0][0];
    count = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                maxN = i;
                maxM = j;
                count = 1;
            }
            else {
                if (a[i][j] == max) {
                    count++;
                }
            }
        }
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

    //вводим переменные и вызываем функцию
    int max, maxN, maxM, count;
    findMax(a, n, m, max, maxN, maxM, count);

    //Выводим результат на экран в заависимости от условия
    if (count > 1) {
        cout << "Максимальное число: " << max << endl;
        cout << "Индексы: [" << maxN << "] [" << maxM << "]" << endl;
        cout << "Количество повторений: " << count << endl;
    }
    else {
        cout << "Максимальное число не повторяется." << endl;
    }

    //Освобождаем память, выделенную под массив
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}