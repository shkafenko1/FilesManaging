#include <iostream>
#include <string>
#include <iomanip>
#include "IntException.h"
#include "StrException.h"
#include "FileException.h"
#pragma once

class Vehicle
{
private:
	std::string model;
	int maxSpeed;

public:
	Vehicle();

	void setModel(std::string model);
	std::string getModel();

	void setSpeed(int maxSpeed);
	int getSpeed();

	friend std::istream& operator>>(std::istream& input, Vehicle& vehicle);
	friend std::ostream& operator<<(std::ostream& output, Vehicle& vehicle);
};