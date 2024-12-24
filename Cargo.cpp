#include "Cargo.h"

Cargo::Cargo()
{
	this->loadCapacity = 0;
	this->ownerCompany = "";
}

void Cargo::setCapacity(int capacity)
{
	this->loadCapacity = capacity;
}

int Cargo::getCapacity()
{
	return this->loadCapacity;
}

void Cargo::setOwner(std::string owner)
{
	this->ownerCompany = owner;
}

std::string Cargo::getOwner()
{
	return this->ownerCompany;
}

std::istream& operator>>(std::istream& input, Cargo& cargo)
{
	input >> static_cast<Vehicle&>(cargo);
	std::cout << "Owner company:" << std::endl;
	while (1)
	{
		try
		{
			input >> cargo.ownerCompany;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw StrException("Failed to input the company!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}
	std::cout << "Load capacity:" << std::endl;
	while (1)
	{
		try
		{
			input >> cargo.loadCapacity;
			if (std::cin.fail() || cargo.loadCapacity <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Load capacity should be a positive int!");
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

std::ostream& operator<<(std::ostream& output, Cargo& cargo)
{
	output << static_cast<Vehicle&>(cargo);
	output << "|" << std::setw(15) << cargo.getOwner();
	output << "|" << std::setw(8) << cargo.getCapacity();

	return output;
}