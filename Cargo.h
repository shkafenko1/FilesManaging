#include "Vehicle.h"
#pragma once

class Cargo : public Vehicle
{
private:
	std::string ownerCompany;
	int loadCapacity;

public:
	Cargo();

	void setOwner(std::string owner);
	std::string getOwner();

	void setCapacity(int capacity);
	int getCapacity();

	friend std::istream& operator>>(std::istream& input, Cargo& cargo);
	friend std::ostream& operator<<(std::ostream& output, Cargo& cargo);
};