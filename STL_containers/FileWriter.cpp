#include "FileWriter.h"



FileWriter::FileWriter()
{
}

FileWriter::FileWriter(const char* fname)
{
	this->fname = fname;
}

void FileWriter::write(map<string, int>&m)
{
	FILE*file = fopen(fname.c_str(), "w");

	int _max = 0;
	string max_word;
	string tmp = "Word - Times used\n";
	for each (pair<string, int> el in m)
	{
		if (_max < el.second)
			_max = el.second, max_word = el.first;
		tmp += el.first + " - ";
		tmp += to_string(el.second);
		tmp += "\n";
	}
	tmp += "\n\nThe most used word is \"" + max_word + "\" - ";
	tmp += to_string(_max);
	tmp += " times\n";
	fputs(tmp.c_str(), file);
	fclose(file);
}
