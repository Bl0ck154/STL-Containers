#pragma once
#include "Header.h"
#include <fstream>
#include <map>
class FileProc
{
	string fname;
	fstream file;
	string content;
	void add_to_content(string tmp1, string tmp2) {
		content += tmp1 + " " + tmp2 + "\n";
	}
	void rewrite()
	{
		file.open(fname, ios::out);
		file << content;
		file.close();
	}
public:
	FileProc(string fname)
	{
		this->fname = fname;
	}
	void read(map<string,string>&mapa)
	{
		file.open(fname, ios::in);
		string tmp1, tmp2;
		bool turn = false;
		while (!file.eof())
		{
			file >> ((turn = !turn) ? tmp1 : tmp2);
			if (!turn)
			{
				mapa.insert(make_pair(tmp1, tmp2));
				add_to_content(tmp1, tmp2);
			}
		}
		file.close();
	}
	void add(string word, string translation)
	{
		file.open(fname, ios::app);
		file << word << " " << translation << endl;
		add_to_content(word, translation);
		file.close();
	}
	void edit(string word, string translation)
	{
		int pos = content.find(word);
		if (pos != string::npos)
		{
			content.erase(pos, word.size());
			content.insert(pos, translation);
			rewrite();
		}
	}
	void remove(string word)
	{
		int pos = content.find(word);
		if (pos != string::npos)
		{
			while (content[pos] != '\n')
				content.erase(pos, 1);
			content.erase(pos, 1);
		}
		rewrite();
	}
};

