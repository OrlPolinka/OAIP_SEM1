#include <iostream>
using namespace std;

//объявляем и расписываем функции для выделения динамической памяти под массив
int* createArray(int n) {
    return new int[n];
}

//объявляем и расписываем функцию для нахождения наименьшего k, при котором A[k] = 0
int findZeroIndex(const int* A, int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            return i;
        }
    }
    return 1;//в случае если элементы равные 0 не были найдены
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

    cout << endl;//переходим на следующую строку

    int zeroIndex = findZeroIndex(A, n);//производом поиск индекса элемента, равного 0

    //выводим наш результат на экран:
    if (zeroIndex != -1) {
        cout << "Наименьший элемент равный 0 занимает позицию " << zeroIndex << endl;
    }
    else {
        cout << "Элементы, равные 0, не были найдены." << endl;
    }

    free(A);//освобождаем выделенную динамическую память
    return 0;
}
