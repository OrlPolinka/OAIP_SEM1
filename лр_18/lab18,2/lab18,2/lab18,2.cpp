#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    // Открываем файл для чтения
    FILE* F1;
    if (fopen_s(&F1, "F1.txt", "r") != 0) {
        cerr << "Ошибка открытия файла F1.txt" << endl;
        return 1;
    }

    // Открываем файл для записи
    FILE* F2;
    if (fopen_s(&F2, "F2.txt", "w") != 0) {
        cerr << "Ошибка открытия файла F2.txt" << endl;
        return 1;
    }

    //создаем массив для хранения строк, не содеражщих цифр, и записываем данные строки в файл F2
    char line[100];
    while (fgets(line, sizeof(line), F1) != NULL) {
        bool containsDigits = false;
        for (int i = 0; line[i] != '\0'; i++) {
            if (isdigit(line[i])) {
                containsDigits = true;
                break;
            }
        }
        if (!containsDigits) {
            fputs(line, F2);
        }
    }

    fclose(F1);
    fclose(F2);

    return 0;
}