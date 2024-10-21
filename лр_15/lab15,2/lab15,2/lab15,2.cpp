#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n;

	cout << "Введите размер массива n = ";
	cin >> n;//вводим размер массива

	//Выделяем память под матрицу
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

	cout << "Введите элементы матрицы:" << endl;
	//Вводим матрицу
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << endl;

	//Поиск первой строки со всеми отрицательными элементами:
	int firstNegativeRow = -1;
	for (int i = 0; i < n; i++) {
		bool allNegative = true;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] >= 0) {
				allNegative = false;
				break;
			}
		}
		if (allNegative) {
			firstNegativeRow = i;
			break;
		}
	}

	//Если нашли строку со всеми отрицательными элементами, то 
	if (firstNegativeRow != -1) {
		//Добавляем ко всем элементам матрицы первый элемент данной строки :
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] += matrix[firstNegativeRow][0];
			}
		}
		//Выводим измененную матрицу на экран:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;//выполняем переход на новую строку
		}
	}
	else {//Иначе выводим соответствующее сообщение на экран:
		cout << "Не была найдена строка со всеми отрацательными числами." << endl;
	}

	// Освобождаем память, выделенную под матрицу
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}