#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Функция для нахождения столбца, в котором находится элемент k
int find(int** a, int x) {
    for (int i = 0; i < sizeof(a[0]); i++) {
        for (int j = 0; j < sizeof(a[0][0]); j++) {
            if (a[i][j] == x) {
                return j + 1;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice;
    cout << "Выберите номер задания" << endl;
    cout << "1 - Задание 1" << endl;
    cout << "2 - Задание 2" << endl;
    cout << "3 - Выход" << endl;
    while(true){
        cout << "Выберите пункт: ";
        cin >> choice;
        switch (choice) {
            case 1:{ 
                int N, M, k;
                //Вводим размер матрицы
                cout << "Введите размеры матрицы: ";
                cin >> N >> M;
                //Вводим число k
                cout << "Введите число k = ";
                cin >> k;

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

                //Выводим результат на экран, используя функцию
                cout << "Столбец, в котором содержится элемент k: " << find(a, k) << endl;

                //освобождаем выделенную память
                for (int i = 0; i < N; i++) {
                    delete[] a[i];
                }
                delete[] a;
                break;
            }
               
            case 2:{
                vector<string> a; // Векторный массив строк для хранения отдельных слов

                cout << "Введите предложение: ";
                string word, s;
                char let;

                // Вводим исходную строку с остановкой на точке
                getline(cin, s, '.');
                s += "."; // Добавляем точку в конец строки для обработки последнего слова
                int i = 0;
                let = s[i];

                // Цикл разбора строки на отдельные слова
                while (let != '.') {
                    if (let != ' ') {
                        word += let; // Отделяем слова
                    }
                    else {
                        a.push_back(word); // Заполняем массив строк
                        word = "";
                    }
                    i++;
                    let = s[i];
                }

                a.push_back(word); // Добавляем последнее слово в массив
                word = "";

                // Если количество слов четное, то меняем местами слова в середине
                if (a.size() % 2 == 0) {
                    swap(a[a.size() / 2], a[a.size() / 2 - 1]);
                }

                // Выводим измененное предложение на экран
                cout << "Измененное предложение: ";
                for (auto c = a.begin(); c != a.end(); c++) {
                    cout << *c << " ";
                }
                cout << ".";
                break;
            }
             
            case 3: {
                exit(0);
            }
        }
    }

    return 0;
}
    

    
