#include <iostream> 
#include <algorithm> 
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	string dict[] = { "hello","lleoh","house","lol","oll" };//вводим словарь слов
	
	for (int i = 0; i < sizeof(dict) / sizeof(dict[0]); i++)//с помощью цикла for выводим все слова на экран  
	{
		cout << dict[i] << " ";
	}
	cout << endl;

	//находим слова, которые записаны одними и теми же буквами
	for (int i = 0; i < sizeof(dict) / sizeof(dict[0]); i++) 
	{
		if (dict[i].size() == dict[i + 1].size())//если их длина одинакова, то
		{
			//сортируем наши слова по номерам в кодировке
			sort(dict[i].begin(), dict[i].end());
			sort(dict[i + 1].begin(), dict[i + 1].end());
		}

		//если после сортировки слова идентичны, то они записаны одними и теми же буквами
		if (dict[i] == dict[i + 1]) 
		{
			cout << "\nСлово под номером " << i + 1 << " и слово под номером " << i + 2 << " записаны одними и теми же буквами.";//и в этом случае выводим наш результат на экран
		}
	}
	return 0;
}