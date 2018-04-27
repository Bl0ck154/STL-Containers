#pragma once
#include "Header.h"
#include <map>

class FileWriter
{
	string fname;
public:
	FileWriter();
	FileWriter(const char*);
	void write(map<string, int>&);
};
