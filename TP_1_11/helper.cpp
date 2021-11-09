#include "helper.h"

bool checkStringToInt(std::string s)
{
	for (auto letter : s)
		if (letter < '0' || letter > '9')
			return false;
	return true;
}