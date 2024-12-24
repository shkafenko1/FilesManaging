#include "Trolley.h"
#include <vector>
#include <sstream>

Trolley::Trolley()
{
	this->freeRideDistance = 0;
	this->power = 0;
}

void Trolley::setDistance(int distance)
{
	this->freeRideDistance = distance;
}

int Trolley::getDistance()
{
	return this->freeRideDistance;
}

void Trolley::setPower(int power)
{
	this->power = power;
}

int Trolley::getPower()
{
	return this->power;
}

std::istream& operator>>(std::istream& input, Trolley& trolley)
{
	input >> static_cast<Passenger&>(trolley);
	std::cout << "Power:" << std::endl;
	while (1)
	{
		try
		{
			input >> trolley.power;
			if (std::cin.fail() || trolley.power <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Power should be a positive int!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}
	std::cout << "Free ride distance:" << std::endl;

	while (1)
	{
		try
		{
			input >> trolley.freeRideDistance;
			if (std::cin.fail() || trolley.freeRideDistance < 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("FRD should be a non-negative int!");
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

std::ostream& operator<<(std::ostream& output, Trolley& trolley)
{
	output << static_cast<Passenger&>(trolley);
	output << "|" << std::setw(6) << trolley.getPower();
	output << "|" << std::setw(5) << trolley.getDistance();
	output << "|" << std::endl;

	output << "+";
	for (size_t i = 0; i < 63; i++)
	{
		output << "-";
	}
	output << "+" << std::endl;

	return output;
}

void Trolley::printHead()
{
	system("cls");
	std::cout << "|" << std::setw(15) << "Model";
	std::cout << "|" << std::setw(9) << "Max speed";
	std::cout << "|" << std::setw(15) << "Park name";
	std::cout << "|" << std::setw(8) << "Capacity";
	std::cout << "|" << std::setw(6) << "Power";
	std::cout << "|" << std::setw(5) << "FRD";
	std::cout << "|" << std::endl;

	std::cout << "+";
	for (size_t i = 0; i < 63; i++)
	{
		std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

std::string Trolley::serialize()
{
	return this->getModel() + ";" + std::to_string(this->getSpeed()) + ";" + this->getPark() + ";" + std::to_string(this->getCapacity()) + ";" + std::to_string(this->power) + ";" + std::to_string(this->freeRideDistance) + "\n";
}

Trolley Trolley::deserialize(const std::string& token)
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
		throw FileException("Object couldn't be deserialized!");
	}
	this->setModel(fields[0]);
	this->setSpeed(stoi(fields[1]));
	this->setPark(fields[2]);
	this->setCapacity(stoi(fields[3]));
	this->setPower(stoi(fields[4]));
	this->setDistance(stoi(fields[5]));

	return *this;
}