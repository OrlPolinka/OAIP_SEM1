#include <iostream>
#include <string>
using namespace std;

//Функция для нахождения количества положительных, отрицательных и равных нулю чисел
void findElementsCount(int& negativeCount, int& positiveCount, int& zeroCount, int** a, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] < 0) {
                negativeCount++;
            }
            else {
                if (a[i][j] > 0) {
                    positiveCount++;
                }
                else {
                    zeroCount++;
                }
            }
        }
    }
}

//Функция для нахождения количества слов в тексте
int countWords(string text) {
    int wordCount = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            wordCount++;
        }
    }
    wordCount++;
    return wordCount;
}

int main() {
    setlocale(LC_ALL, "RUS");
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
            int N, M;
            //Вводим размер матрицы
            cout << "Введите размеры матрицы: ";
            cin >> N >> M;

            //Создаем массив и выделяем для него память 
            int** a;
            a = new int* [N];
            for (int i = 0; i < N; i++) {
                a[i] = new int[M];
            }

            //Выводим нашу матрицу на экран
            cout << "Введите элементы матрицы: " << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cin >> a[i][j];
                }
            }

            //Вводим переменные и используем функцию
            int negativeCount = 0;
            int positiveCount = 0;
            int zeroCount = 0;
            findElementsCount(negativeCount, positiveCount, zeroCount, a, N, M);
            //Выводим результат на экран
            cout << "Отрицательные: " << negativeCount << endl;
            cout << "Положительные: " << positiveCount << endl;
            cout << "Нулевые: " << zeroCount << endl;

            //освобождаем выделенную память
            for (int i = 0; i < N; i++) {
                delete[] a[i];
            }
            delete[] a;
            break;
        }

        case 2: {
            string text;
            cin.ignore(); // Очищаем входной буфер
            
            cout << "Введите текст: ";
            getline(cin, text); // Вводим текст 

            int totalWords = countWords(text);//присваиваем переменной значение функции

            cout << "Общее количество слов: " << totalWords << endl;//выводим результат на экран
            break;
        }

        case 3: {
            exit(0);
        }
        }
    }

    return 0;
}