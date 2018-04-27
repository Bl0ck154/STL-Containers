#include "FileOpener.h"



FileOpener::FileOpener()
{
}


FileOpener::FileOpener(const char* fname)
{
	open(fname);
}


FileOpener::~FileOpener()
{
	close();
}

bool FileOpener::open(const char* fname)
{
	if (file.is_open())
		return false;

	file.open(fname);
	return file.is_open() ? true : false;
}

bool FileOpener::close()
{
	if (!file.is_open())
		return false;
	else
	{
		file.close();
		return file ? false : true;
	}
}

bool FileOpener::read(map<string, int> &mymap)
{
	if (!file.is_open())
		return false;

	string text;
	int tmp;
	while (!file.eof())
	{
		file >> text;
		while (!isalpha(text.back()))
			text.pop_back();
		while (!isalpha(text.front()))
			text.erase(0, 1);
		tmp = mymap[text]++;
		mymap.insert((make_pair(text, tmp)));
	}
}
