#include "Vehicle.h"

Vehicle::Vehicle()
{
	this->maxSpeed = 0;
	this->model = "";
}

void Vehicle::setModel(std::string model)
{
	this->model = model;
}

std::string Vehicle::getModel()
{
	return this->model;
}

void Vehicle::setSpeed(int speed)
{
	this->maxSpeed = speed;
}

int Vehicle::getSpeed()
{
	return this->maxSpeed;
}

std::istream& operator>>(std::istream& input, Vehicle& vehicle)
{
	std::cout << "Model:" << std::endl;
	while (1)
	{
		try
		{
			input >> vehicle.model;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw StrException("Failed to input the model!");
			}
			break;
		}
		catch (BaseException& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}
	std::cout << "Maximum speed:" << std::endl;
	while (1)
	{
		try
		{
			input >> vehicle.maxSpeed;
			if (std::cin.fail() || vehicle.maxSpeed <= 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw IntException("Maximum speed should be a positive int!");
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

std::ostream& operator<<(std::ostream& output, Vehicle& vehicle)
{
	output << "|" << std::setw(15) << vehicle.getModel();
	output << "|" << std::setw(9) << vehicle.getSpeed();

	return output;
}