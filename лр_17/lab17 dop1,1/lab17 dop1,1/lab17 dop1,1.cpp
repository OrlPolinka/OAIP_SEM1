#include <iostream> 
using namespace std;

//Функция для нахождение четных элементров массива на нечетных местах
int findElements(int* a, int n, int count = 0) {
    for (int i = 0+1; i < n; i += 2) {
        if (a[i] < 0) {
            count++;
        }
    }
    cout << "Количество отрицательных элементов, стоящих на четных местах: " << count << endl;//выводим результат на экран
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

    findElements(a, n);//вызываем функцию
  
    delete[] a;//осовбождаем память, выделенную под массив
	return 0;
}