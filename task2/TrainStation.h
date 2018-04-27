#pragma once
#include <vector>
#include "Header.h"
#include "Train.h"
/*�������� ��������� ������������������� ���������- ����� ������� �� �������.
������� ��������: �������� �� ����������� ������� �������� ����������.

��� ������� ������ ���������: �����, ����� �����������, ������� ����������.
����������:
� ���� ������ � �������;
� ����� ���������� � ���� �������;
� ����� ���������� � ������������� ������;
� ������������ ������������ ����� vector.*/
class TrainStation
{
	vector <Train> Trains;
	string Name; // station name
public:
	TrainStation(string name)
	{
		Name = name;
	}
	void AddTrain()
	{
		int num;
		cout << "Enter train number: ";
		cin >> num;
		string dep, dest;
		cout << "Enter departure time: ";
		cin.ignore();
		getline(cin, dep);
		cout << "Enter train destination: ";
		getline(cin, dest);
		Trains.push_back(Train(num, dep, dest));
		cout << "Success!\n";
	}
	void PrintAll()
	{
		for each (Train var in Trains)
		{
			var.PrintInfo();
		}
	}
	void PrintByNum(int num)
	{
		for each (Train var in Trains)
		{
			if (var.GetNumber() == num)
			{
				var.PrintInfo();
				break;
			}
			if (var.GetNumber() == Trains[Trains.size()-1].GetNumber())
				cout << "Not found\n";
		}
	}
};

