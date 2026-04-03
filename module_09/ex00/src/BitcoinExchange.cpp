#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

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
/* 		if (!isValidDate(date))
			throw std::runtime_error("Error: bad database date => " + date); */
		std::stringstream	rateStream(rateString);
		if (!(rateStream >> rate) || (rateStream >> extra))
			throw std::runtime_error("Error: bad database rate => " + rateString);
		_rates[date] = rate;
	}
}

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