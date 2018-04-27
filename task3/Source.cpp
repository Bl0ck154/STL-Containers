#include "Header.h"
#include "Dictionary.h"
#include <Windows.h>
#include <locale>

/*��������� ��������� map ����������� ��������� � �������.
�������� �����������:
1. ����� �����;
2. ����������, ��������, �������������� ����;
3. ������ � ������ ������� � ����.*/
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
		cout << "\n������� �����: \n";

		cin >> word1;
		if (word1[0] == '0') // 0 ��� ������ �� ���������
			break;

		word2 = dictionary.find(word1);
		if (!word2.empty())
		{
			cout << word1 << " - " << word2;
			cout << "\n1. �������������" << "\n2. �������" << endl;
			cin >> answer;
			if (answer == 1)
			{
				cout << "����� ����� ����� ���������������? 1 ��� 2: ";
				cin >> answer;
				cout << "������� ������ �����: ";
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
			cout << "����� �� ������� � �������. �������� ������� (1/0)? ";
			cin >> answer;
			if (answer == 1)
			{
				cout << "������� �������: ";
				cin >> word2;
				dictionary.add(word1, word2);
			}
		}
	}
}