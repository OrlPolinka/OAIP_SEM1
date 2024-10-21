#include <iostream>
using namespace std;

//распишем функцию для проверки, содержится ли слово в массиве:
bool isWordEncountered(char word[][50], int numEncounteredWords, char* currentWord) {
    for (int i = 0; i < numEncounteredWords; ++i) {
        if (strcmp(word[i], currentWord) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	char sentence[] = "Кофе - мой друг. Кофе - моя любовь.";//вводим предложение
	//создаём массив для храения слов, которые уже встречались
	char encounteredWords[100][50];
	int numEncounteredWords = 0;
    //вводим флаг для определения, находимся ли мы внутри слова
	bool inWord = false;
	//вводим переменную, для хранения нашего текущего слова
	char currentWord[50];
	int currentWordIndex = 0;

    for (int i = 0; i <= strlen(sentence); ++i) {//проходим по каждому элементу
        char currentChar = sentence[i];

        if (currentChar == ' ' || currentChar == '\0') {//если это пробел или конец строки, то
            currentWord[currentWordIndex] = '\0';//завершаем текущее слово
            
            if (!isWordEncountered(encounteredWords, numEncounteredWords, currentWord)) {//проверяем, встречалось ли слово раньше
                cout << currentWord << " ";
                strcpy_s(encounteredWords[numEncounteredWords], currentWord);
                ++numEncounteredWords;
            }
            //сбрасываем индекс текущего слова
            currentWordIndex = 0;
            inWord = false;
        }
        else {//добавляем символ в текущее слово
            currentWord[currentWordIndex] = currentChar;
            ++currentWordIndex;
            inWord = true;
        }
    }
    cout << endl;
    return 0;
}
