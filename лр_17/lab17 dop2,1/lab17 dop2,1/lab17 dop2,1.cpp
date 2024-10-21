#include <iostream> 
using namespace std;

//Функция для нахождения максимального, минимального элементов и их разницы
int findElements(int* a, int n, int min, int max, int R = 0) {
    min = a[0];
    max = a[0];
    //Находим максимальный и минимальный элементы
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }
    //Находим их разность
    R = max - min;
    //Выводим результаты на экран
    cout << "Минимальный элемент: " << min << endl;
    cout << "Максимальный элемент: " << max << endl;
    cout << "Их разность равна: " << R << endl;

    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива n = ";
    cin >> n;//вводим размер массива
    cout << endl;

    int* a = new int[n];//создаём динамический массив

    //Вводим массив
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min, max, R = 0;//объявляем переменные
    min = a[0];
    max = a[0];
    findElements(a, n, min, max, R);//вызываем функцию

    delete[] a;//осовбождаем память, выделенную под массив
    return 0;
}