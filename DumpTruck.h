#include "Cargo.h"
#pragma once

class DumpTruck : public Cargo
{
private:
	int volume;
	int axlesCount;

public:
	DumpTruck();

	void setVolume(int volume);
	int getVolume();

	void setAxles(int axles);
	int getAxles();

	void printHead();

	friend std::istream& operator>>(std::istream& input, DumpTruck& dumptruck);

	friend std::ostream& operator<<(std::ostream& output, DumpTruck& dumptruck);

	std::string serialize();
	DumpTruck deserialize(const std::string& token);
};