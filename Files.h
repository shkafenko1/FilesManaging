#pragma once
#pragma warning(disable : 4996)
#include "Data.h"
#include "FileException.h"
#include <fstream>
#include <stdio.h>

class FileHandler
{
	protected:
		std::fstream fileStream;
};

class TextHandler : public FileHandler
{
	public:
		void open(const std::string& filename)
		{
			fileStream.open(filename, std::ios::app | std::ios::in);
			if (!fileStream)
			{
				throw FileException("File didn't open");
			}
		}

		void close()
		{
			if (fileStream.is_open())
				fileStream.close();
		}

		template<typename T>
		void write(Stack<T>& transport)
		{
			while (!transport.isEmpty())
			{
				auto vehicle = transport.peek();
				std::string strvehicle = vehicle.serialize();
				fileStream << strvehicle;
				transport.pop();
			}
		}
		
		template<typename T>
		void read(Stack<T>& transport)
		{
			T vehicle;
			std::string strvehicle;
			while (std::getline(fileStream, strvehicle))
			{
				vehicle = vehicle.deserialize(strvehicle);
				transport.push(vehicle);
			}
			}
};	

class BinaryHandler : public FileHandler
{
	public:
		void open(const std::string& filename)
		{
			fileStream.open(filename, std::ios::binary | std::ios::in | std::ios::out);
			if (!fileStream)
			{
				throw FileException("File didn't open");
			}
		}

		void close()
		{
			if (fileStream.is_open())
				fileStream.close();
		}
		
		template <typename T>
		void write(Stack<T>& transport)
		{
			while (!transport.isEmpty())
			{
				auto vehicle = transport.peek();
				std::string strvehicle = vehicle.serialize();
				fileStream.write(strvehicle.data(), strvehicle.size());
				transport.pop();
			}
		}

		template<typename T>
		void read(Stack<T>& transport)
		{
			std::string strvehicle;
			T vehicle;
			char symbol;
			while (fileStream.get(symbol))
			{
				if (symbol == '\n')
				{
					vehicle = vehicle.deserialize(strvehicle);
					transport.push(vehicle);
					strvehicle.clear();
				}
				else
				{
					strvehicle += symbol;
				}
			}

			if (!strvehicle.empty())
			{
				vehicle = vehicle.deserialize(strvehicle);
				transport.push(vehicle);
				strvehicle.clear();
			}
		}

};