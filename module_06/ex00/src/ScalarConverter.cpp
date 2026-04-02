#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include "ScalarConverter.hpp"
#include "Colors.hpp"

enum e_type
{
	INVALID = -1,
	CHAR = 0,
	PSEUDO = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

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
	size_t	i = 0;
	size_t	len = literal.length();
	bool	hasDigitBeforeDot = false;
	bool	hasDigitAfterDot = false;

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
	return (isDecimalLiteral(literal, true));
}

static bool isDoubleLiteral(const std::string& literal)
{
	return (isDecimalLiteral(literal, false));
}

static int detectType(const std::string& literal)
{
	if (literal.empty())
		return (INVALID);
	if (isCharLiteral(literal))
		return (CHAR);
	if (isPseudoLiteral(literal))
		return (PSEUDO);
	if (isIntLiteral(literal))
		return (INT);
	if (isFloatLiteral(literal))
		return (FLOAT);
	if (isDoubleLiteral(literal))
		return (DOUBLE);
	return (INVALID);
}

static double	parseToDouble(const std::string& literal, int type) {
	std::stringstream	stream;
	long				lValue;
	float 				fValue;
	double				dValue;

	switch (type)
	{
		case CHAR:
			return (static_cast<char>(literal[1]));
		case INT:
			stream.str(literal);
			stream >> lValue;
			return (static_cast<double>(lValue));
		case FLOAT:
			stream.str(literal.substr(0, literal.length() - 1));
			stream >> fValue;
			return (static_cast<double>(fValue));
		case DOUBLE:
			stream.str(literal);
			stream >> dValue;
			return (dValue);
		default:
			return (0.0);
	}
}

static void	printPseudo(const std::string& literal);

static void	printChar(double value) {
	std::cout << std::left << std::setw(8) << "char: ";
	if (
		std::isnan(value) ||
		std::isinf(value) ||
		value < std::numeric_limits<char>::min() ||
		value > std::numeric_limits<char>::max()
	)
	{
		std::cout << RED << "impossible" << RESET << std::endl;
		return;
	}
	char c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
	{
		std::cout << RED << "Non displayable" << RESET << std::endl;
		return;
	}
	std::cout << BLUE << "'" << c << "'" << RESET << std::endl;
}

static void	printInt(double value) {
	std::cout << std::left << std::setw(8) << "int: ";
	if (
		std::isnan(value) ||
		std::isinf(value) ||
		value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max() 
	)
	{
		std::cout << RED << "impossible" << RESET << std::endl;
		return;
	}
	std::cout << BLUE << static_cast<int>(value) << RESET << std::endl;
}

static bool	hasNoFraction(double value) {
	double	intPart;
	return (std::modf(value, &intPart) == 0.0);
}

template <typename T>
static std::string	formatNumber(T value, bool addFSuffix) {
	std::ostringstream stream;

	if (hasNoFraction(value))
		stream << std::fixed << std::setprecision(1);
	stream << value;
	if (addFSuffix)
		stream << "f";
	return (stream.str());
}

static void	printFloat(double value) {
	float f = static_cast<float>(value);
	
	std::cout << std::left << std::setw(8) << "float: ";
	if (std::isnan(f))
	{
		std::cout << BLUE << "nanf" << RESET << std::endl;
		return;
	}
	if (std::isinf(f))
	{
		std::cout << BLUE << (f < 0 ? "-inff" : "+inff") << RESET << std::endl;
		return;
	}
	std::cout << BLUE << formatNumber(f, true) << RESET << std::endl;
}

static void	printDouble(double value) {
	std::cout << std::left << std::setw(8) << "double: ";
	if (std::isnan(value))
	{
		std::cout << BLUE << "nan" << RESET << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		std::cout << BLUE << (value < 0 ? "-inf" : "+inf") << RESET << std::endl;
		return;
	}
	std::cout << BLUE << formatNumber(value, false) << RESET << std::endl;
}

static void printPseudo(const std::string& literal) {
	std::cout << std::left << std::setw(8) << "char: " << RED << "impossible" << RESET << std::endl;
	std::cout << std::left << std::setw(8) << "int: " << RED << "impossible" << RESET << std::endl;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << std::left << std::setw(8) << "float: " << BLUE << literal << RESET << std::endl;
		std::cout << std::left << std::setw(8) << "double: " << BLUE 
				  << literal.substr(0, literal.length() - 1) << RESET << std::endl;
	}
	else
	{
		std::cout << std::left << std::setw(8) << "float: " << BLUE << literal << "f" << RESET << std::endl;
		std::cout << std::left << std::setw(8) << "double: " << BLUE << literal << RESET << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& literal) {
	int	type = detectType(literal);

	if (type == INVALID)
	{
		std::cerr << RED << "Invalid literal" << RESET << std::endl;
		return ;
	}
	if (type == PSEUDO)
	{
		printPseudo(literal);
		return;
	}
	double value = parseToDouble(literal, type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
