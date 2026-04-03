#include <iostream>
#include "BitcoinExchange.hpp"
#include "Colors.hpp"

int	main(void) {
	try {
		BitcoinExchange exchange = BitcoinExchange("data.csv");
	} 
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

}