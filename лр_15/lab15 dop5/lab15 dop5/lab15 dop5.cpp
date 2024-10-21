#include <iostream>
using namespace std;

//объявляем и расписываем функции для выделения динамической памяти под массив
int* createArray(int n) {
    return new int[n];
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n;

    cout << "Введите размер массива n = ";
    cin >> n;//вводим размер массива

    int* A = createArray(n);//выделяем динамическую память под массив a размером n

    //вводим массив 
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }

    //находим максимальное число
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    //подсчитываем, сколько раз оно встречается
    int countMax = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == max) {
            countMax++;
        }
    }

    //выводим результат на экран 
    cout << "Максимальное число " << max << " встречается " << countMax << " раз." << endl;

    free(A);//освобождаем выделенную динамическую память
    return 0;
}