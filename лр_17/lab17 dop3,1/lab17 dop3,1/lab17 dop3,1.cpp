#include <iostream> 
using namespace std;

//Функция для удаления нечетных элементов в одномерном массиве
int delNum(int* mass, int a, int i) {
	for (int k = i; k < a; k++) {
		*(mass + k) = *(mass + k + 1);
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	int a;
	const int N = 20;//максимальное значение для массива
	int* mass = new int[N];//выделяем память для массива

	//вводим размер массива
	cout << "Введите размер массива: ";
	cin >> a;

	//Вводим массив
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < a; i++) {
		cin >> mass[i];
	}

	//проверяем массив на нечетность
	for (int i = 0; i < a; i++) {
		if (mass[i] % 2 != 0) {
			delNum(mass, a, i);//если элемент массива нечетный, то вызываем функцию
			i--;
			a--;
		}
	}

	//выводим на экран измененный массив
	cout << "Измененный массив: " << endl;
	for (int i = 0; i < a; i++) {
		cout << mass[i] << " ";
	}

	delete[] mass;//осовобождаем память, выделенную под массив
	return 0;
}