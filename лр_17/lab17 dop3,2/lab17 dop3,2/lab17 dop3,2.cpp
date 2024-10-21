#include <iostream> 
using namespace std;

int check(bool& hasNegative, int n, int i, int** matrix) {
	for (int j = 0; j < n; j++) {
		if (matrix[i][j] < 0) {
			hasNegative = true;
			break;
		}
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	
	//вводим размер матрицы
	cout << "Введите размеры матрицы: ";
	cin >> n;

	//Динамическое выделение памяти для матрицы
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

	//Вводим элементы матрицы
	cout << "Введите элементы матрицы: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	//Поиск строк без отрицательных элементов и вычисление их суммы
	int sum = 0;
	for (int i = 0; i < n; i++) {
		bool hasNegative = false;
		check(hasNegative, n, i, matrix);
	

	    //Если отрицаьельных элементов нет, то добавляем сумму элементов строки к общей сумме
	    if (!hasNegative) {
			for (int j = 0; j < n; j++) {
				sum += matrix[i][j];
			}
	    }
    }

	//выводим результат на экран
	cout << "Сумма элементов строк без отрицательных элементов: " << sum << endl;

	//Освобождаем память, выделенную для м матрицы
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}