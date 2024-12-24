#include "Vehicle.h"
#pragma once

class Passenger : public Vehicle
{
private:
	std::string parkName;
	int passengerCapacity;

public:
	Passenger();

	void setPark(std::string park);
	std::string getPark();

	void setCapacity(int capacity);
	int getCapacity();

	friend std::istream& operator>>(std::istream& input, Passenger& pass);
	friend std::ostream& operator<<(std::ostream& output, Passenger& pass);
};