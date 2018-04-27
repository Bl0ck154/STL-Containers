#pragma once
#include<map>
#include"Header.h"
#include"FileProc.h"
#include <iterator>

template<typename T>T map_find_by_value(map<T, T>items, T value)
{
	for (map<T, T>::iterator it = items.begin(); it != items.end(); ++it)
		if (it->second == value)
			return it->first;
	return string();
}
class Dictionary
{
	FileProc *file = nullptr;
	map<string, string> items;
public:
	Dictionary() {}
	~Dictionary()
	{
		if (file != nullptr)
			delete file;
	}
	string find(string slovo)
	{
		auto result = items.find(slovo);
		return result != items.end() ? result->second : map_find_by_value(items,slovo);
	}
	void load(string fname)
	{
		file = new FileProc(fname);
		file->read(items);
	}
	void add(string slovo, string perevod)
	{
		if (file == nullptr)
			throw exception("File not loaded");

		file->add(slovo, perevod);
		items.insert(make_pair(slovo, perevod));
	}
	void edit(string slovo, string perevod)
	{
		if (file == nullptr)
			throw exception("File not loaded");

		file->edit(slovo, perevod);
		items.insert(make_pair(slovo, perevod));
	}
	void remove(string slovo)
	{
		if (file == nullptr)
			throw exception("File not loaded");

		items.erase(slovo);
		file->remove(slovo);
	}
};