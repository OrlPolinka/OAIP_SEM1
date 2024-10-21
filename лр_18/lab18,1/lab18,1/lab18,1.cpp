#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    // Открываем файл для чтения
    FILE* fileA;
    if (fopen_s(&fileA, "fileA.txt", "r") != 0) {
        cerr << "Ошибка открытия файла fileA.txt" << endl;
        return 1;
    }

    //вводим число x
    int x;
    cout << "Введите число x: ";
    cin >> x;

    //Читаем компоненты последовательности из файла
    int n = 12;

    //создаем массив для хранения компонентов последовательности
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        if (fscanf_s(fileA, "%d", &arr[i]) != 1) {
            cerr << "Ошибка чтения элемента файла fileA.txt" << endl;
            delete[] arr;
            fclose(fileA);
            return 1;
        }
    }
    fclose(fileA);

    //Ищем 2 числа, среднее арифмитическое которых ближк всего к x
    int closestSum = INT_MAX;
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = (arr[i] + arr[j]) / 2;
            if (abs(sum - x) < abs(closestSum - x)) {
                closestSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    //выводим результат на экран
    cout << "Два числа из последовательности, среднее арифмитическое которых ближе всего к x: " << num1 << ", " << num2 << endl;
    delete[] arr;
    return 0;
}