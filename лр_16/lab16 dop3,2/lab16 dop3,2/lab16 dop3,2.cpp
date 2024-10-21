#include <iostream> 
#include <string> 
#include <Windows.h>
using namespace std;

//функция для нахождения слова БГТУ
string find_bstu(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'Б' && s[i + 1] == 'Г' && s[i + 2] == 'Т' && s[i + 3] == 'У') {
            return "да";
        }
    }
    return "нет";
}

int main() {
    SetConsoleCP(1251); 
    setlocale(LC_ALL, "rus"); 

    string s; //создаем строку
    //вводим строку с клавиатуры
    cout << "Введите строку: "; 
    getline(cin, s);
    cout << "В строке содержится БГТУ: " << find_bstu(s);

    return 0;
}