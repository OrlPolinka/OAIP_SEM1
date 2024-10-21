#include <iostream>
using namespace std;

//функция для поиска минимального элемента
float find_min(float* arr, int n) {
    int a = 0;
    for (int i = 1; i < n; i++) {
        if (abs(arr[a]) > abs(arr[i])) {
            a = i;
        }
    }
    return arr[a];
}

//функция для нахождения суммы
float find_sum(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) { //поиск первого отрицательного элемента
            float sum = 0;
            for (int j = i + 1; j < n; j++) { //считаем сумму
                sum += arr[j];
            }
            return sum;
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus"); 
    float n;
    float* arr; //создаем массив

    //Вводим размер массива
    cout << "Введите размер массива: "; 
    cin >> n;
    //задаем размер массива
    arr = new float[n]; 
    //вводим элементы массива
    cout << "Введите массив: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //Выводим результат на экран, используя функция
    cout << "Минимальный элемент по модулю: " << find_min(arr, n) << endl;
    cout << "Сумма элементов: " << find_sum(arr, n); 

    return 0;
}
