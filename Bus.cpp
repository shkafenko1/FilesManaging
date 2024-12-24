#include "Bus.h"
#include <vector>
#include <sstream>

Bus::Bus()
{
	this->fuelConsumption = 0;
	this->tankVolume = 0;
}

void Bus::setFuel(int fuel)
{
	this->fuelConsumption = fuel;
}

int Bus::getFuel()
{
	return this->fuelConsumption;
}

void Bus::setVolume(int volume)
{
	this->tankVolume = volume;
}

int Bus::getVolume()
{
	return this->tankVolume;
}

std::istream& operator>>(std::istream& input, Bus& bus)
{
	input >> static_cast<Passenger&>(bus);
	std::cout << "Tank volume:" << std::endl;
	while (1)
	{
		try
		{
			input >> bus.tankVolume;
			if (std::cin.fail() || bus.tankVolume <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Tank volume should be a positive int!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}
	std::cout << "Fuel consumption:" << std::endl;
	while (1)
	{
		try
		{
			input >> bus.fuelConsumption;
			if (std::cin.fail() || bus.fuelConsumption <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Fuel consumption should be a positive int!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}


	return input;
}

std::ostream& operator<<(std::ostream& output, Bus& bus)
{
	output << static_cast<Passenger&>(bus);
	output << "|" << std::setw(6) << bus.getVolume();
	output << "|" << std::setw(5) << bus.getFuel();
	output << "|" << std::endl;

	output << "+";
	for (size_t i = 0; i < 63; i++)
	{
		output << "-";
	}
	output << "+" << std::endl;

	return output;
}

void Bus::printHead()
{
	system("cls");
	std::cout << "|" << std::setw(15) << "Model";
	std::cout << "|" << std::setw(9) << "Max speed";
	std::cout << "|" << std::setw(15) << "Park name";
	std::cout << "|" << std::setw(8) << "Capacity";
	std::cout << "|" << std::setw(6) << "Tank";
	std::cout << "|" << std::setw(5) << "Fuel";
	std::cout << "|" << std::endl;

	std::cout << "+";
	for (size_t i = 0; i < 63; i++)
	{
		std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

std::string Bus::serialize()
{
	return this->getModel() + ";" + std::to_string(this->getSpeed()) + ";" + this->getPark() + ";" + std::to_string(this->getCapacity()) + ";" + std::to_string(this->tankVolume) + ";" + std::to_string(this->fuelConsumption) + "\n";
}

Bus Bus::deserialize(const std::string& token)
{
	std::istringstream is(token);
	std::vector<std::string> fields;
	std::string field;

	while (std::getline(is, field, ';'))
	{
		fields.push_back(field);
	}
	if (fields.size() != 6)
	{
		std::cout << "Error:(";
		/*throw FileException("Object couldn't be deserialized!");*/
	}
	this->setModel(fields[0]);
	this->setSpeed(stoi(fields[1]));
	this->setPark(fields[2]);
	this->setCapacity(stoi(fields[3]));
	this->setVolume(stoi(fields[4]));
	this->setFuel(stoi(fields[5]));

	return *this;
}