#pragma once
#include "InputException.h"

class IntException : public InputException
{
public:
	explicit IntException(const std::string& message) : InputException(message) {};
};