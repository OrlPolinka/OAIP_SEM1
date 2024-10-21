#include <iostream>
#include <map>
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

    // Открываем файл для записи
    FILE* fileB;
    if (fopen_s(&fileB, "fileB.txt", "w") != 0) {
        cerr << "Ошибка открытия файла fileB.txt" << endl;
        return 1;
    }

    // Создаем словарь для хранения чисел и их количества в файле
    map<int, int> numCount;

    int num;
    while (fscanf_s(fileA, "%d", &num) == 1) {
        numCount[num]++; // Увеличиваем счетчик для данного числа
    }

    // Записываем в fileB числа, которые встречаются более двух раз
    for (auto const& pair : numCount) {
        if (pair.second > 2) {
            for (int i = 0; i < pair.second; i++) {
                fprintf(fileB, "%d ", pair.first);
            }
        }
    }

    //закрываем файлы
    fclose(fileA);
    fclose(fileB);

    cout << "Результат записан в файл fileB.txt" << endl;
    return 0;
}