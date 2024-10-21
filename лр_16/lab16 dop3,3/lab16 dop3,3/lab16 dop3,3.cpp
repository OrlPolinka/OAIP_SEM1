#include <iostream>
#include <string>
#include <Windows.h>
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

// функция для нахождения слова БГТУ
string find_bstu(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'Б' && s[i + 1] == 'Г' && s[i + 2] == 'Т' && s[i + 3] == 'У') {
            return "да";
        }
    }
    return "нет";
}


int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    int choice;
    cout << "Выберите номер задания" << endl;
    cout << "1 - Задание 1" << endl;
    cout << "2 - Задание 2" << endl;
    cout << "3 - Выход" << endl;
    while (true) {
        cout << "Выберите пункт: ";
        cin >> choice;
        switch (choice) {
        case 1: {
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
            cout << "Сумма элементов: " << find_sum(arr, n) << endl;
            break;
        }

        case 2: {
            string s; //создаем строку
            cin.ignore(); // Очищаем входной буфер
            //вводим строку с клавиатуры
            cout << "Введите строку: ";
            getline(cin, s);
            cout << "В строке содержится БГТУ: " << find_bstu(s) << endl;
            break;
        }

        case 3: {
            exit(0);
        }
        }
    }

    return 0;
}