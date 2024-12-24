#include "Menu.h"

void Menu::chooseTransport()
{
	int choice;
	enum { ZERO, TROLLEY, BUS, DUMPTRUCK };
	Trolley trolley;
	Bus bus;
	DumpTruck truck;

	while (true)
	{
		std::cout << "Choose transport:" << std::endl
			<< "1.Trolley" << std::endl
			<< "2. Bus" << std::endl
			<< "3. Dump Truck" << std::endl
			<< "0. Close app" << std::endl;

		std::cin >> choice;
		system("cls");

		switch (choice)
		{
		case TROLLEY:
			this->Log(trolley, trolleys, "Trolley");
			break;
		case BUS:
			this->Log(bus, buses, "Bus");
			break;
		case DUMPTRUCK:
			this->Log(truck, trucks, "Dump Truck");
			break;
		case ZERO:
			return;
		default:
			break;
		}
	}
}