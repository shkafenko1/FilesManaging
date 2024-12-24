#include "Exception.h"

const char* BaseException::what() const noexcept
{
	return this->message.c_str();
}