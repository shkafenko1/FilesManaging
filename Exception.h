#pragma once
#include <iostream>

class BaseException : public std::exception
{
public:
	explicit BaseException(const std::string& message) : message(message) {}

	const char* what() const noexcept override;

protected:
	std::string message;
};