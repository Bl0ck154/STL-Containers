#include <iostream>
#include "Header.h"
#include "FileOpener.h"
#include "FileWriter.h"
#include <algorithm>

void main()
{
	FileOpener file("text.txt");
	map <string, int> testmap;
	file.read(testmap);

	bool kolonki = false;
	int _max = 0;
	string max_word;
	for each (pair<string,int> el in testmap)
	{
//		_max = max(_max, el.second);
		if (_max < el.second)
			_max = el.second, max_word = el.first;
		cout << "Word: " << el.first << " - " << el.second << " times";
		if ((kolonki = !kolonki))
			cout << "\t\t\t";
		else
			cout << endl;
	}
	cout << "\n\nThe most used word is \"" << max_word << "\" - " << _max << " times\n";
	FileWriter fw("result.txt");
	fw.write(testmap);
}