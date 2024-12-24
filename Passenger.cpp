#include "Passenger.h"

Passenger::Passenger()
{
	this->parkName = "";
	this->passengerCapacity = 0;
}

void Passenger::setPark(std::string park)
{
	this->parkName = park;
}

std::string Passenger::getPark()
{
	return this->parkName;
}

void Passenger::setCapacity(int capacity)
{
	this->passengerCapacity = capacity;
}

int Passenger::getCapacity()
{
	return this->passengerCapacity;
}

std::istream& operator>>(std::istream& input, Passenger& pass)
{
	input >> static_cast<Vehicle&>(pass);
	std::cout << "Park name:" << std::endl;
	while (1)
	{
		try
		{
			input >> pass.parkName;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw StrException("Failed to input the park name!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}
	std::cout << "Passenger capacity:" << std::endl;
	while (1)
	{
		try
		{
			input >> pass.passengerCapacity;
			if (std::cin.fail() || pass.passengerCapacity <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Passenger capacity should be a positive int!");
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

std::ostream& operator<<(std::ostream& output, Passenger& pass)
{
	output << static_cast<Vehicle&>(pass);
	output << "|" << std::setw(15) << pass.getPark();
	output << "|" << std::setw(8) << pass.getCapacity();

	return output;
}