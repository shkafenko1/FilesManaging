#pragma once
#include "Exception.h"

class InputException : public BaseException
{
public:
	explicit InputException(const std::string& message) : BaseException(message) {}
};