#include <iostream>
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

    int arrUnicNum[100];//создаем массив для хранения чисел последовательности
    int unicNum = 0;//создаем переменную количества уникальных чисел
    int num;//создаем переменную для текущего элемента

    while (fscanf_s(fileA, "%d", &num) == 1) {//читаем все элементы файла
        bool dupl = false;//создаем переменную дубликатов
        for (int i = 0; i < unicNum; i++) {//просматриваем все элементы
            if (arrUnicNum[i] == num) {//если элемент дублируется, то 
                dupl = true;//присваиваем переменной значение true
                break;//выход из цикла
            }
        }
        //если не было найдено дубликатов, то записываем данное число в fileB
        if (!dupl) {
            arrUnicNum[unicNum] = num;
            unicNum++;
            fprintf(fileB, "%d ", num);
        }
    }
    //закрываем файлы
    fclose(fileA);
    fclose(fileB);

    cout << "Результат записан в файл fileB.txt" << endl;
    return 0;
}