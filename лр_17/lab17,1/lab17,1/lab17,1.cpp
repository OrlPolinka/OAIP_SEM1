#include <iostream> 
using namespace std;

//Функция для нахождение четных элементров массива на нечетных местах
int findElements(int* a, int n) {
	cout << "Номера четных элементов, стоящих на нечетных местах: ";
	for (int i = 0; i < n; i += 2) {
		if (a[i] % 2 == 0) {
			cout << i + 1 << " ";
		}
	}
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