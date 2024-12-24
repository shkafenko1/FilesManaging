#pragma once
#include "Exception.h"

class FileException : public BaseException
{
	public:
		explicit FileException(const std::string& message) : BaseException(message) {}
};