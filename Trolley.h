#include"Passenger.h"
#pragma once

class Trolley : public Passenger
{
private:
	int power;
	int freeRideDistance;

public:
	Trolley();

	void setPower(int power);
	int getPower();

	void setDistance(int distance);
	int getDistance();

	void printHead();

	std::string serialize();
	Trolley deserialize(const std::string& token);

	friend std::istream& operator>>(std::istream& input, Trolley& trolley);

	friend std::ostream& operator<<(std::ostream& output, Trolley& trolley);
};