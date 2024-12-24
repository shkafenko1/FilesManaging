#include "Passenger.h"
#pragma once

class Bus : public Passenger
{
private:
	int tankVolume;
	int fuelConsumption;

public:
	Bus();

	void setVolume(int volume);
	int getVolume();

	void setFuel(int fuel);
	int getFuel();

	void printHead();

	friend std::istream& operator>>(std::istream& input, Bus& bus);

	friend std::ostream& operator<<(std::ostream& output, Bus& bus);

	std::string serialize();
	Bus deserialize(const std::string& token);
};