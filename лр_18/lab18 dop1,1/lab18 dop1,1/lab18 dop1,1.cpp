#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    // Открываем файл для чтения
    FILE* inputFile;
    if (fopen_s(&inputFile, "input.txt", "rt") != 0) {
        cerr << "Ошибка открытия файла input.txt" << endl;
        return 1;
    }

    // Читаем количество столбцов в матрице из начала файла
    int columns;
    if (fscanf_s(inputFile, "%d", &columns) != 1) {
        cout << "Ошибка чтения количества столбцов из файла input.txt" << endl;
        fclose(inputFile);
        return 1;
    }

    // Открываем файл для записи транспонированной матрицы
    FILE* outputFile;
    if (fopen_s(&outputFile, "output.txt", "w") != 0) {
        cerr << "Ошибка открытия файла output.txt для записи" << endl;
        fclose(inputFile);
        return 1;
    }

    // Записываем количество строк в транспонированной матрице (равное изначальному количеству столбцов)
    fprintf(outputFile, "%d", columns);

    // Создаем двумерный массив для хранения матрицы
    float** matrix = new float* [columns];
    for (int i = 0; i < columns; ++i) {
        matrix[i] = new float[columns];
    }

    // Читаем матрицу из файла и транспонируем её
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (fscanf_s(inputFile, "%f", &matrix[i][j]) != 1) {
                cerr << "Ошибка чтения матрицы из файла input.txt" << endl;
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }
        }
    }

    // Записываем транспонированную матрицу в файл
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < columns; ++j) {
            fprintf(outputFile, " %f", matrix[j][i]);
        }
        fprintf(outputFile, "\n");
    }

    // Закрываем файлы и освобождаем память
    fclose(inputFile);
    fclose(outputFile);

    for (int i = 0; i < columns; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    cout << "Транспонированная матрица записана в файл output.txt" << endl;

    return 0;
}