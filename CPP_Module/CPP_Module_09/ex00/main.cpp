//
// Created by Heesung Choi on 11/19/24.
//

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;

		std::string inputFile(argv[1]), line;
		if (std::getline(inputFile, line)) {
			validateInputHeader(line);
		}

		while (std::getline(inputFile, line)) {
			processLine(exchange, line);
		}

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}


}

void processLine(BitcoinExchange &exchange, const std::string &line) {
	std::stringstream ss(line);
	std::string date, value;

	if (std::getline(ss, date, '|') && std::getline(ss, value, '|')) {
		exchange.processLine(date, value);
	} else {
		throw std::invalid_argument("Invalid input: " + line);
	}
}

void validateInputHeader(const std::string &line) {
	std::stringstream ss(line);
	std::string firstHeader, secondHeader;

	if (std::getline(ss, firstHeader, '|') && std::getline(ss, secondHeader, '|')) {
		if (firstHeader != "date" || secondHeader != "value") {
			throw std::invalid_argument("Invalid input header: " + firstHeader + " | " + secondHeader);
		}
	} else {
		throw std::invalid_argument("Invalid input header: " + line);
	}
}

bool checkLeapYear(std::string date) {
	std::time(&time);
	std::tm *time = std::localtime(&time);

}