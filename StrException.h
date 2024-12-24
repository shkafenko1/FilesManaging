#pragma once
#include "InputException.h"

class StrException : public InputException
{
public:
	StrException(const std::string& message) :InputException(message) {}
};