//
// Created by Heesung Choi on 11/19/24.
//

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::DATA_FILE = "data.csv";
const std::string BitcoinExchange::DATE = "date";
const std::string BitcoinExchange::EXCHANGE_RATE = "exchange_rate";
const std::string BitcoinExchange::INPUT_DELIMITER = "|";
const std::string BitcoinExchange::VALUE = "value";

BitcoinExchange::BitcoinExchange() {
	this->exchangeRate = loadExchangeRate(DATA_FILE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	if (this == &other) {
		return;
	}

	exchangeRate = other.exchangeRate;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this == &other) {
		return *this;
	}

	exchangeRate = other.exchangeRate;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::loadExchangeRate(const std::string &filename) {
	std::map<std::string, double> exchangeRate;
	std::ifstream file(filename);

	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file: " + filename);
	}

	std::string line;

	if (std::getline(file, line)) {
		validateDatabaseHeader(line);
	}

	while (std::getline(file, line)) {
		processLine(exchangeRate, line);
	}

	file.close();

	return exchangeRate;
}

void BitcoinExchange::validateDatabaseHeader(const std::string &line) const {
	std::stringstream ss(line);
	std::string firstHeader, secondHeader;

	if (std::getline(ss, firstHeader, ',') && std::getline(ss, secondHeader)) {
		if (firstHeader != DATE || secondHeader != EXCHANGE_RATE) {
			throw std::runtime_error("Invalid header format. Expected 'date,exchange_rate' but got '" +
									 firstHeader + "," + secondHeader + "'");
		}
	} else {
		throw std::runtime_error("Malformed header line.");
	}
}

void BitcoinExchange::processLine(std::map<std::string, double> &exchangeRate, const std::string &line) {
	std::stringstream ss(line);
	std::string date, rateStr;

	if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
		try {
			double rate = std::stod(rateStr);
			exchangeRate[date] = rate;
		} catch (const std::invalid_argument &) {
			std::cerr << "Error: Invalid rate format in line: " << line << std::endl;
		}
	}
}
