#include "DumpTruck.h"
#include <vector>
#include <sstream>

DumpTruck::DumpTruck()
{
	this->axlesCount = 0;
	this->volume = 0;
}

void DumpTruck::setAxles(int axles)
{
	this->axlesCount = axles;
}

int DumpTruck::getAxles()
{
	return this->axlesCount;
}

void DumpTruck::setVolume(int volume)
{
	this->volume = volume;
}

int DumpTruck::getVolume()
{
	return this->volume;
}

std::istream& operator>>(std::istream& input, DumpTruck& dumptruck)
{
	input >> static_cast<Cargo&>(dumptruck);
	std::cout << "Dump volume:" << std::endl;
	while (1)
	{
		try
		{
			input >> dumptruck.volume;
			if (std::cin.fail() || dumptruck.volume <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Dump volume should be a positive int!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}
	std::cout << "Number of axles:" << std::endl;
	while (1)
	{
		try
		{
			input >> dumptruck.axlesCount;
			if (std::cin.fail() || dumptruck.axlesCount <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Number of axles should be a positive int!");
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

std::ostream& operator<<(std::ostream& output, DumpTruck& dumptruck)
{
	output << static_cast<Cargo&>(dumptruck);
	output << "|" << std::setw(6) << dumptruck.getVolume();
	output << "|" << std::setw(5) << dumptruck.getAxles();
	output << "|" << std::endl;

	output << "+";
	for (size_t i = 0; i < 63; i++)
	{
		output << "-";
	}
	output << "+" << std::endl;

	return output;
}

void DumpTruck::printHead()
{
	system("cls");
	std::cout << "|" << std::setw(15) << "Model";
	std::cout << "|" << std::setw(9) << "Max speed";
	std::cout << "|" << std::setw(15) << "Owner";
	std::cout << "|" << std::setw(8) << "Capacity";
	std::cout << "|" << std::setw(6) << "Dump";
	std::cout << "|" << std::setw(5) << "Axles";
	std::cout << "|" << std::endl;

	std::cout << "+";
	for (size_t i = 0; i < 63; i++)
	{
		std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

std::string DumpTruck::serialize()
{
	return this->getModel() + ";" + std::to_string(this->getSpeed()) + ";" + this->getOwner() + ";" + std::to_string(this->getCapacity()) + ";" + std::to_string(this->volume) + ";" + std::to_string(this->axlesCount) + "\n";
}

DumpTruck DumpTruck::deserialize(const std::string& token)
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
	this->setOwner(fields[2]);
	this->setCapacity(stoi(fields[3]));
	this->setVolume(stoi(fields[4]));
	this->setAxles(stoi(fields[5]));

	return *this;
}