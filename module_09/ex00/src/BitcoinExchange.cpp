#include "BitcoinExchange.hpp"
#include "Colors.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

// CONSTRUCTOR AND DESTRUCTORS
BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string& csvFile) {
	loadDatabase(csvFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _rates(copy._rates) {}

BitcoinExchange::~BitcoinExchange(void) {}

// OPERATOR OVERLOADS
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy)
		_rates = copy._rates;
	return (*this);
}

// MEMBER FUNCTIONS
double	BitcoinExchange::getRateForDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it;

	it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it == _rates.begin())
		throw std::runtime_error("Error: no earlier date in database.");
	it--;
	return (it->second);
}

std::string	BitcoinExchange::trim(const std::string& str) const {
	std::string::size_type	start;
	std::string::size_type	end;

	start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}

bool	BitcoinExchange::isLeapYear(int year) const {
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);
	return (year % 4 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	int		daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int		year;
	int		month;
	int		day;
	char	dash1;
	char	dash2;
	std::stringstream	sstream(date);

	if (date.length() != 10)
		return (false);
	if (!(sstream >> year >> dash1 >> month >> dash2 >> day))
		return (false);
	if (dash1 != '-' || dash2 != '-')
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const {
	std::stringstream	sstream(valueStr);
	char	extra;

	if (!(sstream >> value) || (sstream >> extra))
		return (false);
	return (true);
}

void	BitcoinExchange::loadDatabase(const std::string& csvFile) {
	std::ifstream	file(csvFile.c_str());
	std::string		line;
	std::string		date;
	std::string		rateString;
	double			rate;
	char			extra;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database file.");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::stringstream	ss(line);

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateString))
			throw std::runtime_error("Error: bad database line => " + line);
		if (date.empty() || rateString.empty())
			throw std::runtime_error("Error: bad database line => " + line);
		if (!isValidDate(date))
			throw std::runtime_error("Error: bad database date => " + date);
		std::stringstream	rateStream(rateString);
		if (!(rateStream >> rate) || (rateStream >> extra))
			throw std::runtime_error("Error: bad database rate => " + rateString);
		_rates[date] = rate;
	}
}

void	BitcoinExchange::processInputFile(const std::string& inputFile) const {
	std::ifstream		file(inputFile.c_str());
	std::string		line;
	std::string		date;
	std::string		valueStr;
	double			value;
	double			rate;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file '" + inputFile + "'.");
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty input file.");
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		std::stringstream	sstream(line);
		if (!std::getline(sstream, date, '|') || !std::getline(sstream, valueStr)) {
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		date = trim(date);
		valueStr = trim(valueStr);
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValidValue(valueStr, value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << RED << "Error: too large a number." << RESET << std::endl;
			continue;
		}
		try {
			rate = getRateForDate(date);
			std::cout << date << " => " << BLUE << value << RESET << " = "
					  << GREEN << value * rate << RESET << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
}