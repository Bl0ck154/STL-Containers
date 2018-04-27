#pragma once
#include <string>
#include "Header.h"

class Train
{
	int Number;
	string DepTime; // departure
	string Destination;
public:
	Train(int num, string dep, string dest)
	{
		Number = num;
		DepTime = dep;
		Destination = dest;
	}
	void PrintInfo()
	{
		cout << "Train number: " << Number << "; Going to: " << Destination << "; Departure time: " << DepTime << ".\n";
	}
	int GetNumber()
	{
		return Number;
	}
};

