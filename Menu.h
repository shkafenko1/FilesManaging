#pragma once
#include "Files.h"
#include "Trolley.h"
#include "Bus.h"
#include "DumpTruck.h"
#include "Files.h"

class Menu
{
private:
	Stack<Trolley> trolleys;
	Stack<Bus> buses;
	Stack<DumpTruck> trucks;

	template<typename Transport>
	void addTransport(Transport& transport, Stack<Transport>& object);

	template<typename Transport>
	void printTransport(Stack<Transport>& object);

	template<typename Transport>
	void popTransport(Stack<Transport>& object);

	template<typename Transport>
	void inFileTransport(Stack <Transport>& object, std::string filename, bool binary);

	template<typename Transport>
	void outFileTransport(Stack<Transport>& object, std::string filename, bool binary);

	template <typename Transport>
	void Log(Transport& transport, Stack<Transport>& object, std::string type);

public:
	Menu() {}

	void chooseTransport();
};

// Метод addTransport: добавление транспорта в стек
template<typename Transport>
void Menu::addTransport(Transport& transport, Stack<Transport>& object)
{
	std::cin >> transport;
	object.push(transport); // Вызываем метод push стека
	std::cout << "Added transport to stack." << std::endl;
}

// Метод printTransport: вывод всех объектов транспорта из стека
template<typename Transport>
void Menu::printTransport(Stack<Transport>& object)
{
	object.print(); // Вызываем метод print стека
	std::cout << std::endl;
}

// Метод popTransport: удаление объекта с вершины стека
template<typename Transport>
void Menu::popTransport(Stack<Transport>& object)
{
	if (object.isEmpty()) {
		std::cout << "Stack is empty. Nothing to pop." << std::endl << std::endl;
	}
	else {
		object.pop(); // Вызываем метод pop стека
		std::cout << "Removed top transport from stack." << std::endl << std::endl;
	}
}

// Метод inFileTransport: запись стека в файл
template<typename Transport>
void Menu::inFileTransport(Stack<Transport>& object, std::string filename, bool binary)
{
	if (binary)
	{
		BinaryHandler bfile;
		bfile.open(filename);
		bfile.write(object);
		bfile.close();
	}
	else
	{
		try 
		{
			TextHandler tfile;
			tfile.open(filename);
			tfile.write(object);
			tfile.close();
		}
		catch (BaseException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
}

template<typename Transport>
void Menu::outFileTransport(Stack<Transport>& object, std::string filename, bool binary)
{
	if (binary)
	{
		BinaryHandler bfile;
		bfile.open(filename);
		bfile.read(object);
		bfile.close();
	}
	else
	{
		try
		{
			TextHandler tfile;
			tfile.open(filename);
			tfile.read(object);
			tfile.close();
		}
		catch (BaseException& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
}

// Метод Log: шаблонное меню
template<typename Transport>
void Menu::Log(Transport& transport, Stack<Transport>& object, std::string type)
{
	enum { ZERO, ADD, PRINT, POP, WBIN, WTXT, RBIN, RTXT };
	int choice;

	while (true)
	{
		std::cout << "Choose action:" << std::endl
			<< "1. Add " << type << std::endl
			<< "2. Output " << type << std::endl
			<< "3. Delete last " << type << std::endl
			<< "4. Write " << type << "s to binary file" << std::endl
			<< "5. Write " << type << "s to text file" << std::endl
			<< "6. Read " << type << "s from binary file" << std::endl
			<< "7. Read " << type << "s from text file" << std::endl
			<< "0. Back to transport choice" << std::endl;

		std::cin >> choice;

			system("cls");
		switch (choice)
		{
		case ADD:
			this->addTransport(transport, object);
			break;
		case PRINT:
			this->printTransport(object);
			break;
		case POP:
			this->popTransport(object);
			break;
		case WBIN:
			this->inFileTransport(object, type + ".bin", true);
			break;
		case WTXT:
			this->inFileTransport(object, type + ".txt", false);
			break;
		case RBIN:
			this->outFileTransport(object, type + ".bin", true);
			break;
		case RTXT:
			this->outFileTransport(object, type + ".txt", false);
			break;
		case ZERO:
			return;
		default:
			break;
		}
	}
}