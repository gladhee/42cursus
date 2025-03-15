//
// Created by Heesung Choi on 11/19/24.
//

#include "BitcoinExchange.hpp"

void run(BitcoinExchange &exchange, std::ifstream *inputFile);

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	std::ifstream* inputFile = exchange.getFile(argv[1]);\
	run(exchange, inputFile);

	delete inputFile;
	return 0;
}

void run(BitcoinExchange &exchange, std::ifstream *inputFile) {
	std::string line;

	exchange.validateInputHeader(inputFile);

	while (std::getline(*inputFile, line)) {
		try {
			exchange.processLine(line);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
