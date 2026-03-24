#include <iostream>
#include <string>
#include <cctype>
#include "ScalarConverter.hpp"

static bool	isPseudoLiteral(const std::string& str) {
	return (
		str == "nan" ||
		str == "nanf" ||
		str == "+inf" ||
		str == "-inf" ||
		str == "+inff" ||
		str == "-inff"
	);
}

static bool isCharLiteral(const std::string& literal)
{
	return (
		literal.length() == 3 &&
		literal[0] == '\'' &&
		literal[2] == '\'' &&
		std::isprint(static_cast<unsigned char>(literal[1]))
	);
}

static bool isIntLiteral(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return (false);
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	}
	return (true);
}

static bool isDecimalLiteral(const std::string& literal, bool requireF)
{
	size_t i = 0;
	size_t len = literal.length();
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;

	if (literal.empty())
		return false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	if (i == len)
		return false;

	while (i < len && std::isdigit(static_cast<unsigned char>(literal[i])))
	{
		hasDigitBeforeDot = true;
		i++;
	}

	if (i >= len || literal[i] != '.')
		return false;
	i++;

	while (i < len && std::isdigit(static_cast<unsigned char>(literal[i])))
	{
		hasDigitAfterDot = true;
		i++;
	}

	if (!hasDigitBeforeDot || !hasDigitAfterDot)
		return false;

	if (requireF)
		return (i == len - 1 && literal[i] == 'f');
	else
		return (i == len);
}

static bool isFloatLiteral(const std::string& literal)
{
	return isDecimalLiteral(literal, true);
}

static bool isDoubleLiteral(const std::string& literal)
{
	return isDecimalLiteral(literal, false);
}

static int detectType(const std::string& literal)
{
	if (literal.empty())
		return (-1);
	if (isCharLiteral(literal))
		return 0;
	if (isPseudoLiteral(literal))
		return (1);
	if (isIntLiteral(literal))
		return 2;
	if (isFloatLiteral(literal))
		return 3;
	if (isDoubleLiteral(literal))
		return 4;
	return -1;

}