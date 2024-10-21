#include <iostream>
#include<fstream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    int elementA, elementB, elementC;
    // Открываем файл для чтения
    FILE* inputFile;
    FILE* input1File;
    FILE* input2File;
    FILE* input3File;

    fopen_s(&inputFile, "NameA.txt", "rt");
    fopen_s(&input1File, "NameB.txt", "rt");
    fopen_s(&input2File, "NameC.txt", "rt");
    fopen_s(&input3File, "NameD.txt", "w");

    // Проверяем успешность открытия файлов
    if (inputFile == nullptr || input1File == nullptr || input2File == nullptr || input3File == nullptr) {
        cerr << "Ошибка открытия файлов" << endl;
        return 1;
    }

    //с помощью цикла записываем, чередуя, элементы из других файлов в файл NameD
    while (fscanf_s(inputFile, "%d", &elementA) == 1 && fscanf_s(input1File, "%d", &elementB) == 1 && fscanf_s(input2File, "%d", &elementC) == 1) {
        fprintf(input3File, " %d %d %d", elementA, elementB, elementC);
    } 

    cout << "Результат в файле NameD.txt" << endl;

    return 0;
}