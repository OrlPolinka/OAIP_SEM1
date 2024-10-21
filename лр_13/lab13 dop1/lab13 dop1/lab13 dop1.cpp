#include <iostream>
#include <string>
using namespace std;

//Вводим и расписываем функцию для поиска слов с заданным окончанием
void findWordsWithEnding(const string& input, const string& ending) 
{
    string word = "";//Вводим переменную для хранения текущего слова
    for (char c : input)//Проходим по всем символам нашей строки
    {
        if (c != ' ')//Если символ не является пробелом, добавляем его к текущему слову
        {
            word += c;
        }
        else//Если символ - пробел, значит текущее слово завершилось
        {
            if (word.size() >= ending.size() && word.rfind(ending) == word.size() - ending.size())//Проверяем, содержит ли текущее слово заданное окончание
            {
                cout << word << endl;//Выводим слово, если оно содержит заданное окончание
            }
            word = "";//Сбрасываем текущее слово для следующей итерации
        }
    }
    if (word.size() >= ending.size() && word.rfind(ending) == word.size() - ending.size())//Проверяем последнее слово после завершения цикла
    {
        cout << word << endl;//Выводим последнее слово, если оно содержит заданное окончание
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);//Вводим строку

    string ending;
    cout << "Задайте окончание: ";
    cin >> ending;//Вводим окончание

    findWordsWithEnding(input, ending);//Используем функцию для поиска слов с заданным окончанием

    return 0;
}