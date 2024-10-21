#include <iostream>
#include <string>
using namespace std;

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
    string text;

    cout << "Введите текст: ";
    getline(cin, text); // Вводим текст 

    int totalWords = countWords(text);//присваиваем переменной значение функции

    cout << "Общее количество слов: " << totalWords << endl;//выводим результат на экран

    return 0;
}