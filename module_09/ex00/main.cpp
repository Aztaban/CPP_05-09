#include <iostream>
#include "BitcoinExchange.hpp"
#include "Colors.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		std::cerr << YELLOW << "Usage: ./btc <input_file>" << RESET << std::endl;
		return (1);
	}
	try {
		BitcoinExchange exchange = BitcoinExchange("data.csv");
		exchange.processInputFile(argv[1]);
	} 
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}