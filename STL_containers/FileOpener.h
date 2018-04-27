#pragma once
#include <fstream>
#include "Header.h"

class FileOpener
{
	ifstream file;
public:
	FileOpener();
	FileOpener(const char*);
	~FileOpener();
	bool open(const char*);
	bool close();
	bool read(map<string,int>&);
};

