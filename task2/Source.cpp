#include "Header.h"
#include "TrainStation.h"

void main()
{
	TrainStation station("Rokovata");
	int answer = -1;
	while (answer != 0)
	{
		cout << "1. Add train\n"
			<< "2. Info about train\n"
			<< "3. Info about all\n"
			<< "0. Exit\n";

		cin >> answer;

		switch (answer)
		{
		case 1:
			station.AddTrain();
			break;
		case 2:
			int num;
			cout << "Enter train number: ";
			cin >> num;
			station.PrintByNum(num);
			break;
		case 3:
			station.PrintAll();
		}
	}
}