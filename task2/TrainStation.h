#pragma once
#include <vector>
#include "Header.h"
#include "Train.h"
/*Написать программу «Автоматизированная информаци- онная система ЖД вокзала».
Система содержит: сведения об отправлении поездов дальнего следования.

Для каждого поезда указываем: номер, время отправления, станцию назначения.
Обеспечить:
• Ввод данных в систему;
• Вывод информации о всех поездах;
• Вывод информации о запрашиваемом поезде;
• Использовать контейнерный класс vector.*/
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

