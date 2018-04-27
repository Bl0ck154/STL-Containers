#include "Header.h"
#include "Dictionary.h"
#include <Windows.h>
#include <locale>

/*Используя контейнер map реализовать программу — словарь.
Основные возможности:
1. Поиск слова;
2. Добавление, удаление, редактирование слов;
3. Чтение и запись словаря в файл.*/
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Dictionary dictionary;
	dictionary.load("dict.txt");

	string word1;
	string word2;
	int answer;
	while (true)
	{
		cout << "\nВведите слово: \n";

		cin >> word1;
		if (word1[0] == '0') // 0 для выхода из программы
			break;

		word2 = dictionary.find(word1);
		if (!word2.empty())
		{
			cout << word1 << " - " << word2;
			cout << "\n1. Редактировать" << "\n2. Удалить" << endl;
			cin >> answer;
			if (answer == 1)
			{
				cout << "Какое слово нужно отредактировать? 1 или 2: ";
				cin >> answer;
				cout << "Введите замену слова: ";
				string tmp;
				cin >> tmp;
				dictionary.edit(answer == 1 ? word1 : word2, tmp);
			}
			else if (answer == 2)
			{
				dictionary.remove(word1);
			}
		}
		else
		{
			cout << "Слово не найдено в словаре. Добавить перевод (1/0)? ";
			cin >> answer;
			if (answer == 1)
			{
				cout << "Введите перевод: ";
				cin >> word2;
				dictionary.add(word1, word2);
			}
		}
	}
}