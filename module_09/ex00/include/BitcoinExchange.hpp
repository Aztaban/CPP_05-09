#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange {

private:
	std::map<std::string, double>	_rates;

	BitcoinExchange(void);

	bool		isLeapYear(int year) const;
	bool		isValidDate(const std::string& date) const;
	bool		isValidValue(const std::string& valueStr, double& value) const;
	std::string	trim(const std::string& str) const;
	double		getRateForDate(const std::string& date) const;

public:
	BitcoinExchange(const std::string& csvFile);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange&	operator=(const BitcoinExchange& copy);
	~BitcoinExchange(void);

	void	loadDatabase(const std::string& csvFile);
	void	processInputFile(const std::string& inputFile) const;

};

#endif