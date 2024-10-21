#include <iostream> 
#include <string>  
#include <vector>  
using namespace std; 


int main() {
    setlocale(LC_ALL, "rus"); 
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

    return 0;
}
