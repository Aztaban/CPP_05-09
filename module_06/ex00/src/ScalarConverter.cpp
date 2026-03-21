#include <iostream>
#include <string>
#include <cctype>
#include "ScalarConverter.hpp"

static bool	isDigit(const std::string& str) {
	if (str.empty())
		return (false);
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool	isPseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" ||  str == "-inff");
}

